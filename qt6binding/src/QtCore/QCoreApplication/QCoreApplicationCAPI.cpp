#include "QCoreApplicationBind.h"

extern "C" {

// プロパティ取得
const char* QCoreApplication_applicationName() {
    return QCoreApplicationBind::applicationName();
}

const char* QCoreApplication_applicationVersion() {
    return QCoreApplicationBind::applicationVersion();
}

const char* QCoreApplication_organizationDomain() {
    return QCoreApplicationBind::organizationDomain();
}

const char* QCoreApplication_organizationName() {
    return QCoreApplicationBind::organizationName();
}

bool QCoreApplication_isQuitLockEnabled() {
    return QCoreApplicationBind::isQuitLockEnabled();
}

// プロパティ設定
void QCoreApplication_setApplicationName(const char* name) {
    QCoreApplicationBind::setApplicationName(name);
}

void QCoreApplication_setApplicationVersion(const char* version) {
    QCoreApplicationBind::setApplicationVersion(version);
}

void QCoreApplication_setOrganizationDomain(const char* domain) {
    QCoreApplicationBind::setOrganizationDomain(domain);
}

void QCoreApplication_setOrganizationName(const char* name) {
    QCoreApplicationBind::setOrganizationName(name);
}

void QCoreApplication_setQuitLockEnabled(bool enabled) {
    QCoreApplicationBind::setQuitLockEnabled(enabled);
}

// アプリケーション情報
const char* QCoreApplication_applicationDirPath() {
    return QCoreApplicationBind::applicationDirPath();
}

const char* QCoreApplication_applicationFilePath() {
    return QCoreApplicationBind::applicationFilePath();
}

long long QCoreApplication_applicationPid() {
    return QCoreApplicationBind::applicationPid();
}

bool QCoreApplication_closingDown() {
    return QCoreApplicationBind::closingDown();
}

bool QCoreApplication_startingUp() {
    return QCoreApplicationBind::startingUp();
}

// イベント処理
void QCoreApplication_processEvents(int flags) {
    QCoreApplicationBind::processEvents(flags);
}

void QCoreApplication_processEventsWithTimeout(int flags, int ms) {
    QCoreApplicationBind::processEventsWithTimeout(flags, ms);
}

void QCoreApplication_sendPostedEvents(void* receiver, int eventType) {
    QCoreApplicationBind::sendPostedEvents(static_cast<QObject*>(receiver), eventType);
}

bool QCoreApplication_sendEvent(void* receiver, void* event) {
    return QCoreApplicationBind::sendEvent(static_cast<QObject*>(receiver), static_cast<QEvent*>(event));
}

void QCoreApplication_postEvent(void* receiver, void* event, int priority) {
    QCoreApplicationBind::postEvent(static_cast<QObject*>(receiver), static_cast<QEvent*>(event), priority);
}

void QCoreApplication_removePostedEvents(void* receiver, int eventType) {
    QCoreApplicationBind::removePostedEvents(static_cast<QObject*>(receiver), eventType);
}

// ライブラリパス
void QCoreApplication_addLibraryPath(const char* path) {
    QCoreApplicationBind::addLibraryPath(path);
}

void QCoreApplication_removeLibraryPath(const char* path) {
    QCoreApplicationBind::removeLibraryPath(path);
}

const char** QCoreApplication_libraryPaths(int* count) {
    return QCoreApplicationBind::libraryPaths(count);
}

void QCoreApplication_setLibraryPaths(const char** paths, int count) {
    QCoreApplicationBind::setLibraryPaths(paths, count);
}

// 翻訳
bool QCoreApplication_installTranslator(void* translator) {
    return QCoreApplicationBind::installTranslator(static_cast<QTranslator*>(translator));
}

bool QCoreApplication_removeTranslator(void* translator) {
    return QCoreApplicationBind::removeTranslator(static_cast<QTranslator*>(translator));
}

const char* QCoreApplication_translate(const char* context, const char* sourceText, const char* disambiguation, int n) {
    return QCoreApplicationBind::translate(context, sourceText, disambiguation, n);
}

// アプリケーション属性
void QCoreApplication_setAttribute(int attribute, bool on) {
    QCoreApplicationBind::setAttribute(attribute, on);
}

bool QCoreApplication_testAttribute(int attribute) {
    return QCoreApplicationBind::testAttribute(attribute);
}

// その他
void QCoreApplication_exit(int returnCode) {
    QCoreApplicationBind::exit(returnCode);
}

void QCoreApplication_quit() {
    QCoreApplicationBind::quit();
}

int QCoreApplication_exec() {
    return QCoreApplicationBind::exec();
}

bool QCoreApplication_isSetuidAllowed() {
    return QCoreApplicationBind::isSetuidAllowed();
}

void QCoreApplication_setSetuidAllowed(bool allow) {
    QCoreApplicationBind::setSetuidAllowed(allow);
}

}
