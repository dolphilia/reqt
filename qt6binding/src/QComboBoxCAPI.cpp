#include "QComboBoxBind.h"
#include "qcombobox.h"

extern "C" {

void* QComboBox_create(void* parent) {
    return QComboBoxBind::create(static_cast<QWidget*>(parent));
}

void QComboBox_delete(void* comboBox) {
    QComboBoxBind::destroy(static_cast<QComboBox*>(comboBox));
}

void QComboBox_addItem(void* comboBox, const char* text) {
    QComboBoxBind::addItem(static_cast<QComboBox*>(comboBox), text);
}

void QComboBox_addItems(void* comboBox, const char** items, int count) {
    QComboBoxBind::addItems(static_cast<QComboBox*>(comboBox), items, count);
}

void QComboBox_clear(void* comboBox) {
    QComboBoxBind::clear(static_cast<QComboBox*>(comboBox));
}

const char* QComboBox_currentText(void* comboBox) {
    return QComboBoxBind::currentText(static_cast<QComboBox*>(comboBox));
}

int QComboBox_currentIndex(void* comboBox) {
    return QComboBoxBind::currentIndex(static_cast<QComboBox*>(comboBox));
}

int QComboBox_count(void* comboBox) {
    return QComboBoxBind::count(static_cast<QComboBox*>(comboBox));
}

const char* QComboBox_itemText(void* comboBox, int index) {
    return QComboBoxBind::itemText(static_cast<QComboBox*>(comboBox), index);
}

void QComboBox_setCurrentIndex(void* comboBox, int index) {
    QComboBoxBind::setCurrentIndex(static_cast<QComboBox*>(comboBox), index);
}

void QComboBox_setCurrentText(void* comboBox, const char* text) {
    QComboBoxBind::setCurrentText(static_cast<QComboBox*>(comboBox), text);
}

void QComboBox_setEditable(void* comboBox, bool editable) {
    QComboBoxBind::setEditable(static_cast<QComboBox*>(comboBox), editable);
}

bool QComboBox_isEditable(void* comboBox) {
    return QComboBoxBind::isEditable(static_cast<QComboBox*>(comboBox));
}

void QComboBox_setEnabled(void* comboBox, bool enabled) {
    QComboBoxBind::setEnabled(static_cast<QComboBox*>(comboBox), enabled);
}

bool QComboBox_isEnabled(void* comboBox) {
    return QComboBoxBind::isEnabled(static_cast<QComboBox*>(comboBox));
}

void QComboBox_setCurrentIndexChangedCallback(void* comboBox, QComboBoxCurrentIndexChangedCallback callback) {
    QComboBoxBind::setCurrentIndexChangedCallback(static_cast<QComboBox*>(comboBox), callback);
}

void QComboBox_setCurrentTextChangedCallback(void* comboBox, QComboBoxCurrentTextChangedCallback callback) {
    QComboBoxBind::setCurrentTextChangedCallback(static_cast<QComboBox*>(comboBox), callback);
}

}
