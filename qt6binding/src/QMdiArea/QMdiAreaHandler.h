#ifndef MDIAREA_HANDLER_H
#define MDIAREA_HANDLER_H

#include <QObject>
#include <QMdiArea>
#include <QMdiSubWindow>

typedef void (*SubWindowActivatedCallback)(void*, void*);

class MdiAreaHandler : public QObject {
    Q_OBJECT
public:
    explicit MdiAreaHandler(QObject* parent = nullptr);
    MdiAreaHandler(const MdiAreaHandler&) = delete;
    MdiAreaHandler& operator=(const MdiAreaHandler&) = delete;

    void setMdiArea(QMdiArea* mdiArea);
    void setSubWindowActivatedCallback(SubWindowActivatedCallback callback);

public slots:
    void onSubWindowActivated(QMdiSubWindow* window);

private:
    QMdiArea* mdiArea;
    SubWindowActivatedCallback callback;
};

#endif // MDIAREA_HANDLER_H
