#ifndef BUTTON_CLICK_HANDLER_H
#define BUTTON_CLICK_HANDLER_H

#include <QObject>

class QButtonClickHandler : public QObject {
    Q_OBJECT
    typedef void (*QPushButton_ClickedCallback)(void*);
    typedef void (*QPushButton_PressedCallback)(void*);
    typedef void (*QPushButton_ReleasedCallback)(void*);
public:
    explicit QButtonClickHandler(QObject* parent = nullptr);
    void setClickedCallback(QPushButton_ClickedCallback callback);
    void setPressedCallback(QPushButton_PressedCallback callback);
    void setReleasedCallback(QPushButton_ReleasedCallback callback);
public slots:
    void onClicked() const;
    void onPressed() const;
    void onReleased() const;
private:
    QPushButton_ClickedCallback clickedCallback;
    QPushButton_PressedCallback pressedCallback;
    QPushButton_ReleasedCallback releasedCallback;
};

#endif // BUTTON_CLICK_HANDLER_H
