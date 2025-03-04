#ifndef PLAINTEXTEDIT_HANDLER_H
#define PLAINTEXTEDIT_HANDLER_H

#include <QObject>

class QPlainTextEditHandler : public QObject {
    Q_OBJECT
    typedef void (*QPlainTextEdit_TextChangedCallback)(void*);
    typedef void (*QPlainTextEdit_CursorPositionChangedCallback)(void*);
    typedef void (*QPlainTextEdit_CopyAvailableCallback)(void*, bool);
    typedef void (*QPlainTextEdit_UndoAvailableCallback)(void*, bool);
    typedef void (*QPlainTextEdit_RedoAvailableCallback)(void*, bool);
    typedef void (*QPlainTextEdit_SelectionChangedCallback)(void*);
public:
    explicit QPlainTextEditHandler(QObject* parent = nullptr);
    void setTextChangedCallback(QPlainTextEdit_TextChangedCallback callback);
    void setCursorPositionChangedCallback(QPlainTextEdit_CursorPositionChangedCallback callback);
    void setCopyAvailableCallback(QPlainTextEdit_CopyAvailableCallback callback);
    void setUndoAvailableCallback(QPlainTextEdit_UndoAvailableCallback callback);
    void setRedoAvailableCallback(QPlainTextEdit_RedoAvailableCallback callback);
    void setSelectionChangedCallback(QPlainTextEdit_SelectionChangedCallback callback);
public slots:
    void onTextChanged() const;
    void onCursorPositionChanged() const;
    void onCopyAvailable(bool available) const;
    void onUndoAvailable(bool available) const;
    void onRedoAvailable(bool available) const;
    void onSelectionChanged() const;
private:
    QPlainTextEdit_TextChangedCallback textChangedCallback;
    QPlainTextEdit_CursorPositionChangedCallback cursorPositionChangedCallback;
    QPlainTextEdit_CopyAvailableCallback copyAvailableCallback;
    QPlainTextEdit_UndoAvailableCallback undoAvailableCallback;
    QPlainTextEdit_RedoAvailableCallback redoAvailableCallback;
    QPlainTextEdit_SelectionChangedCallback selectionChangedCallback;
};

#endif // PLAINTEXTEDIT_HANDLER_H
