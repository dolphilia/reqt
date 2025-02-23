#ifndef HANDLER_GROUP_BOX_H
#define HANDLER_GROUP_BOX_H

#include <QObject>

class HandlerGroupBox : public QObject {
    Q_OBJECT
public:
    explicit HandlerGroupBox(QObject *parent = nullptr);
    void setToggleCallback(void (*callback)(void*, bool));
    void* widget;

public slots:
    void onToggled(bool checked);

private:
    void (*toggleCallback)(void*, bool);
};

#endif // HANDLER_GROUP_BOX_H
