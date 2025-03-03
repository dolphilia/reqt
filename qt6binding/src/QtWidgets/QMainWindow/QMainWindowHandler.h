#ifndef MAINWINDOW_HANDLER_H
#define MAINWINDOW_HANDLER_H

#include <QObject>

class MainWindowHandler : public QObject {
    Q_OBJECT
    typedef void (*WindowTitleChangedCallback)(void*, const char*);
public:
    explicit MainWindowHandler(QObject* parent = nullptr);
    void setWindowTitleCallback(WindowTitleChangedCallback callback);
public slots:
    void onWindowTitleChanged(const QString& title) const;
private:
    WindowTitleChangedCallback titleCallback;
};

#endif // MAINWINDOW_HANDLER_H
