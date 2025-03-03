#ifndef QLISTVIEW_HANDLER_H
#define QLISTVIEW_HANDLER_H

#include <QObject>
#include <QModelIndex>

class ListViewHandler : public QObject {
    Q_OBJECT
    typedef void (*ClickedCallback)(void*, int, int);
    typedef void (*DoubleClickedCallback)(void*, int, int);
    typedef void (*SelectionChangedCallback)(void*);
public:
    explicit ListViewHandler(QObject* parent = nullptr);
    void setClickedCallback(ClickedCallback callback);
    void setDoubleClickedCallback(DoubleClickedCallback callback);
    void setSelectionChangedCallback(SelectionChangedCallback callback);
public slots:
    void onClicked(const QModelIndex& index) const;
    void onDoubleClicked(const QModelIndex& index) const;
    void onSelectionChanged() const;
private:
    ClickedCallback clickedCallback;
    DoubleClickedCallback doubleClickedCallback;
    SelectionChangedCallback selectionChangedCallback;
};

#endif // QLISTVIEW_HANDLER_H
