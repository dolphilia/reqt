#ifndef QLISTVIEW_HANDLER_H
#define QLISTVIEW_HANDLER_H

#include <QObject>
#include <QModelIndex>

class QListViewHandler : public QObject {
    Q_OBJECT
    typedef void (*QListView_ClickedCallback)(void*, int, int);
    typedef void (*QListView_DoubleClickedCallback)(void*, int, int);
    typedef void (*QListView_SelectionChangedCallback)(void*);
public:
    explicit QListViewHandler(QObject* parent = nullptr);
    void setClickedCallback(QListView_ClickedCallback callback);
    void setDoubleClickedCallback(QListView_DoubleClickedCallback callback);
    void setSelectionChangedCallback(QListView_SelectionChangedCallback callback);
public slots:
    void onClicked(const QModelIndex& index) const;
    void onDoubleClicked(const QModelIndex& index) const;
    void onSelectionChanged() const;
private:
    QListView_ClickedCallback clickedCallback;
    QListView_DoubleClickedCallback doubleClickedCallback;
    QListView_SelectionChangedCallback selectionChangedCallback;
};

#endif // QLISTVIEW_HANDLER_H
