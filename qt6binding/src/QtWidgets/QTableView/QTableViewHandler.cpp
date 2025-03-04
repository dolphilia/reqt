#include "QTableViewHandler.h"

QTableViewHandler::QTableViewHandler(QObject* parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , doubleClickedCallback(nullptr)
    , activatedCallback(nullptr)
    , enteredCallback(nullptr)
    , pressedCallback(nullptr)
    , selectionChangedCallback(nullptr)
    , horizontalHeaderClickedCallback(nullptr)
    , verticalHeaderClickedCallback(nullptr) {
}

void QTableViewHandler::setClickedCallback(QTableView_ClickedCallback callback) {
    clickedCallback = callback;
}

void QTableViewHandler::setDoubleClickedCallback(QTableView_DoubleClickedCallback callback) {
    doubleClickedCallback = callback;
}

void QTableViewHandler::setActivatedCallback(QTableView_ActivatedCallback callback) {
    activatedCallback = callback;
}

void QTableViewHandler::setEnteredCallback(QTableView_EnteredCallback callback) {
    enteredCallback = callback;
}

void QTableViewHandler::setPressedCallback(QTableView_PressedCallback callback) {
    pressedCallback = callback;
}

void QTableViewHandler::setSelectionChangedCallback(QTableView_SelectionChangedCallback callback) {
    selectionChangedCallback = callback;
}

void QTableViewHandler::setHorizontalHeaderClickedCallback(QTableView_HorizontalHeaderClickedCallback callback) {
    horizontalHeaderClickedCallback = callback;
}

void QTableViewHandler::setVerticalHeaderClickedCallback(QTableView_VerticalHeaderClickedCallback callback) {
    verticalHeaderClickedCallback = callback;
}

void QTableViewHandler::onClicked(const QModelIndex &index) const {
    if (clickedCallback) {
        clickedCallback(parent(), (void*)&index);
    }
}

void QTableViewHandler::onDoubleClicked(const QModelIndex &index) const {
    if (doubleClickedCallback) {
        doubleClickedCallback(parent(), (void*)&index);
    }
}

void QTableViewHandler::onActivated(const QModelIndex &index) const {
    if (activatedCallback) {
        activatedCallback(parent(), (void*)&index);
    }
}

void QTableViewHandler::onEntered(const QModelIndex &index) const {
    if (enteredCallback) {
        enteredCallback(parent(), (void*)&index);
    }
}

void QTableViewHandler::onPressed(const QModelIndex &index) const {
    if (pressedCallback) {
        pressedCallback(parent(), (void*)&index);
    }
}

void QTableViewHandler::onSelectionChanged() const {
    if (selectionChangedCallback) {
        selectionChangedCallback(parent());
    }
}

void QTableViewHandler::onHorizontalHeaderClicked(int section) const {
    if (horizontalHeaderClickedCallback) {
        horizontalHeaderClickedCallback(parent(), section);
    }
}

void QTableViewHandler::onVerticalHeaderClicked(int section) const {
    if (verticalHeaderClickedCallback) {
        verticalHeaderClickedCallback(parent(), section);
    }
}
