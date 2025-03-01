# パフォーマンスモニタリング

## 6.1 シグナル処理時間の計測
```cpp
// 1. シグナルタイマー
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

// 2. シグナル処理プロファイラ
class SignalProfiler {
    struct ProfileData {
        qint64 totalTime;
        qint64 callCount;
        qint64 maxTime;
        qint64 minTime;
    };
    
    std::unordered_map<std::string, ProfileData> profiles;
    std::mutex mutex;
    
public:
    void recordSignal(const std::string& signal, qint64 time) {
        std::lock_guard<std::mutex> lock(mutex);
        auto& profile = profiles[signal];
        profile.totalTime += time;
        profile.callCount++;
        profile.maxTime = std::max(profile.maxTime, time);
        profile.minTime = profile.minTime == 0 ?
            time : std::min(profile.minTime, time);
    }
    
    void dumpProfiles() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& [signal, profile] : profiles) {
            qDebug() << "Signal:" << signal.c_str()
                     << "\n  Total time:" << profile.totalTime << "ms"
                     << "\n  Call count:" << profile.callCount
                     << "\n  Average time:"
                     << (profile.totalTime / profile.callCount) << "ms"
                     << "\n  Max time:" << profile.maxTime << "ms"
                     << "\n  Min time:" << profile.minTime << "ms";
        }
    }
};
```

## 6.2 コールバック頻度の監視
```cpp
// 1. コールバックモニタ
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

// 2. コールバック頻度アナライザ
class CallbackAnalyzer {
    struct CallbackStats {
        int totalCalls;
        std::chrono::steady_clock::time_point lastCall;
        std::vector<double> intervals;
    };
    
    std::unordered_map<void*, CallbackStats> stats;
    std::mutex mutex;
    
public:
    void recordCall(void* callback) {
        std::lock_guard<std::mutex> lock(mutex);
        auto& stat = stats[callback];
        auto now = std::chrono::steady_clock::now();
        
        if (stat.totalCalls > 0) {
            auto interval = std::chrono::duration_cast<
                std::chrono::milliseconds>(
                now - stat.lastCall).count();
            stat.intervals.push_back(interval);
        }
        
        stat.lastCall = now;
        stat.totalCalls++;
    }
    
    void analyzeCallbacks() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& [callback, stat] : stats) {
            if (stat.intervals.empty()) continue;
            
            double sum = std::accumulate(
                stat.intervals.begin(),
                stat.intervals.end(), 0.0);
            double mean = sum / stat.intervals.size();
            
            double sq_sum = std::inner_product(
                stat.intervals.begin(),
                stat.intervals.end(),
                stat.intervals.begin(), 0.0);
            double stdev = std::sqrt(
                sq_sum / stat.intervals.size() - mean * mean);
            
            qDebug() << "Callback:" << callback
                     << "\n  Total calls:" << stat.totalCalls
                     << "\n  Average interval:" << mean << "ms"
                     << "\n  Standard deviation:" << stdev << "ms";
        }
    }
};
```

## 6.3 パフォーマンス監視システム

### 1. メトリクスコレクタ
```cpp
class MetricsCollector {
    struct Metrics {
        qint64 signalCount;
        qint64 totalProcessingTime;
        qint64 callbackCount;
        qint64 totalCallbackTime;
        std::vector<qint64> processingTimes;
    };
    
    std::unordered_map<std::string, Metrics> metrics;
    std::mutex mutex;
    
public:
    void recordSignalMetrics(const std::string& signal,
                            qint64 processingTime) {
        std::lock_guard<std::mutex> lock(mutex);
        auto& m = metrics[signal];
        m.signalCount++;
        m.totalProcessingTime += processingTime;
        m.processingTimes.push_back(processingTime);
    }
    
    void recordCallbackMetrics(const std::string& signal,
                              qint64 callbackTime) {
        std::lock_guard<std::mutex> lock(mutex);
        auto& m = metrics[signal];
        m.callbackCount++;
        m.totalCallbackTime += callbackTime;
    }
    
    void generateReport() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& [signal, m] : metrics) {
            qDebug() << "Signal:" << signal.c_str()
                     << "\n  Signal count:" << m.signalCount
                     << "\n  Total processing time:"
                     << m.totalProcessingTime << "ms"
                     << "\n  Average processing time:"
                     << (m.totalProcessingTime / m.signalCount)
                     << "ms"
                     << "\n  Callback count:" << m.callbackCount
                     << "\n  Total callback time:"
                     << m.totalCallbackTime << "ms"
                     << "\n  Average callback time:"
                     << (m.totalCallbackTime / m.callbackCount)
                     << "ms";
        }
    }
};
```

### 2. パフォーマンスアラート
```cpp
class PerformanceAlert {
    struct Threshold {
        qint64 maxProcessingTime;
        qint64 maxCallbackTime;
        int maxCallbackFrequency;
    };
    
    std::unordered_map<std::string, Threshold> thresholds;
    std::function<void(const std::string&)> alertCallback;
    std::mutex mutex;
    
public:
    void setThreshold(const std::string& signal,
                     const Threshold& threshold) {
        std::lock_guard<std::mutex> lock(mutex);
        thresholds[signal] = threshold;
    }
    
    void setAlertCallback(
        std::function<void(const std::string&)> callback) {
        std::lock_guard<std::mutex> lock(mutex);
        alertCallback = callback;
    }
    
    void checkMetrics(const std::string& signal,
                     qint64 processingTime,
                     qint64 callbackTime,
                     int frequency) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = thresholds.find(signal);
        if (it == thresholds.end()) return;
        
        const auto& threshold = it->second;
        std::stringstream alert;
        bool hasAlert = false;
        
        if (processingTime > threshold.maxProcessingTime) {
            alert << "Processing time exceeded: "
                  << processingTime << "ms";
            hasAlert = true;
        }
        
        if (callbackTime > threshold.maxCallbackTime) {
            if (hasAlert) alert << "\n";
            alert << "Callback time exceeded: "
                  << callbackTime << "ms";
            hasAlert = true;
        }
        
        if (frequency > threshold.maxCallbackFrequency) {
            if (hasAlert) alert << "\n";
            alert << "Callback frequency exceeded: "
                  << frequency << " calls/sec";
            hasAlert = true;
        }
        
        if (hasAlert && alertCallback) {
            alertCallback(alert.str());
        }
    }
};
```

## 6.4 パフォーマンス最適化のガイドライン

### 1. シグナル処理の最適化
- 不要なシグナル発行の削減
- シグナルパラメータの最小化
- キューイング接続の適切な使用
- シグナルの優先順位付け

### 2. コールバック処理の最適化
- コールバック処理の軽量化
- コールバックチェーンの最適化
- メモリアロケーションの最小化
- キャッシュの活用

### 3. リソース使用の最適化
- メモリ使用量の監視
- CPU使用率の監視
- スレッド使用の最適化
- I/O操作の最適化

### 4. モニタリングの最適化
- 必要な情報のみを収集
- 収集頻度の適正化
- ストレージ使用量の考慮
- パフォーマンスへの影響の最小化
