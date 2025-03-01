# シグナル/スロット処理ガイドライン

## 1. 基本概念

### 1.1 シグナル/スロットの対応
```cpp
// C++側のシグナル/スロット
class QButtonBind : public QPushButton {
    Q_OBJECT
signals:
    void clicked(bool checked = false);
public slots:
    void onClicked(bool checked);
};

// C側のコールバック
typedef void (*ButtonCallback)(void* sender, bool checked);
```

### 1.2 コールバック管理
```cpp
// 1. コールバック保持
class CallbackHolder {
    std::unordered_map<std::string, void*> callbacks;
public:
    void setCallback(const std::string& signal, void* callback) {
        callbacks[signal] = callback;
    }
    
    void* getCallback(const std::string& signal) {
        auto it = callbacks.find(signal);
        return (it != callbacks.end()) ? it->second : nullptr;
    }
};

// 2. コールバックディスパッチ
void dispatch_callback(void* sender, const char* signal, void* data) {
    auto* holder = get_callback_holder(sender);
    if (auto callback = holder->getCallback(signal)) {
        reinterpret_cast<void (*)(void*, void*)>(callback)(sender, data);
    }
}
```

## 2. シグナルハンドラの実装

### 2.1 ハンドラクラス
```cpp
// 1. 基本ハンドラ
class QWidgetHandler : public QObject {
    Q_OBJECT
public:
    explicit QWidgetHandler(QWidget* target);
    void setCallback(const char* signal, void* callback);

private slots:
    void onSignal();
    void onSignalWithBool(bool value);
    void onSignalWithInt(int value);
    void onSignalWithString(const QString& value);

private:
    QWidget* m_target;
    std::unordered_map<std::string, void*> m_callbacks;
};

// 2. 特殊化ハンドラ
class QButtonHandler : public QWidgetHandler {
    Q_OBJECT
public:
    explicit QButtonHandler(QAbstractButton* button);

private slots:
    void onClicked(bool checked);
    void onToggled(bool checked);
    void onPressed();
    void onReleased();
};
```

### 2.2 シグナル接続
```cpp
// 1. 直接接続
void connect_signal_direct(QObject* sender, const char* signal,
                         QObject* receiver, const char* slot) {
    QObject::connect(sender, signal, receiver, slot,
                    Qt::DirectConnection);
}

// 2. キューイング接続
void connect_signal_queued(QObject* sender, const char* signal,
                          QObject* receiver, const char* slot) {
    QObject::connect(sender, signal, receiver, slot,
                    Qt::QueuedConnection);
}
```

## 3. C APIインターフェース

### 3.1 コールバック設定
```c
// 1. シグナルコールバックの設定
void Widget_setCallback(void* widget, const char* signal,
                       void (*callback)(void*, void*)) {
    auto* handler = get_handler(widget);
    handler->setCallback(signal, reinterpret_cast<void*>(callback));
}

// 2. イベントフィルタの設定
void Widget_setEventFilter(void* widget,
                         bool (*filter)(void*, void*)) {
    auto* handler = get_handler(widget);
    handler->setEventFilter(filter);
}
```

### 3.2 シグナル発行
```c
// 1. 手動シグナル発行
void Button_click(void* button) {
    auto* btn = static_cast<QAbstractButton*>(button);
    btn->click();
}

// 2. カスタムシグナル発行
void Widget_emitCustomSignal(void* widget, const char* signal,
                           void* data) {
    auto* handler = get_handler(widget);
    handler->emitSignal(signal, data);
}
```

## 4. データ変換

### 4.1 基本型の変換
```cpp
// 1. C++からCへの変換
void convert_to_c(const QVariant& value, void* data) {
    switch (value.type()) {
        case QVariant::Bool:
            *static_cast<bool*>(data) = value.toBool();
            break;
        case QVariant::Int:
            *static_cast<int*>(data) = value.toInt();
            break;
        case QVariant::String: {
            auto str = value.toString().toUtf8();
            strncpy(static_cast<char*>(data), str.constData(),
                   str.size() + 1);
            break;
        }
    }
}

// 2. CからC++への変換
QVariant convert_from_c(void* data, int type) {
    switch (type) {
        case BOOL_TYPE:
            return QVariant(*static_cast<bool*>(data));
        case INT_TYPE:
            return QVariant(*static_cast<int*>(data));
        case STRING_TYPE:
            return QVariant(QString::fromUtf8(
                static_cast<char*>(data)));
        default:
            return QVariant();
    }
}
```

### 4.2 複合型の変換
```cpp
// 1. 構造体の変換
struct Point {
    int x;
    int y;
};

void convert_point(const QPoint& qpoint, Point* point) {
    point->x = qpoint.x();
    point->y = qpoint.y();
}

QPoint convert_point(const Point* point) {
    return QPoint(point->x, point->y);
}

// 2. 配列の変換
struct Array {
    void** items;
    int count;
};

void convert_list(const QList<QObject*>& list, Array* array) {
    array->count = list.size();
    array->items = new void*[array->count];
    for (int i = 0; i < array->count; ++i) {
        array->items[i] = list[i];
    }
}
```

## 5. スレッド安全性

### 5.1 スレッドセーフなシグナル処理
```cpp
// 1. スレッドセーフなコールバック呼び出し
void invoke_callback_safe(QObject* sender, void* callback,
                        void* data) {
    if (QThread::currentThread() == sender->thread()) {
        // 同じスレッドなら直接呼び出し
        reinterpret_cast<void (*)(void*, void*)>(callback)(
            sender, data);
    } else {
        // 異なるスレッドならキューイング
        QMetaObject::invokeMethod(sender, [=]() {
            reinterpret_cast<void (*)(void*, void*)>(callback)(
                sender, data);
        }, Qt::QueuedConnection);
    }
}

// 2. スレッドセーフなイベント処理
class ThreadSafeHandler : public QObject {
    Q_OBJECT
    std::mutex mutex;
    std::queue<std::function<void()>> eventQueue;

public slots:
    void processEvents() {
        std::lock_guard<std::mutex> lock(mutex);
        while (!eventQueue.empty()) {
            eventQueue.front()();
            eventQueue.pop();
        }
    }

public:
    void postEvent(std::function<void()> event) {
        std::lock_guard<std::mutex> lock(mutex);
        eventQueue.push(std::move(event));
        QMetaObject::invokeMethod(this, "processEvents",
                                Qt::QueuedConnection);
    }
};
```

## 6. デバッグサポート

### 6.1 シグナルトレース
```cpp
// 1. シグナルトレーサー
class SignalTracer : public QObject {
    Q_OBJECT
public:
    void installOn(QObject* target) {
        for (int i = 0; i < target->metaObject()->methodCount(); ++i) {
            auto method = target->metaObject()->method(i);
            if (method.methodType() == QMetaMethod::Signal) {
                connect(target, method, this, 
                    SLOT(onSignalEmitted()), Qt::DirectConnection);
            }
        }
    }

private slots:
    void onSignalEmitted() {
        auto* sender = QObject::sender();
        auto* signal = QObject::senderSignalIndex();
        qDebug() << "Signal emitted:"
                 << sender->metaObject()->method(signal).name();
    }
};

// 2. コールバックトレーサー
class CallbackTracer {
    static std::unordered_map<void*, std::string> callbacks;
    static std::mutex mutex;

public:
    static void registerCallback(void* callback,
                               const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex);
        callbacks[callback] = name;
    }

    static void traceCallback(void* callback, void* sender,
                            void* data) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = callbacks.find(callback);
        if (it != callbacks.end()) {
            qDebug() << "Callback called:" << it->second;
        }
    }
};
```

### 6.2 パフォーマンスモニタリング
```cpp
// 1. シグナル処理時間の計測
class SignalTimer : public QObject {
    Q_OBJECT
    QElapsedTimer timer;
    std::unordered_map<std::string, qint64> timings;

public:
    void startTiming(const QString& signal) {
        timer.start();
    }

    void endTiming(const QString& signal) {
        timings[signal.toStdString()] += timer.elapsed();
    }

    void dumpTimings() {
        for (const auto& [signal, time] : timings) {
            qDebug() << "Signal:" << signal.c_str()
                     << "Total time:" << time << "ms";
        }
    }
};

// 2. コールバック頻度の監視
class CallbackMonitor {
    static std::unordered_map<void*, int> callCounts;
    static std::mutex mutex;

public:
    static void incrementCount(void* callback) {
        std::lock_guard<std::mutex> lock(mutex);
        ++callCounts[callback];
    }

    static void dumpStatistics() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& [callback, count] : callCounts) {
            qDebug() << "Callback:" << callback
                     << "Called:" << count << "times";
        }
    }
};
