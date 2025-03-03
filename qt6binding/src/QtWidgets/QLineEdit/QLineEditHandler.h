#ifndef LINEEDIT_HANDLER_H
#define LINEEDIT_HANDLER_H

#include <QObject>

class LineEditHandler : public QObject {
    Q_OBJECT
    typedef void (*TextChangedCallback)(void*, const char*);
public:
    explicit LineEditHandler(QObject* parent = nullptr);
    void setTextChangedCallback(TextChangedCallback callback);
    void setTextEditedCallback(TextChangedCallback callback);
    void setReturnPressedCallback(TextChangedCallback callback);
public slots:
    void onTextChanged(const QString& text) const;
    void onTextEdited(const QString& text) const;
    void onReturnPressed() const;
private:
    TextChangedCallback textChangedCallback;
    TextChangedCallback textEditedCallback;
    TextChangedCallback returnPressedCallback;
};

#endif // LINEEDIT_HANDLER_H
