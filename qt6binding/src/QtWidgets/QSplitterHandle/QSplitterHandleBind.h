#ifndef QSPLITTERHANDLE_BIND_H
#define QSPLITTERHANDLE_BIND_H

#include <QSplitterHandle>

#include "QSplitterHandleHandler.h"

class QSplitterHandleHandler;

class QSplitterHandleBind : public QSplitterHandle {
    Q_OBJECT
    typedef void (*QSplitterHandle_MovedCallback)(void*);
    typedef void (*QSplitterHandle_PressedCallback)(void*);
    typedef void (*QSplitterHandle_ReleasedCallback)(void*);
public:
    explicit QSplitterHandleBind(Qt::Orientation orientation, QSplitter* parent = nullptr);
    ~QSplitterHandleBind() override;
    
    // コールバック設定メソッド
    void setMovedCallback(QSplitterHandle_MovedCallback callback) const;
    void setPressedCallback(QSplitterHandle_PressedCallback callback) const;
    void setReleasedCallback(QSplitterHandle_ReleasedCallback callback) const;
    
    // QSplitterHandleの標準メソッド
    bool opaqueResize() const;
    void setOpaqueResize(bool opaque);
    
protected:
    // マウスイベントをオーバーライド
    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    
private:
    QSplitterHandleHandler* handler;
};

#endif // QSPLITTERHANDLE_BIND_H
