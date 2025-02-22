#ifndef BUTTON_CLICK_HANDLER_H
#define BUTTON_CLICK_HANDLER_H

#include <QObject>

class ButtonClickHandler : public QObject {
    Q_OBJECT
public:
    explicit ButtonClickHandler(void (*callback)(void*) = nullptr);
    ~ButtonClickHandler() override;

public slots:
    void onClick();

private:
    void (*callback)(void*);
};

#endif // BUTTON_CLICK_HANDLER_H
