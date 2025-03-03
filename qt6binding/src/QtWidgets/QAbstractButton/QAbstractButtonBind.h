#ifndef QABSTRACTBUTTON_BIND_H
#define QABSTRACTBUTTON_BIND_H

#include "QAbstractButtonHandler.h"
#include <QAbstractButton>

class QAbstractButtonHandler;

class QAbstractButtonBind : public QAbstractButton {
    Q_OBJECT
public:
    explicit QAbstractButtonBind(QWidget* parent = nullptr);
    ~QAbstractButtonBind() override;
    void setClickedCallback(ClickedCallback callback) const;
    void setPressedCallback(PressedCallback callback) const;
    void setReleasedCallback(ReleasedCallback callback) const;
    void setToggledCallback(ToggledCallback callback) const;
protected:
    bool hitButton(const QPoint &pos) const override;
    void paintEvent(QPaintEvent* event) override;
private:
    QAbstractButtonHandler* handler;
};

#endif // QABSTRACTBUTTON_BIND_H
