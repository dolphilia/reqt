#ifndef QFILEINFO_C_H
#define QFILEINFO_C_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// FileTime enum
#define QFILEINFO_FILETIME_BIRTH 0
#define QFILEINFO_FILETIME_METADATA_CHANGE 1
#define QFILEINFO_FILETIME_MODIFICATION 2
#define QFILEINFO_FILETIME_ACCESS 3

// Permissions flags
#define QFILEINFO_PERMISSION_READABLE 0x4
#define QFILEINFO_PERMISSION_WRITABLE 0x2
#define QFILEINFO_PERMISSION_EXECUTABLE 0x1
#define QFILEINFO_PERMISSION_WRITE_USER 0x0800
#define QFILEINFO_PERMISSION_READ_USER 0x0400
#define QFILEINFO_PERMISSION_EXEC_USER 0x0200
#define QFILEINFO_PERMISSION_WRITE_GROUP 0x0080
#define QFILEINFO_PERMISSION_READ_GROUP 0x0040
#define QFILEINFO_PERMISSION_EXEC_GROUP 0x0020
#define QFILEINFO_PERMISSION_WRITE_OTHER 0x0008
#define QFILEINFO_PERMISSION_READ_OTHER 0x0004
#define QFILEINFO_PERMISSION_EXEC_OTHER 0x0002

// Creation and destruction
void* QFileInfo_create();
void* QFileInfo_createWithPath(const char* path);
void* QFileInfo_createWithDir(void* dir, const char* path);
void* QFileInfo_createWithFileDevice(void* file);
void* QFileInfo_copy(void* fileinfo);
void QFileInfo_delete(void* fileinfo);

// Directory operations
void* QFileInfo_absoluteDir(void* fileinfo);
const char* QFileInfo_absoluteFilePath(void* fileinfo);
const char* QFileInfo_absolutePath(void* fileinfo);
const char* QFileInfo_baseName(void* fileinfo);
int64_t QFileInfo_birthTime(void* fileinfo);
const char* QFileInfo_bundleName(void* fileinfo);
bool QFileInfo_caching(void* fileinfo);
const char* QFileInfo_canonicalFilePath(void* fileinfo);
const char* QFileInfo_canonicalPath(void* fileinfo);
const char* QFileInfo_completeBaseName(void* fileinfo);
const char* QFileInfo_completeSuffix(void* fileinfo);
void* QFileInfo_dir(void* fileinfo);
bool QFileInfo_exists(void* fileinfo);
const char* QFileInfo_fileName(void* fileinfo);
const char* QFileInfo_filePath(void* fileinfo);
int64_t QFileInfo_fileTime(void* fileinfo, int time);
const char* QFileInfo_group(void* fileinfo);
uint32_t QFileInfo_groupId(void* fileinfo);
bool QFileInfo_isAbsolute(void* fileinfo);
bool QFileInfo_isAlias(void* fileinfo);
bool QFileInfo_isBundle(void* fileinfo);
bool QFileInfo_isDir(void* fileinfo);
bool QFileInfo_isExecutable(void* fileinfo);
bool QFileInfo_isFile(void* fileinfo);
bool QFileInfo_isHidden(void* fileinfo);
bool QFileInfo_isJunction(void* fileinfo);
bool QFileInfo_isNativePath(void* fileinfo);
bool QFileInfo_isReadable(void* fileinfo);
bool QFileInfo_isRelative(void* fileinfo);
bool QFileInfo_isRoot(void* fileinfo);
bool QFileInfo_isShortcut(void* fileinfo);
bool QFileInfo_isSymLink(void* fileinfo);
bool QFileInfo_isSymbolicLink(void* fileinfo);
bool QFileInfo_isWritable(void* fileinfo);
const char* QFileInfo_junctionTarget(void* fileinfo);
int64_t QFileInfo_lastModified(void* fileinfo);
int64_t QFileInfo_lastRead(void* fileinfo);
bool QFileInfo_makeAbsolute(void* fileinfo);
int64_t QFileInfo_metadataChangeTime(void* fileinfo);
const char* QFileInfo_owner(void* fileinfo);
uint32_t QFileInfo_ownerId(void* fileinfo);
const char* QFileInfo_path(void* fileinfo);
bool QFileInfo_permission(void* fileinfo, int permissions);
int QFileInfo_permissions(void* fileinfo);
const char* QFileInfo_readSymLink(void* fileinfo);
void QFileInfo_refresh(void* fileinfo);
void QFileInfo_setCaching(void* fileinfo, bool enable);
void QFileInfo_setFile(void* fileinfo, const char* path);
void QFileInfo_setFileWithDir(void* fileinfo, void* dir, const char* path);
void QFileInfo_setFileWithDevice(void* fileinfo, void* file);
int64_t QFileInfo_size(void* fileinfo);
void QFileInfo_stat(void* fileinfo);
const char* QFileInfo_suffix(void* fileinfo);
void QFileInfo_swap(void* fileinfo, void* other);
const char* QFileInfo_symLinkTarget(void* fileinfo);

// Static functions
bool QFileInfo_existsPath(const char* path);

#ifdef __cplusplus
}
#endif

#endif // QFILEINFO_C_H
