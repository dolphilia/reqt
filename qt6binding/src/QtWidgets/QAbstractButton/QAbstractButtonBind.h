#ifndef QABSTRACTBUTTON_BIND_H
#define QABSTRACTBUTTON_BIND_H

#include "QAbstractButtonHandler.h"
#include <QAbstractButton>

class QAbstractButtonHandler;

class QAbstractButtonBind : public QAbstractButton {
    Q_OBJECT
    typedef void (*QAbstractButton_ClickedCallback)(void* data, bool checked);
    typedef void (*QAbstractButton_PressedCallback)(void* data);
    typedef void (*QAbstractButton_ReleasedCallback)(void* data);
    typedef void (*QAbstractButton_ToggledCallback)(void* data, bool checked);
public:
    explicit QAbstractButtonBind(QWidget* parent = nullptr);
    ~QAbstractButtonBind() override;
    void setClickedCallback(QAbstractButton_ClickedCallback callback) const;
    void setPressedCallback(QAbstractButton_PressedCallback callback) const;
    void setReleasedCallback(QAbstractButton_ReleasedCallback callback) const;
    void setToggledCallback(QAbstractButton_ToggledCallback callback) const;
protected:
    bool hitButton(const QPoint &pos) const override;
    void paintEvent(QPaintEvent* event) override;
private:
    QAbstractButtonHandler* handler;
};

#endif // QABSTRACTBUTTON_BIND_H
