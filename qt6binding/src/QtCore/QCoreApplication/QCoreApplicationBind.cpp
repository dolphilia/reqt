#include "QCoreApplicationBind.h"

const char* QCoreApplicationBind::applicationName() {
    static QString name;
    name = QCoreApplication::applicationName();
    return name.toUtf8().constData();
}

const char* QCoreApplicationBind::applicationVersion() {
    static QString version;
    version = QCoreApplication::applicationVersion();
    return version.toUtf8().constData();
}

const char* QCoreApplicationBind::organizationDomain() {
    static QString domain;
    domain = QCoreApplication::organizationDomain();
    return domain.toUtf8().constData();
}

const char* QCoreApplicationBind::organizationName() {
    static QString name;
    name = QCoreApplication::organizationName();
    return name.toUtf8().constData();
}

bool QCoreApplicationBind::isQuitLockEnabled() {
    return QCoreApplication::isQuitLockEnabled();
}

void QCoreApplicationBind::setApplicationName(const char* name) {
    if (name) {
        QCoreApplication::setApplicationName(QString::fromUtf8(name));
    }
}

void QCoreApplicationBind::setApplicationVersion(const char* version) {
    if (version) {
        QCoreApplication::setApplicationVersion(QString::fromUtf8(version));
    }
}

void QCoreApplicationBind::setOrganizationDomain(const char* domain) {
    if (domain) {
        QCoreApplication::setOrganizationDomain(QString::fromUtf8(domain));
    }
}

void QCoreApplicationBind::setOrganizationName(const char* name) {
    if (name) {
        QCoreApplication::setOrganizationName(QString::fromUtf8(name));
    }
}

void QCoreApplicationBind::setQuitLockEnabled(bool enabled) {
    QCoreApplication::setQuitLockEnabled(enabled);
}

const char* QCoreApplicationBind::applicationDirPath() {
    static QString path;
    path = QCoreApplication::applicationDirPath();
    return path.toUtf8().constData();
}

const char* QCoreApplicationBind::applicationFilePath() {
    static QString path;
    path = QCoreApplication::applicationFilePath();
    return path.toUtf8().constData();
}

long long QCoreApplicationBind::applicationPid() {
    return QCoreApplication::applicationPid();
}

bool QCoreApplicationBind::closingDown() {
    return QCoreApplication::closingDown();
}

bool QCoreApplicationBind::startingUp() {
    return QCoreApplication::startingUp();
}

void QCoreApplicationBind::processEvents(int flags) {
    QCoreApplication::processEvents(static_cast<QEventLoop::ProcessEventsFlags>(flags));
}

void QCoreApplicationBind::processEventsWithTimeout(int flags, int ms) {
    QCoreApplication::processEvents(static_cast<QEventLoop::ProcessEventsFlags>(flags), ms);
}

void QCoreApplicationBind::sendPostedEvents(QObject* receiver, int eventType) {
    QCoreApplication::sendPostedEvents(receiver, eventType);
}

bool QCoreApplicationBind::sendEvent(QObject* receiver, QEvent* event) {
    if (receiver && event) {
        return QCoreApplication::sendEvent(receiver, event);
    }
    return false;
}

void QCoreApplicationBind::postEvent(QObject* receiver, QEvent* event, int priority) {
    if (receiver && event) {
        QCoreApplication::postEvent(receiver, event, priority);
    }
}

void QCoreApplicationBind::removePostedEvents(QObject* receiver, int eventType) {
    QCoreApplication::removePostedEvents(receiver, eventType);
}

void QCoreApplicationBind::addLibraryPath(const char* path) {
    if (path) {
        QCoreApplication::addLibraryPath(QString::fromUtf8(path));
    }
}

void QCoreApplicationBind::removeLibraryPath(const char* path) {
    if (path) {
        QCoreApplication::removeLibraryPath(QString::fromUtf8(path));
    }
}

const char** QCoreApplicationBind::libraryPaths(int* count) {
    static QStringList paths;
    static QList<QByteArray> pathsUtf8;
    static QList<const char*> pathsCStr;
    
    paths = QCoreApplication::libraryPaths();
    
    // クリア
    pathsUtf8.clear();
    pathsCStr.clear();
    
    // 変換
    for (const QString& path : paths) {
        pathsUtf8.append(path.toUtf8());
        pathsCStr.append(pathsUtf8.last().constData());
    }
    
    if (count) {
        *count = pathsCStr.size();
    }
    
    return pathsCStr.isEmpty() ? nullptr : pathsCStr.data();
}

void QCoreApplicationBind::setLibraryPaths(const char** paths, int count) {
    if (paths && count > 0) {
        QStringList pathsList;
        for (int i = 0; i < count; ++i) {
            if (paths[i]) {
                pathsList.append(QString::fromUtf8(paths[i]));
            }
        }
        QCoreApplication::setLibraryPaths(pathsList);
    }
}

bool QCoreApplicationBind::installTranslator(QTranslator* translator) {
    if (translator) {
        return QCoreApplication::installTranslator(translator);
    }
    return false;
}

bool QCoreApplicationBind::removeTranslator(QTranslator* translator) {
    if (translator) {
        return QCoreApplication::removeTranslator(translator);
    }
    return false;
}

const char* QCoreApplicationBind::translate(const char* context, const char* sourceText, const char* disambiguation, int n) {
    if (context && sourceText) {
        static QString translation;
        translation = QCoreApplication::translate(context, sourceText, disambiguation, n);
        return translation.toUtf8().constData();
    }
    return nullptr;
}

void QCoreApplicationBind::setAttribute(int attribute, bool on) {
    QCoreApplication::setAttribute(static_cast<Qt::ApplicationAttribute>(attribute), on);
}

bool QCoreApplicationBind::testAttribute(int attribute) {
    return QCoreApplication::testAttribute(static_cast<Qt::ApplicationAttribute>(attribute));
}

void QCoreApplicationBind::exit(int returnCode) {
    QCoreApplication::exit(returnCode);
}

void QCoreApplicationBind::quit() {
    QCoreApplication::quit();
}

int QCoreApplicationBind::exec() {
    return QCoreApplication::exec();
}

bool QCoreApplicationBind::isSetuidAllowed() {
    return QCoreApplication::isSetuidAllowed();
}

void QCoreApplicationBind::setSetuidAllowed(bool allow) {
    QCoreApplication::setSetuidAllowed(allow);
}
