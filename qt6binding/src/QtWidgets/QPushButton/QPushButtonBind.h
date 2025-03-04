#ifndef QPUSHBUTTON_BIND_H
#define QPUSHBUTTON_BIND_H

#include "QPushButtonHandler.h"
#include <QPushButton>

class QPushButtonBind : public QPushButton {
    Q_OBJECT
    typedef void (*QPushButton_ClickedCallback)(void*);
    typedef void (*QPushButton_PressedCallback)(void*);
    typedef void (*QPushButton_ReleasedCallback)(void*);
public:
    explicit QPushButtonBind(const char* text = nullptr, QWidget* parent = nullptr);
    ~QPushButtonBind() override;
    void setClickedCallback(QPushButton_ClickedCallback callback) const;
    void setPressedCallback(QPushButton_PressedCallback callback) const;
    void setReleasedCallback(QPushButton_ReleasedCallback callback) const;
private:
    QButtonClickHandler* handler;
};

#endif // QPUSHBUTTON_BIND_H
