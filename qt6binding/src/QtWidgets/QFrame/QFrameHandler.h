#ifndef FRAME_HANDLER_H
#define FRAME_HANDLER_H

#include <QObject>

class FrameHandler : public QObject {
    Q_OBJECT
public:
    explicit FrameHandler(QObject* parent = nullptr);
};

#endif // FRAME_HANDLER_H
