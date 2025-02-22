#ifndef BIND_Q_TEXT_EDIT_H
#define BIND_Q_TEXT_EDIT_H

#include <QTextEdit>
#include "handler_text_edit.h"

class BindQTextEdit : public QTextEdit {
    Q_OBJECT
public:
    explicit BindQTextEdit(QWidget *parent = nullptr);
    ~BindQTextEdit();

    void setTextEditHandler(TextEditHandler *handler);
    TextEditHandler *handler() const;

private:
    TextEditHandler *m_handler;
};

#endif // BIND_Q_TEXT_EDIT_H
