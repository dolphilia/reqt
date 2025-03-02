#include "QMessageBoxBind.h"
#include "qmessagebox.h"

extern "C" {

// コンストラクタ/デストラクタ
void* QMessageBox_create(void* parent) {
    return QMessageBoxBind::create(static_cast<QWidget*>(parent));
}

void* QMessageBox_createWithIcon(int icon, const char* title, const char* text, int buttons, void* parent, int f) {
    return QMessageBoxBind::createWithIcon(
        static_cast<QMessageBox::Icon>(icon),
        QString::fromUtf8(title),
        QString::fromUtf8(text),
        static_cast<QMessageBox::StandardButtons>(buttons),
        static_cast<QWidget*>(parent),
        static_cast<Qt::WindowFlags>(f)
    );
}

void QMessageBox_delete(void* messageBox) {
    QMessageBoxBind::destroy(static_cast<QMessageBox*>(messageBox));
}

// プロパティ取得
const char* QMessageBox_detailedText(void* messageBox) {
    return QMessageBoxBind::detailedText(static_cast<QMessageBox*>(messageBox)).toUtf8().constData();
}

int QMessageBox_icon(void* messageBox) {
    return static_cast<int>(QMessageBoxBind::icon(static_cast<QMessageBox*>(messageBox)));
}

void* QMessageBox_iconPixmap(void* messageBox) {
    return QMessageBoxBind::iconPixmap(static_cast<QMessageBox*>(messageBox));
}

const char* QMessageBox_informativeText(void* messageBox) {
    return QMessageBoxBind::informativeText(static_cast<QMessageBox*>(messageBox)).toUtf8().constData();
}

int QMessageBox_standardButtons(void* messageBox) {
    return static_cast<int>(QMessageBoxBind::standardButtons(static_cast<QMessageBox*>(messageBox)));
}

const char* QMessageBox_text(void* messageBox) {
    return QMessageBoxBind::text(static_cast<QMessageBox*>(messageBox)).toUtf8().constData();
}

int QMessageBox_textFormat(void* messageBox) {
    return static_cast<int>(QMessageBoxBind::textFormat(static_cast<QMessageBox*>(messageBox)));
}

int QMessageBox_textInteractionFlags(void* messageBox) {
    return static_cast<int>(QMessageBoxBind::textInteractionFlags(static_cast<QMessageBox*>(messageBox)));
}

// プロパティ設定
void QMessageBox_setDetailedText(void* messageBox, const char* text) {
    QMessageBoxBind::setDetailedText(static_cast<QMessageBox*>(messageBox), QString::fromUtf8(text));
}

void QMessageBox_setIcon(void* messageBox, int icon) {
    QMessageBoxBind::setIcon(static_cast<QMessageBox*>(messageBox), static_cast<QMessageBox::Icon>(icon));
}

void QMessageBox_setIconPixmap(void* messageBox, void* pixmap) {
    QMessageBoxBind::setIconPixmap(static_cast<QMessageBox*>(messageBox), *static_cast<QPixmap*>(pixmap));
}

void QMessageBox_setInformativeText(void* messageBox, const char* text) {
    QMessageBoxBind::setInformativeText(static_cast<QMessageBox*>(messageBox), QString::fromUtf8(text));
}

void QMessageBox_setStandardButtons(void* messageBox, int buttons) {
    QMessageBoxBind::setStandardButtons(static_cast<QMessageBox*>(messageBox), static_cast<QMessageBox::StandardButtons>(buttons));
}

void QMessageBox_setText(void* messageBox, const char* text) {
    QMessageBoxBind::setText(static_cast<QMessageBox*>(messageBox), QString::fromUtf8(text));
}

void QMessageBox_setTextFormat(void* messageBox, int format) {
    QMessageBoxBind::setTextFormat(static_cast<QMessageBox*>(messageBox), static_cast<Qt::TextFormat>(format));
}

void QMessageBox_setTextInteractionFlags(void* messageBox, int flags) {
    QMessageBoxBind::setTextInteractionFlags(static_cast<QMessageBox*>(messageBox), static_cast<Qt::TextInteractionFlags>(flags));
}

void QMessageBox_setWindowTitle(void* messageBox, const char* title) {
    QMessageBoxBind::setWindowTitle(static_cast<QMessageBox*>(messageBox), QString::fromUtf8(title));
}

// ボタン関連
void* QMessageBox_addButton(void* messageBox, int button) {
    return QMessageBoxBind::addButton(static_cast<QMessageBox*>(messageBox), static_cast<QMessageBox::StandardButton>(button));
}

void* QMessageBox_addButtonWithText(void* messageBox, const char* text, int role) {
    return QMessageBoxBind::addButtonWithText(static_cast<QMessageBox*>(messageBox), QString::fromUtf8(text), static_cast<QMessageBox::ButtonRole>(role));
}

void QMessageBox_removeButton(void* messageBox, void* button) {
    QMessageBoxBind::removeButton(static_cast<QMessageBox*>(messageBox), static_cast<QAbstractButton*>(button));
}

void* QMessageBox_button(void* messageBox, int which) {
    return QMessageBoxBind::button(static_cast<QMessageBox*>(messageBox), static_cast<QMessageBox::StandardButton>(which));
}

int QMessageBox_buttonRole(void* messageBox, void* button) {
    return static_cast<int>(QMessageBoxBind::buttonRole(static_cast<QMessageBox*>(messageBox), static_cast<QAbstractButton*>(button)));
}

int QMessageBox_standardButton(void* messageBox, void* button) {
    return static_cast<int>(QMessageBoxBind::standardButton(static_cast<QMessageBox*>(messageBox), static_cast<QAbstractButton*>(button)));
}

void* QMessageBox_defaultButton(void* messageBox) {
    return QMessageBoxBind::defaultButton(static_cast<QMessageBox*>(messageBox));
}

void QMessageBox_setDefaultButton(void* messageBox, void* button) {
    QMessageBoxBind::setDefaultButton(static_cast<QMessageBox*>(messageBox), static_cast<QPushButton*>(button));
}

void QMessageBox_setDefaultButtonStandard(void* messageBox, int button) {
    QMessageBoxBind::setDefaultButtonStandard(static_cast<QMessageBox*>(messageBox), static_cast<QMessageBox::StandardButton>(button));
}

void* QMessageBox_escapeButton(void* messageBox) {
    return QMessageBoxBind::escapeButton(static_cast<QMessageBox*>(messageBox));
}

void QMessageBox_setEscapeButton(void* messageBox, void* button) {
    QMessageBoxBind::setEscapeButton(static_cast<QMessageBox*>(messageBox), static_cast<QAbstractButton*>(button));
}

void QMessageBox_setEscapeButtonStandard(void* messageBox, int button) {
    QMessageBoxBind::setEscapeButtonStandard(static_cast<QMessageBox*>(messageBox), static_cast<QMessageBox::StandardButton>(button));
}

// チェックボックス関連
void* QMessageBox_checkBox(void* messageBox) {
    return QMessageBoxBind::checkBox(static_cast<QMessageBox*>(messageBox));
}

void QMessageBox_setCheckBox(void* messageBox, void* cb) {
    QMessageBoxBind::setCheckBox(static_cast<QMessageBox*>(messageBox), static_cast<QCheckBox*>(cb));
}

// アクション
int QMessageBox_exec(void* messageBox) {
    return QMessageBoxBind::exec(static_cast<QMessageBox*>(messageBox));
}

void QMessageBox_open(void* messageBox) {
    QMessageBoxBind::open(static_cast<QMessageBox*>(messageBox));
}

// スタティック関数
void QMessageBox_about(void* parent, const char* title, const char* text) {
    QMessageBoxBind::about(static_cast<QWidget*>(parent), QString::fromUtf8(title), QString::fromUtf8(text));
}

void QMessageBox_aboutQt(void* parent, const char* title) {
    QMessageBoxBind::aboutQt(static_cast<QWidget*>(parent), QString::fromUtf8(title));
}

int QMessageBox_critical(void* parent, const char* title, const char* text, int buttons, int defaultButton) {
    return static_cast<int>(QMessageBoxBind::critical(
        static_cast<QWidget*>(parent),
        QString::fromUtf8(title),
        QString::fromUtf8(text),
        static_cast<QMessageBox::StandardButtons>(buttons),
        static_cast<QMessageBox::StandardButton>(defaultButton)
    ));
}

int QMessageBox_information(void* parent, const char* title, const char* text, int buttons, int defaultButton) {
    return static_cast<int>(QMessageBoxBind::information(
        static_cast<QWidget*>(parent),
        QString::fromUtf8(title),
        QString::fromUtf8(text),
        static_cast<QMessageBox::StandardButtons>(buttons),
        static_cast<QMessageBox::StandardButton>(defaultButton)
    ));
}

int QMessageBox_question(void* parent, const char* title, const char* text, int buttons, int defaultButton) {
    return static_cast<int>(QMessageBoxBind::question(
        static_cast<QWidget*>(parent),
        QString::fromUtf8(title),
        QString::fromUtf8(text),
        static_cast<QMessageBox::StandardButtons>(buttons),
        static_cast<QMessageBox::StandardButton>(defaultButton)
    ));
}

int QMessageBox_warning(void* parent, const char* title, const char* text, int buttons, int defaultButton) {
    return static_cast<int>(QMessageBoxBind::warning(
        static_cast<QWidget*>(parent),
        QString::fromUtf8(title),
        QString::fromUtf8(text),
        static_cast<QMessageBox::StandardButtons>(buttons),
        static_cast<QMessageBox::StandardButton>(defaultButton)
    ));
}

// シグナルハンドラ設定
void QMessageBox_setButtonClickedCallback(void* messageBox, void (*callback)(void*, void*), void* data) {
    QMessageBoxBind::setButtonClickedCallback(
        static_cast<QMessageBox*>(messageBox),
        reinterpret_cast<void (*)(void*, QAbstractButton*)>(callback),
        data
    );
}

}
