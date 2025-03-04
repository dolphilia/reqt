#include "QTableViewBind.h"
#include "QTableViewHandler.h"
#include <QHeaderView>

QTableViewBind::QTableViewBind(QWidget* parent)
    : QTableView(parent)
    , handler(new QTableViewHandler(this)) {
    connect(this, &QTableView::clicked, handler, &QTableViewHandler::onClicked);
    connect(this, &QTableView::doubleClicked, handler, &QTableViewHandler::onDoubleClicked);
    connect(this, &QTableView::activated, handler, &QTableViewHandler::onActivated);
    connect(this, &QTableView::entered, handler, &QTableViewHandler::onEntered);
    connect(this, &QTableView::pressed, handler, &QTableViewHandler::onPressed);
    if (selectionModel()) {
        connect(selectionModel(), &QItemSelectionModel::selectionChanged, handler, &QTableViewHandler::onSelectionChanged);
    }
    connect(horizontalHeader(), &QHeaderView::sectionClicked, handler, &QTableViewHandler::onHorizontalHeaderClicked);
    connect(verticalHeader(), &QHeaderView::sectionClicked, handler, &QTableViewHandler::onVerticalHeaderClicked);
}

QTableViewBind::~QTableViewBind() {
    delete handler;
}

void QTableViewBind::setClickedCallback(QTableView_ClickedCallback callback) const {
    handler->setClickedCallback(callback);
}

void QTableViewBind::setDoubleClickedCallback(QTableView_DoubleClickedCallback callback) const {
    handler->setDoubleClickedCallback(callback);
}

void QTableViewBind::setActivatedCallback(QTableView_ActivatedCallback callback) const {
    handler->setActivatedCallback(callback);
}

void QTableViewBind::setEnteredCallback(QTableView_EnteredCallback callback) const {
    handler->setEnteredCallback(callback);
}

void QTableViewBind::setPressedCallback(QTableView_PressedCallback callback) const {
    handler->setPressedCallback(callback);
}

void QTableViewBind::setSelectionChangedCallback(QTableView_SelectionChangedCallback callback) const {
    handler->setSelectionChangedCallback(callback);
}

void QTableViewBind::setHorizontalHeaderClickedCallback(QTableView_HorizontalHeaderClickedCallback callback) const {
    handler->setHorizontalHeaderClickedCallback(callback);
}

void QTableViewBind::setVerticalHeaderClickedCallback(QTableView_VerticalHeaderClickedCallback callback) const {
    handler->setVerticalHeaderClickedCallback(callback);
}
