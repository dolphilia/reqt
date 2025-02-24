#ifndef BIND_Q_SLIDER_H
#define BIND_Q_SLIDER_H

#include <QSlider>
#include "QSliderHandler.h"

class BindQSlider : public QSlider {
    Q_OBJECT
public:
    explicit BindQSlider(QWidget *parent = nullptr);
    explicit BindQSlider(Qt::Orientation orientation, QWidget *parent = nullptr);
    ~BindQSlider();

    void setSliderHandler(SliderHandler *handler);
    SliderHandler *handler() const;

private:
    SliderHandler *m_handler;
};

#endif // BIND_Q_SLIDER_H
