#ifndef QSIZEGRIP_HANDLER_H
#define QSIZEGRIP_HANDLER_H

#include <QObject>

class QSizeGripHandler : public QObject {
    Q_OBJECT
public:
    explicit QSizeGripHandler(QObject* parent = nullptr);

public slots:
    // QSizeGripには特定のシグナルがないため、必要に応じて追加できます

private:
    // コールバック関数ポインタがあれば追加
};

#endif // QSIZEGRIP_HANDLER_H
