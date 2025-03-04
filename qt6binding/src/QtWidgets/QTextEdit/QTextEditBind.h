#ifndef QTEXTEDIT_BIND_H
#define QTEXTEDIT_BIND_H

#include <QTextEdit>

#include "QTextEditHandler.h"

class QTextEditHandler;

class QTextEditBind : public QTextEdit {
    Q_OBJECT
    typedef void (*QTextEdit_TextChangedCallback)(void*);
    typedef void (*QTextEdit_CopyAvailableCallback)(void*, bool);
    typedef void (*QTextEdit_UndoAvailableCallback)(void*, bool);
    typedef void (*QTextEdit_RedoAvailableCallback)(void*, bool);
    typedef void (*QTextEdit_SelectionChangedCallback)(void*);
    typedef void (*QTextEdit_CursorPositionChangedCallback)(void*);
public:
    explicit QTextEditBind(QWidget* parent = nullptr);
    ~QTextEditBind() override;
    void setTextChangedCallback(QTextEdit_TextChangedCallback callback) const;
    void setCopyAvailableCallback(QTextEdit_CopyAvailableCallback callback) const;
    void setUndoAvailableCallback(QTextEdit_UndoAvailableCallback callback) const;
    void setRedoAvailableCallback(QTextEdit_RedoAvailableCallback callback) const;
    void setSelectionChangedCallback(QTextEdit_SelectionChangedCallback callback) const;
    void setCursorPositionChangedCallback(QTextEdit_CursorPositionChangedCallback callback) const;
private:
    QTextEditHandler* handler;
};

#endif // QTEXTEDIT_BIND_H
