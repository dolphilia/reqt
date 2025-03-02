#ifndef BIND_Q_PLAIN_TEXT_EDIT_H
#define BIND_Q_PLAIN_TEXT_EDIT_H

#include <QPlainTextEdit>
#include "QPlainTextEditHandler.h"

class BindQPlainTextEdit : public QPlainTextEdit {
    Q_OBJECT

public:
    explicit BindQPlainTextEdit(QWidget* parent = nullptr);
    ~BindQPlainTextEdit();

    void setPlainTextEditHandler(QPlainTextEditHandler* handler);
    QPlainTextEditHandler* handler() const;

private:
    QPlainTextEditHandler* m_handler;
};

#endif // QPLAINTEXTEDIT_BIND_H
