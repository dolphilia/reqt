#ifndef COMBOBOX_HANDLER_H
#define COMBOBOX_HANDLER_H

#include <QObject>

class QComboBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*QComboBox_CurrentIndexChangedCallback)(void*, int);
    typedef void (*QComboBox_CurrentTextChangedCallback)(void*, const char*);
public:
    explicit QComboBoxHandler(QObject* parent = nullptr);
    void setCurrentIndexCallback(QComboBox_CurrentIndexChangedCallback callback);
    void setCurrentTextCallback(QComboBox_CurrentTextChangedCallback callback);
public slots:
    void onCurrentIndexChanged(int index) const;
    void onCurrentTextChanged(const QString& text) const;
private:
    QComboBox_CurrentIndexChangedCallback indexCallback;
    QComboBox_CurrentTextChangedCallback textCallback;
};

#endif // COMBOBOX_HANDLER_H
