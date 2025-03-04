#ifndef QLINEEDIT_BIND_H
#define QLINEEDIT_BIND_H

#include "QLineEditHandler.h"
#include <QLineEdit>

class QLineEditBind : public QLineEdit {
    Q_OBJECT
    typedef void (*QLineEdit_TextChangedCallback)(void*, const char*);
    typedef void (*QLineEdit_TextEditedCallback)(void*, const char*);
    typedef void (*QLineEdit_ReturnPressedCallback)(void*, const char*);
public:
    explicit QLineEditBind(QWidget* parent = nullptr);
    explicit QLineEditBind(const QString& text, QWidget* parent = nullptr);
    ~QLineEditBind() override;
    void setTextChangedCallback(QLineEdit_TextChangedCallback callback) const;
    void setTextEditedCallback(QLineEdit_TextEditedCallback callback) const;
    void setReturnPressedCallback(QLineEdit_ReturnPressedCallback callback) const;
private:
    QLineEditHandler* handler;
};

#endif // QLINEEDIT_BIND_H
