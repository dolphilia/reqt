#ifndef HBOXLAYOUT_HANDLER_H
#define HBOXLAYOUT_HANDLER_H

#include <QObject>

class HBoxLayoutHandler : public QObject {
    Q_OBJECT
public:
    explicit HBoxLayoutHandler(QObject* parent = nullptr);
};

#endif // HBOXLAYOUT_HANDLER_H
