#ifndef BIND_Q_GRID_LAYOUT_H
#define BIND_Q_GRID_LAYOUT_H

#include <QGridLayout>
#include <QWidget>

class BindQGridLayout : public QGridLayout {
    Q_OBJECT
public:
    BindQGridLayout();
    void addWidgetToGrid(QWidget* widget, int row, int column);
};

#endif // BIND_Q_GRID_LAYOUT_H
