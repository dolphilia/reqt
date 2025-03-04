#ifndef QSCROLLBAR_BIND_H
#define QSCROLLBAR_BIND_H

#include <QScrollBar>

#include "QScrollBarHandler.h"

class QScrollBarHandler;

class QScrollBarBind : public QScrollBar {
    Q_OBJECT
    typedef void (*QScrollBar_ValueChangedCallback)(void*, int);
    typedef void (*QScrollBar_SliderMovedCallback)(void*, int);
    typedef void (*QScrollBar_SliderPressedCallback)(void*);
    typedef void (*QScrollBar_SliderReleasedCallback)(void*);
    typedef void (*QScrollBar_RangeChangedCallback)(void*, int, int);
    typedef void (*QScrollBar_ActionTriggeredCallback)(void*, int);
public:
    explicit QScrollBarBind(QWidget* parent = nullptr);
    explicit QScrollBarBind(Qt::Orientation orientation, QWidget* parent = nullptr);
    ~QScrollBarBind() override;
    void setValueChangedCallback(QScrollBar_ValueChangedCallback callback) const;
    void setSliderMovedCallback(QScrollBar_SliderMovedCallback callback) const;
    void setSliderPressedCallback(QScrollBar_SliderPressedCallback callback) const;
    void setSliderReleasedCallback(QScrollBar_SliderReleasedCallback callback) const;
    void setRangeChangedCallback(QScrollBar_RangeChangedCallback callback) const;
    void setActionTriggeredCallback(QScrollBar_ActionTriggeredCallback callback) const;
private:
    QScrollBarHandler* handler;
};

#endif // QSCROLLBAR_BIND_H
