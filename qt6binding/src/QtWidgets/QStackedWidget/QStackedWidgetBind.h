#ifndef QSTACKEDWIDGET_BIND_H
#define QSTACKEDWIDGET_BIND_H

#include <QStackedWidget>
#include "QStackedWidgetHandler.h"

class QStackedWidgetBind : public QStackedWidget {
    Q_OBJECT

public:
    explicit QStackedWidgetBind(QWidget* parent = nullptr);
    ~QStackedWidgetBind() override;

    void setCurrentChangedCallback(void (*callback)(void*, int));
    void setWidgetRemovedCallback(void (*callback)(void*, int));

private:
    QStackedWidgetHandler* handler;
};

#endif // QSTACKEDWIDGET_BIND_H
