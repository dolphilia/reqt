#ifndef RADIOBUTTON_HANDLER_H
#define RADIOBUTTON_HANDLER_H

#include <QObject>

class QRadioButtonHandler : public QObject {
    Q_OBJECT
    typedef void (*QRadioButton_ToggledCallback)(void*, bool);
    typedef void (*QRadioButton_ClickedCallback)(void*, bool);
    typedef void (*QRadioButton_PressedCallback)(void*);
    typedef void (*QRadioButton_ReleasedCallback)(void*);
public:
    explicit QRadioButtonHandler(QObject* parent = nullptr);
    void setToggledCallback(QRadioButton_ToggledCallback callback);
    void setClickedCallback(QRadioButton_ClickedCallback callback);
    void setPressedCallback(QRadioButton_PressedCallback callback);
    void setReleasedCallback(QRadioButton_ReleasedCallback callback);
public slots:
    void onToggled(bool checked) const;
    void onClicked(bool checked) const;
    void onPressed() const;
    void onReleased() const;
private:
    QRadioButton_ToggledCallback toggledCallback;
    QRadioButton_ClickedCallback clickedCallback;
    QRadioButton_PressedCallback pressedCallback;
    QRadioButton_ReleasedCallback releasedCallback;
};

#endif // RADIOBUTTON_HANDLER_H
