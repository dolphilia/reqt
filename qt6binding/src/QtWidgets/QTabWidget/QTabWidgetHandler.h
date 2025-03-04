#ifndef QTABWIDGET_HANDLER_H
#define QTABWIDGET_HANDLER_H

#include <QObject>

class QTabWidgetHandler : public QObject {
    Q_OBJECT
    typedef void (*QTabWidget_CurrentChangedCallback)(void*, int);
    typedef void (*QTabWidget_TabCloseRequestedCallback)(void*, int);
public:
    explicit QTabWidgetHandler(QObject* parent = nullptr);
    void setCurrentChangedCallback(QTabWidget_CurrentChangedCallback callback);
    void setTabCloseRequestedCallback(QTabWidget_TabCloseRequestedCallback callback);

public slots:
    void onCurrentChanged(int index) const;
    void onTabCloseRequested(int index) const;

private:
    QTabWidget_CurrentChangedCallback currentChangedCallback;
    QTabWidget_TabCloseRequestedCallback tabCloseRequestedCallback;
};

#endif // QTABWIDGET_HANDLER_H
