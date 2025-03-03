#ifndef QABSTRACTBUTTON_BIND_H
#define QABSTRACTBUTTON_BIND_H

#include "QAbstractButtonHandler.h"
#include <QAbstractButton>

class QAbstractButtonHandler;

class QAbstractButtonBind : public QAbstractButton {
    Q_OBJECT
    typedef void (*ClickCallback)(void* data, bool checked);
    typedef void (*PressCallback)(void* data);
    typedef void (*ReleaseCallback)(void* data);
    typedef void (*ToggleCallback)(void* data, bool checked);
public:
    explicit QAbstractButtonBind(QWidget* parent = nullptr);
    ~QAbstractButtonBind() override;
    void setClickedCallback(ClickCallback callback) const;
    void setPressedCallback(PressCallback callback) const;
    void setReleasedCallback(ReleaseCallback callback) const;
    void setToggledCallback(ToggleCallback callback) const;
protected:
    bool hitButton(const QPoint &pos) const override;
    void paintEvent(QPaintEvent* event) override;
private:
    QAbstractButtonHandler* handler;
};

#endif // QABSTRACTBUTTON_BIND_H
