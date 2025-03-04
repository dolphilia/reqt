#include "QTreeViewBind.h"
#include "QTreeViewHandler.h"

QTreeViewBind::QTreeViewBind(QWidget *parent)
    : QTreeView(parent)
    , handler(new QTreeViewHandler(this)) {
    connect(this, &QTreeView::clicked, handler, &QTreeViewHandler::onClicked);
    connect(this, &QTreeView::doubleClicked, handler, &QTreeViewHandler::onDoubleClicked);
    connect(this, &QTreeView::expanded, handler, &QTreeViewHandler::onExpanded);
    connect(this, &QTreeView::collapsed, handler, &QTreeViewHandler::onCollapsed);
    connect(this, &QTreeView::activated, handler, &QTreeViewHandler::onActivated);
    connect(this, &QTreeView::entered, handler, &QTreeViewHandler::onEntered);
    connect(this, &QTreeView::pressed, handler, &QTreeViewHandler::onPressed);
    connect(selectionModel(), &QItemSelectionModel::selectionChanged, handler, &QTreeViewHandler::onSelectionChanged);
}

QTreeViewBind::~QTreeViewBind() {
    delete handler;
}

void QTreeViewBind::setClickedCallback(QTreeView_ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}

void QTreeViewBind::setDoubleClickedCallback(QTreeView_DoubleClickedCallback callback) const {
    handler->setDoubleClickedCallback(callback);
}

void QTreeViewBind::setExpandedCallback(QTreeView_ExpandedCallback callback) const {
    handler->setExpandedCallback(callback);
}

void QTreeViewBind::setCollapsedCallback(QTreeView_CollapsedCallback callback) const {
    handler->setCollapsedCallback(callback);
}

void QTreeViewBind::setActivatedCallback(QTreeView_ActivatedCallback callback) const {
    handler->setActivatedCallback(callback);
}

void QTreeViewBind::setEnteredCallback(QTreeView_EnteredCallback callback) const {
    handler->setEnteredCallback(callback);
}

void QTreeViewBind::setPressedCallback(QTreeView_PressedCallback callback) const {
    handler->setPressedCallback(callback);
}

void QTreeViewBind::setSelectionChangedCallback(QTreeView_SelectionChangedCallback callback) const {
    handler->setSelectionChangedCallback(callback);
}
