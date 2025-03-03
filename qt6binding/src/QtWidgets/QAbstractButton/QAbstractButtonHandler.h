#ifndef QABSTRACTBUTTON_HANDLER_H
#define QABSTRACTBUTTON_HANDLER_H

#include <QObject>
#include <QAbstractButton>

typedef void (*ClickedCallback)(void* data, bool checked);
typedef void (*PressedCallback)(void* data);
typedef void (*ReleasedCallback)(void* data);
typedef void (*ToggledCallback)(void* data, bool checked);

class QAbstractButtonHandler : public QObject {
    Q_OBJECT
public:
    explicit QAbstractButtonHandler(QAbstractButton* button, QObject* parent = nullptr);

    void setClickedCallback(ClickedCallback callback);
    void setPressedCallback(PressedCallback callback);
    void setReleasedCallback(ReleasedCallback callback);
    void setToggledCallback(ToggledCallback callback);

public slots:
    void onClicked(bool checked) const;
    void onPressed() const;
    void onReleased() const;
    void onToggled(bool checked) const;

private:
    ClickedCallback clickedCallback;
    PressedCallback pressedCallback;
    ReleasedCallback releasedCallback;
    ToggledCallback toggledCallback;
};

#endif // QABSTRACTBUTTON_HANDLER_H
