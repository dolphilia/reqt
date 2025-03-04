#ifndef MENUBAR_HANDLER_H
#define MENUBAR_HANDLER_H

#include <QObject>
#include <QAction>

class QMenuBarHandler : public QObject {
    Q_OBJECT
    typedef void (*QMenuBar_TriggeredCallback)(void*, void*);
    typedef void (*QMenuBar_HoveredCallback)(void*, void*);
public:
    explicit QMenuBarHandler(QObject* parent = nullptr);
    void setTriggeredCallback(QMenuBar_TriggeredCallback callback);
    void setHoveredCallback(QMenuBar_HoveredCallback callback);
public slots:
    void onTriggered(QAction* action) const;
    void onHovered(QAction* action) const;
private:
    QMenuBar_TriggeredCallback triggeredCallback;
    QMenuBar_HoveredCallback hoveredCallback;
};

#endif // MENUBAR_HANDLER_H
