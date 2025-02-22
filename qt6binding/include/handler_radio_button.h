#ifndef HANDLER_RADIO_BUTTON_H
#define HANDLER_RADIO_BUTTON_H

#include <QObject>

class RadioButtonHandler : public QObject {
    Q_OBJECT
public:
    explicit RadioButtonHandler(QObject *parent = nullptr);
    ~RadioButtonHandler();

    void setToggledCallback(void (*callback)(bool checked));
    void setClickedCallback(void (*callback)(bool checked));
    void setPressedCallback(void (*callback)());
    void setReleasedCallback(void (*callback)());

public slots:
    void onToggled(bool checked);
    void onClicked(bool checked);
    void onPressed();
    void onReleased();

private:
    void (*m_toggledCallback)(bool checked);
    void (*m_clickedCallback)(bool checked);
    void (*m_pressedCallback)();
    void (*m_releasedCallback)();
};

#endif // HANDLER_RADIO_BUTTON_H
