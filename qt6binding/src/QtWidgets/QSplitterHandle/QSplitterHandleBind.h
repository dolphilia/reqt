#ifndef QSPLITTERHANDLE_BIND_H
#define QSPLITTERHANDLE_BIND_H

#include <QSplitterHandle>
#include "QSplitterHandleHandler.h"

class QSplitterHandleBind : public QSplitterHandle {
    Q_OBJECT

public:
    explicit QSplitterHandleBind(Qt::Orientation orientation, QSplitter* parent);
    ~QSplitterHandleBind() override;

    void setDoubleClickedCallback(void (*callback)(void*));
    void setMovedCallback(void (*callback)(void*, int));
    
    // Make protected methods public
    using QSplitterHandle::moveSplitter;
    using QSplitterHandle::closestLegalPosition;
    
    // Add missing method
    void setOpaqueResize(bool opaque) {
        splitter()->setOpaqueResize(opaque);
    }

private:
    QSplitterHandleHandler* handler;
};

#endif // QSPLITTERHANDLE_BIND_H
