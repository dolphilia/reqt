#ifndef QMAINWINDOW_BIND_H
#define QMAINWINDOW_BIND_H

#include <QMainWindow>

class QMainWindowBind : public QMainWindow {
    Q_OBJECT

public:
    explicit QMainWindowBind(QWidget* parent = nullptr);
    ~QMainWindowBind() override;
};

#endif // QMAINWINDOW_BIND_H
