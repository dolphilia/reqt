#include "QListViewBind.h"
#include "QListViewHandler.h"

QListViewBind::QListViewBind(QWidget* parent)
    : QListView(parent)
    , handler(new ListViewHandler(this)) {
    connect(this, &QListView::clicked, handler, &ListViewHandler::onClicked);
    connect(this, &QListView::doubleClicked, handler, &ListViewHandler::onDoubleClicked);
    connect(this->selectionModel(), &QItemSelectionModel::selectionChanged, handler, &ListViewHandler::onSelectionChanged);
}

QListViewBind::~QListViewBind() {
    delete handler;
}

void QListViewBind::setClickedCallback(ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}

void QListViewBind::setDoubleClickedCallback(DoubleClickedCallback callback) const {
    handler->setDoubleClickedCallback(callback);
}

void QListViewBind::setSelectionChangedCallback(SelectionChangedCallback callback) const {
    handler->setSelectionChangedCallback(callback);
}
