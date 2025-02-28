#ifndef QFILEINFO_BIND_H
#define QFILEINFO_BIND_H

#include <QFileInfo>
#include <QDir>
#include <QDateTime>
#include <QFileDevice>

class QFileInfoBind {
public:
    // Creation and destruction
    static QFileInfo* create();
    static QFileInfo* createWithPath(const char* path);
    static QFileInfo* createWithDir(const QDir* dir, const char* path);
    static QFileInfo* createWithFileDevice(QFileDevice* file);
    static QFileInfo* copy(const QFileInfo* fileinfo);
    static void destroy(QFileInfo* fileinfo);

    // Directory operations
    static QDir* absoluteDir(QFileInfo* fileinfo);
    static const char* absoluteFilePath(QFileInfo* fileinfo);
    static const char* absolutePath(QFileInfo* fileinfo);
    static const char* baseName(QFileInfo* fileinfo);
    static qint64 birthTime(QFileInfo* fileinfo);
    static const char* bundleName(QFileInfo* fileinfo);
    static bool caching(QFileInfo* fileinfo);
    static const char* canonicalFilePath(QFileInfo* fileinfo);
    static const char* canonicalPath(QFileInfo* fileinfo);
    static const char* completeBaseName(QFileInfo* fileinfo);
    static const char* completeSuffix(QFileInfo* fileinfo);
    static QDir* dir(QFileInfo* fileinfo);
    static bool exists(QFileInfo* fileinfo);
    static const char* fileName(QFileInfo* fileinfo);
    static const char* filePath(QFileInfo* fileinfo);
    static qint64 fileTime(QFileInfo* fileinfo, QFileDevice::FileTime time);
    static const char* group(QFileInfo* fileinfo);
    static uint groupId(QFileInfo* fileinfo);
    static bool isAbsolute(QFileInfo* fileinfo);
    static bool isAlias(QFileInfo* fileinfo);
    static bool isBundle(QFileInfo* fileinfo);
    static bool isDir(QFileInfo* fileinfo);
    static bool isExecutable(QFileInfo* fileinfo);
    static bool isFile(QFileInfo* fileinfo);
    static bool isHidden(QFileInfo* fileinfo);
    static bool isJunction(QFileInfo* fileinfo);
    static bool isNativePath(QFileInfo* fileinfo);
    static bool isReadable(QFileInfo* fileinfo);
    static bool isRelative(QFileInfo* fileinfo);
    static bool isRoot(QFileInfo* fileinfo);
    static bool isShortcut(QFileInfo* fileinfo);
    static bool isSymLink(QFileInfo* fileinfo);
    static bool isSymbolicLink(QFileInfo* fileinfo);
    static bool isWritable(QFileInfo* fileinfo);
    static const char* junctionTarget(QFileInfo* fileinfo);
    static qint64 lastModified(QFileInfo* fileinfo);
    static qint64 lastRead(QFileInfo* fileinfo);
    static bool makeAbsolute(QFileInfo* fileinfo);
    static qint64 metadataChangeTime(QFileInfo* fileinfo);
    static const char* owner(QFileInfo* fileinfo);
    static uint ownerId(QFileInfo* fileinfo);
    static const char* path(QFileInfo* fileinfo);
    static bool permission(QFileInfo* fileinfo, QFileDevice::Permissions permissions);
    static QFileDevice::Permissions permissions(QFileInfo* fileinfo);
    static const char* readSymLink(QFileInfo* fileinfo);
    static void refresh(QFileInfo* fileinfo);
    static void setCaching(QFileInfo* fileinfo, bool enable);
    static void setFile(QFileInfo* fileinfo, const char* path);
    static void setFileWithDir(QFileInfo* fileinfo, const QDir* dir, const char* path);
    static void setFileWithDevice(QFileInfo* fileinfo, QFileDevice* file);
    static qint64 size(QFileInfo* fileinfo);
    static void stat(QFileInfo* fileinfo);
    static const char* suffix(QFileInfo* fileinfo);
    static void swap(QFileInfo* fileinfo, QFileInfo* other);
    static const char* symLinkTarget(QFileInfo* fileinfo);

    // Static functions
    static bool existsPath(const char* path);
};

#endif // QFILEINFO_BIND_H
