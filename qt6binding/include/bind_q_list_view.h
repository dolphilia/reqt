#ifndef QLISTVIEW_BIND_H
#define QLISTVIEW_BIND_H

#include <QListView>
#include <QSize>
#include "handler_list_view.h"

class QListViewBind : public QListView {
    Q_OBJECT

public:
    explicit QListViewBind(QWidget* parent = nullptr);
    ~QListViewBind() override;

    static void* create(QWidget* parent);
    static void destroy(QListView* listView);
    static void setModel(QListView* listView, QAbstractItemModel* model);
    static QAbstractItemModel* model(QListView* listView);
    static void setSelectionMode(QListView* listView, int mode);
    static int selectionMode(QListView* listView);
    static void setFlow(QListView* listView, int flow);
    static int flow(QListView* listView);
    static void setWrapping(QListView* listView, bool wrap);
    static bool isWrapping(QListView* listView);
    static void setResizeMode(QListView* listView, int mode);
    static int resizeMode(QListView* listView);
    static void setSpacing(QListView* listView, int space);
    static int spacing(QListView* listView);
    static void setBatchSize(QListView* listView, int batchSize);
    static int batchSize(QListView* listView);
    static void setGridSize(QListView* listView, int width, int height);
    static void gridSize(QListView* listView, int* width, int* height);
    static void setViewMode(QListView* listView, int mode);
    static int viewMode(QListView* listView);
    static void setUniformItemSizes(QListView* listView, bool enable);
    static bool uniformItemSizes(QListView* listView);
    static void setWordWrap(QListView* listView, bool on);
    static bool wordWrap(QListView* listView);
    static void setSelectionRectVisible(QListView* listView, bool show);
    static bool isSelectionRectVisible(QListView* listView);
    static void setItemAlignment(QListView* listView, int alignment);
    static int itemAlignment(QListView* listView);
    static void setModelColumn(QListView* listView, int column);
    static int modelColumn(QListView* listView);

    // Event handlers
    static void setClickedCallback(QListView* listView, ListViewClickedCallback callback);
    static void setDoubleClickedCallback(QListView* listView, ListViewDoubleClickedCallback callback);
    static void setSelectionChangedCallback(QListView* listView, ListViewSelectionChangedCallback callback);
};

#endif // QLISTVIEW_BIND_H
