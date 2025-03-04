#ifndef GROUPBOX_HANDLER_H
#define GROUPBOX_HANDLER_H

#include <QObject>

class QGroupBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*QGroupBox_ToggledCallback)(void*, bool);
public:
    explicit QGroupBoxHandler(QObject* parent = nullptr);
    void setToggledCallback(QGroupBox_ToggledCallback callback);
public slots:
    void onToggled(bool checked) const;
private:
    QGroupBox_ToggledCallback toggledCallback;
};

#endif // GROUPBOX_HANDLER_H
