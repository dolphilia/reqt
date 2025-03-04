#ifndef QDIAL_BIND_H
#define QDIAL_BIND_H

#include <QDial>
#include "QDialHandler.h"

class QDialBind : public QDial {
    Q_OBJECT
    typedef void (*QDial_ValueChangedCallback)(void*, int);
    typedef void (*QDial_SliderMovedCallback)(void*, int);
    typedef void (*QDial_SliderPressedCallback)(void*);
    typedef void (*QDial_SliderReleasedCallback)(void*);
public:
    explicit QDialBind(QWidget* parent = nullptr);
    ~QDialBind() override;

    // コールバック設定
    void setValueChangedCallback(QDial_ValueChangedCallback callback) const;
    void setSliderMovedCallback(QDial_SliderMovedCallback callback) const;
    void setSliderPressedCallback(QDial_SliderPressedCallback callback) const;
    void setSliderReleasedCallback(QDial_SliderReleasedCallback callback) const;

private:
    QDialHandler* handler;
};

#endif // QDIAL_BIND_H
