#ifndef QINPUTDIALOG_BIND_H
#define QINPUTDIALOG_BIND_H

#include <QString>
#include <QInputDialog>
#include <QLineEdit>
#include "QInputDialogHandler.h"

class QInputDialogBind {
public:
    // コンストラクタ/デストラクタ
    static QInputDialog* create(QWidget* parent = nullptr, int flags = 0);
    static void destroy(QInputDialog* dialog);

    // プロパティ
    static QString cancelButtonText(QInputDialog* dialog);
    static void setCancelButtonText(QInputDialog* dialog, const char* text);
    static bool isComboBoxEditable(QInputDialog* dialog);
    static void setComboBoxEditable(QInputDialog* dialog, bool editable);
    static void setComboBoxItems(QInputDialog* dialog, const char** items, int count);
    static int doubleDecimals(QInputDialog* dialog);
    static void setDoubleDecimals(QInputDialog* dialog, int decimals);
    static double doubleMaximum(QInputDialog* dialog);
    static void setDoubleMaximum(QInputDialog* dialog, double max);
    static double doubleMinimum(QInputDialog* dialog);
    static void setDoubleMinimum(QInputDialog* dialog, double min);
    static void setDoubleRange(QInputDialog* dialog, double min, double max);
    static double doubleStep(QInputDialog* dialog);
    static void setDoubleStep(QInputDialog* dialog, double step);
    static double doubleValue(QInputDialog* dialog);
    static void setDoubleValue(QInputDialog* dialog, double value);
    static int inputMode(QInputDialog* dialog);
    static void setInputMode(QInputDialog* dialog, int mode);
    static int intMaximum(QInputDialog* dialog);
    static void setIntMaximum(QInputDialog* dialog, int max);
    static int intMinimum(QInputDialog* dialog);
    static void setIntMinimum(QInputDialog* dialog, int min);
    static void setIntRange(QInputDialog* dialog, int min, int max);
    static int intStep(QInputDialog* dialog);
    static void setIntStep(QInputDialog* dialog, int step);
    static int intValue(QInputDialog* dialog);
    static void setIntValue(QInputDialog* dialog, int value);
    static QString labelText(QInputDialog* dialog);
    static void setLabelText(QInputDialog* dialog, const char* text);
    static QString okButtonText(QInputDialog* dialog);
    static void setOkButtonText(QInputDialog* dialog, const char* text);
    static int options(QInputDialog* dialog);
    static void setOption(QInputDialog* dialog, int option, bool on);
    static void setOptions(QInputDialog* dialog, int options);
    static bool testOption(QInputDialog* dialog, int option);
    static int textEchoMode(QInputDialog* dialog);
    static void setTextEchoMode(QInputDialog* dialog, int mode);
    static QString textValue(QInputDialog* dialog);
    static void setTextValue(QInputDialog* dialog, const char* text);

    // 操作
    static void open(QInputDialog* dialog);
    static void done(QInputDialog* dialog, int result);
    static void setVisible(QInputDialog* dialog, bool visible);

    // スタティック関数
    static double getDouble(QWidget* parent, const char* title, const char* label, double value, double min, double max, int decimals, bool* ok, int flags);
    static int getInt(QWidget* parent, const char* title, const char* label, int value, int min, int max, int step, bool* ok, int flags);
    static const char* getItem(QWidget* parent, const char* title, const char* label, const char** items, int itemCount, int current, bool editable, bool* ok, int flags);
    static const char* getMultiLineText(QWidget* parent, const char* title, const char* label, const char* text, bool* ok, int flags);
    static const char* getText(QWidget* parent, const char* title, const char* label, int mode, const char* text, bool* ok, int flags);

    // コールバック設定
    static void setDoubleValueChangedCallback(QInputDialog* dialog, QInputDialogDoubleValueChangedCallback callback);
    static void setDoubleValueSelectedCallback(QInputDialog* dialog, QInputDialogDoubleValueSelectedCallback callback);
    static void setIntValueChangedCallback(QInputDialog* dialog, QInputDialogIntValueChangedCallback callback);
    static void setIntValueSelectedCallback(QInputDialog* dialog, QInputDialogIntValueSelectedCallback callback);
    static void setTextValueChangedCallback(QInputDialog* dialog, QInputDialogTextValueChangedCallback callback);
    static void setTextValueSelectedCallback(QInputDialog* dialog, QInputDialogTextValueSelectedCallback callback);
};

#endif // QINPUTDIALOG_BIND_H
