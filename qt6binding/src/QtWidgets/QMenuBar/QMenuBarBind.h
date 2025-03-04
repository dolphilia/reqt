#ifndef QMENUBAR_BIND_H
#define QMENUBAR_BIND_H

#include "QMenuBarHandler.h"
#include <QMenuBar>

class QMenuBarBind : public QMenuBar {
    Q_OBJECT
    typedef void (*QMenuBar_TriggeredCallback)(void*, void*);
    typedef void (*QMenuBar_HoveredCallback)(void*, void*);
public:
    explicit QMenuBarBind(QWidget* parent = nullptr);
    ~QMenuBarBind() override;
    void setTriggeredCallback(QMenuBar_TriggeredCallback callback) const;
    void setHoveredCallback(QMenuBar_HoveredCallback callback) const;
private:
    QMenuBarHandler* handler;
};

#endif // QMENUBAR_BIND_H
