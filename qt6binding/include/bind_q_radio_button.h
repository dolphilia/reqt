#ifndef BIND_Q_RADIO_BUTTON_H
#define BIND_Q_RADIO_BUTTON_H

#include <QRadioButton>
#include "handler_radio_button.h"

class BindQRadioButton : public QRadioButton {
    Q_OBJECT
public:
    explicit BindQRadioButton(QWidget *parent = nullptr);
    explicit BindQRadioButton(const QString &text, QWidget *parent = nullptr);
    ~BindQRadioButton();

    void setRadioButtonHandler(RadioButtonHandler *handler);
    RadioButtonHandler *handler() const;

private:
    RadioButtonHandler *m_handler;
};

#endif // BIND_Q_RADIO_BUTTON_H
