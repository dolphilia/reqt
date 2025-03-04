#ifndef QRADIOBUTTON_BIND_H
#define QRADIOBUTTON_BIND_H

#include "QRadioButtonHandler.h"
#include <QRadioButton>

class QRadioButtonBind : public QRadioButton {
    Q_OBJECT
    typedef void (*QRadioButton_ToggledCallback)(void*, bool);
    typedef void (*QRadioButton_ClickedCallback)(void*, bool);
    typedef void (*QRadioButton_PressedCallback)(void*);
    typedef void (*QRadioButton_ReleasedCallback)(void*);
public:
    explicit QRadioButtonBind(QWidget* parent = nullptr);
    explicit QRadioButtonBind(const QString& text, QWidget* parent = nullptr);
    ~QRadioButtonBind() override;
    void setToggledCallback(QRadioButton_ToggledCallback callback) const;
    void setClickedCallback(QRadioButton_ClickedCallback callback) const;
    void setPressedCallback(QRadioButton_PressedCallback callback) const;
    void setReleasedCallback(QRadioButton_ReleasedCallback callback) const;
private:
    QRadioButtonHandler* handler;
};

#endif // QRADIOBUTTON_BIND_H
