#include "QMessageBoxBind.h"
#include "qmessagebox.h"

extern "C" {

// コンストラクタ/デストラクタ
void* QMessageBox_create(void* parent) {
    return new QMessageBoxBind(static_cast<QWidget*>(parent));
}

void* QMessageBox_createWithIcon(int icon, const char* title, const char* text, int buttons, void* parent, int f) {
    return new QMessageBoxBind(
        static_cast<QMessageBox::Icon>(icon),
        QString::fromUtf8(title),
        QString::fromUtf8(text),
        static_cast<QMessageBox::StandardButtons>(buttons),
        static_cast<QWidget*>(parent),
        static_cast<Qt::WindowFlags>(f)
    );
}

void QMessageBox_delete(void* messageBox) {
    delete static_cast<QMessageBoxBind*>(messageBox);
}

// プロパティ取得
const char* QMessageBox_detailedText(void* messageBox) {
    return static_cast<QMessageBoxBind*>(messageBox)->detailedText().toUtf8().constData();
}

int QMessageBox_icon(void* messageBox) {
    return static_cast<int>(static_cast<QMessageBoxBind*>(messageBox)->icon());
}

void* QMessageBox_iconPixmap(void* messageBox) {
    return const_cast<QPixmap*>(&static_cast<QMessageBoxBind*>(messageBox)->iconPixmap());
}

const char* QMessageBox_informativeText(void* messageBox) {
    return static_cast<QMessageBoxBind*>(messageBox)->informativeText().toUtf8().constData();
}

int QMessageBox_standardButtons(void* messageBox) {
    return static_cast<int>(static_cast<QMessageBoxBind*>(messageBox)->standardButtons());
}

const char* QMessageBox_text(void* messageBox) {
    return static_cast<QMessageBoxBind*>(messageBox)->text().toUtf8().constData();
}

int QMessageBox_textFormat(void* messageBox) {
    return static_cast<int>(static_cast<QMessageBoxBind*>(messageBox)->textFormat());
}

int QMessageBox_textInteractionFlags(void* messageBox) {
    return static_cast<int>(static_cast<QMessageBoxBind*>(messageBox)->textInteractionFlags());
}

// プロパティ設定
void QMessageBox_setDetailedText(void* messageBox, const char* text) {
    static_cast<QMessageBoxBind*>(messageBox)->setDetailedText(QString::fromUtf8(text));
}

void QMessageBox_setIcon(void* messageBox, int icon) {
    static_cast<QMessageBoxBind*>(messageBox)->setIcon(static_cast<QMessageBox::Icon>(icon));
}

void QMessageBox_setIconPixmap(void* messageBox, void* pixmap) {
    static_cast<QMessageBoxBind*>(messageBox)->setIconPixmap(*static_cast<QPixmap*>(pixmap));
}

void QMessageBox_setInformativeText(void* messageBox, const char* text) {
    static_cast<QMessageBoxBind*>(messageBox)->setInformativeText(QString::fromUtf8(text));
}

void QMessageBox_setStandardButtons(void* messageBox, int buttons) {
    static_cast<QMessageBoxBind*>(messageBox)->setStandardButtons(static_cast<QMessageBox::StandardButtons>(buttons));
}

void QMessageBox_setText(void* messageBox, const char* text) {
    static_cast<QMessageBoxBind*>(messageBox)->setText(QString::fromUtf8(text));
}

void QMessageBox_setTextFormat(void* messageBox, int format) {
    static_cast<QMessageBoxBind*>(messageBox)->setTextFormat(static_cast<Qt::TextFormat>(format));
}

void QMessageBox_setTextInteractionFlags(void* messageBox, int flags) {
    static_cast<QMessageBoxBind*>(messageBox)->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(flags));
}

void QMessageBox_setWindowTitle(void* messageBox, const char* title) {
    static_cast<QMessageBoxBind*>(messageBox)->setWindowTitle(QString::fromUtf8(title));
}

// ボタン関連
void* QMessageBox_addButton(void* messageBox, int button) {
    return static_cast<QMessageBoxBind*>(messageBox)->addButton(static_cast<QMessageBox::StandardButton>(button));
}

void* QMessageBox_addButtonWithText(void* messageBox, const char* text, int role) {
    return static_cast<QMessageBoxBind*>(messageBox)->addButton(QString::fromUtf8(text), static_cast<QMessageBox::ButtonRole>(role));
}

void QMessageBox_removeButton(void* messageBox, void* button) {
    static_cast<QMessageBoxBind*>(messageBox)->removeButton(static_cast<QAbstractButton*>(button));
}

void* QMessageBox_button(void* messageBox, int which) {
    return static_cast<QMessageBoxBind*>(messageBox)->button(static_cast<QMessageBox::StandardButton>(which));
}

int QMessageBox_buttonRole(void* messageBox, void* button) {
    return static_cast<int>(static_cast<QMessageBoxBind*>(messageBox)->buttonRole(static_cast<QAbstractButton*>(button)));
}

int QMessageBox_standardButton(void* messageBox, void* button) {
    return static_cast<int>(static_cast<QMessageBoxBind*>(messageBox)->standardButton(static_cast<QAbstractButton*>(button)));
}

void* QMessageBox_defaultButton(void* messageBox) {
    return static_cast<QMessageBoxBind*>(messageBox)->defaultButton();
}

void QMessageBox_setDefaultButton(void* messageBox, void* button) {
    static_cast<QMessageBoxBind*>(messageBox)->setDefaultButton(static_cast<QPushButton*>(button));
}

void QMessageBox_setDefaultButtonStandard(void* messageBox, int button) {
    static_cast<QMessageBoxBind*>(messageBox)->setDefaultButton(static_cast<QMessageBox::StandardButton>(button));
}

void* QMessageBox_escapeButton(void* messageBox) {
    return static_cast<QMessageBoxBind*>(messageBox)->escapeButton();
}

void QMessageBox_setEscapeButton(void* messageBox, void* button) {
    static_cast<QMessageBoxBind*>(messageBox)->setEscapeButton(static_cast<QAbstractButton*>(button));
}

void QMessageBox_setEscapeButtonStandard(void* messageBox, int button) {
    static_cast<QMessageBoxBind*>(messageBox)->setEscapeButton(static_cast<QMessageBox::StandardButton>(button));
}

// チェックボックス関連
void* QMessageBox_checkBox(void* messageBox) {
    return static_cast<QMessageBoxBind*>(messageBox)->checkBox();
}

void QMessageBox_setCheckBox(void* messageBox, void* cb) {
    static_cast<QMessageBoxBind*>(messageBox)->setCheckBox(static_cast<QCheckBox*>(cb));
}

// アクション
int QMessageBox_exec(void* messageBox) {
    return static_cast<QMessageBoxBind*>(messageBox)->exec();
}

void QMessageBox_open(void* messageBox) {
    static_cast<QMessageBoxBind*>(messageBox)->open();
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
    static_cast<QMessageBoxBind*>(messageBox)->setButtonClickedCallback(
        reinterpret_cast<void (*)(void*, QAbstractButton*)>(callback)
    );
}

}
