#include "QInputDialogBind.h"
#include "QInputDialogHandler.h"

QInputDialogBind::QInputDialogBind(QWidget* parent, Qt::WindowFlags flags)
    : QInputDialog(parent, flags)
    , handler(new QInputDialogHandler(this)) {
    connect(this, &QInputDialog::doubleValueChanged, handler, &QInputDialogHandler::onDoubleValueChanged);
    connect(this, &QInputDialog::doubleValueSelected, handler, &QInputDialogHandler::onDoubleValueSelected);
    connect(this, &QInputDialog::intValueChanged, handler, &QInputDialogHandler::onIntValueChanged);
    connect(this, &QInputDialog::intValueSelected, handler, &QInputDialogHandler::onIntValueSelected);
    connect(this, &QInputDialog::textValueChanged, handler, &QInputDialogHandler::onTextValueChanged);
    connect(this, &QInputDialog::textValueSelected, handler, &QInputDialogHandler::onTextValueSelected);
}

QInputDialogBind::~QInputDialogBind() {
    delete handler;
}

void QInputDialogBind::setDoubleValueChangedCallback(DoubleValueChangedCallback callback) const {
    handler->setDoubleValueChangedCallback(callback);
}

void QInputDialogBind::setDoubleValueSelectedCallback(DoubleValueSelectedCallback callback) const {
    handler->setDoubleValueSelectedCallback(callback);
}

void QInputDialogBind::setIntValueChangedCallback(IntValueChangedCallback callback) const {
    handler->setIntValueChangedCallback(callback);
}

void QInputDialogBind::setIntValueSelectedCallback(IntValueSelectedCallback callback) const {
    handler->setIntValueSelectedCallback(callback);
}

void QInputDialogBind::setTextValueChangedCallback(TextValueChangedCallback callback) const {
    handler->setTextValueChangedCallback(callback);
}

void QInputDialogBind::setTextValueSelectedCallback(TextValueSelectedCallback callback) const {
    handler->setTextValueSelectedCallback(callback);
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
