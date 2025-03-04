#ifndef QSPLITTERHANDLE_HANDLER_H
#define QSPLITTERHANDLE_HANDLER_H

#include <QObject>

class QSplitterHandleHandler : public QObject {
    Q_OBJECT
    typedef void (*QSplitterHandle_MovedCallback)(void*);
    typedef void (*QSplitterHandle_PressedCallback)(void*);
    typedef void (*QSplitterHandle_ReleasedCallback)(void*);
public:
    explicit QSplitterHandleHandler(QObject* parent = nullptr);
    void setMovedCallback(QSplitterHandle_MovedCallback callback);
    void setPressedCallback(QSplitterHandle_PressedCallback callback);
    void setReleasedCallback(QSplitterHandle_ReleasedCallback callback);

public slots:
    void onMoved() const;
    void onPressed() const;
    void onReleased() const;

private:
    QSplitterHandle_MovedCallback movedCallback;
    QSplitterHandle_PressedCallback pressedCallback;
    QSplitterHandle_ReleasedCallback releasedCallback;
};

#endif // QSPLITTERHANDLE_HANDLER_H
