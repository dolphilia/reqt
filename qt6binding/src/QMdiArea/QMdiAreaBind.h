#ifndef QMDIAREA_BIND_H
#define QMDIAREA_BIND_H

#include <QMdiArea>
#include "QMdiAreaHandler.h"

class QMdiAreaBind : public QMdiArea {
    Q_OBJECT

public:
    explicit QMdiAreaBind(QWidget* parent = nullptr);
    ~QMdiAreaBind() override;

    void setSubWindowActivatedCallback(void (*callback)(void*, void*));

private:
    MdiAreaHandler* handler;
};

#endif // QMDIAREA_BIND_H
