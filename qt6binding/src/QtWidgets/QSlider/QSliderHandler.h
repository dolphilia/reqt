#ifndef QSLIDER_HANDLER_H
#define QSLIDER_HANDLER_H

#include <QObject>

class QSliderHandler : public QObject {
    Q_OBJECT
    typedef void (*QSlider_ValueChangedCallback)(void*, int);
    typedef void (*QSlider_SliderMovedCallback)(void*, int);
    typedef void (*QSlider_SliderPressedCallback)(void*);
    typedef void (*QSlider_SliderReleasedCallback)(void*);
    typedef void (*QSlider_RangeChangedCallback)(void*, int, int);
    typedef void (*QSlider_ActionTriggeredCallback)(void*, int);
public:
    explicit QSliderHandler(QObject* parent = nullptr);
    void setValueChangedCallback(QSlider_ValueChangedCallback callback);
    void setSliderMovedCallback(QSlider_SliderMovedCallback callback);
    void setSliderPressedCallback(QSlider_SliderPressedCallback callback);
    void setSliderReleasedCallback(QSlider_SliderReleasedCallback callback);
    void setRangeChangedCallback(QSlider_RangeChangedCallback callback);
    void setActionTriggeredCallback(QSlider_ActionTriggeredCallback callback);

public slots:
    void onValueChanged(int value) const;
    void onSliderMoved(int position) const;
    void onSliderPressed() const;
    void onSliderReleased() const;
    void onRangeChanged(int min, int max) const;
    void onActionTriggered(int action) const;

private:
    QSlider_ValueChangedCallback valueChangedCallback;
    QSlider_SliderMovedCallback sliderMovedCallback;
    QSlider_SliderPressedCallback sliderPressedCallback;
    QSlider_SliderReleasedCallback sliderReleasedCallback;
    QSlider_RangeChangedCallback rangeChangedCallback;
    QSlider_ActionTriggeredCallback actionTriggeredCallback;
};

#endif // QSLIDER_HANDLER_H
