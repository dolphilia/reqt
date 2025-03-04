#include "QListViewBind.h"
#include "QListViewHandler.h"

QListViewBind::QListViewBind(QWidget* parent)
    : QListView(parent)
    , handler(new QListViewHandler(this)) {
    connect(this, &QListView::clicked, handler, &QListViewHandler::onClicked);
    connect(this, &QListView::doubleClicked, handler, &QListViewHandler::onDoubleClicked);
    connect(this->selectionModel(), &QItemSelectionModel::selectionChanged, handler, &QListViewHandler::onSelectionChanged);
}

QListViewBind::~QListViewBind() {
    delete handler;
}

void QListViewBind::setClickedCallback(QListView_ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}

void QListViewBind::setDoubleClickedCallback(QListView_DoubleClickedCallback callback) const {
    handler->setDoubleClickedCallback(callback);
}

void QListViewBind::setSelectionChangedCallback(QListView_SelectionChangedCallback callback) const {
    handler->setSelectionChangedCallback(callback);
}
