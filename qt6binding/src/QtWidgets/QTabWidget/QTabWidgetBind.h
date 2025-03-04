#ifndef QTABWIDGET_BIND_H
#define QTABWIDGET_BIND_H

#include <QTabWidget>

#include "QTabWidgetHandler.h"

class QTabWidgetHandler;

class QTabWidgetBind : public QTabWidget {
    Q_OBJECT
    typedef void (*QTabWidget_CurrentChangedCallback)(void*, int);
    typedef void (*QTabWidget_TabCloseRequestedCallback)(void*, int);
public:
    explicit QTabWidgetBind(QWidget* parent = nullptr);
    ~QTabWidgetBind() override;
    void setCurrentChangedCallback(QTabWidget_CurrentChangedCallback callback) const;
    void setTabCloseRequestedCallback(QTabWidget_TabCloseRequestedCallback callback) const;
private:
    QTabWidgetHandler* handler;
};

#endif // QTABWIDGET_BIND_H
