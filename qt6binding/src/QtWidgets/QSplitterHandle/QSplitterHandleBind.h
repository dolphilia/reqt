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
    typedef bool (*QSplitterHandle_EventCallback)(void*, void*);
    typedef void (*QSplitterHandle_PaintCallback)(void*);
    typedef void (*QSplitterHandle_ResizeCallback)(void*, void*);
public:
    explicit QSplitterHandleBind(Qt::Orientation orientation, QSplitter* parent = nullptr);
    ~QSplitterHandleBind() override;
    // Reimplemented Public Functions
    QSize sizeHint() const override;
    // Protected Functions
    int closestLegalPosition(int pos);
    void moveSplitter(int pos);
    // Callback
    void setMovedCallback(QSplitterHandle_MovedCallback callback) const;
    void setPressedCallback(QSplitterHandle_PressedCallback callback) const;
    void setReleasedCallback(QSplitterHandle_ReleasedCallback callback) const;
    void setEventCallback(QSplitterHandle_EventCallback callback) const;
    void setPaintCallback(QSplitterHandle_PaintCallback callback) const;
    void setResizeCallback(QSplitterHandle_ResizeCallback callback) const;
protected:
    // Reimplemented Protected Functions
    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    bool event(QEvent *event) override;
    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;
    
private:
    QSplitterHandleHandler* handler;
};

#endif // QSPLITTERHANDLE_BIND_H
