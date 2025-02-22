#ifndef QDIAL_BIND_H
#define QDIAL_BIND_H

#include <QDial>
#include "handler_dial.h"

class QDialBind : public QDial {
    Q_OBJECT

public:
    explicit QDialBind(QWidget* parent = nullptr);
    ~QDialBind() override;

    void setValueChangedCallback(QDial* dial, void (*callback)(void*, int));
    void setSliderMovedCallback(QDial* dial, void (*callback)(void*, int));
    void setSliderPressedCallback(QDial* dial, void (*callback)(void*));
    void setSliderReleasedCallback(QDial* dial, void (*callback)(void*));

    void setNotchesVisible(bool visible);
    bool notchesVisible() const;
    void setNotchTarget(double target);
    double notchTarget() const;
    void setWrapping(bool on);
    bool wrapping() const;

private:
    DialHandler* handler;
};

#endif // QDIAL_BIND_H
