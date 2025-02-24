#include "QListViewBind.h"
#include "qlistview.h"
#include "QListViewHandler.h"

QListViewBind::QListViewBind(QWidget* parent)
    : QListView(parent)
{
}

QListViewBind::~QListViewBind()
{
}

void* QListViewBind::create(QWidget* parent)
{
    return new QListViewBind(parent);
}

void QListViewBind::destroy(QListView* listView)
{
    delete listView;
}

void QListViewBind::setModel(QListView* listView, QAbstractItemModel* model)
{
    listView->setModel(model);
}

QAbstractItemModel* QListViewBind::model(QListView* listView)
{
    return listView->model();
}

void QListViewBind::setSelectionMode(QListView* listView, int mode)
{
    listView->setSelectionMode(static_cast<QAbstractItemView::SelectionMode>(mode));
}

int QListViewBind::selectionMode(QListView* listView)
{
    return static_cast<int>(listView->selectionMode());
}

void QListViewBind::setFlow(QListView* listView, int flow)
{
    listView->setFlow(static_cast<QListView::Flow>(flow));
}

int QListViewBind::flow(QListView* listView)
{
    return static_cast<int>(listView->flow());
}

void QListViewBind::setWrapping(QListView* listView, bool wrap)
{
    listView->setWrapping(wrap);
}

bool QListViewBind::isWrapping(QListView* listView)
{
    return listView->isWrapping();
}

void QListViewBind::setResizeMode(QListView* listView, int mode)
{
    listView->setResizeMode(static_cast<QListView::ResizeMode>(mode));
}

int QListViewBind::resizeMode(QListView* listView)
{
    return static_cast<int>(listView->resizeMode());
}

void QListViewBind::setSpacing(QListView* listView, int space)
{
    listView->setSpacing(space);
}

int QListViewBind::spacing(QListView* listView)
{
    return listView->spacing();
}

void QListViewBind::setBatchSize(QListView* listView, int batchSize)
{
    listView->setBatchSize(batchSize);
}

int QListViewBind::batchSize(QListView* listView)
{
    return listView->batchSize();
}

void QListViewBind::setGridSize(QListView* listView, int width, int height)
{
    listView->setGridSize(QSize(width, height));
}

void QListViewBind::gridSize(QListView* listView, int* width, int* height)
{
    QSize size = listView->gridSize();
    if (width) *width = size.width();
    if (height) *height = size.height();
}

void QListViewBind::setViewMode(QListView* listView, int mode)
{
    listView->setViewMode(static_cast<QListView::ViewMode>(mode));
}

int QListViewBind::viewMode(QListView* listView)
{
    return static_cast<int>(listView->viewMode());
}

void QListViewBind::setUniformItemSizes(QListView* listView, bool enable)
{
    listView->setUniformItemSizes(enable);
}

bool QListViewBind::uniformItemSizes(QListView* listView)
{
    return listView->uniformItemSizes();
}

void QListViewBind::setWordWrap(QListView* listView, bool on)
{
    listView->setWordWrap(on);
}

bool QListViewBind::wordWrap(QListView* listView)
{
    return listView->wordWrap();
}

void QListViewBind::setSelectionRectVisible(QListView* listView, bool show)
{
    listView->setSelectionRectVisible(show);
}

bool QListViewBind::isSelectionRectVisible(QListView* listView)
{
    return listView->isSelectionRectVisible();
}

void QListViewBind::setItemAlignment(QListView* listView, int alignment)
{
    listView->setItemAlignment(static_cast<Qt::Alignment>(alignment));
}

int QListViewBind::itemAlignment(QListView* listView)
{
    return static_cast<int>(listView->itemAlignment());
}

void QListViewBind::setModelColumn(QListView* listView, int column)
{
    listView->setModelColumn(column);
}

int QListViewBind::modelColumn(QListView* listView)
{
    return listView->modelColumn();
}

void QListViewBind::setClickedCallback(QListView* listView, ListViewClickedCallback callback)
{
    auto handler = listView->findChild<ListViewHandler*>();
    if (!handler) {
        handler = new ListViewHandler(callback);
        handler->setParent(listView);
        QObject::connect(listView, &QListView::clicked,
                        handler, &ListViewHandler::onClicked);
    }
}

void QListViewBind::setDoubleClickedCallback(QListView* listView, ListViewDoubleClickedCallback callback)
{
    auto handler = listView->findChild<ListViewHandler*>();
    if (!handler) {
        handler = new ListViewHandler(nullptr, callback);
        handler->setParent(listView);
        QObject::connect(listView, &QListView::doubleClicked,
                        handler, &ListViewHandler::onDoubleClicked);
    }
}

void QListViewBind::setSelectionChangedCallback(QListView* listView, ListViewSelectionChangedCallback callback)
{
    auto handler = listView->findChild<ListViewHandler*>();
    if (!handler) {
        handler = new ListViewHandler(nullptr, nullptr, callback);
        handler->setParent(listView);
        QObject::connect(listView->selectionModel(), &QItemSelectionModel::selectionChanged,
                        handler, &ListViewHandler::onSelectionChanged);
    }
}
