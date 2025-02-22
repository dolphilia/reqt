#include "c_q_radio_button.h"
#include "bind_q_radio_button.h"
#include "handler_radio_button.h"
#include <QString>
#include <QIcon>
#include <QKeySequence>

extern "C" {

void* QRadioButton_create(void* parent)
{
    return new BindQRadioButton(reinterpret_cast<QWidget*>(parent));
}

void* QRadioButton_createWithText(const char* text, void* parent)
{
    return new BindQRadioButton(QString::fromUtf8(text), reinterpret_cast<QWidget*>(parent));
}

void QRadioButton_delete(void* radio_button)
{
    delete static_cast<BindQRadioButton*>(radio_button);
}

void QRadioButton_setText(void* radio_button, const char* text)
{
    static_cast<BindQRadioButton*>(radio_button)->setText(QString::fromUtf8(text));
}

const char* QRadioButton_text(void* radio_button)
{
    QString text = static_cast<BindQRadioButton*>(radio_button)->text();
    return qstrdup(text.toUtf8().constData());
}

void QRadioButton_setChecked(void* radio_button, bool checked)
{
    static_cast<BindQRadioButton*>(radio_button)->setChecked(checked);
}

bool QRadioButton_isChecked(void* radio_button)
{
    return static_cast<BindQRadioButton*>(radio_button)->isChecked();
}

void QRadioButton_setEnabled(void* radio_button, bool enabled)
{
    static_cast<BindQRadioButton*>(radio_button)->setEnabled(enabled);
}

bool QRadioButton_isEnabled(void* radio_button)
{
    return static_cast<BindQRadioButton*>(radio_button)->isEnabled();
}

void QRadioButton_setIcon(void* radio_button, const char* icon_path)
{
    static_cast<BindQRadioButton*>(radio_button)->setIcon(QIcon(QString::fromUtf8(icon_path)));
}

void QRadioButton_setShortcut(void* radio_button, const char* shortcut)
{
    static_cast<BindQRadioButton*>(radio_button)->setShortcut(QKeySequence(QString::fromUtf8(shortcut)));
}

void QRadioButton_setAutoExclusive(void* radio_button, bool auto_exclusive)
{
    static_cast<BindQRadioButton*>(radio_button)->setAutoExclusive(auto_exclusive);
}

bool QRadioButton_autoExclusive(void* radio_button)
{
    return static_cast<BindQRadioButton*>(radio_button)->autoExclusive();
}

void QRadioButton_setToggledCallback(void* radio_button, QRadioButtonToggledCallback callback)
{
    BindQRadioButton* qradio_button = static_cast<BindQRadioButton*>(radio_button);
    RadioButtonHandler* handler = qradio_button->handler();
    if (!handler) {
        handler = new RadioButtonHandler(qradio_button);
        qradio_button->setRadioButtonHandler(handler);
    }
    handler->setToggledCallback(callback);
}

void QRadioButton_setClickedCallback(void* radio_button, QRadioButtonClickedCallback callback)
{
    BindQRadioButton* qradio_button = static_cast<BindQRadioButton*>(radio_button);
    RadioButtonHandler* handler = qradio_button->handler();
    if (!handler) {
        handler = new RadioButtonHandler(qradio_button);
        qradio_button->setRadioButtonHandler(handler);
    }
    handler->setClickedCallback(callback);
}

void QRadioButton_setPressedCallback(void* radio_button, QRadioButtonPressedCallback callback)
{
    BindQRadioButton* qradio_button = static_cast<BindQRadioButton*>(radio_button);
    RadioButtonHandler* handler = qradio_button->handler();
    if (!handler) {
        handler = new RadioButtonHandler(qradio_button);
        qradio_button->setRadioButtonHandler(handler);
    }
    handler->setPressedCallback(callback);
}

void QRadioButton_setReleasedCallback(void* radio_button, QRadioButtonReleasedCallback callback)
{
    BindQRadioButton* qradio_button = static_cast<BindQRadioButton*>(radio_button);
    RadioButtonHandler* handler = qradio_button->handler();
    if (!handler) {
        handler = new RadioButtonHandler(qradio_button);
        qradio_button->setRadioButtonHandler(handler);
    }
    handler->setReleasedCallback(callback);
}

}
