#ifndef DIAL_HANDLER_H
#define DIAL_HANDLER_H

#include <QObject>
#include <QDial>

// コールバック関数の型定義
typedef void (*ValueChangedCallback)(void*, int);
typedef void (*SliderMovedCallback)(void*, int);
typedef void (*SliderPressedCallback)(void*);
typedef void (*SliderReleasedCallback)(void*);

class DialHandler : public QObject {
    Q_OBJECT
public:
    explicit DialHandler(QObject* parent = nullptr);
    DialHandler(const DialHandler&) = delete;
    DialHandler& operator=(const DialHandler&) = delete;

    void setValueChangedCallback(ValueChangedCallback callback);
    void setSliderMovedCallback(SliderMovedCallback callback);
    void setSliderPressedCallback(SliderPressedCallback callback);
    void setSliderReleasedCallback(SliderReleasedCallback callback);

public slots:
    void onValueChanged(int value);
    void onSliderMoved(int position);
    void onSliderPressed();
    void onSliderReleased();

private:
    ValueChangedCallback valueChangedCallback;
    SliderMovedCallback sliderMovedCallback;
    SliderPressedCallback sliderPressedCallback;
    SliderReleasedCallback sliderReleasedCallback;
};

#endif // DIAL_HANDLER_H
