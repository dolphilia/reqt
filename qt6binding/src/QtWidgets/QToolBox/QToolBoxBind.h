#ifndef QTOOLBOX_BIND_H
#define QTOOLBOX_BIND_H

#include <QToolBox>
#include "QToolBoxHandler.h"

class QToolBoxHandler;

class QToolBoxBind : public QToolBox {
    Q_OBJECT
    typedef void (*QToolBox_CurrentChangedCallback)(void*, int);
public:
    explicit QToolBoxBind(QWidget* parent = nullptr);
    ~QToolBoxBind() override;
    void setCurrentChangedCallback(QToolBox_CurrentChangedCallback callback) const;
private:
    QToolBoxHandler* handler;
};

#endif // QTOOLBOX_BIND_H
