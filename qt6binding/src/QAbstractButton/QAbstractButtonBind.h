#ifndef QABSTRACTBUTTON_BIND_H
#define QABSTRACTBUTTON_BIND_H

#include <QAbstractButton>
#include <QButtonGroup>
#include <QIcon>
#include <QKeySequence>
#include <QSize>
#include <QString>

class QAbstractButtonHandler;

class QAbstractButtonBind {
public:
    // コンストラクタ/デストラクタ
    static QAbstractButton* create(QWidget* parent);
    static void destroy(QAbstractButton* button);
    
    // プロパティ取得
    static bool autoExclusive(QAbstractButton* button);
    static bool autoRepeat(QAbstractButton* button);
    static int autoRepeatDelay(QAbstractButton* button);
    static int autoRepeatInterval(QAbstractButton* button);
    static QButtonGroup* group(QAbstractButton* button);
    static QIcon* icon(QAbstractButton* button);
    static QSize* iconSize(QAbstractButton* button);
    static bool isCheckable(QAbstractButton* button);
    static bool isChecked(QAbstractButton* button);
    static bool isDown(QAbstractButton* button);
    static QKeySequence* shortcut(QAbstractButton* button);
    static QString* text(QAbstractButton* button);
    
    // プロパティ設定
    static void setAutoExclusive(QAbstractButton* button, bool autoExclusive);
    static void setAutoRepeat(QAbstractButton* button, bool autoRepeat);
    static void setAutoRepeatDelay(QAbstractButton* button, int delay);
    static void setAutoRepeatInterval(QAbstractButton* button, int interval);
    static void setCheckable(QAbstractButton* button, bool checkable);
    static void setDown(QAbstractButton* button, bool down);
    static void setIcon(QAbstractButton* button, QIcon* icon);
    static void setIconSize(QAbstractButton* button, QSize* size);
    static void setShortcut(QAbstractButton* button, QKeySequence* shortcut);
    static void setText(QAbstractButton* button, const char* text);
    static void setChecked(QAbstractButton* button, bool checked);
    
    // アクション
    static void animateClick(QAbstractButton* button);
    static void click(QAbstractButton* button);
    static void toggle(QAbstractButton* button);
    
    // シグナルハンドラ設定
    static void setClickedCallback(QAbstractButton* button, void (*callback)(void*, bool), void* data);
    static void setPressedCallback(QAbstractButton* button, void (*callback)(void*), void* data);
    static void setReleasedCallback(QAbstractButton* button, void (*callback)(void*), void* data);
    static void setToggledCallback(QAbstractButton* button, void (*callback)(void*, bool), void* data);
    
    // ハンドラ管理
    static QAbstractButtonHandler* getHandler(QAbstractButton* button);
    static void setHandler(QAbstractButton* button, QAbstractButtonHandler* handler);
};

#endif // QABSTRACTBUTTON_BIND_H
