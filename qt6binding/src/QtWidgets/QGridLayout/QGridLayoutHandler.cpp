#include "QGridLayoutHandler.h"

GridLayoutHandler::GridLayoutHandler(QObject* parent)
    : QObject(parent)
    , cellEmptyChangedCallback(nullptr) {
}

void GridLayoutHandler::setCellEmptyChangedCallback(CellEmptyChangedCallback callback) {
    cellEmptyChangedCallback = callback;
}

void GridLayoutHandler::onCellEmptyChanged(int row, int column) const {
    if (cellEmptyChangedCallback) {
        cellEmptyChangedCallback(parent(), row, column);
    }
}
