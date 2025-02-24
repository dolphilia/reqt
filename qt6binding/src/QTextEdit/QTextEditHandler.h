#ifndef HANDLER_TEXT_EDIT_H
#define HANDLER_TEXT_EDIT_H

#include <QObject>

class TextEditHandler : public QObject {
    Q_OBJECT
public:
    explicit TextEditHandler(QObject *parent = nullptr);
    ~TextEditHandler();

    void setTextChangedCallback(void (*callback)());
    void setCopyAvailableCallback(void (*callback)(bool available));
    void setUndoAvailableCallback(void (*callback)(bool available));
    void setRedoAvailableCallback(void (*callback)(bool available));
    void setSelectionChangedCallback(void (*callback)());
    void setCursorPositionChangedCallback(void (*callback)());

public slots:
    void onTextChanged();
    void onCopyAvailable(bool available);
    void onUndoAvailable(bool available);
    void onRedoAvailable(bool available);
    void onSelectionChanged();
    void onCursorPositionChanged();

private:
    void (*m_textChangedCallback)();
    void (*m_copyAvailableCallback)(bool available);
    void (*m_undoAvailableCallback)(bool available);
    void (*m_redoAvailableCallback)(bool available);
    void (*m_selectionChangedCallback)();
    void (*m_cursorPositionChangedCallback)();
};

#endif // HANDLER_TEXT_EDIT_H
