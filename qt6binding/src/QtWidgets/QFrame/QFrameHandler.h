#ifndef FRAME_HANDLER_H
#define FRAME_HANDLER_H

#include <QObject>

class QFrameHandler : public QObject {
    Q_OBJECT
public:
    explicit QFrameHandler(QObject* parent = nullptr);
};

#endif // FRAME_HANDLER_H
