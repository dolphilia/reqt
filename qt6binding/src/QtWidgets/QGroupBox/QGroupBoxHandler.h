#ifndef GROUPBOX_HANDLER_H
#define GROUPBOX_HANDLER_H

#include <QObject>

class GroupBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*ToggledCallback)(void*, bool);
public:
    explicit GroupBoxHandler(QObject* parent = nullptr);
    void setToggledCallback(ToggledCallback callback);
public slots:
    void onToggled(bool checked) const;
private:
    ToggledCallback toggledCallback;
};

#endif // GROUPBOX_HANDLER_H
