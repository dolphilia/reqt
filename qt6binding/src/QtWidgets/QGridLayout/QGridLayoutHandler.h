#ifndef QGRIDLAYOUT_HANDLER_H
#define QGRIDLAYOUT_HANDLER_H

#include <QObject>

class GridLayoutHandler : public QObject {
    Q_OBJECT
    typedef void (*CellEmptyChangedCallback)(void*, int, int);
public:
    explicit GridLayoutHandler(QObject* parent = nullptr);
    void setCellEmptyChangedCallback(CellEmptyChangedCallback callback);
public slots:
    void onCellEmptyChanged(int row, int column) const;
private:
    CellEmptyChangedCallback cellEmptyChangedCallback;
};

#endif // QGRIDLAYOUT_HANDLER_H
