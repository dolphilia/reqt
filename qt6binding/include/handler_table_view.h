#ifndef HANDLER_TABLE_VIEW_H
#define HANDLER_TABLE_VIEW_H

#include <QObject>
#include <QModelIndex>

class TableViewHandler : public QObject {
    Q_OBJECT
public:
    explicit TableViewHandler(QObject *parent = nullptr);
    ~TableViewHandler();

    void setClickedCallback(void (*callback)(void* index));
    void setDoubleClickedCallback(void (*callback)(void* index));
    void setActivatedCallback(void (*callback)(void* index));
    void setEnteredCallback(void (*callback)(void* index));
    void setPressedCallback(void (*callback)(void* index));
    void setSelectionChangedCallback(void (*callback)());
    void setHorizontalHeaderClickedCallback(void (*callback)(int section));
    void setVerticalHeaderClickedCallback(void (*callback)(int section));

public slots:
    void onClicked(const QModelIndex &index);
    void onDoubleClicked(const QModelIndex &index);
    void onActivated(const QModelIndex &index);
    void onEntered(const QModelIndex &index);
    void onPressed(const QModelIndex &index);
    void onSelectionChanged();
    void onHorizontalHeaderClicked(int section);
    void onVerticalHeaderClicked(int section);

private:
    void (*m_clickedCallback)(void* index);
    void (*m_doubleClickedCallback)(void* index);
    void (*m_activatedCallback)(void* index);
    void (*m_enteredCallback)(void* index);
    void (*m_pressedCallback)(void* index);
    void (*m_selectionChangedCallback)();
    void (*m_horizontalHeaderClickedCallback)(int section);
    void (*m_verticalHeaderClickedCallback)(int section);
};

#endif // HANDLER_TABLE_VIEW_H
