#ifndef HANDLER_SCROLL_AREA_H
#define HANDLER_SCROLL_AREA_H

#include <QObject>

class ScrollAreaHandler : public QObject {
    Q_OBJECT
public:
    explicit ScrollAreaHandler(QObject *parent = nullptr);
    ~ScrollAreaHandler();

    void setVerticalScrollBarValueChangedCallback(void (*callback)(int value));
    void setHorizontalScrollBarValueChangedCallback(void (*callback)(int value));

public slots:
    void onVerticalScrollBarValueChanged(int value);
    void onHorizontalScrollBarValueChanged(int value);

private:
    void (*m_verticalScrollBarValueChangedCallback)(int value);
    void (*m_horizontalScrollBarValueChangedCallback)(int value);
};

#endif // HANDLER_SCROLL_AREA_H
