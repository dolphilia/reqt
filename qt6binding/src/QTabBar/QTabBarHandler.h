#ifndef HANDLER_TAB_BAR_H
#define HANDLER_TAB_BAR_H

#include <QObject>

class TabBarHandler : public QObject {
    Q_OBJECT
public:
    explicit TabBarHandler(QObject *parent = nullptr);
    ~TabBarHandler();

    void setCurrentChangedCallback(void (*callback)(int));
    void setTabCloseRequestedCallback(void (*callback)(int));

public slots:
    void onCurrentChanged(int index);
    void onTabCloseRequested(int index);

private:
    void (*m_currentChangedCallback)(int);
    void (*m_tabCloseRequestedCallback)(int);
};

#endif // HANDLER_TAB_BAR_H
