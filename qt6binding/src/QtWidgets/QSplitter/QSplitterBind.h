#ifndef QSPLITTER_BIND_H
#define QSPLITTER_BIND_H

#include <QSplitter>
#include "QSplitterHandler.h"

class QSplitterHandler;

class QSplitterBind : public QSplitter {
    Q_OBJECT
    typedef void (*QSplitter_SplitterMovedCallback)(void*, int, int);
public:
    explicit QSplitterBind(Qt::Orientation orientation, QWidget* parent = nullptr);
    explicit QSplitterBind(QWidget* parent = nullptr);
    ~QSplitterBind() override;

    void setSplitterMovedCallback(QSplitter_SplitterMovedCallback callback) const;

private:
    QSplitterHandler* handler;
};

#endif // QSPLITTER_BIND_H
