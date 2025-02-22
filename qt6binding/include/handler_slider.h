#ifndef HANDLER_SLIDER_H
#define HANDLER_SLIDER_H

#include <QObject>

class SliderHandler : public QObject {
    Q_OBJECT
public:
    explicit SliderHandler(QObject *parent = nullptr);
    ~SliderHandler();

    void setValueChangedCallback(void (*callback)(int value));
    void setSliderMovedCallback(void (*callback)(int position));
    void setSliderPressedCallback(void (*callback)());
    void setSliderReleasedCallback(void (*callback)());
    void setRangeChangedCallback(void (*callback)(int min, int max));
    void setActionTriggeredCallback(void (*callback)(int action));

public slots:
    void onValueChanged(int value);
    void onSliderMoved(int position);
    void onSliderPressed();
    void onSliderReleased();
    void onRangeChanged(int min, int max);
    void onActionTriggered(int action);

private:
    void (*m_valueChangedCallback)(int value);
    void (*m_sliderMovedCallback)(int position);
    void (*m_sliderPressedCallback)();
    void (*m_sliderReleasedCallback)();
    void (*m_rangeChangedCallback)(int min, int max);
    void (*m_actionTriggeredCallback)(int action);
};

#endif // HANDLER_SLIDER_H
