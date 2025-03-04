#ifndef QTABBAR_HANDLER_H
#define QTABBAR_HANDLER_H

#include <QObject>

class QTabBarHandler : public QObject {
    Q_OBJECT
    typedef void (*QTabBar_CurrentChangedCallback)(void*, int);
    typedef void (*QTabBar_TabCloseRequestedCallback)(void*, int);
public:
    explicit QTabBarHandler(QObject *parent = nullptr);
    ~QTabBarHandler() override;
    void setCurrentChangedCallback(QTabBar_CurrentChangedCallback callback);
    void setTabCloseRequestedCallback(QTabBar_TabCloseRequestedCallback callback);

public slots:
    void onCurrentChanged(int index) const;
    void onTabCloseRequested(int index) const;

private:
    QTabBar_CurrentChangedCallback currentChangedCallback;
    QTabBar_TabCloseRequestedCallback tabCloseRequestedCallback;
};

#endif // QTABBAR_HANDLER_H
