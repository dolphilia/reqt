#ifndef CHECKBOX_HANDLER_H
#define CHECKBOX_HANDLER_H

#include <QObject>

class CheckBoxHandler : public QObject {
    Q_OBJECT
public:
    explicit CheckBoxHandler(QObject* parent = nullptr);
    void setStateChangedCallback(void (*callback)(void*, int));
    void setToggledCallback(void (*callback)(void*, bool));

public slots:
    void onStateChanged(int state);
    void onToggled(bool checked);

private:
    void (*stateCallback)(void*, int);
    void (*toggleCallback)(void*, bool);
};

#endif // CHECKBOX_HANDLER_H
