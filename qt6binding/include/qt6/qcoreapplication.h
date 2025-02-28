#ifndef QCOREAPPLICATION_C_H
#define QCOREAPPLICATION_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// イベントループフラグ
#define QEVENTLOOP_ALLEVENTS 0x00
#define QEVENTLOOP_EXCLUDEUSEREVENT 0x01
#define QEVENTLOOP_EXCLUDESOCKETNOTIFIER 0x02
#define QEVENTLOOP_WAITFOREVENTS 0x04
#define QEVENTLOOP_DIALOGEXEC 0x08
#define QEVENTLOOP_EVENTLOOPEXEC 0x10
#define QEVENTLOOP_X11EXCLUDENOTIFIER 0x20
#define QEVENTLOOP_EXCLUDEPOSTEDVENTS 0x40
#define QEVENTLOOP_PROCESSDEFERREDEVENTS 0x80

// アプリケーション属性
#define QT_AA_NATIVEWINDOWS 0
#define QT_AA_MSWINDOWSUSEDIRECTWRITEBYDEFAULT 1
#define QT_AA_DONTCREATENATIVEWIDGETSIBLINGS 2
#define QT_AA_MACDONTSWAPCTRLMETA 3
#define QT_AA_USEHIGHDPISCALING 4
#define QT_AA_DISABLEHIGHDPISCALING 5
#define QT_AA_USEHIGHDPIPIXMAPS 6
#define QT_AA_DISABLEHIGHDPIPIXMAPS 7
#define QT_AA_SHAREAPPLICATIONFONT 8
#define QT_AA_SETPALETTE 9
#define QT_AA_ENABLEHIGHDPISCALING 10
#define QT_AA_DISABLESHADEREFFECTS 11
#define QT_AA_DONTUSENATUREDOCKWIDGET 12
#define QT_AA_MACUSESMALLSCROLLBARS 13
#define QT_AA_COMPRESSHIBERNATEEVENTS 14
#define QT_AA_DONTUSEFONTCONFIG 15
#define QT_AA_QUITONLASTWINDOWCLOSED 16
#define QT_AA_DISABLEWINDOWPOSITIONING 17
#define QT_AA_DONTSHOWSHORTCUTSINALTERNATIVES 18
#define QT_AA_DONTSHOWICONSINTOOLBARS 19
#define QT_AA_DONTUSECUSTOMCURSORS 20
#define QT_AA_DONTUSESTYLEHINTS 21
#define QT_AA_ACCEPTTOUCHEVENTS 22
#define QT_AA_SYNTHETICMOUSEFROMTOUCHEVENTSTIMESTAMP 23
#define QT_AA_COMPRESSTOUCH 24
#define QT_AA_DONTCREATENANATIVEWIDGETSIBLINGS 25
#define QT_AA_DONTUSESOFTWARERASIZER 26
#define QT_AA_DONTUSESOFTWARERASIZER_MASK 27
#define QT_AA_FORCERASTERWIDGETS 28
#define QT_AA_PLUGINAPPPLICATION 29

// プロパティ取得
const char* QCoreApplication_applicationName();
const char* QCoreApplication_applicationVersion();
const char* QCoreApplication_organizationDomain();
const char* QCoreApplication_organizationName();
bool QCoreApplication_isQuitLockEnabled();

// プロパティ設定
void QCoreApplication_setApplicationName(const char* name);
void QCoreApplication_setApplicationVersion(const char* version);
void QCoreApplication_setOrganizationDomain(const char* domain);
void QCoreApplication_setOrganizationName(const char* name);
void QCoreApplication_setQuitLockEnabled(bool enabled);

// アプリケーション情報
const char* QCoreApplication_applicationDirPath();
const char* QCoreApplication_applicationFilePath();
long long QCoreApplication_applicationPid();
bool QCoreApplication_closingDown();
bool QCoreApplication_startingUp();

// イベント処理
void QCoreApplication_processEvents(int flags);
void QCoreApplication_processEventsWithTimeout(int flags, int ms);
void QCoreApplication_sendPostedEvents(void* receiver, int eventType);
bool QCoreApplication_sendEvent(void* receiver, void* event);
void QCoreApplication_postEvent(void* receiver, void* event, int priority);
void QCoreApplication_removePostedEvents(void* receiver, int eventType);

// ライブラリパス
void QCoreApplication_addLibraryPath(const char* path);
void QCoreApplication_removeLibraryPath(const char* path);
const char** QCoreApplication_libraryPaths(int* count);
void QCoreApplication_setLibraryPaths(const char** paths, int count);

// 翻訳
bool QCoreApplication_installTranslator(void* translator);
bool QCoreApplication_removeTranslator(void* translator);
const char* QCoreApplication_translate(const char* context, const char* sourceText, const char* disambiguation, int n);

// アプリケーション属性
void QCoreApplication_setAttribute(int attribute, bool on);
bool QCoreApplication_testAttribute(int attribute);

// その他
void QCoreApplication_exit(int returnCode);
void QCoreApplication_quit();
int QCoreApplication_exec();
bool QCoreApplication_isSetuidAllowed();
void QCoreApplication_setSetuidAllowed(bool allow);

#ifdef __cplusplus
}
#endif

#endif // QCOREAPPLICATION_C_H
