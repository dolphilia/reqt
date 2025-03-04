#include "QListViewHandler.h"

QListViewHandler::QListViewHandler(QObject* parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , doubleClickedCallback(nullptr)
    , selectionChangedCallback(nullptr) {
}

void QListViewHandler::setClickedCallback(QListView_ClickedCallback callback) {
    clickedCallback = callback;
}

void QListViewHandler::setDoubleClickedCallback(QListView_DoubleClickedCallback callback) {
    doubleClickedCallback = callback;
}

void QListViewHandler::setSelectionChangedCallback(QListView_SelectionChangedCallback callback) {
    selectionChangedCallback = callback;
}

void QListViewHandler::onClicked(const QModelIndex& index) const {
    if (clickedCallback) {
        clickedCallback(parent(), index.row(), index.column());
    }
}

void QListViewHandler::onDoubleClicked(const QModelIndex& index) const {
    if (doubleClickedCallback) {
        doubleClickedCallback(parent(), index.row(), index.column());
    }
}

void QListViewHandler::onSelectionChanged() const {
    if (selectionChangedCallback) {
        selectionChangedCallback(parent());
    }
}
