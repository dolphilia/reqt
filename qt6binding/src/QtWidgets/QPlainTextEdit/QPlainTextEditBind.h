#ifndef QPLAINTEXTEDIT_BIND_H
#define QPLAINTEXTEDIT_BIND_H

#include "QPlainTextEditHandler.h"
#include <QPlainTextEdit>

class QPlainTextEditBind : public QPlainTextEdit {
    Q_OBJECT
    typedef void (*QPlainTextEdit_TextChangedCallback)(void*);
    typedef void (*QPlainTextEdit_CursorPositionChangedCallback)(void*);
    typedef void (*QPlainTextEdit_CopyAvailableCallback)(void*, bool);
    typedef void (*QPlainTextEdit_UndoAvailableCallback)(void*, bool);
    typedef void (*QPlainTextEdit_RedoAvailableCallback)(void*, bool);
    typedef void (*QPlainTextEdit_SelectionChangedCallback)(void*);
public:
    explicit QPlainTextEditBind(QWidget* parent = nullptr);
    ~QPlainTextEditBind() override;
    void setTextChangedCallback(QPlainTextEdit_TextChangedCallback callback) const;
    void setCursorPositionChangedCallback(QPlainTextEdit_CursorPositionChangedCallback callback) const;
    void setCopyAvailableCallback(QPlainTextEdit_CopyAvailableCallback callback) const;
    void setUndoAvailableCallback(QPlainTextEdit_UndoAvailableCallback callback) const;
    void setRedoAvailableCallback(QPlainTextEdit_RedoAvailableCallback callback) const;
    void setSelectionChangedCallback(QPlainTextEdit_SelectionChangedCallback callback) const;
private:
    QPlainTextEditHandler* handler;
};

#endif // QPLAINTEXTEDIT_BIND_H
