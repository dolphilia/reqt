#ifndef QMDIAREA_HANDLER_H
#define QMDIAREA_HANDLER_H

#include <QObject>
#include <QMdiSubWindow>

class QMdiAreaHandler : public QObject {
    Q_OBJECT
    typedef void (*QMdiArea_SubWindowActivatedCallback)(void*, void*);
public:
    explicit QMdiAreaHandler(QObject* parent = nullptr);
    void setSubWindowActivatedCallback(QMdiArea_SubWindowActivatedCallback callback);
public slots:
    void onSubWindowActivated(QMdiSubWindow* window) const;
private:
    QMdiArea_SubWindowActivatedCallback callback;
};

#endif // QMDIAREA_HANDLER_H
