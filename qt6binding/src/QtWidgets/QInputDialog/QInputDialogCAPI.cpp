#include "QInputDialogBind.h"

extern "C" {

void* QInputDialog_create(void* parent) {
    return new QInputDialogBind(static_cast<QWidget*>(parent));
}

void QInputDialog_delete(void* dialog) {
    delete static_cast<QInputDialogBind*>(dialog);
}

// Methods

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

// Static Methods

double QInputDialog_getDouble(void* parent, const char* title, const char* label, double value, double min, double max, int decimals, bool* ok, int flags) {
    bool okValue;
    double result = QInputDialog::getDouble(
        static_cast<QWidget*>(parent),
        QString::fromUtf8(title),
        QString::fromUtf8(label),
        value,
        min,
        max,
        decimals,
        &okValue,
        static_cast<Qt::WindowFlags>(flags)
    );
    if (ok) *ok = okValue;
    return result;
}

int QInputDialog_getInt(void* parent, const char* title, const char* label, int value, int min, int max, int step, bool* ok, int flags) {
    bool okValue;
    int result = QInputDialog::getInt(
        static_cast<QWidget*>(parent),
        QString::fromUtf8(title),
        QString::fromUtf8(label),
        value,
        min,
        max,
        step,
        &okValue,
        static_cast<Qt::WindowFlags>(flags)
    );
    if (ok) *ok = okValue;
    return result;
}

const char* QInputDialog_getItem(void* parent, const char* title, const char* label, const char** items, int itemCount, int current, bool editable, bool* ok, int flags) {
    if (!items || itemCount < 0) return nullptr;
    bool okValue;
    QStringList itemList;
    for (int i = 0; i < itemCount; ++i) {
        if (items[i]) {
            itemList << QString::fromUtf8(items[i]);
        }
    }
    static QByteArray data;
    QString result = QInputDialog::getItem(
        static_cast<QWidget*>(parent),
        title ? QString::fromUtf8(title) : QString(),
        label ? QString::fromUtf8(label) : QString(),
        itemList,
        current >= 0 && current < itemCount ? current : 0,
        editable,
        &okValue,
        static_cast<Qt::WindowFlags>(flags)
    );
    if (ok) *ok = okValue;
    data = result.toUtf8();
    return data.constData();
}

const char* QInputDialog_getMultiLineText(void* parent, const char* title, const char* label, const char* text, bool* ok, int flags) {
    bool okValue;
    static QByteArray data;
    QString result = QInputDialog::getMultiLineText(
        static_cast<QWidget*>(parent),
        title ? QString::fromUtf8(title) : QString(),
        label ? QString::fromUtf8(label) : QString(),
        text ? QString::fromUtf8(text) : QString(),
        &okValue,
        static_cast<Qt::WindowFlags>(flags)
    );
    if (ok) *ok = okValue;
    data = result.toUtf8();
    return data.constData();
}

const char* QInputDialog_getText(void* parent, const char* title, const char* label, int mode, const char* text, bool* ok, int flags) {
    bool okValue;
    static QByteArray data;
    QString result = QInputDialog::getText(
        static_cast<QWidget*>(parent),
        title ? QString::fromUtf8(title) : QString(),
        label ? QString::fromUtf8(label) : QString(),
        static_cast<QLineEdit::EchoMode>(mode),
        text ? QString::fromUtf8(text) : QString(),
        &okValue,
        static_cast<Qt::WindowFlags>(flags)
    );
    if (ok) *ok = okValue;
    data = result.toUtf8();
    return data.constData();
}

// Callback

typedef void (*QInputDialog_DoubleValueChangedCallback)(void*, double);
typedef void (*QInputDialog_DoubleValueSelectedCallback)(void*, double);
typedef void (*QInputDialog_IntValueChangedCallback)(void*, int);
typedef void (*QInputDialog_IntValueSelectedCallback)(void*, int);
typedef void (*QInputDialog_TextValueChangedCallback)(void*, const char*);
typedef void (*QInputDialog_TextValueSelectedCallback)(void*, const char*);

void QInputDialog_setDoubleValueChangedCallback(void* dialog, QInputDialog_DoubleValueChangedCallback callback) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleValueChangedCallback(callback);
}

void QInputDialog_setDoubleValueSelectedCallback(void* dialog, QInputDialog_DoubleValueSelectedCallback callback) {
    static_cast<QInputDialogBind*>(dialog)->setDoubleValueSelectedCallback(callback);
}

void QInputDialog_setIntValueChangedCallback(void* dialog, QInputDialog_IntValueChangedCallback callback) {
    static_cast<QInputDialogBind*>(dialog)->setIntValueChangedCallback(callback);
}

void QInputDialog_setIntValueSelectedCallback(void* dialog, QInputDialog_IntValueSelectedCallback callback) {
    static_cast<QInputDialogBind*>(dialog)->setIntValueSelectedCallback(callback);
}

void QInputDialog_setTextValueChangedCallback(void* dialog, QInputDialog_TextValueChangedCallback callback) {
    static_cast<QInputDialogBind*>(dialog)->setTextValueChangedCallback(callback);
}

void QInputDialog_setTextValueSelectedCallback(void* dialog, QInputDialog_TextValueSelectedCallback callback) {
    static_cast<QInputDialogBind*>(dialog)->setTextValueSelectedCallback(callback);
}

}
