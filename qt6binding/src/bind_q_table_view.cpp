#include "bind_q_table_view.h"
#include <QHeaderView>

BindQTableView::BindQTableView(QWidget *parent)
    : QTableView(parent)
    , m_handler(nullptr)
{
}

BindQTableView::~BindQTableView()
{
    delete m_handler;
}

void BindQTableView::setTableViewHandler(TableViewHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QTableView::clicked,
                  m_handler, &TableViewHandler::onClicked);
        disconnect(this, &QTableView::doubleClicked,
                  m_handler, &TableViewHandler::onDoubleClicked);
        disconnect(this, &QTableView::activated,
                  m_handler, &TableViewHandler::onActivated);
        disconnect(this, &QTableView::entered,
                  m_handler, &TableViewHandler::onEntered);
        disconnect(this, &QTableView::pressed,
                  m_handler, &TableViewHandler::onPressed);
        disconnect(selectionModel(), &QItemSelectionModel::selectionChanged,
                  m_handler, &TableViewHandler::onSelectionChanged);
        disconnect(horizontalHeader(), &QHeaderView::sectionClicked,
                  m_handler, &TableViewHandler::onHorizontalHeaderClicked);
        disconnect(verticalHeader(), &QHeaderView::sectionClicked,
                  m_handler, &TableViewHandler::onVerticalHeaderClicked);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QTableView::clicked,
                m_handler, &TableViewHandler::onClicked);
        connect(this, &QTableView::doubleClicked,
                m_handler, &TableViewHandler::onDoubleClicked);
        connect(this, &QTableView::activated,
                m_handler, &TableViewHandler::onActivated);
        connect(this, &QTableView::entered,
                m_handler, &TableViewHandler::onEntered);
        connect(this, &QTableView::pressed,
                m_handler, &TableViewHandler::onPressed);
        if (selectionModel()) {
            connect(selectionModel(), &QItemSelectionModel::selectionChanged,
                    m_handler, &TableViewHandler::onSelectionChanged);
        }
        connect(horizontalHeader(), &QHeaderView::sectionClicked,
                m_handler, &TableViewHandler::onHorizontalHeaderClicked);
        connect(verticalHeader(), &QHeaderView::sectionClicked,
                m_handler, &TableViewHandler::onVerticalHeaderClicked);
    }
}

TableViewHandler *BindQTableView::handler() const
{
    return m_handler;
}
