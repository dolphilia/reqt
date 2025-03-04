#ifndef SCROLLAREA_HANDLER_H
#define SCROLLAREA_HANDLER_H

#include <QObject>

class QScrollAreaHandler : public QObject {
    Q_OBJECT
    typedef void (*QScrollArea_VerticalScrollBarValueChangedCallback)(void*, int);
    typedef void (*QScrollArea_HorizontalScrollBarValueChangedCallback)(void*, int);
public:
    explicit QScrollAreaHandler(QObject* parent = nullptr);
    void setVerticalScrollCallback(QScrollArea_VerticalScrollBarValueChangedCallback callback);
    void setHorizontalScrollCallback(QScrollArea_HorizontalScrollBarValueChangedCallback callback);
public slots:
    void onVerticalScrollBarValueChanged(int value) const;
    void onHorizontalScrollBarValueChanged(int value) const;
private:
    QScrollArea_VerticalScrollBarValueChangedCallback verticalCallback;
    QScrollArea_HorizontalScrollBarValueChangedCallback horizontalCallback;
};

#endif // SCROLLAREA_HANDLER_H
