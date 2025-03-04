#ifndef QSCROLLBAR_HANDLER_H
#define QSCROLLBAR_HANDLER_H

#include <QObject>

class QScrollBarHandler : public QObject {
    Q_OBJECT
    typedef void (*QScrollBar_ValueChangedCallback)(void*, int);
    typedef void (*QScrollBar_SliderMovedCallback)(void*, int);
    typedef void (*QScrollBar_SliderPressedCallback)(void*);
    typedef void (*QScrollBar_SliderReleasedCallback)(void*);
    typedef void (*QScrollBar_RangeChangedCallback)(void*, int, int);
    typedef void (*QScrollBar_ActionTriggeredCallback)(void*, int);
public:
    explicit QScrollBarHandler(QObject* parent = nullptr);
    void setValueChangedCallback(QScrollBar_ValueChangedCallback callback);
    void setSliderMovedCallback(QScrollBar_SliderMovedCallback callback);
    void setSliderPressedCallback(QScrollBar_SliderPressedCallback callback);
    void setSliderReleasedCallback(QScrollBar_SliderReleasedCallback callback);
    void setRangeChangedCallback(QScrollBar_RangeChangedCallback callback);
    void setActionTriggeredCallback(QScrollBar_ActionTriggeredCallback callback);

public slots:
    void onValueChanged(int value) const;
    void onSliderMoved(int position) const;
    void onSliderPressed() const;
    void onSliderReleased() const;
    void onRangeChanged(int min, int max) const;
    void onActionTriggered(int action) const;

private:
    QScrollBar_ValueChangedCallback valueChangedCallback;
    QScrollBar_SliderMovedCallback sliderMovedCallback;
    QScrollBar_SliderPressedCallback sliderPressedCallback;
    QScrollBar_SliderReleasedCallback sliderReleasedCallback;
    QScrollBar_RangeChangedCallback rangeChangedCallback;
    QScrollBar_ActionTriggeredCallback actionTriggeredCallback;
};

#endif // QSCROLLBAR_HANDLER_H
