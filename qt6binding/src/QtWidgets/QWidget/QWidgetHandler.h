#ifndef QWIDGET_HANDLER_H
#define QWIDGET_HANDLER_H

#include <QObject>
#include <QPoint>
#include <QIcon>
#include <QString>

class QWidgetHandler : public QObject {
    Q_OBJECT
    typedef void (*QWidget_CustomContextMenuRequestedCallback)(void*, const QPoint*);
    typedef void (*QWidget_WindowIconChangedCallback)(void*, const QIcon*);
    typedef void (*QWidget_WindowTitleChangedCallback)(void*, const QString*);
public:
    explicit QWidgetHandler(QObject* parent = nullptr);
    void setCustomContextMenuRequestedCallback(QWidget_CustomContextMenuRequestedCallback callback);
    void setWindowIconChangedCallback(QWidget_WindowIconChangedCallback callback);
    void setWindowTitleChangedCallback(QWidget_WindowTitleChangedCallback callback);

public slots:
    void onCustomContextMenuRequested(const QPoint &pos) const;
    void onWindowIconChanged(const QIcon &icon) const;
    void onWindowTitleChanged(const QString &title) const;

private:
    QWidget_CustomContextMenuRequestedCallback customContextMenuRequestedCallback;
    QWidget_WindowIconChangedCallback windowIconChangedCallback;
    QWidget_WindowTitleChangedCallback windowTitleChangedCallback;
};

#endif // QWIDGET_HANDLER_H
