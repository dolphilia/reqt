#ifndef QCOREAPPLICATION_BIND_H
#define QCOREAPPLICATION_BIND_H

#include <QCoreApplication>
#include <QEvent>
#include <QStringList>
#include <QTranslator>

class QCoreApplicationBind {
public:
    // プロパティ取得
    static const char* applicationName();
    static const char* applicationVersion();
    static const char* organizationDomain();
    static const char* organizationName();
    static bool isQuitLockEnabled();
    
    // プロパティ設定
    static void setApplicationName(const char* name);
    static void setApplicationVersion(const char* version);
    static void setOrganizationDomain(const char* domain);
    static void setOrganizationName(const char* name);
    static void setQuitLockEnabled(bool enabled);
    
    // アプリケーション情報
    static const char* applicationDirPath();
    static const char* applicationFilePath();
    static long long applicationPid();
    static bool closingDown();
    static bool startingUp();
    
    // イベント処理
    static void processEvents(int flags);
    static void processEventsWithTimeout(int flags, int ms);
    static void sendPostedEvents(QObject* receiver, int eventType);
    static bool sendEvent(QObject* receiver, QEvent* event);
    static void postEvent(QObject* receiver, QEvent* event, int priority);
    static void removePostedEvents(QObject* receiver, int eventType);
    
    // ライブラリパス
    static void addLibraryPath(const char* path);
    static void removeLibraryPath(const char* path);
    static const char** libraryPaths(int* count);
    static void setLibraryPaths(const char** paths, int count);
    
    // 翻訳
    static bool installTranslator(QTranslator* translator);
    static bool removeTranslator(QTranslator* translator);
    static const char* translate(const char* context, const char* sourceText, const char* disambiguation, int n);
    
    // アプリケーション属性
    static void setAttribute(int attribute, bool on);
    static bool testAttribute(int attribute);
    
    // その他
    static void exit(int returnCode);
    static void quit();
    static int exec();
    static bool isSetuidAllowed();
    static void setSetuidAllowed(bool allow);
};

#endif // QCOREAPPLICATION_BIND_H
