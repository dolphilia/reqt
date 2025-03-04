#ifndef QGRIDLAYOUT_HANDLER_H
#define QGRIDLAYOUT_HANDLER_H

#include <QObject>

class QGridLayoutHandler : public QObject {
    Q_OBJECT
    typedef void (*QGridLayout_CellEmptyChangedCallback)(void*, int, int);
public:
    explicit QGridLayoutHandler(QObject* parent = nullptr);
    void setCellEmptyChangedCallback(QGridLayout_CellEmptyChangedCallback callback);
public slots:
    void onCellEmptyChanged(int row, int column) const;
private:
    QGridLayout_CellEmptyChangedCallback cellEmptyChangedCallback;
};

#endif // QGRIDLAYOUT_HANDLER_H
