#include "QFileSystemModelBind.h"
#include "QFileSystemModelHandler.h"
#include <QModelIndex>

QFileSystemModel* QFileSystemModelBind::create(QObject* parent) {
    return new QFileSystemModel(parent);
}

void QFileSystemModelBind::destroy(QFileSystemModel* model) {
    if (model) {
        delete model;
    }
}

void QFileSystemModelBind::setRootPath(QFileSystemModel* model, const char* path) {
    if (model && path) {
        model->setRootPath(QString::fromUtf8(path));
    }
}

const char* QFileSystemModelBind::rootPath(QFileSystemModel* model) {
    if (model) {
        static QString str;
        str = model->rootPath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QFileSystemModelBind::filePath(QFileSystemModel* model, void* index) {
    if (model && index) {
        static QString str;
        str = model->filePath(*static_cast<QModelIndex*>(index));
        return str.toUtf8().constData();
    }
    return nullptr;
}

const char* QFileSystemModelBind::fileName(QFileSystemModel* model, void* index) {
    if (model && index) {
        static QString str;
        str = model->fileName(*static_cast<QModelIndex*>(index));
        return str.toUtf8().constData();
    }
    return nullptr;
}

bool QFileSystemModelBind::isDir(QFileSystemModel* model, void* index) {
    if (model && index) {
        return model->isDir(*static_cast<QModelIndex*>(index));
    }
    return false;
}

qint64 QFileSystemModelBind::size(QFileSystemModel* model, void* index) {
    if (model && index) {
        return model->size(*static_cast<QModelIndex*>(index));
    }
    return 0;
}

const char* QFileSystemModelBind::type(QFileSystemModel* model, void* index) {
    if (model && index) {
        static QString str;
        str = model->type(*static_cast<QModelIndex*>(index));
        return str.toUtf8().constData();
    }
    return nullptr;
}

void* QFileSystemModelBind::indexFromPath(QFileSystemModel* model, const char* path) {
    if (model && path) {
        static QModelIndex idx;
        idx = model->index(QString::fromUtf8(path));
        return new QModelIndex(idx);
    }
    return nullptr;
}

void QFileSystemModelBind::setNameFilters(QFileSystemModel* model, const char** filters, int count) {
    if (model && filters && count > 0) {
        QStringList filterList;
        for (int i = 0; i < count; i++) {
            if (filters[i]) {
                filterList << QString::fromUtf8(filters[i]);
            }
        }
        model->setNameFilters(filterList);
    }
}

void QFileSystemModelBind::setFilter(QFileSystemModel* model, int filters) {
    if (model) {
        model->setFilter(static_cast<QDir::Filters>(filters));
    }
}

int QFileSystemModelBind::filter(QFileSystemModel* model) {
    if (model) {
        return static_cast<int>(model->filter());
    }
    return 0;
}

void QFileSystemModelBind::setNameFilterDisables(QFileSystemModel* model, bool enable) {
    if (model) {
        model->setNameFilterDisables(enable);
    }
}

bool QFileSystemModelBind::nameFilterDisables(QFileSystemModel* model) {
    return model ? model->nameFilterDisables() : false;
}

void QFileSystemModelBind::setResolveSymlinks(QFileSystemModel* model, bool enable) {
    if (model) {
        model->setResolveSymlinks(enable);
    }
}

bool QFileSystemModelBind::resolveSymlinks(QFileSystemModel* model) {
    return model ? model->resolveSymlinks() : false;
}

void QFileSystemModelBind::setReadOnly(QFileSystemModel* model, bool enable) {
    if (model) {
        model->setReadOnly(enable);
    }
}

bool QFileSystemModelBind::isReadOnly(QFileSystemModel* model) {
    return model ? model->isReadOnly() : true;
}

void QFileSystemModelBind::setDirectoryLoadedCallback(QFileSystemModel* model, QFileSystemModelDirectoryLoadedCallback callback) {
    if (model) {
        // 既存のハンドラーを削除
        QObject* existingHandler = model->findChild<FileSystemModelHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        FileSystemModelHandler* handler = new FileSystemModelHandler();
        handler->setParent(model);
        handler->setDirectoryLoadedCallback(callback);
        QObject::connect(model, &QFileSystemModel::directoryLoaded, handler, &FileSystemModelHandler::onDirectoryLoaded);
    }
}

void QFileSystemModelBind::setFileRenamedCallback(QFileSystemModel* model, QFileSystemModelFileRenamedCallback callback) {
    if (model) {
        // 既存のハンドラーを削除
        QObject* existingHandler = model->findChild<FileSystemModelHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        FileSystemModelHandler* handler = new FileSystemModelHandler();
        handler->setParent(model);
        handler->setFileRenamedCallback(callback);
        QObject::connect(model, &QFileSystemModel::fileRenamed, handler, &FileSystemModelHandler::onFileRenamed);
    }
}

void QFileSystemModelBind::setRootPathChangedCallback(QFileSystemModel* model, QFileSystemModelRootPathChangedCallback callback) {
    if (model) {
        // 既存のハンドラーを削除
        QObject* existingHandler = model->findChild<FileSystemModelHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        FileSystemModelHandler* handler = new FileSystemModelHandler();
        handler->setParent(model);
        handler->setRootPathChangedCallback(callback);
        QObject::connect(model, &QFileSystemModel::rootPathChanged, handler, &FileSystemModelHandler::onRootPathChanged);
    }
}

// Options
void QFileSystemModelBind::setOption(QFileSystemModel* model, QFileSystemModel::Option option, bool on) {
    if (model) {
        model->setOption(option, on);
    }
}

void QFileSystemModelBind::setOptions(QFileSystemModel* model, QFileSystemModel::Options options) {
    if (model) {
        model->setOptions(options);
    }
}

bool QFileSystemModelBind::testOption(QFileSystemModel* model, QFileSystemModel::Option option) {
    return model ? model->testOption(option) : false;
}

QFileSystemModel::Options QFileSystemModelBind::options(QFileSystemModel* model) {
    return model ? model->options() : QFileSystemModel::Options();
}

// File operations
QModelIndex QFileSystemModelBind::mkdir(QFileSystemModel* model, const QModelIndex* parent, const char* name) {
    if (model && parent && name) {
        return model->mkdir(*parent, QString::fromUtf8(name));
    }
    return QModelIndex();
}

bool QFileSystemModelBind::remove(QFileSystemModel* model, const QModelIndex* index) {
    return model && index ? model->remove(*index) : false;
}

bool QFileSystemModelBind::rmdir(QFileSystemModel* model, const QModelIndex* index) {
    return model && index ? model->rmdir(*index) : false;
}

// Additional information
const char* QFileSystemModelBind::fileIcon(QFileSystemModel* model, const QModelIndex* index) {
    if (model && index) {
        static QString str;
        str = model->fileIcon(*index).name();
        return str.toUtf8().constData();
    }
    return nullptr;
}

QFileInfo* QFileSystemModelBind::fileInfo(QFileSystemModel* model, const QModelIndex* index) {
    if (model && index) {
        return new QFileInfo(model->fileInfo(*index));
    }
    return nullptr;
}

qint64 QFileSystemModelBind::lastModified(QFileSystemModel* model, const QModelIndex* index) {
    if (model && index) {
        return model->lastModified(*index).toSecsSinceEpoch();
    }
    return 0;
}

QFileDevice::Permissions QFileSystemModelBind::permissions(QFileSystemModel* model, const QModelIndex* index) {
    return model && index ? model->permissions(*index) : QFileDevice::Permissions();
}

const char* QFileSystemModelBind::rootDirectory(QFileSystemModel* model) {
    if (model) {
        static QString str;
        str = model->rootDirectory().absolutePath();
        return str.toUtf8().constData();
    }
    return nullptr;
}

// Model functions
bool QFileSystemModelBind::hasChildren(QFileSystemModel* model, const QModelIndex* parent) {
    return model ? model->hasChildren(parent ? *parent : QModelIndex()) : false;
}

int QFileSystemModelBind::rowCount(QFileSystemModel* model, const QModelIndex* parent) {
    return model ? model->rowCount(parent ? *parent : QModelIndex()) : 0;
}

int QFileSystemModelBind::columnCount(QFileSystemModel* model, const QModelIndex* parent) {
    return model ? model->columnCount(parent ? *parent : QModelIndex()) : 0;
}

QModelIndex QFileSystemModelBind::parent(QFileSystemModel* model, const QModelIndex* index) {
    return model && index ? model->parent(*index) : QModelIndex();
}

QModelIndex QFileSystemModelBind::index(QFileSystemModel* model, int row, int column, const QModelIndex* parent) {
    return model ? model->index(row, column, parent ? *parent : QModelIndex()) : QModelIndex();
}

const char* QFileSystemModelBind::headerData(QFileSystemModel* model, int section, Qt::Orientation orientation, int role) {
    if (model) {
        static QString str;
        QVariant data = model->headerData(section, orientation, role);
        if (data.isValid()) {
            str = data.toString();
            return str.toUtf8().constData();
        }
    }
    return nullptr;
}
