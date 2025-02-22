#ifndef MDIAREA_HANDLER_H
#define MDIAREA_HANDLER_H

#include <QObject>
#include <QMdiArea>
#include <QMdiSubWindow>

class MdiAreaHandler : public QObject {
    Q_OBJECT
public:
    explicit MdiAreaHandler(QObject* parent = nullptr);
    void setMdiArea(QMdiArea* mdiArea);
    void setSubWindowActivatedCallback(void (*callback)(void*, void*));

public slots:
    void onSubWindowActivated(QMdiSubWindow* window);

private:
    QMdiArea* mdiArea;
    void (*callback)(void*, void*);
};

#endif // MDIAREA_HANDLER_H
