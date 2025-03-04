#ifndef HBOXLAYOUT_HANDLER_H
#define HBOXLAYOUT_HANDLER_H

#include <QObject>

class QHBoxLayoutHandler : public QObject {
    Q_OBJECT
public:
    explicit QHBoxLayoutHandler(QObject* parent = nullptr);
};

#endif // HBOXLAYOUT_HANDLER_H
