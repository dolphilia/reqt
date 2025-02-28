#include "qdir.h"
#include "QDirBind.h"
#include <QDir>

extern "C" {

void* QDir_create() {
    return QDirBind::create();
}

void* QDir_createWithPath(const char* path) {
    return QDirBind::createWithPath(path);
}

void* QDir_createWithFilters(const char* path, const char* nameFilter, int sort, int filters) {
    return QDirBind::createWithFilters(path, nameFilter, static_cast<QDir::SortFlags>(sort), static_cast<QDir::Filters>(filters));
}

void* QDir_copy(void* dir) {
    return QDirBind::copy(static_cast<QDir*>(dir));
}

void QDir_delete(void* dir) {
    QDirBind::destroy(static_cast<QDir*>(dir));
}

const char* QDir_absoluteFilePath(void* dir, const char* fileName) {
    return QDirBind::absoluteFilePath(static_cast<QDir*>(dir), fileName);
}

const char* QDir_absolutePath(void* dir) {
    return QDirBind::absolutePath(static_cast<QDir*>(dir));
}

const char* QDir_canonicalPath(void* dir) {
    return QDirBind::canonicalPath(static_cast<QDir*>(dir));
}

bool QDir_cd(void* dir, const char* dirName) {
    return QDirBind::cd(static_cast<QDir*>(dir), dirName);
}

bool QDir_cdUp(void* dir) {
    return QDirBind::cdUp(static_cast<QDir*>(dir));
}

int64_t QDir_count(void* dir) {
    return QDirBind::count(static_cast<QDir*>(dir));
}

const char* QDir_dirName(void* dir) {
    return QDirBind::dirName(static_cast<QDir*>(dir));
}

void** QDir_entryInfoList(void* dir, const char** nameFilters, int nameFilterCount, int filters, int sort, int* count) {
    return reinterpret_cast<void**>(QDirBind::entryInfoList(
        static_cast<QDir*>(dir),
        nameFilters,
        nameFilterCount,
        static_cast<QDir::Filters>(filters),
        static_cast<QDir::SortFlags>(sort),
        count
    ));
}

void** QDir_entryInfoListWithFilters(void* dir, int filters, int sort, int* count) {
    return reinterpret_cast<void**>(QDirBind::entryInfoListWithFilters(
        static_cast<QDir*>(dir),
        static_cast<QDir::Filters>(filters),
        static_cast<QDir::SortFlags>(sort),
        count
    ));
}

const char** QDir_entryList(void* dir, const char** nameFilters, int nameFilterCount, int filters, int sort, int* count) {
    return QDirBind::entryList(
        static_cast<QDir*>(dir),
        nameFilters,
        nameFilterCount,
        static_cast<QDir::Filters>(filters),
        static_cast<QDir::SortFlags>(sort),
        count
    );
}

const char** QDir_entryListWithFilters(void* dir, int filters, int sort, int* count) {
    return QDirBind::entryListWithFilters(
        static_cast<QDir*>(dir),
        static_cast<QDir::Filters>(filters),
        static_cast<QDir::SortFlags>(sort),
        count
    );
}

bool QDir_exists(void* dir, const char* name) {
    return QDirBind::exists(static_cast<QDir*>(dir), name);
}

bool QDir_existsDir(void* dir) {
    return QDirBind::existsDir(static_cast<QDir*>(dir));
}

const char* QDir_filePath(void* dir, const char* fileName) {
    return QDirBind::filePath(static_cast<QDir*>(dir), fileName);
}

int QDir_filter(void* dir) {
    return static_cast<int>(QDirBind::filter(static_cast<QDir*>(dir)));
}

bool QDir_isAbsolute(void* dir) {
    return QDirBind::isAbsolute(static_cast<QDir*>(dir));
}

bool QDir_isEmpty(void* dir, int filters) {
    return QDirBind::isEmpty(static_cast<QDir*>(dir), static_cast<QDir::Filters>(filters));
}

bool QDir_isReadable(void* dir) {
    return QDirBind::isReadable(static_cast<QDir*>(dir));
}

bool QDir_isRelative(void* dir) {
    return QDirBind::isRelative(static_cast<QDir*>(dir));
}

bool QDir_isRoot(void* dir) {
    return QDirBind::isRoot(static_cast<QDir*>(dir));
}

bool QDir_makeAbsolute(void* dir) {
    return QDirBind::makeAbsolute(static_cast<QDir*>(dir));
}

bool QDir_mkdir(void* dir, const char* dirName) {
    return QDirBind::mkdir(static_cast<QDir*>(dir), dirName);
}

bool QDir_mkdirWithPermissions(void* dir, const char* dirName, int permissions) {
    return QDirBind::mkdirWithPermissions(static_cast<QDir*>(dir), dirName, static_cast<QFileDevice::Permissions>(permissions));
}

bool QDir_mkpath(void* dir, const char* dirPath) {
    return QDirBind::mkpath(static_cast<QDir*>(dir), dirPath);
}

const char** QDir_nameFilters(void* dir, int* count) {
    return QDirBind::nameFilters(static_cast<QDir*>(dir), count);
}

const char* QDir_path(void* dir) {
    return QDirBind::path(static_cast<QDir*>(dir));
}

void QDir_refresh(void* dir) {
    QDirBind::refresh(static_cast<QDir*>(dir));
}

const char* QDir_relativeFilePath(void* dir, const char* fileName) {
    return QDirBind::relativeFilePath(static_cast<QDir*>(dir), fileName);
}

bool QDir_remove(void* dir, const char* fileName) {
    return QDirBind::remove(static_cast<QDir*>(dir), fileName);
}

bool QDir_removeRecursively(void* dir) {
    return QDirBind::removeRecursively(static_cast<QDir*>(dir));
}

bool QDir_rename(void* dir, const char* oldName, const char* newName) {
    return QDirBind::rename(static_cast<QDir*>(dir), oldName, newName);
}

bool QDir_rmdir(void* dir, const char* dirName) {
    return QDirBind::rmdir(static_cast<QDir*>(dir), dirName);
}

bool QDir_rmpath(void* dir, const char* dirPath) {
    return QDirBind::rmpath(static_cast<QDir*>(dir), dirPath);
}

void QDir_setFilter(void* dir, int filters) {
    QDirBind::setFilter(static_cast<QDir*>(dir), static_cast<QDir::Filters>(filters));
}

void QDir_setNameFilters(void* dir, const char** nameFilters, int count) {
    QDirBind::setNameFilters(static_cast<QDir*>(dir), nameFilters, count);
}

void QDir_setPath(void* dir, const char* path) {
    QDirBind::setPath(static_cast<QDir*>(dir), path);
}

void QDir_setSorting(void* dir, int sort) {
    QDirBind::setSorting(static_cast<QDir*>(dir), static_cast<QDir::SortFlags>(sort));
}

int QDir_sorting(void* dir) {
    return static_cast<int>(QDirBind::sorting(static_cast<QDir*>(dir)));
}

void QDir_swap(void* dir, void* other) {
    QDirBind::swap(static_cast<QDir*>(dir), static_cast<QDir*>(other));
}

// Static functions
void QDir_addSearchPath(const char* prefix, const char* path) {
    QDirBind::addSearchPath(prefix, path);
}

const char* QDir_cleanPath(const char* path) {
    return QDirBind::cleanPath(path);
}

void* QDir_current() {
    return QDirBind::current();
}

const char* QDir_currentPath() {
    return QDirBind::currentPath();
}

void** QDir_drives(int* count) {
    return reinterpret_cast<void**>(QDirBind::drives(count));
}

const char* QDir_fromNativeSeparators(const char* pathName) {
    return QDirBind::fromNativeSeparators(pathName);
}

void* QDir_home() {
    return QDirBind::home();
}

const char* QDir_homePath() {
    return QDirBind::homePath();
}

bool QDir_isAbsolutePath(const char* path) {
    return QDirBind::isAbsolutePath(path);
}

bool QDir_isRelativePath(const char* path) {
    return QDirBind::isRelativePath(path);
}

char QDir_listSeparator() {
    return QDirBind::listSeparator();
}

bool QDir_match(const char* filter, const char* fileName) {
    return QDirBind::match(filter, fileName);
}

bool QDir_matchList(const char** filters, int count, const char* fileName) {
    return QDirBind::matchList(filters, count, fileName);
}

void* QDir_root() {
    return QDirBind::root();
}

const char* QDir_rootPath() {
    return QDirBind::rootPath();
}

const char** QDir_searchPaths(const char* prefix, int* count) {
    return QDirBind::searchPaths(prefix, count);
}

char QDir_separator() {
    return QDirBind::separator();
}

bool QDir_setCurrent(const char* path) {
    return QDirBind::setCurrent(path);
}

void QDir_setSearchPaths(const char* prefix, const char** searchPaths, int count) {
    QDirBind::setSearchPaths(prefix, searchPaths, count);
}

void* QDir_temp() {
    return QDirBind::temp();
}

const char* QDir_tempPath() {
    return QDirBind::tempPath();
}

const char* QDir_toNativeSeparators(const char* pathName) {
    return QDirBind::toNativeSeparators(pathName);
}

}
