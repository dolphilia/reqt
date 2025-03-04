#ifndef QGROUPBOX_BIND_H
#define QGROUPBOX_BIND_H

#include "QGroupBoxHandler.h"
#include <QGroupBox>

class QGroupBoxBind : public QGroupBox {
    Q_OBJECT
    typedef void (*QGroupBox_ToggledCallback)(void*, bool);
public:
    explicit QGroupBoxBind(QWidget* parent = nullptr);
    explicit QGroupBoxBind(const QString& title, QWidget* parent = nullptr);
    ~QGroupBoxBind() override;
    
    void setToggledCallback(QGroupBox_ToggledCallback callback) const;
private:
    QGroupBoxHandler* handler;
};

#endif // QGROUPBOX_BIND_H
