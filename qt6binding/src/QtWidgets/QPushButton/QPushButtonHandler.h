#ifndef BUTTON_CLICK_HANDLER_H
#define BUTTON_CLICK_HANDLER_H

#include <QObject>

class ButtonClickHandler : public QObject {
    Q_OBJECT
    typedef void (*ClickedCallback)(void*);
    typedef void (*PressedCallback)(void*);
    typedef void (*ReleasedCallback)(void*);
public:
    explicit ButtonClickHandler(QObject* parent = nullptr);
    void setClickedCallback(ClickedCallback callback);
    void setPressedCallback(PressedCallback callback);
    void setReleasedCallback(ReleasedCallback callback);
public slots:
    void onClicked() const;
    void onPressed() const;
    void onReleased() const;
private:
    ClickedCallback clickedCallback;
    PressedCallback pressedCallback;
    ReleasedCallback releasedCallback;
};

#endif // BUTTON_CLICK_HANDLER_H
