#ifndef QT6_QINPUTDIALOG_H
#define QT6_QINPUTDIALOG_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*QInputDialogDoubleValueChangedCallback)(void*, double);
typedef void (*QInputDialogDoubleValueSelectedCallback)(void*, double);
typedef void (*QInputDialogIntValueChangedCallback)(void*, int);
typedef void (*QInputDialogIntValueSelectedCallback)(void*, int);
typedef void (*QInputDialogTextValueChangedCallback)(void*, const char*);
typedef void (*QInputDialogTextValueSelectedCallback)(void*, const char*);

// InputMode enum
enum QInputDialogInputMode {
    QInputDialog_TextInput = 0,
    QInputDialog_IntInput = 1,
    QInputDialog_DoubleInput = 2
};

// InputDialogOption enum
enum QInputDialogOption {
    QInputDialog_NoButtons = 0x00000001,
    QInputDialog_UseListViewForComboBoxItems = 0x00000002
};

// コンストラクタ/デストラクタ
void* QInputDialog_create(void* parent);
void QInputDialog_delete(void* dialog);

// プロパティの設定と取得
void QInputDialog_setCancelButtonText(void* dialog, const char* text);
const char* QInputDialog_cancelButtonText(void* dialog);
void QInputDialog_setComboBoxEditable(void* dialog, bool editable);
bool QInputDialog_isComboBoxEditable(void* dialog);
void QInputDialog_setComboBoxItems(void* dialog, const char** items, int count);
void QInputDialog_setDoubleDecimals(void* dialog, int decimals);
int QInputDialog_doubleDecimals(void* dialog);
void QInputDialog_setDoubleMaximum(void* dialog, double max);
double QInputDialog_doubleMaximum(void* dialog);
void QInputDialog_setDoubleMinimum(void* dialog, double min);
double QInputDialog_doubleMinimum(void* dialog);
void QInputDialog_setDoubleRange(void* dialog, double min, double max);
void QInputDialog_setDoubleStep(void* dialog, double step);
double QInputDialog_doubleStep(void* dialog);
void QInputDialog_setDoubleValue(void* dialog, double value);
double QInputDialog_doubleValue(void* dialog);
void QInputDialog_setInputMode(void* dialog, int mode);
int QInputDialog_inputMode(void* dialog);
void QInputDialog_setIntMaximum(void* dialog, int max);
int QInputDialog_intMaximum(void* dialog);
void QInputDialog_setIntMinimum(void* dialog, int min);
int QInputDialog_intMinimum(void* dialog);
void QInputDialog_setIntRange(void* dialog, int min, int max);
void QInputDialog_setIntStep(void* dialog, int step);
int QInputDialog_intStep(void* dialog);
void QInputDialog_setIntValue(void* dialog, int value);
int QInputDialog_intValue(void* dialog);
void QInputDialog_setLabelText(void* dialog, const char* text);
const char* QInputDialog_labelText(void* dialog);
void QInputDialog_setOkButtonText(void* dialog, const char* text);
const char* QInputDialog_okButtonText(void* dialog);
void QInputDialog_setOptions(void* dialog, int options);
int QInputDialog_options(void* dialog);
void QInputDialog_setOption(void* dialog, int option, bool on);
bool QInputDialog_testOption(void* dialog, int option);
void QInputDialog_setTextEchoMode(void* dialog, int mode);
int QInputDialog_textEchoMode(void* dialog);
void QInputDialog_setTextValue(void* dialog, const char* text);
const char* QInputDialog_textValue(void* dialog);

// 操作
void QInputDialog_open(void* dialog);
void QInputDialog_done(void* dialog, int result);
void QInputDialog_setVisible(void* dialog, bool visible);

// スタティック関数
double QInputDialog_getDouble(void* parent, const char* title, const char* label, double value, double min, double max, int decimals, bool* ok, int flags);
int QInputDialog_getInt(void* parent, const char* title, const char* label, int value, int min, int max, int step, bool* ok, int flags);
const char* QInputDialog_getItem(void* parent, const char* title, const char* label, const char** items, int itemCount, int current, bool editable, bool* ok, int flags);
const char* QInputDialog_getMultiLineText(void* parent, const char* title, const char* label, const char* text, bool* ok, int flags);
const char* QInputDialog_getText(void* parent, const char* title, const char* label, int mode, const char* text, bool* ok, int flags);

// コールバック設定
void QInputDialog_setDoubleValueChangedCallback(void* dialog, QInputDialogDoubleValueChangedCallback callback);
void QInputDialog_setDoubleValueSelectedCallback(void* dialog, QInputDialogDoubleValueSelectedCallback callback);
void QInputDialog_setIntValueChangedCallback(void* dialog, QInputDialogIntValueChangedCallback callback);
void QInputDialog_setIntValueSelectedCallback(void* dialog, QInputDialogIntValueSelectedCallback callback);
void QInputDialog_setTextValueChangedCallback(void* dialog, QInputDialogTextValueChangedCallback callback);
void QInputDialog_setTextValueSelectedCallback(void* dialog, QInputDialogTextValueSelectedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QT6_QINPUTDIALOG_H
