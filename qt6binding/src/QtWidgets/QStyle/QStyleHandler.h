#ifndef QSTYLE_HANDLER_H
#define QSTYLE_HANDLER_H

#include <QObject>
#include <QStyle>

class QStyleHandler : public QObject {
    Q_OBJECT
public:
    explicit QStyleHandler(QObject* parent = nullptr);
    
    // QStyleはシグナルを持たないため、ハンドラーメソッドは必要ありませんが、
    // 将来的な拡張性のために空のハンドラークラスを用意しています
};

#endif // QSTYLE_HANDLER_H
