#include "QInputDialogBind.h"
#include <QInputDialog>
#include <QLineEdit>

QInputDialog* QInputDialogBind::create(QWidget* parent, int flags) {
    QInputDialog* dialog = new QInputDialog(parent);
    if (flags != 0) {
        dialog->setWindowFlags(static_cast<Qt::WindowFlags>(flags));
    }
    return dialog;
}

void QInputDialogBind::destroy(QInputDialog* dialog) {
    if (!dialog) return;
    // 関連するハンドラーを検索して削除
    QInputDialogHandler* handler = dialog->findChild<QInputDialogHandler*>();
    if (handler) {
        delete handler;
    }
    delete dialog;
}

QString QInputDialogBind::cancelButtonText(QInputDialog* dialog) {
    return dialog->cancelButtonText();
}

void QInputDialogBind::setCancelButtonText(QInputDialog* dialog, const char* text) {
    dialog->setCancelButtonText(QString::fromUtf8(text));
}

bool QInputDialogBind::isComboBoxEditable(QInputDialog* dialog) {
    return dialog->isComboBoxEditable();
}

void QInputDialogBind::setComboBoxEditable(QInputDialog* dialog, bool editable) {
    dialog->setComboBoxEditable(editable);
}

void QInputDialogBind::setComboBoxItems(QInputDialog* dialog, const char** items, int count) {
    QStringList itemList;
    for (int i = 0; i < count; ++i) {
        itemList << QString::fromUtf8(items[i]);
    }
    dialog->setComboBoxItems(itemList);
}

int QInputDialogBind::doubleDecimals(QInputDialog* dialog) {
    return dialog->doubleDecimals();
}

void QInputDialogBind::setDoubleDecimals(QInputDialog* dialog, int decimals) {
    dialog->setDoubleDecimals(decimals);
}

double QInputDialogBind::doubleMaximum(QInputDialog* dialog) {
    return dialog->doubleMaximum();
}

void QInputDialogBind::setDoubleMaximum(QInputDialog* dialog, double max) {
    dialog->setDoubleMaximum(max);
}

double QInputDialogBind::doubleMinimum(QInputDialog* dialog) {
    return dialog->doubleMinimum();
}

void QInputDialogBind::setDoubleMinimum(QInputDialog* dialog, double min) {
    dialog->setDoubleMinimum(min);
}

void QInputDialogBind::setDoubleRange(QInputDialog* dialog, double min, double max) {
    dialog->setDoubleRange(min, max);
}

double QInputDialogBind::doubleStep(QInputDialog* dialog) {
    return dialog->doubleStep();
}

void QInputDialogBind::setDoubleStep(QInputDialog* dialog, double step) {
    dialog->setDoubleStep(step);
}

double QInputDialogBind::doubleValue(QInputDialog* dialog) {
    return dialog->doubleValue();
}

void QInputDialogBind::setDoubleValue(QInputDialog* dialog, double value) {
    dialog->setDoubleValue(value);
}

int QInputDialogBind::inputMode(QInputDialog* dialog) {
    return static_cast<int>(dialog->inputMode());
}

void QInputDialogBind::setInputMode(QInputDialog* dialog, int mode) {
    dialog->setInputMode(static_cast<QInputDialog::InputMode>(mode));
}

int QInputDialogBind::intMaximum(QInputDialog* dialog) {
    return dialog->intMaximum();
}

void QInputDialogBind::setIntMaximum(QInputDialog* dialog, int max) {
    dialog->setIntMaximum(max);
}

int QInputDialogBind::intMinimum(QInputDialog* dialog) {
    return dialog->intMinimum();
}

void QInputDialogBind::setIntMinimum(QInputDialog* dialog, int min) {
    dialog->setIntMinimum(min);
}

void QInputDialogBind::setIntRange(QInputDialog* dialog, int min, int max) {
    dialog->setIntRange(min, max);
}

int QInputDialogBind::intStep(QInputDialog* dialog) {
    return dialog->intStep();
}

void QInputDialogBind::setIntStep(QInputDialog* dialog, int step) {
    dialog->setIntStep(step);
}

int QInputDialogBind::intValue(QInputDialog* dialog) {
    return dialog->intValue();
}

void QInputDialogBind::setIntValue(QInputDialog* dialog, int value) {
    dialog->setIntValue(value);
}

QString QInputDialogBind::labelText(QInputDialog* dialog) {
    return dialog->labelText();
}

void QInputDialogBind::setLabelText(QInputDialog* dialog, const char* text) {
    dialog->setLabelText(QString::fromUtf8(text));
}

QString QInputDialogBind::okButtonText(QInputDialog* dialog) {
    return dialog->okButtonText();
}

void QInputDialogBind::setOkButtonText(QInputDialog* dialog, const char* text) {
    dialog->setOkButtonText(QString::fromUtf8(text));
}

int QInputDialogBind::options(QInputDialog* dialog) {
    return static_cast<int>(dialog->options());
}

void QInputDialogBind::setOption(QInputDialog* dialog, int option, bool on) {
    dialog->setOption(static_cast<QInputDialog::InputDialogOption>(option), on);
}

void QInputDialogBind::setOptions(QInputDialog* dialog, int options) {
    dialog->setOptions(static_cast<QInputDialog::InputDialogOptions>(options));
}

bool QInputDialogBind::testOption(QInputDialog* dialog, int option) {
    return dialog->testOption(static_cast<QInputDialog::InputDialogOption>(option));
}

int QInputDialogBind::textEchoMode(QInputDialog* dialog) {
    return static_cast<int>(dialog->textEchoMode());
}

void QInputDialogBind::setTextEchoMode(QInputDialog* dialog, int mode) {
    dialog->setTextEchoMode(static_cast<QLineEdit::EchoMode>(mode));
}

QString QInputDialogBind::textValue(QInputDialog* dialog) {
    return dialog->textValue();
}

void QInputDialogBind::setTextValue(QInputDialog* dialog, const char* text) {
    dialog->setTextValue(QString::fromUtf8(text));
}

void QInputDialogBind::open(QInputDialog* dialog) {
    dialog->open();
}

void QInputDialogBind::done(QInputDialog* dialog, int result) {
    dialog->done(result);
}

void QInputDialogBind::setVisible(QInputDialog* dialog, bool visible) {
    dialog->setVisible(visible);
}

double QInputDialogBind::getDouble(QWidget* parent, const char* title, const char* label, double value, double min, double max, int decimals, bool* ok, int flags) {
    bool okValue;
    double result = QInputDialog::getDouble(
        parent,
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

int QInputDialogBind::getInt(QWidget* parent, const char* title, const char* label, int value, int min, int max, int step, bool* ok, int flags) {
    bool okValue;
    int result = QInputDialog::getInt(
        parent,
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

const char* QInputDialogBind::getItem(QWidget* parent, const char* title, const char* label, const char** items, int itemCount, int current, bool editable, bool* ok, int flags) {
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
        parent,
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

const char* QInputDialogBind::getMultiLineText(QWidget* parent, const char* title, const char* label, const char* text, bool* ok, int flags) {
    bool okValue;
    static QByteArray data;
    QString result = QInputDialog::getMultiLineText(
        parent,
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

const char* QInputDialogBind::getText(QWidget* parent, const char* title, const char* label, int mode, const char* text, bool* ok, int flags) {
    bool okValue;
    static QByteArray data;
    QString result = QInputDialog::getText(
        parent,
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

void QInputDialogBind::setDoubleValueChangedCallback(QInputDialog* dialog, QInputDialogDoubleValueChangedCallback callback) {
    if (!dialog) return;
    QInputDialogHandler* handler = dialog->findChild<QInputDialogHandler*>();
    if (!handler) {
        handler = new QInputDialogHandler(dialog);
        handler->setObjectName("QInputDialogHandler");  // ハンドラーに名前を設定
        QObject::connect(dialog, &QInputDialog::doubleValueChanged, handler, &QInputDialogHandler::onDoubleValueChanged);
    }
    handler->setDoubleValueChangedCallback(callback);
}

void QInputDialogBind::setDoubleValueSelectedCallback(QInputDialog* dialog, QInputDialogDoubleValueSelectedCallback callback) {
    if (!dialog) return;
    QInputDialogHandler* handler = dialog->findChild<QInputDialogHandler*>();
    if (!handler) {
        handler = new QInputDialogHandler(dialog);
        handler->setObjectName("QInputDialogHandler");
        QObject::connect(dialog, &QInputDialog::doubleValueSelected, handler, &QInputDialogHandler::onDoubleValueSelected);
    }
    handler->setDoubleValueSelectedCallback(callback);
}

void QInputDialogBind::setIntValueChangedCallback(QInputDialog* dialog, QInputDialogIntValueChangedCallback callback) {
    if (!dialog) return;
    QInputDialogHandler* handler = dialog->findChild<QInputDialogHandler*>();
    if (!handler) {
        handler = new QInputDialogHandler(dialog);
        handler->setObjectName("QInputDialogHandler");
        QObject::connect(dialog, &QInputDialog::intValueChanged, handler, &QInputDialogHandler::onIntValueChanged);
    }
    handler->setIntValueChangedCallback(callback);
}

void QInputDialogBind::setIntValueSelectedCallback(QInputDialog* dialog, QInputDialogIntValueSelectedCallback callback) {
    if (!dialog) return;
    QInputDialogHandler* handler = dialog->findChild<QInputDialogHandler*>();
    if (!handler) {
        handler = new QInputDialogHandler(dialog);
        handler->setObjectName("QInputDialogHandler");
        QObject::connect(dialog, &QInputDialog::intValueSelected, handler, &QInputDialogHandler::onIntValueSelected);
    }
    handler->setIntValueSelectedCallback(callback);
}

void QInputDialogBind::setTextValueChangedCallback(QInputDialog* dialog, QInputDialogTextValueChangedCallback callback) {
    if (!dialog) return;
    QInputDialogHandler* handler = dialog->findChild<QInputDialogHandler*>();
    if (!handler) {
        handler = new QInputDialogHandler(dialog);
        handler->setObjectName("QInputDialogHandler");
        QObject::connect(dialog, &QInputDialog::textValueChanged, handler, &QInputDialogHandler::onTextValueChanged);
    }
    handler->setTextValueChangedCallback(callback);
}

void QInputDialogBind::setTextValueSelectedCallback(QInputDialog* dialog, QInputDialogTextValueSelectedCallback callback) {
    if (!dialog) return;
    QInputDialogHandler* handler = dialog->findChild<QInputDialogHandler*>();
    if (!handler) {
        handler = new QInputDialogHandler(dialog);
        handler->setObjectName("QInputDialogHandler");
        QObject::connect(dialog, &QInputDialog::textValueSelected, handler, &QInputDialogHandler::onTextValueSelected);
    }
    handler->setTextValueSelectedCallback(callback);
}
