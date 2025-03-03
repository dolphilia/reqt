#ifndef QLINEEDIT_HANDLER_H
#define QLINEEDIT_HANDLER_H

#include <QObject>

class QLineEditHandler : public QObject {
    Q_OBJECT
    typedef void (*TextChangedCallback)(void*, const char*);
    typedef void (*TextEditedCallback)(void*, const char*);
    typedef void (*ReturnPressedCallback)(void*, const char*);
public:
    explicit QLineEditHandler(QObject* parent = nullptr);
    void setTextChangedCallback(TextChangedCallback callback);
    void setTextEditedCallback(TextEditedCallback callback);
    void setReturnPressedCallback(ReturnPressedCallback callback);
public slots:
    void onTextChanged(const QString& text) const;
    void onTextEdited(const QString& text) const;
    void onReturnPressed() const;
private:
    TextChangedCallback textChangedCallback;
    TextEditedCallback textEditedCallback;
    ReturnPressedCallback returnPressedCallback;
};

#endif // QLINEEDIT_HANDLER_H
