#include "QListViewHandler.h"

ListViewHandler::ListViewHandler(QObject* parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , doubleClickedCallback(nullptr)
    , selectionChangedCallback(nullptr) {
}

void ListViewHandler::setClickedCallback(ClickedCallback callback) {
    clickedCallback = callback;
}

void ListViewHandler::setDoubleClickedCallback(DoubleClickedCallback callback) {
    doubleClickedCallback = callback;
}

void ListViewHandler::setSelectionChangedCallback(SelectionChangedCallback callback) {
    selectionChangedCallback = callback;
}

void ListViewHandler::onClicked(const QModelIndex& index) const {
    if (clickedCallback) {
        clickedCallback(parent(), index.row(), index.column());
    }
}

void ListViewHandler::onDoubleClicked(const QModelIndex& index) const {
    if (doubleClickedCallback) {
        doubleClickedCallback(parent(), index.row(), index.column());
    }
}

void ListViewHandler::onSelectionChanged() const {
    if (selectionChangedCallback) {
        selectionChangedCallback(parent());
    }
}
