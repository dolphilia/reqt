#ifndef QSPLITTER_HANDLER_H
#define QSPLITTER_HANDLER_H

#include <QObject>

class QSplitterHandler : public QObject {
    Q_OBJECT
    typedef void (*QSplitter_SplitterMovedCallback)(void*, int, int);
public:
    explicit QSplitterHandler(QObject* parent = nullptr);

    void setSplitterMovedCallback(QSplitter_SplitterMovedCallback callback);

public slots:
    void onSplitterMoved(int pos, int index) const;

private:
    QSplitter_SplitterMovedCallback splitterMovedCallback;
};

#endif // QSPLITTER_HANDLER_H
