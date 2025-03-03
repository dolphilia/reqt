#ifndef COMBOBOX_HANDLER_H
#define COMBOBOX_HANDLER_H

#include <QObject>

class ComboBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*CurrentIndexChangedCallback)(void*, int);
    typedef void (*CurrentTextChangedCallback)(void*, const char*);
public:
    explicit ComboBoxHandler(QObject* parent = nullptr);
    void setCurrentIndexCallback(CurrentIndexChangedCallback callback);
    void setCurrentTextCallback(CurrentTextChangedCallback callback);
public slots:
    void onCurrentIndexChanged(int index) const;
    void onCurrentTextChanged(const QString& text) const;
private:
    CurrentIndexChangedCallback indexCallback;
    CurrentTextChangedCallback textCallback;
};

#endif // COMBOBOX_HANDLER_H
