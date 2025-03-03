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
    void setValueChangedCallback(ValueChangedCallback callback) const;
    void setSliderMovedCallback(SliderMovedCallback callback) const;
    void setSliderPressedCallback(SliderPressedCallback callback) const;
    void setSliderReleasedCallback(SliderReleasedCallback callback) const;

private:
    DialHandler* handler;
};

#endif // QDIAL_BIND_H
