#ifndef LISTVIEW_HANDLER_H
#define LISTVIEW_HANDLER_H

#include <QObject>
#include <QModelIndex>

typedef void (*ListViewClickedCallback)(void* listView, int row, int column);
typedef void (*ListViewDoubleClickedCallback)(void* listView, int row, int column);
typedef void (*ListViewSelectionChangedCallback)(void* listView);

class ListViewHandler : public QObject
{
    Q_OBJECT

public:
    explicit ListViewHandler(ListViewClickedCallback clicked = nullptr,
                           ListViewDoubleClickedCallback doubleClicked = nullptr,
                           ListViewSelectionChangedCallback selectionChanged = nullptr,
                           QObject* parent = nullptr);

public slots:
    void onClicked(const QModelIndex& index);
    void onDoubleClicked(const QModelIndex& index);
    void onSelectionChanged();

private:
    ListViewClickedCallback m_clickedCallback;
    ListViewDoubleClickedCallback m_doubleClickedCallback;
    ListViewSelectionChangedCallback m_selectionChangedCallback;
};

#endif // LISTVIEW_HANDLER_H
