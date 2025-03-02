#ifndef QFILESYSTEMMODEL_HANDLER_H
#define QFILESYSTEMMODEL_HANDLER_H

#include <QObject>
#include <QString>

class FileSystemModelHandler : public QObject {
    Q_OBJECT
public:
    explicit FileSystemModelHandler(QObject* parent = nullptr);
    
    void setDirectoryLoadedCallback(void (*callback)(void*, const char*));
    void setFileRenamedCallback(void (*callback)(void*, const char*, const char*, const char*));
    void setRootPathChangedCallback(void (*callback)(void*, const char*));

public slots:
    void onDirectoryLoaded(const QString& path);
    void onFileRenamed(const QString& path, const QString& oldName, const QString& newName);
    void onRootPathChanged(const QString& newPath);

private:
    void (*directoryLoadedCallback)(void*, const char*);
    void (*fileRenamedCallback)(void*, const char*, const char*, const char*);
    void (*rootPathChangedCallback)(void*, const char*);
};

#endif // QFILESYSTEMMODEL_HANDLER_H
