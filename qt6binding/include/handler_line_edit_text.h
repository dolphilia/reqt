#ifndef LINEEDIT_TEXT_HANDLER_H
#define LINEEDIT_TEXT_HANDLER_H

#include <QObject>

class LineEditTextHandler : public QObject {
    Q_OBJECT
public:
    explicit LineEditTextHandler(void (*callback)(void*, const char*) = nullptr);

public slots:
    void onTextChanged(const QString& text);

private:
    void (*callback)(void*, const char*);
};

#endif // LINEEDIT_TEXT_HANDLER_H
