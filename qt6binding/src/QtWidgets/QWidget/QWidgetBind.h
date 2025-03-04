#ifndef QWIDGET_BIND_H
#define QWIDGET_BIND_H

#include <QWidget>
#include <QIcon>

#include "QWidgetHandler.h"

class QWidgetHandler;

class QWidgetBind : public QWidget {
    Q_OBJECT
    typedef void (*QWidget_CustomContextMenuRequestedCallback)(void*, const QPoint*);
    typedef void (*QWidget_WindowIconChangedCallback)(void*, const QIcon*);
    typedef void (*QWidget_WindowTitleChangedCallback)(void*, const QString*);
public:
    explicit QWidgetBind(QWidget *parent = nullptr);
    ~QWidgetBind() override;
    // Signal callbacks
    void setCustomContextMenuRequestedCallback(QWidget_CustomContextMenuRequestedCallback callback) const;
    void setWindowIconChangedCallback(QWidget_WindowIconChangedCallback callback) const;
    void setWindowTitleChangedCallback(QWidget_WindowTitleChangedCallback callback) const;

private:
    QWidgetHandler* handler;
};

#endif // QWIDGET_BIND_H
