#ifndef QTOOLBOX_HANDLER_H
#define QTOOLBOX_HANDLER_H

#include <QObject>

class QToolBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*QToolBox_CurrentChangedCallback)(void*, int);
public:
    explicit QToolBoxHandler(QObject* parent = nullptr);
    ~QToolBoxHandler();

    void setCurrentChangedCallback(QToolBox_CurrentChangedCallback callback);

public slots:
    void onCurrentChanged(int index) const;

private:
    QToolBox_CurrentChangedCallback currentChangedCallback;
};

#endif // QTOOLBOX_HANDLER_H
