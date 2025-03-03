#ifndef QLINEEDIT_BIND_H
#define QLINEEDIT_BIND_H

#include "QLineEditHandler.h"
#include <QLineEdit>

class QLineEditBind : public QLineEdit {
    Q_OBJECT
    typedef void (*TextChangedCallback)(void*, const char*);
    typedef void (*TextEditedCallback)(void*, const char*);
    typedef void (*ReturnPressedCallback)(void*, const char*);
public:
    explicit QLineEditBind(QWidget* parent = nullptr);
    explicit QLineEditBind(const QString& text, QWidget* parent = nullptr);
    ~QLineEditBind() override;
    void setTextChangedCallback(TextChangedCallback callback) const;
    void setTextEditedCallback(TextEditedCallback callback) const;
    void setReturnPressedCallback(ReturnPressedCallback callback) const;
private:
    QLineEditHandler* handler;
};

#endif // QLINEEDIT_BIND_H
