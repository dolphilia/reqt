#ifndef QDIR_C_H
#define QDIR_C_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Filter flags
#define QDIR_FILTER_DIRS              0x001
#define QDIR_FILTER_ALL_DIRS          0x002
#define QDIR_FILTER_FILES             0x004
#define QDIR_FILTER_DRIVES            0x008
#define QDIR_FILTER_NO_SYMLINKS       0x010
#define QDIR_FILTER_NO_FILTER         0x000
#define QDIR_FILTER_ALL_ENTRIES       0x007
#define QDIR_FILTER_READABLE          0x020
#define QDIR_FILTER_WRITABLE          0x040
#define QDIR_FILTER_EXECUTABLE        0x080
#define QDIR_FILTER_MODIFIED          0x100
#define QDIR_FILTER_HIDDEN            0x200
#define QDIR_FILTER_SYSTEM            0x400
#define QDIR_FILTER_CASE_SENSITIVE    0x800

// Sort flags
#define QDIR_SORT_NAME               0x00
#define QDIR_SORT_TIME               0x01
#define QDIR_SORT_SIZE               0x02
#define QDIR_SORT_TYPE               0x03
#define QDIR_SORT_UNSORTED           0x04
#define QDIR_SORT_IGNORE_CASE        0x08
#define QDIR_SORT_DIR_FIRST          0x10
#define QDIR_SORT_DIR_LAST           0x20
#define QDIR_SORT_LOCALE_AWARE       0x40
#define QDIR_SORT_NO_SORT            0x80

// Creation and destruction
void* QDir_create();
void* QDir_createWithPath(const char* path);
void* QDir_createWithFilters(const char* path, const char* nameFilter, int sort, int filters);
void* QDir_copy(void* dir);
void QDir_delete(void* dir);

// Path operations
const char* QDir_absoluteFilePath(void* dir, const char* fileName);
const char* QDir_absolutePath(void* dir);
const char* QDir_canonicalPath(void* dir);
bool QDir_cd(void* dir, const char* dirName);
bool QDir_cdUp(void* dir);
int64_t QDir_count(void* dir);
const char* QDir_dirName(void* dir);
void** QDir_entryInfoList(void* dir, const char** nameFilters, int nameFilterCount, int filters, int sort, int* count);
void** QDir_entryInfoListWithFilters(void* dir, int filters, int sort, int* count);
const char** QDir_entryList(void* dir, const char** nameFilters, int nameFilterCount, int filters, int sort, int* count);
const char** QDir_entryListWithFilters(void* dir, int filters, int sort, int* count);

// File and directory operations
bool QDir_exists(void* dir, const char* name);
bool QDir_existsDir(void* dir);
const char* QDir_filePath(void* dir, const char* fileName);
int QDir_filter(void* dir);
bool QDir_isAbsolute(void* dir);
bool QDir_isEmpty(void* dir, int filters);
bool QDir_isReadable(void* dir);
bool QDir_isRelative(void* dir);
bool QDir_isRoot(void* dir);
bool QDir_makeAbsolute(void* dir);
bool QDir_mkdir(void* dir, const char* dirName);
bool QDir_mkdirWithPermissions(void* dir, const char* dirName, int permissions);
bool QDir_mkpath(void* dir, const char* dirPath);
const char** QDir_nameFilters(void* dir, int* count);
const char* QDir_path(void* dir);
void QDir_refresh(void* dir);
const char* QDir_relativeFilePath(void* dir, const char* fileName);
bool QDir_remove(void* dir, const char* fileName);
bool QDir_removeRecursively(void* dir);
bool QDir_rename(void* dir, const char* oldName, const char* newName);
bool QDir_rmdir(void* dir, const char* dirName);
bool QDir_rmpath(void* dir, const char* dirPath);
void QDir_setFilter(void* dir, int filters);
void QDir_setNameFilters(void* dir, const char** nameFilters, int count);
void QDir_setPath(void* dir, const char* path);
void QDir_setSorting(void* dir, int sort);
int QDir_sorting(void* dir);
void QDir_swap(void* dir, void* other);

// Static functions
void QDir_addSearchPath(const char* prefix, const char* path);
const char* QDir_cleanPath(const char* path);
void* QDir_current();
const char* QDir_currentPath();
void** QDir_drives(int* count);
const char* QDir_fromNativeSeparators(const char* pathName);
void* QDir_home();
const char* QDir_homePath();
bool QDir_isAbsolutePath(const char* path);
bool QDir_isRelativePath(const char* path);
char QDir_listSeparator();
bool QDir_match(const char* filter, const char* fileName);
bool QDir_matchList(const char** filters, int count, const char* fileName);
void* QDir_root();
const char* QDir_rootPath();
const char** QDir_searchPaths(const char* prefix, int* count);
char QDir_separator();
bool QDir_setCurrent(const char* path);
void QDir_setSearchPaths(const char* prefix, const char** searchPaths, int count);
void* QDir_temp();
const char* QDir_tempPath();
const char* QDir_toNativeSeparators(const char* pathName);

#ifdef __cplusplus
}
#endif

#endif // QDIR_C_H
