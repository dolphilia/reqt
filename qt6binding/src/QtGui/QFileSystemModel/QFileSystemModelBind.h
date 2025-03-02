#ifndef QFILESYSTEMMODEL_BIND_H
#define QFILESYSTEMMODEL_BIND_H

#include <QFileSystemModel>
#include <QString>

typedef void (*QFileSystemModelDirectoryLoadedCallback)(void* model, const char* path);
typedef void (*QFileSystemModelFileRenamedCallback)(void* model, const char* path, const char* oldName, const char* newName);
typedef void (*QFileSystemModelRootPathChangedCallback)(void* model, const char* newPath);

class QFileSystemModelBind {
public:
    static QFileSystemModel* create(QObject* parent = nullptr);
    static void destroy(QFileSystemModel* model);
    
    // Basic operations
    static void setRootPath(QFileSystemModel* model, const char* path);
    static const char* rootPath(QFileSystemModel* model);
    static const char* filePath(QFileSystemModel* model, void* index);
    static const char* fileName(QFileSystemModel* model, void* index);
    static bool isDir(QFileSystemModel* model, void* index);
    static qint64 size(QFileSystemModel* model, void* index);
    static const char* type(QFileSystemModel* model, void* index);
    static void* indexFromPath(QFileSystemModel* model, const char* path);
    
    // Filter operations
    static void setNameFilters(QFileSystemModel* model, const char** filters, int count);
    static void setFilter(QFileSystemModel* model, int filters);
    static int filter(QFileSystemModel* model);
    static void setNameFilterDisables(QFileSystemModel* model, bool enable);
    static bool nameFilterDisables(QFileSystemModel* model);
    
    // Resolving symlinks
    static void setResolveSymlinks(QFileSystemModel* model, bool enable);
    static bool resolveSymlinks(QFileSystemModel* model);
    
    // Read-only settings
    static void setReadOnly(QFileSystemModel* model, bool enable);
    static bool isReadOnly(QFileSystemModel* model);

    // Options
    static void setOption(QFileSystemModel* model, QFileSystemModel::Option option, bool on);
    static void setOptions(QFileSystemModel* model, QFileSystemModel::Options options);
    static bool testOption(QFileSystemModel* model, QFileSystemModel::Option option);
    static QFileSystemModel::Options options(QFileSystemModel* model);

    // File operations
    static QModelIndex mkdir(QFileSystemModel* model, const QModelIndex* parent, const char* name);
    static bool remove(QFileSystemModel* model, const QModelIndex* index);
    static bool rmdir(QFileSystemModel* model, const QModelIndex* index);

    // Additional information
    static const char* fileIcon(QFileSystemModel* model, const QModelIndex* index);
    static QFileInfo* fileInfo(QFileSystemModel* model, const QModelIndex* index);
    static qint64 lastModified(QFileSystemModel* model, const QModelIndex* index);
    static QFileDevice::Permissions permissions(QFileSystemModel* model, const QModelIndex* index);
    static const char* rootDirectory(QFileSystemModel* model);

    // Model functions
    static bool hasChildren(QFileSystemModel* model, const QModelIndex* parent);
    static int rowCount(QFileSystemModel* model, const QModelIndex* parent);
    static int columnCount(QFileSystemModel* model, const QModelIndex* parent);
    static QModelIndex parent(QFileSystemModel* model, const QModelIndex* index);
    static QModelIndex index(QFileSystemModel* model, int row, int column, const QModelIndex* parent);
    static const char* headerData(QFileSystemModel* model, int section, Qt::Orientation orientation, int role);

    // Callback setters
    static void setDirectoryLoadedCallback(QFileSystemModel* model, QFileSystemModelDirectoryLoadedCallback callback);
    static void setFileRenamedCallback(QFileSystemModel* model, QFileSystemModelFileRenamedCallback callback);
    static void setRootPathChangedCallback(QFileSystemModel* model, QFileSystemModelRootPathChangedCallback callback);
};

#endif // QFILESYSTEMMODEL_BIND_H
