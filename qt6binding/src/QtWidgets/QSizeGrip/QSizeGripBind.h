#ifndef QSIZEGRIP_BIND_H
#define QSIZEGRIP_BIND_H

#include <QSizeGrip>

#include "QSizeGripHandler.h"

class QSizeGripHandler;

class QSizeGripBind : public QSizeGrip {
    Q_OBJECT
public:
    explicit QSizeGripBind(QWidget* parent = nullptr);
    ~QSizeGripBind() override;
    
private:
    QSizeGripHandler* handler;
};

#endif // QSIZEGRIP_BIND_H
