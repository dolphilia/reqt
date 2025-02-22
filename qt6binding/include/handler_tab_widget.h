#ifndef HANDLER_TAB_WIDGET_H
#define HANDLER_TAB_WIDGET_H

#include <QObject>

class TabWidgetHandler : public QObject {
    Q_OBJECT
public:
    explicit TabWidgetHandler(QObject *parent = nullptr);
    ~TabWidgetHandler();

    void setCurrentChangedCallback(void (*callback)(int));
    void setTabCloseRequestedCallback(void (*callback)(int));

public slots:
    void onCurrentChanged(int index);
    void onTabCloseRequested(int index);

private:
    void (*m_currentChangedCallback)(int);
    void (*m_tabCloseRequestedCallback)(int);
};

#endif // HANDLER_TAB_WIDGET_H
