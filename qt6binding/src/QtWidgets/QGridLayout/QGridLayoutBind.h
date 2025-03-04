#ifndef QGRIDLAYOUT_BIND_H
#define QGRIDLAYOUT_BIND_H

#include "QGridLayoutHandler.h"
#include <QGridLayout>
#include <QWidget>

class QGridLayoutBind : public QGridLayout {
    Q_OBJECT
    typedef void (*QGridLayout_CellEmptyChangedCallback)(void*, int, int);
public:
    explicit QGridLayoutBind(QWidget* parent = nullptr);
    ~QGridLayoutBind() override;
    void addWidgetToGrid(QWidget* widget, int row, int column);
    void setCellEmptyChangedCallback(QGridLayout_CellEmptyChangedCallback callback) const;
private:
    QGridLayoutHandler* handler;
};

#endif // QGRIDLAYOUT_BIND_H
