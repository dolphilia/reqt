#ifndef QLINEEDIT_BIND_H
#define QLINEEDIT_BIND_H

#include "QLineEditHandler.h"
#include <QLineEdit>

class QLineEditBind : public QLineEdit {
    Q_OBJECT
    typedef void (*TextChangedCallback)(void*, const char*);
public:
    explicit QLineEditBind(QWidget* parent = nullptr);
    explicit QLineEditBind(const QString& text, QWidget* parent = nullptr);
    ~QLineEditBind() override;
    void setTextChangedCallback(TextChangedCallback callback) const;
    void setTextEditedCallback(TextChangedCallback callback) const;
    void setReturnPressedCallback(TextChangedCallback callback) const;
private:
    LineEditHandler* handler;
};

#endif // QLINEEDIT_BIND_H
