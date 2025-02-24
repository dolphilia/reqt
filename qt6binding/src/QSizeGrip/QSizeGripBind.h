#ifndef QSIZEGRIP_BIND_H
#define QSIZEGRIP_BIND_H

#include <QSizeGrip>

class QSizeGripBind : public QSizeGrip {
    Q_OBJECT

public:
    explicit QSizeGripBind(QWidget* parent = nullptr);
    ~QSizeGripBind() override;
};

#endif // QSIZEGRIP_BIND_H
