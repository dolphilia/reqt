#include "QInputDialogBind.h"
#include "qinputdialog.h"

extern "C" {

void* QInputDialog_create(void* parent) {
    return new QInputDialogBind(static_cast<QWidget*>(parent));
}

void QInputDialog_delete(void* dialog) {
    delete static_cast<QInputDialogBind*>(dialog);
}

void QInputDialog_setCancelButtonText(void* dialog, const char* text) {
    static_cast<QInputDialogBind*>(dialog)->setCancelButtonText(QString::fromUtf8(text));
}

const char* QInputDialog_cancelButtonText(void* dialog) {
    static QByteArray data;
    data = static_cast<QInputDialogBind*>(dialog)->cancelButtonText().toUtf8();
    return data.constData();
}

void QInputDialog_setComboBoxEditable(void* dialog, bool editable) {
    static_cast<QInputDialogBind*>(dialog)->setComboBoxEditable(editable);
}

bool QInputDialog_isComboBoxEditable(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->isComboBoxEditable();
}

void QInputDialog_setComboBoxItems(void* dialog, const char** items, int count) {
    QStringList itemList;
    for (int i = 0; i < count; ++i) {
        itemList << QString::fromUtf8(items[i]);
    }
    static_cast<QInputDialogBind*>(dialog)->setComboBoxItems(itemList);
}

void QInputDialog_setDoubleDecimals(void* dialog, int decimals) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleDecimals(decimals);
}

int QInputDialog_doubleDecimals(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->doubleDecimals();
}

void QInputDialog_setDoubleMaximum(void* dialog, double max) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleMaximum(max);
}

double QInputDialog_doubleMaximum(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->doubleMaximum();
}

void QInputDialog_setDoubleMinimum(void* dialog, double min) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleMinimum(min);
}

double QInputDialog_doubleMinimum(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->doubleMinimum();
}

void QInputDialog_setDoubleRange(void* dialog, double min, double max) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleRange(min, max);
}

void QInputDialog_setDoubleStep(void* dialog, double step) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleStep(step);
}

double QInputDialog_doubleStep(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->doubleStep();
}

void QInputDialog_setDoubleValue(void* dialog, double value) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleValue(value);
}

double QInputDialog_doubleValue(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->doubleValue();
}

void QInputDialog_setInputMode(void* dialog, int mode) {
    static_cast<QInputDialogBind*>(dialog)->setInputMode(static_cast<QInputDialog::InputMode>(mode));
}

int QInputDialog_inputMode(void* dialog) {
    return static_cast<int>(static_cast<QInputDialogBind*>(dialog)->inputMode());
}

void QInputDialog_setIntMaximum(void* dialog, int max) {
    static_cast<QInputDialogBind*>(dialog)->setIntMaximum(max);
}

int QInputDialog_intMaximum(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->intMaximum();
}

void QInputDialog_setIntMinimum(void* dialog, int min) {
    static_cast<QInputDialogBind*>(dialog)->setIntMinimum(min);
}

int QInputDialog_intMinimum(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->intMinimum();
}

void QInputDialog_setIntRange(void* dialog, int min, int max) {
    static_cast<QInputDialogBind*>(dialog)->setIntRange(min, max);
}

void QInputDialog_setIntStep(void* dialog, int step) {
    static_cast<QInputDialogBind*>(dialog)->setIntStep(step);
}

int QInputDialog_intStep(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->intStep();
}

void QInputDialog_setIntValue(void* dialog, int value) {
    static_cast<QInputDialogBind*>(dialog)->setIntValue(value);
}

int QInputDialog_intValue(void* dialog) {
    return static_cast<QInputDialogBind*>(dialog)->intValue();
}

void QInputDialog_setLabelText(void* dialog, const char* text) {
    static_cast<QInputDialogBind*>(dialog)->setLabelText(QString::fromUtf8(text));
}

const char* QInputDialog_labelText(void* dialog) {
    static QByteArray data;
    data = static_cast<QInputDialogBind*>(dialog)->labelText().toUtf8();
    return data.constData();
}

void QInputDialog_setOkButtonText(void* dialog, const char* text) {
    static_cast<QInputDialogBind*>(dialog)->setOkButtonText(QString::fromUtf8(text));
}

const char* QInputDialog_okButtonText(void* dialog) {
    static QByteArray data;
    data = static_cast<QInputDialogBind*>(dialog)->okButtonText().toUtf8();
    return data.constData();
}

void QInputDialog_setOptions(void* dialog, int options) {
    static_cast<QInputDialogBind*>(dialog)->setOptions(static_cast<QInputDialog::InputDialogOptions>(options));
}

int QInputDialog_options(void* dialog) {
    return static_cast<int>(static_cast<QInputDialogBind*>(dialog)->options());
}

void QInputDialog_setOption(void* dialog, int option, bool on) {
    static_cast<QInputDialogBind*>(dialog)->setOption(static_cast<QInputDialog::InputDialogOption>(option), on);
}

bool QInputDialog_testOption(void* dialog, int option) {
    return static_cast<QInputDialogBind*>(dialog)->testOption(static_cast<QInputDialog::InputDialogOption>(option));
}

void QInputDialog_setTextEchoMode(void* dialog, int mode) {
    static_cast<QInputDialogBind*>(dialog)->setTextEchoMode(static_cast<QLineEdit::EchoMode>(mode));
}

int QInputDialog_textEchoMode(void* dialog) {
    return static_cast<int>(static_cast<QInputDialogBind*>(dialog)->textEchoMode());
}

void QInputDialog_setTextValue(void* dialog, const char* text) {
    static_cast<QInputDialogBind*>(dialog)->setTextValue(QString::fromUtf8(text));
}

const char* QInputDialog_textValue(void* dialog) {
    static QByteArray data;
    data = static_cast<QInputDialogBind*>(dialog)->textValue().toUtf8();
    return data.constData();
}

void QInputDialog_open(void* dialog) {
    static_cast<QInputDialogBind*>(dialog)->open();
}

void QInputDialog_done(void* dialog, int result) {
    static_cast<QInputDialogBind*>(dialog)->done(result);
}

void QInputDialog_setVisible(void* dialog, bool visible) {
    static_cast<QInputDialogBind*>(dialog)->setVisible(visible);
}

double QInputDialog_getDouble(void* parent, const char* title, const char* label, double value, double min, double max, int decimals, bool* ok, int flags) {
    return QInputDialogBind::getDouble(static_cast<QWidget*>(parent), title, label, value, min, max, decimals, ok, flags);
}

int QInputDialog_getInt(void* parent, const char* title, const char* label, int value, int min, int max, int step, bool* ok, int flags) {
    return QInputDialogBind::getInt(static_cast<QWidget*>(parent), title, label, value, min, max, step, ok, flags);
}

const char* QInputDialog_getItem(void* parent, const char* title, const char* label, const char** items, int itemCount, int current, bool editable, bool* ok, int flags) {
    return QInputDialogBind::getItem(static_cast<QWidget*>(parent), title, label, items, itemCount, current, editable, ok, flags);
}

const char* QInputDialog_getMultiLineText(void* parent, const char* title, const char* label, const char* text, bool* ok, int flags) {
    return QInputDialogBind::getMultiLineText(static_cast<QWidget*>(parent), title, label, text, ok, flags);
}

const char* QInputDialog_getText(void* parent, const char* title, const char* label, int mode, const char* text, bool* ok, int flags) {
    return QInputDialogBind::getText(static_cast<QWidget*>(parent), title, label, mode, text, ok, flags);
}

void QInputDialog_setDoubleValueChangedCallback(void* dialog, void (*callback)(void*, double)) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleValueChangedCallback(callback);
}

void QInputDialog_setDoubleValueSelectedCallback(void* dialog, void (*callback)(void*, double)) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleValueSelectedCallback(callback);
}

void QInputDialog_setIntValueChangedCallback(void* dialog, void (*callback)(void*, int)) {
    static_cast<QInputDialogBind*>(dialog)->setIntValueChangedCallback(callback);
}

void QInputDialog_setIntValueSelectedCallback(void* dialog, void (*callback)(void*, int)) {
    static_cast<QInputDialogBind*>(dialog)->setIntValueSelectedCallback(callback);
}

void QInputDialog_setTextValueChangedCallback(void* dialog, void (*callback)(void*, const char*)) {
    static_cast<QInputDialogBind*>(dialog)->setTextValueChangedCallback(callback);
}

void QInputDialog_setTextValueSelectedCallback(void* dialog, void (*callback)(void*, const char*)) {
    static_cast<QInputDialogBind*>(dialog)->setTextValueSelectedCallback(callback);
}

}
