#ifndef QSTACKEDWIDGET_HANDLER_H
#define QSTACKEDWIDGET_HANDLER_H

#include <QObject>
#include <QStackedWidget>

class QStackedWidgetHandler : public QObject {
    Q_OBJECT
    typedef void (*QStackedWidget_CurrentChangedCallback)(void*, int);
    typedef void (*QStackedWidget_WidgetRemovedCallback)(void*, int);
public:
    explicit QStackedWidgetHandler(QObject* parent = nullptr);
    void setCurrentChangedCallback(QStackedWidget_CurrentChangedCallback callback);
    void setWidgetRemovedCallback(QStackedWidget_WidgetRemovedCallback callback);

public slots:
    void onCurrentChanged(int index) const;
    void onWidgetRemoved(int index) const;

private:
    QStackedWidget_CurrentChangedCallback currentChangedCallback;
    QStackedWidget_WidgetRemovedCallback widgetRemovedCallback;
};

#endif // QSTACKEDWIDGET_HANDLER_H
