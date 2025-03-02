#ifndef QSPLITTER_BIND_H
#define QSPLITTER_BIND_H

#include <QSplitter>
#include "QSplitterHandler.h"

class QSplitterBind : public QSplitter {
    Q_OBJECT

public:
    explicit QSplitterBind(Qt::Orientation orientation, QWidget* parent = nullptr);
    explicit QSplitterBind(QWidget* parent = nullptr);
    ~QSplitterBind() override;

    void setSplitterMovedCallback(void (*callback)(void*, int, int));

private:
    QSplitterHandler* handler;
};

#endif // QSPLITTER_BIND_H
