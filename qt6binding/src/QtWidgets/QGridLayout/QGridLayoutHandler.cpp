#include "QGridLayoutHandler.h"

QGridLayoutHandler::QGridLayoutHandler(QObject* parent)
    : QObject(parent)
    , cellEmptyChangedCallback(nullptr) {
}

void QGridLayoutHandler::setCellEmptyChangedCallback(QGridLayout_CellEmptyChangedCallback callback) {
    cellEmptyChangedCallback = callback;
}

void QGridLayoutHandler::onCellEmptyChanged(int row, int column) const {
    if (cellEmptyChangedCallback) {
        cellEmptyChangedCallback(parent(), row, column);
    }
}
