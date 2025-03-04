#ifndef QLINEEDIT_HANDLER_H
#define QLINEEDIT_HANDLER_H

#include <QObject>

class QLineEditHandler : public QObject {
    Q_OBJECT
    typedef void (*QLineEdit_TextChangedCallback)(void*, const char*);
    typedef void (*QLineEdit_TextEditedCallback)(void*, const char*);
    typedef void (*QLineEdit_ReturnPressedCallback)(void*, const char*);
public:
    explicit QLineEditHandler(QObject* parent = nullptr);
    void setTextChangedCallback(QLineEdit_TextChangedCallback callback);
    void setTextEditedCallback(QLineEdit_TextEditedCallback callback);
    void setReturnPressedCallback(QLineEdit_ReturnPressedCallback callback);
public slots:
    void onTextChanged(const QString& text) const;
    void onTextEdited(const QString& text) const;
    void onReturnPressed() const;
private:
    QLineEdit_TextChangedCallback textChangedCallback;
    QLineEdit_TextEditedCallback textEditedCallback;
    QLineEdit_ReturnPressedCallback returnPressedCallback;
};

#endif // QLINEEDIT_HANDLER_H
