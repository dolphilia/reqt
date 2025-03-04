#ifndef DIAL_HANDLER_H
#define DIAL_HANDLER_H

#include <QObject>
#include <QDial>

// コールバック関数の型定義

class QDialHandler : public QObject {
    Q_OBJECT
    typedef void (*QDial_ValueChangedCallback)(void*, int);
    typedef void (*QDial_SliderMovedCallback)(void*, int);
    typedef void (*QDial_SliderPressedCallback)(void*);
    typedef void (*QDial_SliderReleasedCallback)(void*);
public:
    explicit QDialHandler(QObject* parent = nullptr);

    void setValueChangedCallback(QDial_ValueChangedCallback callback);
    void setSliderMovedCallback(QDial_SliderMovedCallback callback);
    void setSliderPressedCallback(QDial_SliderPressedCallback callback);
    void setSliderReleasedCallback(QDial_SliderReleasedCallback callback);

public slots:
    void onValueChanged(int value) const;
    void onSliderMoved(int position) const;
    void onSliderPressed() const;
    void onSliderReleased() const;

private:
    QDial_ValueChangedCallback valueChangedCallback;
    QDial_SliderMovedCallback sliderMovedCallback;
    QDial_SliderPressedCallback sliderPressedCallback;
    QDial_SliderReleasedCallback sliderReleasedCallback;
};

#endif // DIAL_HANDLER_H
