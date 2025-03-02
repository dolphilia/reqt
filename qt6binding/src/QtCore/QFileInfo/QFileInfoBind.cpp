#include "QFileInfoBind.h"
#include <QString>

QFileInfo* QFileInfoBind::create() {
    return new QFileInfo();
}

QFileInfo* QFileInfoBind::createWithPath(const char* path) {
    return new QFileInfo(QString::fromUtf8(path));
}

QFileInfo* QFileInfoBind::createWithDir(const QDir* dir, const char* path) {
    return new QFileInfo(*dir, QString::fromUtf8(path));
}

QFileInfo* QFileInfoBind::createWithFileDevice(QFileDevice* file) {
    return new QFileInfo(*file);
}

QFileInfo* QFileInfoBind::copy(const QFileInfo* fileinfo) {
    return new QFileInfo(*fileinfo);
}

void QFileInfoBind::destroy(QFileInfo* fileinfo) {
    delete fileinfo;
}

QDir* QFileInfoBind::absoluteDir(QFileInfo* fileinfo) {
    if (fileinfo) {
        return new QDir(fileinfo->absoluteDir());
    }
    return nullptr;
}

const char* QFileInfoBind::absoluteFilePath(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->absoluteFilePath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QFileInfoBind::absolutePath(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->absolutePath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QFileInfoBind::baseName(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->baseName();
        return str.toUtf8().constData();
    }
    return nullptr;
}

qint64 QFileInfoBind::birthTime(QFileInfo* fileinfo) {
    if (fileinfo) {
        return fileinfo->birthTime().toSecsSinceEpoch();
    }
    return 0;
}

const char* QFileInfoBind::bundleName(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->bundleName();
        return str.toUtf8().constData();
    }
    return nullptr;
}

bool QFileInfoBind::caching(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->caching() : false;
}

const char* QFileInfoBind::canonicalFilePath(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->canonicalFilePath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QFileInfoBind::canonicalPath(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->canonicalPath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QFileInfoBind::completeBaseName(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->completeBaseName();
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QFileInfoBind::completeSuffix(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->completeSuffix();
        return str.toUtf8().constData();
    }
    return nullptr;
}

QDir* QFileInfoBind::dir(QFileInfo* fileinfo) {
    if (fileinfo) {
        return new QDir(fileinfo->dir());
    }
    return nullptr;
}

bool QFileInfoBind::exists(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->exists() : false;
}

const char* QFileInfoBind::fileName(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->fileName();
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QFileInfoBind::filePath(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->filePath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

qint64 QFileInfoBind::fileTime(QFileInfo* fileinfo, QFileDevice::FileTime time) {
    if (fileinfo) {
        return fileinfo->fileTime(time).toSecsSinceEpoch();
    }
    return 0;
}

const char* QFileInfoBind::group(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->group();
        return str.toUtf8().constData();
    }
    return nullptr;
}

uint QFileInfoBind::groupId(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->groupId() : 0;
}

bool QFileInfoBind::isAbsolute(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isAbsolute() : false;
}

bool QFileInfoBind::isAlias(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isAlias() : false;
}

bool QFileInfoBind::isBundle(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isBundle() : false;
}

bool QFileInfoBind::isDir(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isDir() : false;
}

bool QFileInfoBind::isExecutable(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isExecutable() : false;
}

bool QFileInfoBind::isFile(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isFile() : false;
}

bool QFileInfoBind::isHidden(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isHidden() : false;
}

bool QFileInfoBind::isJunction(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isJunction() : false;
}

bool QFileInfoBind::isNativePath(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isNativePath() : false;
}

bool QFileInfoBind::isReadable(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isReadable() : false;
}

bool QFileInfoBind::isRelative(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isRelative() : false;
}

bool QFileInfoBind::isRoot(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isRoot() : false;
}

bool QFileInfoBind::isShortcut(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isShortcut() : false;
}

bool QFileInfoBind::isSymLink(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isSymLink() : false;
}

bool QFileInfoBind::isSymbolicLink(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isSymbolicLink() : false;
}

bool QFileInfoBind::isWritable(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->isWritable() : false;
}

const char* QFileInfoBind::junctionTarget(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->junctionTarget();
        return str.toUtf8().constData();
    }
    return nullptr;
}

qint64 QFileInfoBind::lastModified(QFileInfo* fileinfo) {
    if (fileinfo) {
        return fileinfo->lastModified().toSecsSinceEpoch();
    }
    return 0;
}

qint64 QFileInfoBind::lastRead(QFileInfo* fileinfo) {
    if (fileinfo) {
        return fileinfo->lastRead().toSecsSinceEpoch();
    }
    return 0;
}

bool QFileInfoBind::makeAbsolute(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->makeAbsolute() : false;
}

qint64 QFileInfoBind::metadataChangeTime(QFileInfo* fileinfo) {
    if (fileinfo) {
        return fileinfo->metadataChangeTime().toSecsSinceEpoch();
    }
    return 0;
}

const char* QFileInfoBind::owner(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->owner();
        return str.toUtf8().constData();
    }
    return nullptr;
}

uint QFileInfoBind::ownerId(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->ownerId() : 0;
}

const char* QFileInfoBind::path(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->path();
        return str.toUtf8().constData();
    }
    return nullptr;
}

bool QFileInfoBind::permission(QFileInfo* fileinfo, QFileDevice::Permissions permissions) {
    return fileinfo ? fileinfo->permission(permissions) : false;
}

QFileDevice::Permissions QFileInfoBind::permissions(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->permissions() : QFileDevice::Permissions();
}

const char* QFileInfoBind::readSymLink(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->readSymLink();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QFileInfoBind::refresh(QFileInfo* fileinfo) {
    if (fileinfo) {
        fileinfo->refresh();
    }
}

void QFileInfoBind::setCaching(QFileInfo* fileinfo, bool enable) {
    if (fileinfo) {
        fileinfo->setCaching(enable);
    }
}

void QFileInfoBind::setFile(QFileInfo* fileinfo, const char* path) {
    if (fileinfo && path) {
        fileinfo->setFile(QString::fromUtf8(path));
    }
}

void QFileInfoBind::setFileWithDir(QFileInfo* fileinfo, const QDir* dir, const char* path) {
    if (fileinfo && dir && path) {
        fileinfo->setFile(*dir, QString::fromUtf8(path));
    }
}

void QFileInfoBind::setFileWithDevice(QFileInfo* fileinfo, QFileDevice* file) {
    if (fileinfo && file) {
        fileinfo->setFile(*file);
    }
}

qint64 QFileInfoBind::size(QFileInfo* fileinfo) {
    return fileinfo ? fileinfo->size() : 0;
}

void QFileInfoBind::stat(QFileInfo* fileinfo) {
    if (fileinfo) {
        fileinfo->stat();
    }
}

const char* QFileInfoBind::suffix(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->suffix();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QFileInfoBind::swap(QFileInfo* fileinfo, QFileInfo* other) {
    if (fileinfo && other) {
        fileinfo->swap(*other);
    }
}

const char* QFileInfoBind::symLinkTarget(QFileInfo* fileinfo) {
    if (fileinfo) {
        static QString str;
        str = fileinfo->symLinkTarget();
        return str.toUtf8().constData();
    }
    return nullptr;
}

bool QFileInfoBind::existsPath(const char* path) {
    return path ? QFileInfo::exists(QString::fromUtf8(path)) : false;
}
