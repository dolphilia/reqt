#ifndef QSTACKEDWIDGET_BIND_H
#define QSTACKEDWIDGET_BIND_H

#include <QStackedWidget>
#include "QStackedWidgetHandler.h"

class QStackedWidgetHandler;

class QStackedWidgetBind : public QStackedWidget {
    Q_OBJECT
    typedef void (*QStackedWidget_CurrentChangedCallback)(void*, int);
    typedef void (*QStackedWidget_WidgetRemovedCallback)(void*, int);
public:
    explicit QStackedWidgetBind(QWidget* parent = nullptr);
    ~QStackedWidgetBind() override;
    void setCurrentChangedCallback(QStackedWidget_CurrentChangedCallback callback) const;
    void setWidgetRemovedCallback(QStackedWidget_WidgetRemovedCallback callback) const;
private:
    QStackedWidgetHandler* handler;
};

#endif // QSTACKEDWIDGET_BIND_H
