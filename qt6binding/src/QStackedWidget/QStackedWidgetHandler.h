#ifndef QSTACKEDWIDGET_HANDLER_H
#define QSTACKEDWIDGET_HANDLER_H

#include <QObject>
#include <QStackedWidget>

typedef void (*StackedWidgetCurrentChangedCallback)(void*, int);
typedef void (*StackedWidgetWidgetRemovedCallback)(void*, int);

class QStackedWidgetHandler : public QObject {
    Q_OBJECT
public:
    explicit QStackedWidgetHandler(QObject* parent = nullptr);
    QStackedWidgetHandler(const QStackedWidgetHandler&) = delete;
    QStackedWidgetHandler& operator=(const QStackedWidgetHandler&) = delete;

    void setStackedWidget(QStackedWidget* stackedWidget);
    void setCurrentChangedCallback(StackedWidgetCurrentChangedCallback callback);
    void setWidgetRemovedCallback(StackedWidgetWidgetRemovedCallback callback);

public slots:
    void onCurrentChanged(int index);
    void onWidgetRemoved(int index);

private:
    QStackedWidget* stackedWidget;
    StackedWidgetCurrentChangedCallback currentChangedCallback;
    StackedWidgetWidgetRemovedCallback widgetRemovedCallback;
};

#endif // QSTACKEDWIDGET_HANDLER_H
