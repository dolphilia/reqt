#ifndef QABSTRACTBUTTON_HANDLER_H
#define QABSTRACTBUTTON_HANDLER_H

#include <QObject>
#include <QAbstractButton>

class QAbstractButtonHandler : public QObject {
    Q_OBJECT
    typedef void (*ClickCallback)(void* data, bool checked);
    typedef void (*PressCallback)(void* data);
    typedef void (*ReleaseCallback)(void* data);
    typedef void (*ToggleCallback)(void* data, bool checked);
public:
    explicit QAbstractButtonHandler(QObject* parent = nullptr);

    void setClickedCallback(ClickCallback callback);
    void setPressedCallback(PressCallback callback);
    void setReleasedCallback(ReleaseCallback callback);
    void setToggledCallback(ToggleCallback callback);

public slots:
    void onClicked(bool checked) const;
    void onPressed() const;
    void onReleased() const;
    void onToggled(bool checked) const;

private:
    ClickCallback clickedCallback;
    PressCallback pressedCallback;
    ReleaseCallback releasedCallback;
    ToggleCallback toggledCallback;
};

#endif // QABSTRACTBUTTON_HANDLER_H
