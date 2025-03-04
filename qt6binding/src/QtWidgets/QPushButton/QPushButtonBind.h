#ifndef QPUSHBUTTON_BIND_H
#define QPUSHBUTTON_BIND_H

#include "QPushButtonHandler.h"
#include <QPushButton>

class QPushButtonBind : public QPushButton {
    Q_OBJECT
    typedef void (*ClickedCallback)(void*);
    typedef void (*PressedCallback)(void*);
    typedef void (*ReleasedCallback)(void*);
public:
    explicit QPushButtonBind(const char* text = nullptr, QWidget* parent = nullptr);
    ~QPushButtonBind() override;
    void setClickedCallback(ClickedCallback callback) const;
    void setPressedCallback(PressedCallback callback) const;
    void setReleasedCallback(ReleasedCallback callback) const;
private:
    ButtonClickHandler* handler;
};

#endif // QPUSHBUTTON_BIND_H
