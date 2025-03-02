#ifndef BIND_Q_PLAIN_TEXT_EDIT_HANDLER_H
#define BIND_Q_PLAIN_TEXT_EDIT_HANDLER_H

#include <QObject>

class QPlainTextEditHandler : public QObject {
    Q_OBJECT
public:
    explicit QPlainTextEditHandler(QObject* parent = nullptr);
    ~QPlainTextEditHandler();

    void setTextChangedCallback(void (*callback)());
    void setCursorPositionChangedCallback(void (*callback)());
    void setCopyAvailableCallback(void (*callback)(bool));
    void setUndoAvailableCallback(void (*callback)(bool));
    void setRedoAvailableCallback(void (*callback)(bool));
    void setSelectionChangedCallback(void (*callback)());

public slots:
    void onTextChanged();
    void onCursorPositionChanged();
    void onCopyAvailable(bool available);
    void onUndoAvailable(bool available);
    void onRedoAvailable(bool available);
    void onSelectionChanged();

private:
    void (*m_textChangedCallback)();
    void (*m_cursorPositionChangedCallback)();
    void (*m_copyAvailableCallback)(bool);
    void (*m_undoAvailableCallback)(bool);
    void (*m_redoAvailableCallback)(bool);
    void (*m_selectionChangedCallback)();
};

#endif // QPLAINTEXTEDIT_HANDLER_H
