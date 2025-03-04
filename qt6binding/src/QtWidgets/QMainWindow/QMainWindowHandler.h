#ifndef MAINWINDOW_HANDLER_H
#define MAINWINDOW_HANDLER_H

#include <QObject>

class QMainWindowHandler : public QObject {
    Q_OBJECT
    typedef void (*QMainWindow_WindowTitleChangedCallback)(void*, const char*);
public:
    explicit QMainWindowHandler(QObject* parent = nullptr);
    void setWindowTitleCallback(QMainWindow_WindowTitleChangedCallback callback);
public slots:
    void onWindowTitleChanged(const QString& title) const;
private:
    QMainWindow_WindowTitleChangedCallback titleCallback;
};

#endif // MAINWINDOW_HANDLER_H
