#ifndef QTOOLBUTTON_HANDLER_H
#define QTOOLBUTTON_HANDLER_H

#include "QAbstractButton/QAbstractButtonHandler.h"
#include <QObject>

class QToolButtonHandler : public QObject {
    Q_OBJECT
    typedef void (*QToolButton_ClickedCallback)(void*);
    typedef void (*QToolButton_ToggledCallback)(void*, bool);
    typedef void (*QToolButton_TriggeredCallback)(void*);
public:
    explicit QToolButtonHandler(QObject* parent = nullptr);
    void setClickedCallback(QToolButton_ClickedCallback callback);
    void setToggledCallback(QToolButton_ToggledCallback callback);
    void setTriggeredCallback(QToolButton_TriggeredCallback callback);

public slots:
    void onClicked() const;
    void onToggled(bool checked) const;
    void onTriggered() const;

private:
    QToolButton_ClickedCallback clickedCallback;
    QToolButton_ToggledCallback toggledCallback;
    QToolButton_TriggeredCallback triggeredCallback;
};

#endif // QTOOLBUTTON_HANDLER_H
