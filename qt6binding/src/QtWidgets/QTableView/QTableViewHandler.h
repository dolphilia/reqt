#ifndef QTABLEVIEW_HANDLER_H
#define QTABLEVIEW_HANDLER_H

#include <QObject>
#include <QModelIndex>

class QTableViewHandler : public QObject {
    Q_OBJECT
    typedef void (*QTableView_ClickedCallback)(void*, void* index);
    typedef void (*QTableView_DoubleClickedCallback)(void*, void* index);
    typedef void (*QTableView_ActivatedCallback)(void*, void* index);
    typedef void (*QTableView_EnteredCallback)(void*, void* index);
    typedef void (*QTableView_PressedCallback)(void*, void* index);
    typedef void (*QTableView_SelectionChangedCallback)(void*);
    typedef void (*QTableView_HorizontalHeaderClickedCallback)(void*, int section);
    typedef void (*QTableView_VerticalHeaderClickedCallback)(void*, int section);
public:
    explicit QTableViewHandler(QObject* parent = nullptr);
    void setClickedCallback(QTableView_ClickedCallback callback);
    void setDoubleClickedCallback(QTableView_DoubleClickedCallback callback);
    void setActivatedCallback(QTableView_ActivatedCallback callback);
    void setEnteredCallback(QTableView_EnteredCallback callback);
    void setPressedCallback(QTableView_PressedCallback callback);
    void setSelectionChangedCallback(QTableView_SelectionChangedCallback callback);
    void setHorizontalHeaderClickedCallback(QTableView_HorizontalHeaderClickedCallback callback);
    void setVerticalHeaderClickedCallback(QTableView_VerticalHeaderClickedCallback callback);

public slots:
    void onClicked(const QModelIndex &index) const;
    void onDoubleClicked(const QModelIndex &index) const;
    void onActivated(const QModelIndex &index) const;
    void onEntered(const QModelIndex &index) const;
    void onPressed(const QModelIndex &index) const;
    void onSelectionChanged() const;
    void onHorizontalHeaderClicked(int section) const;
    void onVerticalHeaderClicked(int section) const;

private:
    QTableView_ClickedCallback clickedCallback;
    QTableView_DoubleClickedCallback doubleClickedCallback;
    QTableView_ActivatedCallback activatedCallback;
    QTableView_EnteredCallback enteredCallback;
    QTableView_PressedCallback pressedCallback;
    QTableView_SelectionChangedCallback selectionChangedCallback;
    QTableView_HorizontalHeaderClickedCallback horizontalHeaderClickedCallback;
    QTableView_VerticalHeaderClickedCallback verticalHeaderClickedCallback;
};

#endif // HANDLER_TABLE_VIEW_H
