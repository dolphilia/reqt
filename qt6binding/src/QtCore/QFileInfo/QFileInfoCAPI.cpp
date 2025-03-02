#include "qfileinfo.h"
#include "QFileInfoBind.h"
#include <QFileDevice>
#include <QDir>

extern "C" {

void* QFileInfo_create() {
    return QFileInfoBind::create();
}

void* QFileInfo_createWithPath(const char* path) {
    return QFileInfoBind::createWithPath(path);
}

void* QFileInfo_createWithDir(void* dir, const char* path) {
    return QFileInfoBind::createWithDir(static_cast<QDir*>(dir), path);
}

void* QFileInfo_createWithFileDevice(void* file) {
    return QFileInfoBind::createWithFileDevice(static_cast<QFileDevice*>(file));
}

void* QFileInfo_copy(void* fileinfo) {
    return QFileInfoBind::copy(static_cast<QFileInfo*>(fileinfo));
}

void QFileInfo_delete(void* fileinfo) {
    QFileInfoBind::destroy(static_cast<QFileInfo*>(fileinfo));
}

void* QFileInfo_absoluteDir(void* fileinfo) {
    return QFileInfoBind::absoluteDir(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_absoluteFilePath(void* fileinfo) {
    return QFileInfoBind::absoluteFilePath(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_absolutePath(void* fileinfo) {
    return QFileInfoBind::absolutePath(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_baseName(void* fileinfo) {
    return QFileInfoBind::baseName(static_cast<QFileInfo*>(fileinfo));
}

int64_t QFileInfo_birthTime(void* fileinfo) {
    return QFileInfoBind::birthTime(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_bundleName(void* fileinfo) {
    return QFileInfoBind::bundleName(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_caching(void* fileinfo) {
    return QFileInfoBind::caching(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_canonicalFilePath(void* fileinfo) {
    return QFileInfoBind::canonicalFilePath(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_canonicalPath(void* fileinfo) {
    return QFileInfoBind::canonicalPath(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_completeBaseName(void* fileinfo) {
    return QFileInfoBind::completeBaseName(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_completeSuffix(void* fileinfo) {
    return QFileInfoBind::completeSuffix(static_cast<QFileInfo*>(fileinfo));
}

void* QFileInfo_dir(void* fileinfo) {
    return QFileInfoBind::dir(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_exists(void* fileinfo) {
    return QFileInfoBind::exists(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_fileName(void* fileinfo) {
    return QFileInfoBind::fileName(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_filePath(void* fileinfo) {
    return QFileInfoBind::filePath(static_cast<QFileInfo*>(fileinfo));
}

int64_t QFileInfo_fileTime(void* fileinfo, int time) {
    return QFileInfoBind::fileTime(static_cast<QFileInfo*>(fileinfo), static_cast<QFileDevice::FileTime>(time));
}

const char* QFileInfo_group(void* fileinfo) {
    return QFileInfoBind::group(static_cast<QFileInfo*>(fileinfo));
}

uint32_t QFileInfo_groupId(void* fileinfo) {
    return QFileInfoBind::groupId(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isAbsolute(void* fileinfo) {
    return QFileInfoBind::isAbsolute(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isAlias(void* fileinfo) {
    return QFileInfoBind::isAlias(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isBundle(void* fileinfo) {
    return QFileInfoBind::isBundle(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isDir(void* fileinfo) {
    return QFileInfoBind::isDir(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isExecutable(void* fileinfo) {
    return QFileInfoBind::isExecutable(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isFile(void* fileinfo) {
    return QFileInfoBind::isFile(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isHidden(void* fileinfo) {
    return QFileInfoBind::isHidden(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isJunction(void* fileinfo) {
    return QFileInfoBind::isJunction(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isNativePath(void* fileinfo) {
    return QFileInfoBind::isNativePath(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isReadable(void* fileinfo) {
    return QFileInfoBind::isReadable(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isRelative(void* fileinfo) {
    return QFileInfoBind::isRelative(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isRoot(void* fileinfo) {
    return QFileInfoBind::isRoot(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isShortcut(void* fileinfo) {
    return QFileInfoBind::isShortcut(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isSymLink(void* fileinfo) {
    return QFileInfoBind::isSymLink(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isSymbolicLink(void* fileinfo) {
    return QFileInfoBind::isSymbolicLink(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_isWritable(void* fileinfo) {
    return QFileInfoBind::isWritable(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_junctionTarget(void* fileinfo) {
    return QFileInfoBind::junctionTarget(static_cast<QFileInfo*>(fileinfo));
}

int64_t QFileInfo_lastModified(void* fileinfo) {
    return QFileInfoBind::lastModified(static_cast<QFileInfo*>(fileinfo));
}

int64_t QFileInfo_lastRead(void* fileinfo) {
    return QFileInfoBind::lastRead(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_makeAbsolute(void* fileinfo) {
    return QFileInfoBind::makeAbsolute(static_cast<QFileInfo*>(fileinfo));
}

int64_t QFileInfo_metadataChangeTime(void* fileinfo) {
    return QFileInfoBind::metadataChangeTime(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_owner(void* fileinfo) {
    return QFileInfoBind::owner(static_cast<QFileInfo*>(fileinfo));
}

uint32_t QFileInfo_ownerId(void* fileinfo) {
    return QFileInfoBind::ownerId(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_path(void* fileinfo) {
    return QFileInfoBind::path(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_permission(void* fileinfo, int permissions) {
    return QFileInfoBind::permission(static_cast<QFileInfo*>(fileinfo), static_cast<QFileDevice::Permissions>(permissions));
}

int QFileInfo_permissions(void* fileinfo) {
    return static_cast<int>(QFileInfoBind::permissions(static_cast<QFileInfo*>(fileinfo)));
}

const char* QFileInfo_readSymLink(void* fileinfo) {
    return QFileInfoBind::readSymLink(static_cast<QFileInfo*>(fileinfo));
}

void QFileInfo_refresh(void* fileinfo) {
    QFileInfoBind::refresh(static_cast<QFileInfo*>(fileinfo));
}

void QFileInfo_setCaching(void* fileinfo, bool enable) {
    QFileInfoBind::setCaching(static_cast<QFileInfo*>(fileinfo), enable);
}

void QFileInfo_setFile(void* fileinfo, const char* path) {
    QFileInfoBind::setFile(static_cast<QFileInfo*>(fileinfo), path);
}

void QFileInfo_setFileWithDir(void* fileinfo, void* dir, const char* path) {
    QFileInfoBind::setFileWithDir(static_cast<QFileInfo*>(fileinfo), static_cast<QDir*>(dir), path);
}

void QFileInfo_setFileWithDevice(void* fileinfo, void* file) {
    QFileInfoBind::setFileWithDevice(static_cast<QFileInfo*>(fileinfo), static_cast<QFileDevice*>(file));
}

int64_t QFileInfo_size(void* fileinfo) {
    return QFileInfoBind::size(static_cast<QFileInfo*>(fileinfo));
}

void QFileInfo_stat(void* fileinfo) {
    QFileInfoBind::stat(static_cast<QFileInfo*>(fileinfo));
}

const char* QFileInfo_suffix(void* fileinfo) {
    return QFileInfoBind::suffix(static_cast<QFileInfo*>(fileinfo));
}

void QFileInfo_swap(void* fileinfo, void* other) {
    QFileInfoBind::swap(static_cast<QFileInfo*>(fileinfo), static_cast<QFileInfo*>(other));
}

const char* QFileInfo_symLinkTarget(void* fileinfo) {
    return QFileInfoBind::symLinkTarget(static_cast<QFileInfo*>(fileinfo));
}

bool QFileInfo_existsPath(const char* path) {
    return QFileInfoBind::existsPath(path);
}

}
