#ifndef QDIR_BIND_H
#define QDIR_BIND_H

#include <QDir>
#include <QString>
#include <QStringList>
#include <QFileInfo>

class QDirBind {
public:
    // Creation and destruction
    static QDir* create();
    static QDir* createWithPath(const char* path);
    static QDir* createWithFilters(const char* path, const char* nameFilter, QDir::SortFlags sort, QDir::Filters filters);
    static QDir* copy(const QDir* dir);
    static void destroy(QDir* dir);

    // Path operations
    static const char* absoluteFilePath(QDir* dir, const char* fileName);
    static const char* absolutePath(QDir* dir);
    static const char* canonicalPath(QDir* dir);
    static bool cd(QDir* dir, const char* dirName);
    static bool cdUp(QDir* dir);
    static qint64 count(QDir* dir);
    static const char* dirName(QDir* dir);
    static QFileInfo** entryInfoList(QDir* dir, const char** nameFilters, int nameFilterCount, QDir::Filters filters, QDir::SortFlags sort, int* count);
    static QFileInfo** entryInfoListWithFilters(QDir* dir, QDir::Filters filters, QDir::SortFlags sort, int* count);
    static const char** entryList(QDir* dir, const char** nameFilters, int nameFilterCount, QDir::Filters filters, QDir::SortFlags sort, int* count);
    static const char** entryListWithFilters(QDir* dir, QDir::Filters filters, QDir::SortFlags sort, int* count);

    // File and directory operations
    static bool exists(QDir* dir, const char* name);
    static bool existsDir(QDir* dir);
    static const char* filePath(QDir* dir, const char* fileName);
    static QDir::Filters filter(QDir* dir);
    static bool isAbsolute(QDir* dir);
    static bool isEmpty(QDir* dir, QDir::Filters filters);
    static bool isReadable(QDir* dir);
    static bool isRelative(QDir* dir);
    static bool isRoot(QDir* dir);
    static bool makeAbsolute(QDir* dir);
    static bool mkdir(QDir* dir, const char* dirName);
    static bool mkdirWithPermissions(QDir* dir, const char* dirName, QFileDevice::Permissions permissions);
    static bool mkpath(QDir* dir, const char* dirPath);
    static const char** nameFilters(QDir* dir, int* count);
    static const char* path(QDir* dir);
    static void refresh(QDir* dir);
    static const char* relativeFilePath(QDir* dir, const char* fileName);
    static bool remove(QDir* dir, const char* fileName);
    static bool removeRecursively(QDir* dir);
    static bool rename(QDir* dir, const char* oldName, const char* newName);
    static bool rmdir(QDir* dir, const char* dirName);
    static bool rmpath(QDir* dir, const char* dirPath);
    static void setFilter(QDir* dir, QDir::Filters filters);
    static void setNameFilters(QDir* dir, const char** nameFilters, int count);
    static void setPath(QDir* dir, const char* path);
    static void setSorting(QDir* dir, QDir::SortFlags sort);
    static QDir::SortFlags sorting(QDir* dir);
    static void swap(QDir* dir, QDir* other);

    // Static functions
    static void addSearchPath(const char* prefix, const char* path);
    static const char* cleanPath(const char* path);
    static QDir* current();
    static const char* currentPath();
    static QFileInfo** drives(int* count);
    static const char* fromNativeSeparators(const char* pathName);
    static QDir* home();
    static const char* homePath();
    static bool isAbsolutePath(const char* path);
    static bool isRelativePath(const char* path);
    static char listSeparator();
    static bool match(const char* filter, const char* fileName);
    static bool matchList(const char** filters, int count, const char* fileName);
    static QDir* root();
    static const char* rootPath();
    static const char** searchPaths(const char* prefix, int* count);
    static char separator();
    static bool setCurrent(const char* path);
    static void setSearchPaths(const char* prefix, const char** searchPaths, int count);
    static QDir* temp();
    static const char* tempPath();
    static const char* toNativeSeparators(const char* pathName);
};

#endif // QDIR_BIND_H
