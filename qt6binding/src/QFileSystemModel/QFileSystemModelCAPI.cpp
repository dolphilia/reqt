#include "qfilesystemmodel.h"
#include "QFileSystemModelBind.h"
#include <QObject>

extern "C" {

void* QFileSystemModel_create(void* parent) {
    return QFileSystemModelBind::create(static_cast<QObject*>(parent));
}

void QFileSystemModel_delete(void* model) {
    QFileSystemModelBind::destroy(static_cast<QFileSystemModel*>(model));
}

void QFileSystemModel_setRootPath(void* model, const char* path) {
    QFileSystemModelBind::setRootPath(static_cast<QFileSystemModel*>(model), path);
}

const char* QFileSystemModel_rootPath(void* model) {
    return QFileSystemModelBind::rootPath(static_cast<QFileSystemModel*>(model));
}

const char* QFileSystemModel_filePath(void* model, void* index) {
    return QFileSystemModelBind::filePath(static_cast<QFileSystemModel*>(model), index);
}

const char* QFileSystemModel_fileName(void* model, void* index) {
    return QFileSystemModelBind::fileName(static_cast<QFileSystemModel*>(model), index);
}

bool QFileSystemModel_isDir(void* model, void* index) {
    return QFileSystemModelBind::isDir(static_cast<QFileSystemModel*>(model), index);
}

int64_t QFileSystemModel_size(void* model, void* index) {
    return QFileSystemModelBind::size(static_cast<QFileSystemModel*>(model), index);
}

const char* QFileSystemModel_type(void* model, void* index) {
    return QFileSystemModelBind::type(static_cast<QFileSystemModel*>(model), index);
}

void* QFileSystemModel_indexFromPath(void* model, const char* path) {
    return QFileSystemModelBind::indexFromPath(static_cast<QFileSystemModel*>(model), path);
}

void QFileSystemModel_setNameFilters(void* model, const char** filters, int count) {
    QFileSystemModelBind::setNameFilters(static_cast<QFileSystemModel*>(model), filters, count);
}

void QFileSystemModel_setFilter(void* model, int filters) {
    QFileSystemModelBind::setFilter(static_cast<QFileSystemModel*>(model), filters);
}

int QFileSystemModel_filter(void* model) {
    return QFileSystemModelBind::filter(static_cast<QFileSystemModel*>(model));
}

void QFileSystemModel_setNameFilterDisables(void* model, bool enable) {
    QFileSystemModelBind::setNameFilterDisables(static_cast<QFileSystemModel*>(model), enable);
}

bool QFileSystemModel_nameFilterDisables(void* model) {
    return QFileSystemModelBind::nameFilterDisables(static_cast<QFileSystemModel*>(model));
}

void QFileSystemModel_setResolveSymlinks(void* model, bool enable) {
    QFileSystemModelBind::setResolveSymlinks(static_cast<QFileSystemModel*>(model), enable);
}

bool QFileSystemModel_resolveSymlinks(void* model) {
    return QFileSystemModelBind::resolveSymlinks(static_cast<QFileSystemModel*>(model));
}

void QFileSystemModel_setReadOnly(void* model, bool enable) {
    QFileSystemModelBind::setReadOnly(static_cast<QFileSystemModel*>(model), enable);
}

bool QFileSystemModel_isReadOnly(void* model) {
    return QFileSystemModelBind::isReadOnly(static_cast<QFileSystemModel*>(model));
}

void QFileSystemModel_setDirectoryLoadedCallback(void* model, QFileSystemModelDirectoryLoadedCallback callback) {
    QFileSystemModelBind::setDirectoryLoadedCallback(static_cast<QFileSystemModel*>(model), callback);
}

void QFileSystemModel_setFileRenamedCallback(void* model, QFileSystemModelFileRenamedCallback callback) {
    QFileSystemModelBind::setFileRenamedCallback(static_cast<QFileSystemModel*>(model), callback);
}

void QFileSystemModel_setRootPathChangedCallback(void* model, QFileSystemModelRootPathChangedCallback callback) {
    QFileSystemModelBind::setRootPathChangedCallback(static_cast<QFileSystemModel*>(model), callback);
}

// Options
void QFileSystemModel_setOption(void* model, int option, bool on) {
    QFileSystemModelBind::setOption(static_cast<QFileSystemModel*>(model), static_cast<QFileSystemModel::Option>(option), on);
}

void QFileSystemModel_setOptions(void* model, int options) {
    QFileSystemModelBind::setOptions(static_cast<QFileSystemModel*>(model), static_cast<QFileSystemModel::Options>(options));
}

bool QFileSystemModel_testOption(void* model, int option) {
    return QFileSystemModelBind::testOption(static_cast<QFileSystemModel*>(model), static_cast<QFileSystemModel::Option>(option));
}

int QFileSystemModel_options(void* model) {
    return static_cast<int>(QFileSystemModelBind::options(static_cast<QFileSystemModel*>(model)));
}

// File operations
void* QFileSystemModel_mkdir(void* model, void* parent, const char* name) {
    QModelIndex result = QFileSystemModelBind::mkdir(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(parent),
        name
    );
    return result.isValid() ? new QModelIndex(result) : nullptr;
}

bool QFileSystemModel_remove(void* model, void* index) {
    return QFileSystemModelBind::remove(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(index)
    );
}

bool QFileSystemModel_rmdir(void* model, void* index) {
    return QFileSystemModelBind::rmdir(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(index)
    );
}

// Additional information
const char* QFileSystemModel_fileIcon(void* model, void* index) {
    return QFileSystemModelBind::fileIcon(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(index)
    );
}

void* QFileSystemModel_fileInfo(void* model, void* index) {
    return QFileSystemModelBind::fileInfo(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(index)
    );
}

int64_t QFileSystemModel_lastModified(void* model, void* index) {
    return QFileSystemModelBind::lastModified(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(index)
    );
}

int QFileSystemModel_permissions(void* model, void* index) {
    return static_cast<int>(QFileSystemModelBind::permissions(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(index)
    ));
}

const char* QFileSystemModel_rootDirectory(void* model) {
    return QFileSystemModelBind::rootDirectory(static_cast<QFileSystemModel*>(model));
}

// Model functions
bool QFileSystemModel_hasChildren(void* model, void* parent) {
    return QFileSystemModelBind::hasChildren(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(parent)
    );
}

int QFileSystemModel_rowCount(void* model, void* parent) {
    return QFileSystemModelBind::rowCount(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(parent)
    );
}

int QFileSystemModel_columnCount(void* model, void* parent) {
    return QFileSystemModelBind::columnCount(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(parent)
    );
}

void* QFileSystemModel_parent(void* model, void* index) {
    QModelIndex result = QFileSystemModelBind::parent(
        static_cast<QFileSystemModel*>(model),
        static_cast<QModelIndex*>(index)
    );
    return result.isValid() ? new QModelIndex(result) : nullptr;
}

void* QFileSystemModel_index(void* model, int row, int column, void* parent) {
    QModelIndex result = QFileSystemModelBind::index(
        static_cast<QFileSystemModel*>(model),
        row,
        column,
        static_cast<QModelIndex*>(parent)
    );
    return result.isValid() ? new QModelIndex(result) : nullptr;
}

const char* QFileSystemModel_headerData(void* model, int section, int orientation, int role) {
    return QFileSystemModelBind::headerData(
        static_cast<QFileSystemModel*>(model),
        section,
        static_cast<Qt::Orientation>(orientation),
        role
    );
}

}
