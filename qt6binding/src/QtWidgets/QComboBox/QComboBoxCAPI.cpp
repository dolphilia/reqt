#include "QComboBoxBind.h"
#include "qcombobox.h"

extern "C" {

void* QComboBox_create(void* parent) {
    return new QComboBoxBind(static_cast<QWidget*>(parent));
}

void QComboBox_delete(void* comboBox) {
    delete static_cast<QComboBoxBind*>(comboBox);
}

void QComboBox_addItem(void* comboBox, const char* text) {
    const QString qstr = QString::fromUtf8(text);
    static_cast<QComboBoxBind*>(comboBox)->addItem(qstr);
}

void QComboBox_addItems(void* comboBox, const char** items, int count) {
    QStringList list;
    for (int i = 0; i < count; ++i) {
        if (items[i]) {
            list << QString::fromUtf8(items[i]);
        }
    }
    static_cast<QComboBoxBind*>(comboBox)->addItems(list);
}

void QComboBox_clear(void* comboBox) {
    static_cast<QComboBoxBind*>(comboBox)->clear();
}

const char* QComboBox_currentText(void* comboBox) {
    const QString qstr = static_cast<QComboBoxBind*>(comboBox)->currentText();
    return qstr.toUtf8().constData();
}

int QComboBox_currentIndex(void* comboBox) {
    return static_cast<QComboBoxBind*>(comboBox)->currentIndex();
}

int QComboBox_count(void* comboBox) {
    return static_cast<QComboBoxBind*>(comboBox)->count();
}

const char* QComboBox_itemText(void* comboBox, int index) {
    const QString qstr = static_cast<QComboBoxBind*>(comboBox)->itemText(index);
    return qstr.toUtf8().constData();
}

void QComboBox_setCurrentIndex(void* comboBox, int index) {
    static_cast<QComboBoxBind*>(comboBox)->setCurrentIndex(index);
}

void QComboBox_setCurrentText(void* comboBox, const char* text) {
    static_cast<QComboBoxBind*>(comboBox)->setCurrentText(text);
}

void QComboBox_setEditable(void* comboBox, bool editable) {
    static_cast<QComboBoxBind*>(comboBox)->setEditable(editable);
}

bool QComboBox_isEditable(void* comboBox) {
    return static_cast<QComboBoxBind*>(comboBox)->isEditable();
}

void QComboBox_setEnabled(void* comboBox, bool enabled) {
    static_cast<QComboBoxBind*>(comboBox)->setEnabled(enabled);
}

bool QComboBox_isEnabled(void* comboBox) {
    return static_cast<QComboBoxBind*>(comboBox)->isEnabled();
}

void QComboBox_setCurrentIndexChangedCallback(void* comboBox, CurrentIndexChangedCallback callback) {
    static_cast<QComboBoxBind*>(comboBox)->setCurrentIndexChangedCallback(callback);
}

void QComboBox_setCurrentTextChangedCallback(void* comboBox, CurrentTextChangedCallback callback) {
    static_cast<QComboBoxBind*>(comboBox)->setCurrentTextChangedCallback(callback);
}

}
