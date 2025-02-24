#ifndef QDIAL_BIND_H
#define QDIAL_BIND_H

#include <QDial>
#include "QDialHandler.h"

class QDialBind : public QDial {
    Q_OBJECT

public:
    explicit QDialBind(QWidget* parent = nullptr);
    ~QDialBind() override;

    // コールバック設定
    void setValueChangedCallback(ValueChangedCallback callback);
    void setSliderMovedCallback(SliderMovedCallback callback);
    void setSliderPressedCallback(SliderPressedCallback callback);
    void setSliderReleasedCallback(SliderReleasedCallback callback);

    // プロパティ設定
    using QDial::setMinimum;
    using QDial::setMaximum;
    using QDial::setRange;
    using QDial::setValue;
    using QDial::setSingleStep;
    using QDial::setPageStep;
    using QDial::setNotchTarget;
    using QDial::setNotchesVisible;
    using QDial::setWrapping;

    // プロパティ取得
    using QDial::minimum;
    using QDial::maximum;
    using QDial::value;
    using QDial::singleStep;
    using QDial::pageStep;
    using QDial::notchTarget;
    using QDial::notchesVisible;
    using QDial::wrapping;

private:
    DialHandler* handler;
};

#endif // QDIAL_BIND_H
