#ifndef QSLIDER_BIND_H
#define QSLIDER_BIND_H

#include <QSlider>

#include "QSliderHandler.h"

class QSliderHandler;

class QSliderBind : public QSlider {
    Q_OBJECT
    typedef void (*QSlider_ValueChangedCallback)(void*, int);
    typedef void (*QSlider_SliderMovedCallback)(void*, int);
    typedef void (*QSlider_SliderPressedCallback)(void*);
    typedef void (*QSlider_SliderReleasedCallback)(void*);
    typedef void (*QSlider_RangeChangedCallback)(void*, int, int);
    typedef void (*QSlider_ActionTriggeredCallback)(void*, int);
public:
    explicit QSliderBind(QWidget* parent = nullptr);
    explicit QSliderBind(Qt::Orientation orientation, QWidget* parent = nullptr);
    ~QSliderBind() override;
    
    void setValueChangedCallback(QSlider_ValueChangedCallback callback) const;
    void setSliderMovedCallback(QSlider_SliderMovedCallback callback) const;
    void setSliderPressedCallback(QSlider_SliderPressedCallback callback) const;
    void setSliderReleasedCallback(QSlider_SliderReleasedCallback callback) const;
    void setRangeChangedCallback(QSlider_RangeChangedCallback callback) const;
    void setActionTriggeredCallback(QSlider_ActionTriggeredCallback callback) const;
    
private:
    QSliderHandler* handler;
};

#endif // QSLIDER_BIND_H
