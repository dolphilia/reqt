#ifndef QTOOLBUTTON_BIND_H
#define QTOOLBUTTON_BIND_H

#include <QToolButton>

#include "QToolButtonHandler.h"
#include "QAbstractButton/QAbstractButtonBind.h"

class QToolButtonHandler;

class QToolButtonBind : public QToolButton {
    Q_OBJECT
    typedef void (*QToolButton_ClickedCallback)(void*);
    typedef void (*QToolButton_ToggledCallback)(void*, bool);
    typedef void (*QToolButton_TriggeredCallback)(void*);
public:
    explicit QToolButtonBind(QWidget* parent = nullptr);
    ~QToolButtonBind() override;
    void setClickedCallback(QToolButton_ClickedCallback callback) const;
    void setToggledCallback(QToolButton_ToggledCallback callback) const;
    void setTriggeredCallback(QToolButton_TriggeredCallback callback) const;
private:
    QToolButtonHandler* handler;
};

#endif // QTOOLBUTTON_BIND_H
