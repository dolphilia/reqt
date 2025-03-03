#ifndef CHECKBOX_HANDLER_H
#define CHECKBOX_HANDLER_H

#include "QAbstractButton/QAbstractButtonHandler.h"
#include <QObject>

class CheckBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*StateCallback)(void*, int);
    typedef void (*ToggleCallback)(void*, bool);
    typedef void (*ClickCallback)(void*, bool);
public:
    explicit CheckBoxHandler(QObject* parent = nullptr);
    void setStateChangedCallback(StateCallback callback);
    void setToggledCallback(ToggleCallback callback);
    void setClickedCallback(ClickCallback callback);

public slots:
    void onStateChanged(int state) const;
    void onToggled(bool checked) const;
    void onClicked(bool checked) const;

private:
    StateCallback stateCallback;
    ToggleCallback toggleCallback;
    ClickCallback clickedCallback;
};

#endif // CHECKBOX_HANDLER_H
