#ifndef QFILESYSTEMMODEL_C_H
#define QFILESYSTEMMODEL_C_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Options enum
#define QFILESYSTEMMODEL_OPTION_DONT_WATCH_FOR_CHANGES     0x01
#define QFILESYSTEMMODEL_OPTION_DONT_RESOLVE_SYMLINKS      0x02
#define QFILESYSTEMMODEL_OPTION_DONT_USE_CUSTOM_DIRECTORY_ICONS 0x04

// Roles enum
#define QFILESYSTEMMODEL_ROLE_FILE_ICON           0x0100
#define QFILESYSTEMMODEL_ROLE_FILE_PATH           0x0101
#define QFILESYSTEMMODEL_ROLE_FILE_NAME           0x0102
#define QFILESYSTEMMODEL_ROLE_FILE_PERMISSIONS    0x0103
#define QFILESYSTEMMODEL_ROLE_FILE_INFO           0x0104

// QFileSystemModel creation/destruction
void* QFileSystemModel_create(void* parent);
void QFileSystemModel_delete(void* model);

// Basic operations
void QFileSystemModel_setRootPath(void* model, const char* path);
const char* QFileSystemModel_rootPath(void* model);
const char* QFileSystemModel_filePath(void* model, void* index);
const char* QFileSystemModel_fileName(void* model, void* index);
bool QFileSystemModel_isDir(void* model, void* index);
int64_t QFileSystemModel_size(void* model, void* index);
const char* QFileSystemModel_type(void* model, void* index);
void* QFileSystemModel_indexFromPath(void* model, const char* path);

// Filter operations
void QFileSystemModel_setNameFilters(void* model, const char** filters, int count);
void QFileSystemModel_setFilter(void* model, int filters);
int QFileSystemModel_filter(void* model);
void QFileSystemModel_setNameFilterDisables(void* model, bool enable);
bool QFileSystemModel_nameFilterDisables(void* model);

// Resolving symlinks
void QFileSystemModel_setResolveSymlinks(void* model, bool enable);
bool QFileSystemModel_resolveSymlinks(void* model);

// Read-only settings
void QFileSystemModel_setReadOnly(void* model, bool enable);
bool QFileSystemModel_isReadOnly(void* model);

// Options
void QFileSystemModel_setOption(void* model, int option, bool on);
void QFileSystemModel_setOptions(void* model, int options);
bool QFileSystemModel_testOption(void* model, int option);
int QFileSystemModel_options(void* model);

// File operations
void* QFileSystemModel_mkdir(void* model, void* parent, const char* name);
bool QFileSystemModel_remove(void* model, void* index);
bool QFileSystemModel_rmdir(void* model, void* index);

// Additional information
const char* QFileSystemModel_fileIcon(void* model, void* index);
void* QFileSystemModel_fileInfo(void* model, void* index);
int64_t QFileSystemModel_lastModified(void* model, void* index);
int QFileSystemModel_permissions(void* model, void* index);
const char* QFileSystemModel_rootDirectory(void* model);

// Model functions
bool QFileSystemModel_hasChildren(void* model, void* parent);
int QFileSystemModel_rowCount(void* model, void* parent);
int QFileSystemModel_columnCount(void* model, void* parent);
void* QFileSystemModel_parent(void* model, void* index);
void* QFileSystemModel_index(void* model, int row, int column, void* parent);
const char* QFileSystemModel_headerData(void* model, int section, int orientation, int role);

// Callback types
typedef void (*QFileSystemModelDirectoryLoadedCallback)(void* model, const char* path);
typedef void (*QFileSystemModelFileRenamedCallback)(void* model, const char* path, const char* oldName, const char* newName);
typedef void (*QFileSystemModelRootPathChangedCallback)(void* model, const char* newPath);

// Callback setters
void QFileSystemModel_setDirectoryLoadedCallback(void* model, QFileSystemModelDirectoryLoadedCallback callback);
void QFileSystemModel_setFileRenamedCallback(void* model, QFileSystemModelFileRenamedCallback callback);
void QFileSystemModel_setRootPathChangedCallback(void* model, QFileSystemModelRootPathChangedCallback callback);

// Filter flags
#define QFILESYSTEMMODEL_FILTER_DIRS              0x001
#define QFILESYSTEMMODEL_FILTER_FILES             0x002
#define QFILESYSTEMMODEL_FILTER_DRIVES            0x004
#define QFILESYSTEMMODEL_FILTER_ALLENTRIES        0x007
#define QFILESYSTEMMODEL_FILTER_NOFILTER          0x000
#define QFILESYSTEMMODEL_FILTER_READABLE          0x010
#define QFILESYSTEMMODEL_FILTER_WRITABLE          0x020
#define QFILESYSTEMMODEL_FILTER_EXECUTABLE        0x040
#define QFILESYSTEMMODEL_FILTER_MODIFIED          0x080
#define QFILESYSTEMMODEL_FILTER_HIDDEN            0x100
#define QFILESYSTEMMODEL_FILTER_SYSTEM            0x200
#define QFILESYSTEMMODEL_FILTER_CASESENSITIVE     0x800
#define QFILESYSTEMMODEL_FILTER_NODOTANDDOTDOT    0x1000
#define QFILESYSTEMMODEL_FILTER_NODOT             0x2000
#define QFILESYSTEMMODEL_FILTER_NODOTDOT          0x4000
#define QFILESYSTEMMODEL_FILTER_ALLOWALL          0x8000

#ifdef __cplusplus
}
#endif

#endif // QFILESYSTEMMODEL_C_H
