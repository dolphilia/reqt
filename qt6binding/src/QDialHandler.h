#ifndef DIAL_HANDLER_H
#define DIAL_HANDLER_H

#include <QObject>
#include <QDial>

class DialHandler : public QObject {
    Q_OBJECT
public:
    explicit DialHandler(QObject* parent = nullptr);
    void setDial(QDial* dial);
    void setValueChangedCallback(void (*callback)(void*, int));
    void setSliderMovedCallback(void (*callback)(void*, int));
    void setSliderPressedCallback(void (*callback)(void*));
    void setSliderReleasedCallback(void (*callback)(void*));

public slots:
    void onValueChanged(int value);
    void onSliderMoved(int value);
    void onSliderPressed();
    void onSliderReleased();

private:
    QDial* dial;
    void (*valueChangedCallback)(void*, int);
    void (*sliderMovedCallback)(void*, int);
    void (*sliderPressedCallback)(void*);
    void (*sliderReleasedCallback)(void*);
};

#endif // DIAL_HANDLER_H
