#ifndef QSPLITTERHANDLE_HANDLER_H
#define QSPLITTERHANDLE_HANDLER_H

#include <QObject>
#include <QSplitterHandle>
#include <QEvent>

typedef void (*SplitterHandleDoubleClickedCallback)(void*);
typedef void (*SplitterHandleMovedCallback)(void*, int);

class QSplitterHandleHandler : public QObject {
    Q_OBJECT
public:
    explicit QSplitterHandleHandler(QObject* parent = nullptr);
    QSplitterHandleHandler(const QSplitterHandleHandler&) = delete;
    QSplitterHandleHandler& operator=(const QSplitterHandleHandler&) = delete;

    void setSplitterHandle(QSplitterHandle* handle);
    void setDoubleClickedCallback(SplitterHandleDoubleClickedCallback callback);
    void setMovedCallback(SplitterHandleMovedCallback callback);

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

private:
    QSplitterHandle* handle;
    SplitterHandleDoubleClickedCallback doubleClickedCallback;
    SplitterHandleMovedCallback movedCallback;
};

#endif // QSPLITTERHANDLE_HANDLER_H
