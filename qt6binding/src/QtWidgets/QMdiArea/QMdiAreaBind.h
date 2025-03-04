#ifndef QMDIAREA_BIND_H
#define QMDIAREA_BIND_H

#include "QMdiAreaHandler.h"
#include <QMdiArea>

class QMdiAreaBind : public QMdiArea {
    Q_OBJECT
    typedef void (*QMdiArea_SubWindowActivatedCallback)(void*, void*);
public:
    explicit QMdiAreaBind(QWidget* parent = nullptr);
    ~QMdiAreaBind() override;
    void setSubWindowActivatedCallback(QMdiArea_SubWindowActivatedCallback callback) const;
private:
    QMdiAreaHandler* handler;
};

#endif // QMDIAREA_BIND_H
