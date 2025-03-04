#include "QTreeViewHandler.h"

QTreeViewHandler::QTreeViewHandler(QObject *parent)
    : QObject(parent)
    , clickedCallback(nullptr)
    , doubleClickedCallback(nullptr)
    , expandedCallback(nullptr)
    , collapsedCallback(nullptr)
    , activatedCallback(nullptr)
    , enteredCallback(nullptr)
    , pressedCallback(nullptr)
    , selectionChangedCallback(nullptr) {
}

QTreeViewHandler::~QTreeViewHandler() {
}

void QTreeViewHandler::setClickedCallback(QTreeView_ClickedCallback callback) {
    clickedCallback = callback;
}

void QTreeViewHandler::setDoubleClickedCallback(QTreeView_DoubleClickedCallback callback) {
    doubleClickedCallback = callback;
}

void QTreeViewHandler::setExpandedCallback(QTreeView_ExpandedCallback callback) {
    expandedCallback = callback;
}

void QTreeViewHandler::setCollapsedCallback(QTreeView_CollapsedCallback callback) {
    collapsedCallback = callback;
}

void QTreeViewHandler::setActivatedCallback(QTreeView_ActivatedCallback callback) {
    activatedCallback = callback;
}

void QTreeViewHandler::setEnteredCallback(QTreeView_EnteredCallback callback) {
    enteredCallback = callback;
}

void QTreeViewHandler::setPressedCallback(QTreeView_PressedCallback callback) {
    pressedCallback = callback;
}

void QTreeViewHandler::setSelectionChangedCallback(QTreeView_SelectionChangedCallback callback) {
    selectionChangedCallback = callback;
}

void QTreeViewHandler::onClicked(const QModelIndex &index) const {
    if (clickedCallback) {
        clickedCallback(parent(), (void*)&index);
    }
}

void QTreeViewHandler::onDoubleClicked(const QModelIndex &index) const {
    if (doubleClickedCallback) {
        doubleClickedCallback(parent(), (void*)&index);
    }
}

void QTreeViewHandler::onExpanded(const QModelIndex &index) const {
    if (expandedCallback) {
        expandedCallback(parent(), (void*)&index);
    }
}

void QTreeViewHandler::onCollapsed(const QModelIndex &index) const {
    if (collapsedCallback) {
        collapsedCallback(parent(), (void*)&index);
    }
}

void QTreeViewHandler::onActivated(const QModelIndex &index) const {
    if (activatedCallback) {
        activatedCallback(parent(), (void*)&index);
    }
}

void QTreeViewHandler::onEntered(const QModelIndex &index) const {
    if (enteredCallback) {
        enteredCallback(parent(), (void*)&index);
    }
}

void QTreeViewHandler::onPressed(const QModelIndex &index) const {
    if (pressedCallback) {
        pressedCallback(parent(), (void*)&index);
    }
}

void QTreeViewHandler::onSelectionChanged() const {
    if (selectionChangedCallback) {
        selectionChangedCallback(parent());
    }
}
