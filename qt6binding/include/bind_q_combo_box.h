#ifndef QCOMBOBOX_BIND_H
#define QCOMBOBOX_BIND_H

#include <QComboBox>

typedef void (*QComboBoxCurrentIndexChangedCallback)(void* comboBox, int index);
typedef void (*QComboBoxCurrentTextChangedCallback)(void* comboBox, const char* text);

class QComboBoxBind {
public:
    static QComboBox* create(QWidget* parent = nullptr);
    static void destroy(QComboBox* comboBox);
    static void addItem(QComboBox* comboBox, const char* text);
    static void addItems(QComboBox* comboBox, const char** items, int count);
    static void clear(QComboBox* comboBox);
    static const char* currentText(QComboBox* comboBox);
    static int currentIndex(QComboBox* comboBox);
    static int count(QComboBox* comboBox);
    static const char* itemText(QComboBox* comboBox, int index);
    static void setCurrentIndex(QComboBox* comboBox, int index);
    static void setCurrentText(QComboBox* comboBox, const char* text);
    static void setEditable(QComboBox* comboBox, bool editable);
    static bool isEditable(QComboBox* comboBox);
    static void setEnabled(QComboBox* comboBox, bool enabled);
    static bool isEnabled(QComboBox* comboBox);
    static void setCurrentIndexChangedCallback(QComboBox* comboBox, QComboBoxCurrentIndexChangedCallback callback);
    static void setCurrentTextChangedCallback(QComboBox* comboBox, QComboBoxCurrentTextChangedCallback callback);
};

#endif // QCOMBOBOX_BIND_H
