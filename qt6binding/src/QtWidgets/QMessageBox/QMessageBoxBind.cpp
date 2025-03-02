#include "QMessageBoxBind.h"
#include "QMessageBoxHandler.h"

QMessageBox* QMessageBoxBind::create(QWidget* parent) {
    QMessageBox* messageBox = new QMessageBox(parent);
    setHandler(messageBox, new QMessageBoxHandler(messageBox, messageBox));
    return messageBox;
}

QMessageBox* QMessageBoxBind::createWithIcon(QMessageBox::Icon icon, const QString& title, const QString& text, QMessageBox::StandardButtons buttons, QWidget* parent, Qt::WindowFlags f) {
    QMessageBox* messageBox = new QMessageBox(icon, title, text, buttons, parent, f);
    setHandler(messageBox, new QMessageBoxHandler(messageBox, messageBox));
    return messageBox;
}

void QMessageBoxBind::destroy(QMessageBox* messageBox) {
    if (messageBox) {
        delete messageBox;
    }
}

QString QMessageBoxBind::detailedText(QMessageBox* messageBox) {
    return messageBox->detailedText();
}

QMessageBox::Icon QMessageBoxBind::icon(QMessageBox* messageBox) {
    return messageBox->icon();
}

QPixmap* QMessageBoxBind::iconPixmap(QMessageBox* messageBox) {
    return new QPixmap(messageBox->iconPixmap());
}

QString QMessageBoxBind::informativeText(QMessageBox* messageBox) {
    return messageBox->informativeText();
}

QMessageBox::StandardButtons QMessageBoxBind::standardButtons(QMessageBox* messageBox) {
    return messageBox->standardButtons();
}

QString QMessageBoxBind::text(QMessageBox* messageBox) {
    return messageBox->text();
}

Qt::TextFormat QMessageBoxBind::textFormat(QMessageBox* messageBox) {
    return messageBox->textFormat();
}

Qt::TextInteractionFlags QMessageBoxBind::textInteractionFlags(QMessageBox* messageBox) {
    return messageBox->textInteractionFlags();
}

void QMessageBoxBind::setDetailedText(QMessageBox* messageBox, const QString& text) {
    messageBox->setDetailedText(text);
}

void QMessageBoxBind::setIcon(QMessageBox* messageBox, QMessageBox::Icon icon) {
    messageBox->setIcon(icon);
}

void QMessageBoxBind::setIconPixmap(QMessageBox* messageBox, const QPixmap& pixmap) {
    messageBox->setIconPixmap(pixmap);
}

void QMessageBoxBind::setInformativeText(QMessageBox* messageBox, const QString& text) {
    messageBox->setInformativeText(text);
}

void QMessageBoxBind::setStandardButtons(QMessageBox* messageBox, QMessageBox::StandardButtons buttons) {
    messageBox->setStandardButtons(buttons);
}

void QMessageBoxBind::setText(QMessageBox* messageBox, const QString& text) {
    messageBox->setText(text);
}

void QMessageBoxBind::setTextFormat(QMessageBox* messageBox, Qt::TextFormat format) {
    messageBox->setTextFormat(format);
}

void QMessageBoxBind::setTextInteractionFlags(QMessageBox* messageBox, Qt::TextInteractionFlags flags) {
    messageBox->setTextInteractionFlags(flags);
}

void QMessageBoxBind::setWindowTitle(QMessageBox* messageBox, const QString& title) {
    messageBox->setWindowTitle(title);
}

QPushButton* QMessageBoxBind::addButton(QMessageBox* messageBox, QMessageBox::StandardButton button) {
    return messageBox->addButton(button);
}

QPushButton* QMessageBoxBind::addButtonWithText(QMessageBox* messageBox, const QString& text, QMessageBox::ButtonRole role) {
    return messageBox->addButton(text, role);
}

void QMessageBoxBind::removeButton(QMessageBox* messageBox, QAbstractButton* button) {
    messageBox->removeButton(button);
}

QAbstractButton* QMessageBoxBind::button(QMessageBox* messageBox, QMessageBox::StandardButton which) {
    return messageBox->button(which);
}

QMessageBox::ButtonRole QMessageBoxBind::buttonRole(QMessageBox* messageBox, QAbstractButton* button) {
    return messageBox->buttonRole(button);
}

QMessageBox::StandardButton QMessageBoxBind::standardButton(QMessageBox* messageBox, QAbstractButton* button) {
    return messageBox->standardButton(button);
}

QPushButton* QMessageBoxBind::defaultButton(QMessageBox* messageBox) {
    return messageBox->defaultButton();
}

void QMessageBoxBind::setDefaultButton(QMessageBox* messageBox, QPushButton* button) {
    messageBox->setDefaultButton(button);
}

void QMessageBoxBind::setDefaultButtonStandard(QMessageBox* messageBox, QMessageBox::StandardButton button) {
    messageBox->setDefaultButton(button);
}

QAbstractButton* QMessageBoxBind::escapeButton(QMessageBox* messageBox) {
    return messageBox->escapeButton();
}

void QMessageBoxBind::setEscapeButton(QMessageBox* messageBox, QAbstractButton* button) {
    messageBox->setEscapeButton(button);
}

void QMessageBoxBind::setEscapeButtonStandard(QMessageBox* messageBox, QMessageBox::StandardButton button) {
    messageBox->setEscapeButton(button);
}

QCheckBox* QMessageBoxBind::checkBox(QMessageBox* messageBox) {
    return messageBox->checkBox();
}

void QMessageBoxBind::setCheckBox(QMessageBox* messageBox, QCheckBox* cb) {
    messageBox->setCheckBox(cb);
}

int QMessageBoxBind::exec(QMessageBox* messageBox) {
    return messageBox->exec();
}

void QMessageBoxBind::open(QMessageBox* messageBox) {
    messageBox->open();
}

void QMessageBoxBind::about(QWidget* parent, const QString& title, const QString& text) {
    QMessageBox::about(parent, title, text);
}

void QMessageBoxBind::aboutQt(QWidget* parent, const QString& title) {
    QMessageBox::aboutQt(parent, title);
}

QMessageBox::StandardButton QMessageBoxBind::critical(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton) {
    return QMessageBox::critical(parent, title, text, buttons, defaultButton);
}

QMessageBox::StandardButton QMessageBoxBind::information(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton) {
    return QMessageBox::information(parent, title, text, buttons, defaultButton);
}

QMessageBox::StandardButton QMessageBoxBind::question(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton) {
    return QMessageBox::question(parent, title, text, buttons, defaultButton);
}

QMessageBox::StandardButton QMessageBoxBind::warning(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton) {
    return QMessageBox::warning(parent, title, text, buttons, defaultButton);
}

void QMessageBoxBind::setButtonClickedCallback(QMessageBox* messageBox, void (*callback)(void*, QAbstractButton*), void* data) {
    QMessageBoxHandler* handler = getHandler(messageBox);
    if (handler) {
        handler->buttonClickedCallback = callback;
        handler->buttonClickedData = data;
    }
}

QMessageBoxHandler* QMessageBoxBind::getHandler(QMessageBox* messageBox) {
    return messageBox->findChild<QMessageBoxHandler*>();
}

void QMessageBoxBind::setHandler(QMessageBox* messageBox, QMessageBoxHandler* handler) {
    if (handler) {
        handler->setParent(messageBox);
    }
}
