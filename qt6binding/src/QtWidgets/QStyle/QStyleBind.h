#ifndef QSTYLE_BIND_H
#define QSTYLE_BIND_H

#include <QStyle>
#include <QApplication>
#include "QStyleHandler.h"

class QStyleHandler;

class QStyleBind : public QObject {
    Q_OBJECT
public:
    explicit QStyleBind(QObject* parent = nullptr);
    ~QStyleBind() override;

private:
    QStyleHandler* handler;
};

#endif // QSTYLE_BIND_H
