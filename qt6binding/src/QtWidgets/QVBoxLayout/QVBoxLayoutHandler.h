#ifndef QVBOXLAYOUT_HANDLER_H
#define QVBOXLAYOUT_HANDLER_H

#include <QObject>

class QVBoxLayoutHandler : public QObject {
    Q_OBJECT
public:
    explicit QVBoxLayoutHandler(QObject* parent = nullptr);
    
private:
    // QVBoxLayoutはシグナルを持たないため、コールバック関数は定義しません
};

#endif // QVBOXLAYOUT_HANDLER_H
