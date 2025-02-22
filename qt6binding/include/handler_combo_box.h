#ifndef COMBOBOX_HANDLER_H
#define COMBOBOX_HANDLER_H

#include <QObject>

class ComboBoxHandler : public QObject {
    Q_OBJECT
public:
    explicit ComboBoxHandler(void (*indexCallback)(void*, int) = nullptr,
                           void (*textCallback)(void*, const char*) = nullptr);

public slots:
    void onCurrentIndexChanged(int index);
    void onCurrentTextChanged(const QString& text);

private:
    void (*indexCallback)(void*, int);
    void (*textCallback)(void*, const char*);
};

#endif // COMBOBOX_HANDLER_H
