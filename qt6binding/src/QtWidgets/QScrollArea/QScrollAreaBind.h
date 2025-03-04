#ifndef QSCROLLAREA_BIND_H
#define QSCROLLAREA_BIND_H

#include "QScrollAreaHandler.h"
#include <QScrollArea>

class QScrollAreaBind : public QScrollArea {
    Q_OBJECT
    typedef void (*QScrollArea_VerticalScrollBarValueChangedCallback)(void*, int);
    typedef void (*QScrollArea_HorizontalScrollBarValueChangedCallback)(void*, int);
public:
    explicit QScrollAreaBind(QWidget* parent = nullptr);
    ~QScrollAreaBind() override;
    void setVerticalScrollBarValueChangedCallback(QScrollArea_VerticalScrollBarValueChangedCallback callback) const;
    void setHorizontalScrollBarValueChangedCallback(QScrollArea_HorizontalScrollBarValueChangedCallback callback) const;
private:
    QScrollAreaHandler* handler;
};

#endif // QSCROLLAREA_BIND_H
