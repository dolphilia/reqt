#ifndef QTEXTEDIT_HANDLER_H
#define QTEXTEDIT_HANDLER_H

#include <QObject>

class QTextEditHandler : public QObject {
    Q_OBJECT
    typedef void (*QTextEdit_TextChangedCallback)(void*);
    typedef void (*QTextEdit_CopyAvailableCallback)(void*, bool);
    typedef void (*QTextEdit_UndoAvailableCallback)(void*, bool);
    typedef void (*QTextEdit_RedoAvailableCallback)(void*, bool);
    typedef void (*QTextEdit_SelectionChangedCallback)(void*);
    typedef void (*QTextEdit_CursorPositionChangedCallback)(void*);
public:
    explicit QTextEditHandler(QObject* parent = nullptr);
    void setTextChangedCallback(QTextEdit_TextChangedCallback callback);
    void setCopyAvailableCallback(QTextEdit_CopyAvailableCallback callback);
    void setUndoAvailableCallback(QTextEdit_UndoAvailableCallback callback);
    void setRedoAvailableCallback(QTextEdit_RedoAvailableCallback callback);
    void setSelectionChangedCallback(QTextEdit_SelectionChangedCallback callback);
    void setCursorPositionChangedCallback(QTextEdit_CursorPositionChangedCallback callback);

public slots:
    void onTextChanged() const;
    void onCopyAvailable(bool available) const;
    void onUndoAvailable(bool available) const;
    void onRedoAvailable(bool available) const;
    void onSelectionChanged() const;
    void onCursorPositionChanged() const;

private:
    QTextEdit_TextChangedCallback textChangedCallback;
    QTextEdit_CopyAvailableCallback copyAvailableCallback;
    QTextEdit_UndoAvailableCallback undoAvailableCallback;
    QTextEdit_RedoAvailableCallback redoAvailableCallback;
    QTextEdit_SelectionChangedCallback selectionChangedCallback;
    QTextEdit_CursorPositionChangedCallback cursorPositionChangedCallback;
};

#endif // QTEXTEDIT_HANDLER_H
