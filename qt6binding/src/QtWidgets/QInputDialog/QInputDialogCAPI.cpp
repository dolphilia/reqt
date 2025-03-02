#include "QInputDialogBind.h"
#include "QInputDialogHandler.h"
#include <QInputDialog>
#include <QLineEdit>

extern "C" {

// コンストラクタとデストラクタ
void* QInputDialog_create(void* parent) {
    return QInputDialogBind::create(static_cast<QWidget*>(parent));
}

void QInputDialog_delete(void* dialog) {
    QInputDialogBind::destroy(static_cast<QInputDialog*>(dialog));
}

// プロパティの設定と取得
void QInputDialog_setCancelButtonText(void* dialog, const char* text) {
    QInputDialogBind::setCancelButtonText(static_cast<QInputDialog*>(dialog), text);
}

const char* QInputDialog_cancelButtonText(void* dialog) {
    if (!dialog) return nullptr;
    static QByteArray data;
    data = QInputDialogBind::cancelButtonText(static_cast<QInputDialog*>(dialog)).toUtf8();
    return data.constData();
}

void QInputDialog_setComboBoxEditable(void* dialog, bool editable) {
    QInputDialogBind::setComboBoxEditable(static_cast<QInputDialog*>(dialog), editable);
}

bool QInputDialog_isComboBoxEditable(void* dialog) {
    return QInputDialogBind::isComboBoxEditable(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setDoubleDecimals(void* dialog, int decimals) {
    QInputDialogBind::setDoubleDecimals(static_cast<QInputDialog*>(dialog), decimals);
}

int QInputDialog_doubleDecimals(void* dialog) {
    return QInputDialogBind::doubleDecimals(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setDoubleMaximum(void* dialog, double max) {
    QInputDialogBind::setDoubleMaximum(static_cast<QInputDialog*>(dialog), max);
}

double QInputDialog_doubleMaximum(void* dialog) {
    return QInputDialogBind::doubleMaximum(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setDoubleMinimum(void* dialog, double min) {
    QInputDialogBind::setDoubleMinimum(static_cast<QInputDialog*>(dialog), min);
}

double QInputDialog_doubleMinimum(void* dialog) {
    return QInputDialogBind::doubleMinimum(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setDoubleStep(void* dialog, double step) {
    QInputDialogBind::setDoubleStep(static_cast<QInputDialog*>(dialog), step);
}

double QInputDialog_doubleStep(void* dialog) {
    return QInputDialogBind::doubleStep(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setDoubleValue(void* dialog, double value) {
    QInputDialogBind::setDoubleValue(static_cast<QInputDialog*>(dialog), value);
}

double QInputDialog_doubleValue(void* dialog) {
    return QInputDialogBind::doubleValue(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setInputMode(void* dialog, int mode) {
    QInputDialogBind::setInputMode(static_cast<QInputDialog*>(dialog), mode);
}

int QInputDialog_inputMode(void* dialog) {
    return QInputDialogBind::inputMode(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setIntMaximum(void* dialog, int max) {
    QInputDialogBind::setIntMaximum(static_cast<QInputDialog*>(dialog), max);
}

int QInputDialog_intMaximum(void* dialog) {
    return QInputDialogBind::intMaximum(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setIntMinimum(void* dialog, int min) {
    QInputDialogBind::setIntMinimum(static_cast<QInputDialog*>(dialog), min);
}

int QInputDialog_intMinimum(void* dialog) {
    return QInputDialogBind::intMinimum(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setIntStep(void* dialog, int step) {
    QInputDialogBind::setIntStep(static_cast<QInputDialog*>(dialog), step);
}

int QInputDialog_intStep(void* dialog) {
    return QInputDialogBind::intStep(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setIntValue(void* dialog, int value) {
    QInputDialogBind::setIntValue(static_cast<QInputDialog*>(dialog), value);
}

int QInputDialog_intValue(void* dialog) {
    return QInputDialogBind::intValue(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setLabelText(void* dialog, const char* text) {
    QInputDialogBind::setLabelText(static_cast<QInputDialog*>(dialog), text);
}

const char* QInputDialog_labelText(void* dialog) {
    if (!dialog) return nullptr;
    static QByteArray data;
    data = QInputDialogBind::labelText(static_cast<QInputDialog*>(dialog)).toUtf8();
    return data.constData();
}

void QInputDialog_setOkButtonText(void* dialog, const char* text) {
    QInputDialogBind::setOkButtonText(static_cast<QInputDialog*>(dialog), text);
}

const char* QInputDialog_okButtonText(void* dialog) {
    if (!dialog) return nullptr;
    static QByteArray data;
    data = QInputDialogBind::okButtonText(static_cast<QInputDialog*>(dialog)).toUtf8();
    return data.constData();
}

void QInputDialog_setOptions(void* dialog, int options) {
    QInputDialogBind::setOptions(static_cast<QInputDialog*>(dialog), options);
}

int QInputDialog_options(void* dialog) {
    return QInputDialogBind::options(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setOption(void* dialog, int option, bool on) {
    QInputDialogBind::setOption(static_cast<QInputDialog*>(dialog), option, on);
}

bool QInputDialog_testOption(void* dialog, int option) {
    return QInputDialogBind::testOption(static_cast<QInputDialog*>(dialog), option);
}

void QInputDialog_setTextEchoMode(void* dialog, int mode) {
    QInputDialogBind::setTextEchoMode(static_cast<QInputDialog*>(dialog), mode);
}

int QInputDialog_textEchoMode(void* dialog) {
    return QInputDialogBind::textEchoMode(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_setTextValue(void* dialog, const char* text) {
    QInputDialogBind::setTextValue(static_cast<QInputDialog*>(dialog), text);
}

const char* QInputDialog_textValue(void* dialog) {
    if (!dialog) return nullptr;
    static QByteArray data;
    data = QInputDialogBind::textValue(static_cast<QInputDialog*>(dialog)).toUtf8();
    return data.constData();
}

// 操作
void QInputDialog_open(void* dialog) {
    QInputDialogBind::open(static_cast<QInputDialog*>(dialog));
}

void QInputDialog_done(void* dialog, int result) {
    QInputDialogBind::done(static_cast<QInputDialog*>(dialog), result);
}

void QInputDialog_setVisible(void* dialog, bool visible) {
    QInputDialogBind::setVisible(static_cast<QInputDialog*>(dialog), visible);
}

// スタティック関数
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

// コールバック設定
void QInputDialog_setDoubleValueChangedCallback(void* dialog, QInputDialogDoubleValueChangedCallback callback) {
    QInputDialogBind::setDoubleValueChangedCallback(static_cast<QInputDialog*>(dialog), callback);
}

void QInputDialog_setDoubleValueSelectedCallback(void* dialog, QInputDialogDoubleValueSelectedCallback callback) {
    QInputDialogBind::setDoubleValueSelectedCallback(static_cast<QInputDialog*>(dialog), callback);
}

void QInputDialog_setIntValueChangedCallback(void* dialog, QInputDialogIntValueChangedCallback callback) {
    QInputDialogBind::setIntValueChangedCallback(static_cast<QInputDialog*>(dialog), callback);
}

void QInputDialog_setIntValueSelectedCallback(void* dialog, QInputDialogIntValueSelectedCallback callback) {
    QInputDialogBind::setIntValueSelectedCallback(static_cast<QInputDialog*>(dialog), callback);
}

void QInputDialog_setTextValueChangedCallback(void* dialog, QInputDialogTextValueChangedCallback callback) {
    QInputDialogBind::setTextValueChangedCallback(static_cast<QInputDialog*>(dialog), callback);
}

void QInputDialog_setTextValueSelectedCallback(void* dialog, QInputDialogTextValueSelectedCallback callback) {
    QInputDialogBind::setTextValueSelectedCallback(static_cast<QInputDialog*>(dialog), callback);
}

} // extern "C"
