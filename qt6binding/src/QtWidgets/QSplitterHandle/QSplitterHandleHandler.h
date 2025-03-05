#ifndef QSPLITTERHANDLE_HANDLER_H
#define QSPLITTERHANDLE_HANDLER_H

#include <QObject>
#include <QEvent>
#include <QResizeEvent>

class QSplitterHandleHandler : public QObject {
    Q_OBJECT
    typedef void (*QSplitterHandle_MovedCallback)(void*);
    typedef void (*QSplitterHandle_PressedCallback)(void*);
    typedef void (*QSplitterHandle_ReleasedCallback)(void*);
    typedef bool (*QSplitterHandle_EventCallback)(void*, void*);
    typedef void (*QSplitterHandle_PaintCallback)(void*);
    typedef void (*QSplitterHandle_ResizeCallback)(void*, void*);
public:
    explicit QSplitterHandleHandler(QObject* parent = nullptr);
    void setMovedCallback(QSplitterHandle_MovedCallback callback);
    void setPressedCallback(QSplitterHandle_PressedCallback callback);
    void setReleasedCallback(QSplitterHandle_ReleasedCallback callback);
    void setEventCallback(QSplitterHandle_EventCallback callback);
    void setPaintCallback(QSplitterHandle_PaintCallback callback);
    void setResizeCallback(QSplitterHandle_ResizeCallback callback);

public slots:
    void onMoved() const;
    void onPressed() const;
    void onReleased() const;
    bool onEvent(QEvent* event) const;
    void onPaint() const;
    void onResize(QResizeEvent* event) const;

private:
    QSplitterHandle_MovedCallback movedCallback;
    QSplitterHandle_PressedCallback pressedCallback;
    QSplitterHandle_ReleasedCallback releasedCallback;
    QSplitterHandle_EventCallback eventCallback;
    QSplitterHandle_PaintCallback paintCallback;
    QSplitterHandle_ResizeCallback resizeCallback;
};

#endif // QSPLITTERHANDLE_HANDLER_H
