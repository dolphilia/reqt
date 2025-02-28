#include "QDirBind.h"
#include <QStringList>

QDir* QDirBind::create() {
    return new QDir();
}

QDir* QDirBind::createWithPath(const char* path) {
    return new QDir(QString::fromUtf8(path));
}

QDir* QDirBind::createWithFilters(const char* path, const char* nameFilter, QDir::SortFlags sort, QDir::Filters filters) {
    return new QDir(QString::fromUtf8(path), QString::fromUtf8(nameFilter), sort, filters);
}

QDir* QDirBind::copy(const QDir* dir) {
    return new QDir(*dir);
}

void QDirBind::destroy(QDir* dir) {
    delete dir;
}

const char* QDirBind::absoluteFilePath(QDir* dir, const char* fileName) {
    if (dir && fileName) {
        static QString str;
        str = dir->absoluteFilePath(QString::fromUtf8(fileName));
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QDirBind::absolutePath(QDir* dir) {
    if (dir) {
        static QString str;
        str = dir->absolutePath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QDirBind::canonicalPath(QDir* dir) {
    if (dir) {
        static QString str;
        str = dir->canonicalPath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

bool QDirBind::cd(QDir* dir, const char* dirName) {
    return dir && dirName ? dir->cd(QString::fromUtf8(dirName)) : false;
}

bool QDirBind::cdUp(QDir* dir) {
    return dir ? dir->cdUp() : false;
}

qint64 QDirBind::count(QDir* dir) {
    return dir ? dir->count() : 0;
}

const char* QDirBind::dirName(QDir* dir) {
    if (dir) {
        static QString str;
        str = dir->dirName();
        return str.toUtf8().constData();
    }
    return nullptr;
}

QFileInfo** QDirBind::entryInfoList(QDir* dir, const char** nameFilters, int nameFilterCount, QDir::Filters filters, QDir::SortFlags sort, int* count) {
    if (dir && nameFilters && nameFilterCount > 0) {
        QStringList filterList;
        for (int i = 0; i < nameFilterCount; i++) {
            if (nameFilters[i]) {
                filterList << QString::fromUtf8(nameFilters[i]);
            }
        }
        QFileInfoList list = dir->entryInfoList(filterList, filters, sort);
        *count = list.size();
        if (*count > 0) {
            QFileInfo** result = new QFileInfo*[*count];
            for (int i = 0; i < *count; i++) {
                result[i] = new QFileInfo(list[i]);
            }
            return result;
        }
    }
    *count = 0;
    return nullptr;
}

QFileInfo** QDirBind::entryInfoListWithFilters(QDir* dir, QDir::Filters filters, QDir::SortFlags sort, int* count) {
    if (dir) {
        QFileInfoList list = dir->entryInfoList(filters, sort);
        *count = list.size();
        if (*count > 0) {
            QFileInfo** result = new QFileInfo*[*count];
            for (int i = 0; i < *count; i++) {
                result[i] = new QFileInfo(list[i]);
            }
            return result;
        }
    }
    *count = 0;
    return nullptr;
}

const char** QDirBind::entryList(QDir* dir, const char** nameFilters, int nameFilterCount, QDir::Filters filters, QDir::SortFlags sort, int* count) {
    if (dir && nameFilters && nameFilterCount > 0) {
        QStringList filterList;
        for (int i = 0; i < nameFilterCount; i++) {
            if (nameFilters[i]) {
                filterList << QString::fromUtf8(nameFilters[i]);
            }
        }
        QStringList list = dir->entryList(filterList, filters, sort);
        *count = list.size();
        if (*count > 0) {
            const char** result = new const char*[*count];
            for (int i = 0; i < *count; i++) {
                result[i] = qstrdup(list[i].toUtf8().constData());
            }
            return result;
        }
    }
    *count = 0;
    return nullptr;
}

const char** QDirBind::entryListWithFilters(QDir* dir, QDir::Filters filters, QDir::SortFlags sort, int* count) {
    if (dir) {
        QStringList list = dir->entryList(filters, sort);
        *count = list.size();
        if (*count > 0) {
            const char** result = new const char*[*count];
            for (int i = 0; i < *count; i++) {
                result[i] = qstrdup(list[i].toUtf8().constData());
            }
            return result;
        }
    }
    *count = 0;
    return nullptr;
}

bool QDirBind::exists(QDir* dir, const char* name) {
    return dir && name ? dir->exists(QString::fromUtf8(name)) : false;
}

bool QDirBind::existsDir(QDir* dir) {
    return dir ? dir->exists() : false;
}

const char* QDirBind::filePath(QDir* dir, const char* fileName) {
    if (dir && fileName) {
        static QString str;
        str = dir->filePath(QString::fromUtf8(fileName));
        return str.toUtf8().constData();
    }
    return nullptr;
}

QDir::Filters QDirBind::filter(QDir* dir) {
    return dir ? dir->filter() : QDir::NoFilter;
}

bool QDirBind::isAbsolute(QDir* dir) {
    return dir ? dir->isAbsolute() : false;
}

bool QDirBind::isEmpty(QDir* dir, QDir::Filters filters) {
    return dir ? dir->isEmpty(filters) : true;
}

bool QDirBind::isReadable(QDir* dir) {
    return dir ? dir->isReadable() : false;
}

bool QDirBind::isRelative(QDir* dir) {
    return dir ? dir->isRelative() : false;
}

bool QDirBind::isRoot(QDir* dir) {
    return dir ? dir->isRoot() : false;
}

bool QDirBind::makeAbsolute(QDir* dir) {
    return dir ? dir->makeAbsolute() : false;
}

bool QDirBind::mkdir(QDir* dir, const char* dirName) {
    return dir && dirName ? dir->mkdir(QString::fromUtf8(dirName)) : false;
}

bool QDirBind::mkdirWithPermissions(QDir* dir, const char* dirName, QFileDevice::Permissions permissions) {
    return dir && dirName ? dir->mkdir(QString::fromUtf8(dirName), permissions) : false;
}

bool QDirBind::mkpath(QDir* dir, const char* dirPath) {
    return dir && dirPath ? dir->mkpath(QString::fromUtf8(dirPath)) : false;
}

const char** QDirBind::nameFilters(QDir* dir, int* count) {
    if (dir) {
        QStringList filters = dir->nameFilters();
        *count = filters.size();
        if (*count > 0) {
            const char** result = new const char*[*count];
            for (int i = 0; i < *count; i++) {
                result[i] = qstrdup(filters[i].toUtf8().constData());
            }
            return result;
        }
    }
    *count = 0;
    return nullptr;
}

const char* QDirBind::path(QDir* dir) {
    if (dir) {
        static QString str;
        str = dir->path();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QDirBind::refresh(QDir* dir) {
    if (dir) {
        dir->refresh();
    }
}

const char* QDirBind::relativeFilePath(QDir* dir, const char* fileName) {
    if (dir && fileName) {
        static QString str;
        str = dir->relativeFilePath(QString::fromUtf8(fileName));
        return str.toUtf8().constData();
    }
    return nullptr;
}

bool QDirBind::remove(QDir* dir, const char* fileName) {
    return dir && fileName ? dir->remove(QString::fromUtf8(fileName)) : false;
}

bool QDirBind::removeRecursively(QDir* dir) {
    return dir ? dir->removeRecursively() : false;
}

bool QDirBind::rename(QDir* dir, const char* oldName, const char* newName) {
    return dir && oldName && newName ? dir->rename(QString::fromUtf8(oldName), QString::fromUtf8(newName)) : false;
}

bool QDirBind::rmdir(QDir* dir, const char* dirName) {
    return dir && dirName ? dir->rmdir(QString::fromUtf8(dirName)) : false;
}

bool QDirBind::rmpath(QDir* dir, const char* dirPath) {
    return dir && dirPath ? dir->rmpath(QString::fromUtf8(dirPath)) : false;
}

void QDirBind::setFilter(QDir* dir, QDir::Filters filters) {
    if (dir) {
        dir->setFilter(filters);
    }
}

void QDirBind::setNameFilters(QDir* dir, const char** nameFilters, int count) {
    if (dir && nameFilters && count > 0) {
        QStringList filterList;
        for (int i = 0; i < count; i++) {
            if (nameFilters[i]) {
                filterList << QString::fromUtf8(nameFilters[i]);
            }
        }
        dir->setNameFilters(filterList);
    }
}

void QDirBind::setPath(QDir* dir, const char* path) {
    if (dir && path) {
        dir->setPath(QString::fromUtf8(path));
    }
}

void QDirBind::setSorting(QDir* dir, QDir::SortFlags sort) {
    if (dir) {
        dir->setSorting(sort);
    }
}

QDir::SortFlags QDirBind::sorting(QDir* dir) {
    return dir ? dir->sorting() : QDir::NoSort;
}

void QDirBind::swap(QDir* dir, QDir* other) {
    if (dir && other) {
        dir->swap(*other);
    }
}

// Static functions
void QDirBind::addSearchPath(const char* prefix, const char* path) {
    if (prefix && path) {
        QDir::addSearchPath(QString::fromUtf8(prefix), QString::fromUtf8(path));
    }
}

const char* QDirBind::cleanPath(const char* path) {
    if (path) {
        static QString str;
        str = QDir::cleanPath(QString::fromUtf8(path));
        return str.toUtf8().constData();
    }
    return nullptr;
}

QDir* QDirBind::current() {
    return new QDir(QDir::current());
}

const char* QDirBind::currentPath() {
    static QString str;
    str = QDir::currentPath();
    return str.toUtf8().constData();
}

QFileInfo** QDirBind::drives(int* count) {
    QFileInfoList list = QDir::drives();
    *count = list.size();
    if (*count > 0) {
        QFileInfo** result = new QFileInfo*[*count];
        for (int i = 0; i < *count; i++) {
            result[i] = new QFileInfo(list[i]);
        }
        return result;
    }
    return nullptr;
}

const char* QDirBind::fromNativeSeparators(const char* pathName) {
    if (pathName) {
        static QString str;
        str = QDir::fromNativeSeparators(QString::fromUtf8(pathName));
        return str.toUtf8().constData();
    }
    return nullptr;
}

QDir* QDirBind::home() {
    return new QDir(QDir::home());
}

const char* QDirBind::homePath() {
    static QString str;
    str = QDir::homePath();
    return str.toUtf8().constData();
}

bool QDirBind::isAbsolutePath(const char* path) {
    return path ? QDir::isAbsolutePath(QString::fromUtf8(path)) : false;
}

bool QDirBind::isRelativePath(const char* path) {
    return path ? QDir::isRelativePath(QString::fromUtf8(path)) : false;
}

char QDirBind::listSeparator() {
    return QDir::listSeparator().toLatin1();
}

bool QDirBind::match(const char* filter, const char* fileName) {
    return filter && fileName ? QDir::match(QString::fromUtf8(filter), QString::fromUtf8(fileName)) : false;
}

bool QDirBind::matchList(const char** filters, int count, const char* fileName) {
    if (filters && count > 0 && fileName) {
        QStringList filterList;
        for (int i = 0; i < count; i++) {
            if (filters[i]) {
                filterList << QString::fromUtf8(filters[i]);
            }
        }
        return QDir::match(filterList, QString::fromUtf8(fileName));
    }
    return false;
}

QDir* QDirBind::root() {
    return new QDir(QDir::root());
}

const char* QDirBind::rootPath() {
    static QString str;
    str = QDir::rootPath();
    return str.toUtf8().constData();
}

const char** QDirBind::searchPaths(const char* prefix, int* count) {
    if (prefix) {
        QStringList paths = QDir::searchPaths(QString::fromUtf8(prefix));
        *count = paths.size();
        if (*count > 0) {
            const char** result = new const char*[*count];
            for (int i = 0; i < *count; i++) {
                result[i] = qstrdup(paths[i].toUtf8().constData());
            }
            return result;
        }
    }
    *count = 0;
    return nullptr;
}

char QDirBind::separator() {
    return QDir::separator().toLatin1();
}

bool QDirBind::setCurrent(const char* path) {
    return path ? QDir::setCurrent(QString::fromUtf8(path)) : false;
}

void QDirBind::setSearchPaths(const char* prefix, const char** searchPaths, int count) {
    if (prefix && searchPaths && count > 0) {
        QStringList pathList;
        for (int i = 0; i < count; i++) {
            if (searchPaths[i]) {
                pathList << QString::fromUtf8(searchPaths[i]);
            }
        }
        QDir::setSearchPaths(QString::fromUtf8(prefix), pathList);
    }
}

QDir* QDirBind::temp() {
    return new QDir(QDir::temp());
}

const char* QDirBind::tempPath() {
    static QString str;
    str = QDir::tempPath();
    return str.toUtf8().constData();
}

const char* QDirBind::toNativeSeparators(const char* pathName) {
    if (pathName) {
        static QString str;
        str = QDir::toNativeSeparators(QString::fromUtf8(pathName));
        return str.toUtf8().constData();
    }
    return nullptr;
}
