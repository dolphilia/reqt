#ifndef QABSTRACTBUTTON_HANDLER_H
#define QABSTRACTBUTTON_HANDLER_H

#include <QObject>
#include <QAbstractButton>

class QAbstractButtonHandler : public QObject {
    Q_OBJECT
    typedef void (*QAbstractButton_ClickedCallback)(void* data, bool checked);
    typedef void (*QAbstractButton_PressedCallback)(void* data);
    typedef void (*QAbstractButton_ReleasedCallback)(void* data);
    typedef void (*QAbstractButton_ToggledCallback)(void* data, bool checked);
public:
    explicit QAbstractButtonHandler(QObject* parent = nullptr);

    void setClickedCallback(QAbstractButton_ClickedCallback callback);
    void setPressedCallback(QAbstractButton_PressedCallback callback);
    void setReleasedCallback(QAbstractButton_ReleasedCallback callback);
    void setToggledCallback(QAbstractButton_ToggledCallback callback);

public slots:
    void onClicked(bool checked) const;
    void onPressed() const;
    void onReleased() const;
    void onToggled(bool checked) const;

private:
    QAbstractButton_ClickedCallback clickedCallback;
    QAbstractButton_PressedCallback pressedCallback;
    QAbstractButton_ReleasedCallback releasedCallback;
    QAbstractButton_ToggledCallback toggledCallback;
};

#endif // QABSTRACTBUTTON_HANDLER_H
