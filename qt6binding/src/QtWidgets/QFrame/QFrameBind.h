#ifndef QFRAME_BIND_H
#define QFRAME_BIND_H

#include "QFrameHandler.h"
#include <QFrame>

class QFrameBind : public QFrame {
    Q_OBJECT
public:
    explicit QFrameBind(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~QFrameBind() override;

private:
    QFrameHandler* handler;
};

#endif // QFRAME_BIND_H
