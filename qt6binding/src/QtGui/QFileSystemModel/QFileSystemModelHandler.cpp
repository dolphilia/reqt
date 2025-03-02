#include "QFileSystemModelHandler.h"

FileSystemModelHandler::FileSystemModelHandler(QObject* parent)
    : QObject(parent)
    , directoryLoadedCallback(nullptr)
    , fileRenamedCallback(nullptr)
    , rootPathChangedCallback(nullptr)
{
}

void FileSystemModelHandler::setDirectoryLoadedCallback(void (*callback)(void*, const char*)) {
    directoryLoadedCallback = callback;
}

void FileSystemModelHandler::setFileRenamedCallback(void (*callback)(void*, const char*, const char*, const char*)) {
    fileRenamedCallback = callback;
}

void FileSystemModelHandler::setRootPathChangedCallback(void (*callback)(void*, const char*)) {
    rootPathChangedCallback = callback;
}

void FileSystemModelHandler::onDirectoryLoaded(const QString& path) {
    if (directoryLoadedCallback) {
        directoryLoadedCallback(parent(), path.toUtf8().constData());
    }
}

void FileSystemModelHandler::onFileRenamed(const QString& path, const QString& oldName, const QString& newName) {
    if (fileRenamedCallback) {
        fileRenamedCallback(parent(), 
                          path.toUtf8().constData(),
                          oldName.toUtf8().constData(),
                          newName.toUtf8().constData());
    }
}

void FileSystemModelHandler::onRootPathChanged(const QString& newPath) {
    if (rootPathChangedCallback) {
        rootPathChangedCallback(parent(), newPath.toUtf8().constData());
    }
}
