#ifndef QSPLITTER_HANDLER_H
#define QSPLITTER_HANDLER_H

#include <QObject>
#include <QSplitter>

typedef void (*SplitterMovedCallback)(void*, int, int);

class QSplitterHandler : public QObject {
    Q_OBJECT
public:
    explicit QSplitterHandler(QObject* parent = nullptr);
    QSplitterHandler(const QSplitterHandler&) = delete;
    QSplitterHandler& operator=(const QSplitterHandler&) = delete;

    void setSplitter(QSplitter* splitter);
    void setSplitterMovedCallback(SplitterMovedCallback callback);

public slots:
    void onSplitterMoved(int pos, int index);

private:
    QSplitter* splitter;
    SplitterMovedCallback splitterMovedCallback;
};

#endif // QSPLITTER_HANDLER_H
