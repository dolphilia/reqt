#ifndef QLINEEDIT_BIND_H
#define QLINEEDIT_BIND_H

#include <QLineEdit>

typedef void (*QLineEditTextChangedCallback)(void* lineEdit, const char* text);

class QLineEditBind {
public:
    static QLineEdit* create(const char* text, QWidget* parent = nullptr);
    static void destroy(QLineEdit* lineEdit);
    static void setText(QLineEdit* lineEdit, const char* text);
    static const char* text(QLineEdit* lineEdit);
    static void setPlaceholderText(QLineEdit* lineEdit, const char* text);
    static const char* placeholderText(QLineEdit* lineEdit);
    static void setMaxLength(QLineEdit* lineEdit, int length);
    static int maxLength(QLineEdit* lineEdit);
    static void setReadOnly(QLineEdit* lineEdit, bool readOnly);
    static bool isReadOnly(QLineEdit* lineEdit);
    static void setClearButtonEnabled(QLineEdit* lineEdit, bool enable);
    static bool isClearButtonEnabled(QLineEdit* lineEdit);
    static void setEnabled(QLineEdit* lineEdit, bool enabled);
    static bool isEnabled(QLineEdit* lineEdit);
    static void clear(QLineEdit* lineEdit);
    static void selectAll(QLineEdit* lineEdit);
    static void setEchoMode(QLineEdit* lineEdit, int mode);
    static int echoMode(QLineEdit* lineEdit);
    static void setTextChangedCallback(QLineEdit* lineEdit, QLineEditTextChangedCallback callback);
    static void setTextEditedCallback(QLineEdit* lineEdit, QLineEditTextChangedCallback callback);
    static void setReturnPressedCallback(QLineEdit* lineEdit, QLineEditTextChangedCallback callback);
};

#endif // QLINEEDIT_BIND_H
