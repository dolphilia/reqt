#ifndef QMESSAGEBOX_BIND_H
#define QMESSAGEBOX_BIND_H

#include <QMessageBox>
#include <QCheckBox>
#include <QPushButton>
#include <QPixmap>

class QMessageBoxHandler;

class QMessageBoxBind {
public:
    // コンストラクタ/デストラクタ
    static QMessageBox* create(QWidget* parent = nullptr);
    static QMessageBox* createWithIcon(QMessageBox::Icon icon, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::NoButton, QWidget* parent = nullptr, Qt::WindowFlags f = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    static void destroy(QMessageBox* messageBox);

    // プロパティ取得
    static QString detailedText(QMessageBox* messageBox);
    static QMessageBox::Icon icon(QMessageBox* messageBox);
    static QPixmap* iconPixmap(QMessageBox* messageBox);
    static QString informativeText(QMessageBox* messageBox);
    static QMessageBox::StandardButtons standardButtons(QMessageBox* messageBox);
    static QString text(QMessageBox* messageBox);
    static Qt::TextFormat textFormat(QMessageBox* messageBox);
    static Qt::TextInteractionFlags textInteractionFlags(QMessageBox* messageBox);

    // プロパティ設定
    static void setDetailedText(QMessageBox* messageBox, const QString& text);
    static void setIcon(QMessageBox* messageBox, QMessageBox::Icon icon);
    static void setIconPixmap(QMessageBox* messageBox, const QPixmap& pixmap);
    static void setInformativeText(QMessageBox* messageBox, const QString& text);
    static void setStandardButtons(QMessageBox* messageBox, QMessageBox::StandardButtons buttons);
    static void setText(QMessageBox* messageBox, const QString& text);
    static void setTextFormat(QMessageBox* messageBox, Qt::TextFormat format);
    static void setTextInteractionFlags(QMessageBox* messageBox, Qt::TextInteractionFlags flags);
    static void setWindowTitle(QMessageBox* messageBox, const QString& title);

    // ボタン関連
    static QPushButton* addButton(QMessageBox* messageBox, QMessageBox::StandardButton button);
    static QPushButton* addButtonWithText(QMessageBox* messageBox, const QString& text, QMessageBox::ButtonRole role);
    static void removeButton(QMessageBox* messageBox, QAbstractButton* button);
    static QAbstractButton* button(QMessageBox* messageBox, QMessageBox::StandardButton which);
    static QMessageBox::ButtonRole buttonRole(QMessageBox* messageBox, QAbstractButton* button);
    static QMessageBox::StandardButton standardButton(QMessageBox* messageBox, QAbstractButton* button);
    static QPushButton* defaultButton(QMessageBox* messageBox);
    static void setDefaultButton(QMessageBox* messageBox, QPushButton* button);
    static void setDefaultButtonStandard(QMessageBox* messageBox, QMessageBox::StandardButton button);
    static QAbstractButton* escapeButton(QMessageBox* messageBox);
    static void setEscapeButton(QMessageBox* messageBox, QAbstractButton* button);
    static void setEscapeButtonStandard(QMessageBox* messageBox, QMessageBox::StandardButton button);

    // チェックボックス関連
    static QCheckBox* checkBox(QMessageBox* messageBox);
    static void setCheckBox(QMessageBox* messageBox, QCheckBox* cb);

    // アクション
    static int exec(QMessageBox* messageBox);
    static void open(QMessageBox* messageBox);

    // スタティック関数
    static void about(QWidget* parent, const QString& title, const QString& text);
    static void aboutQt(QWidget* parent, const QString& title = QString());
    static QMessageBox::StandardButton critical(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    static QMessageBox::StandardButton information(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    static QMessageBox::StandardButton question(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No), QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);
    static QMessageBox::StandardButton warning(QWidget* parent, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::Ok, QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);

    // シグナルハンドラ設定
    static void setButtonClickedCallback(QMessageBox* messageBox, void (*callback)(void*, QAbstractButton*), void* data);

    // ハンドラ管理
    static QMessageBoxHandler* getHandler(QMessageBox* messageBox);
    static void setHandler(QMessageBox* messageBox, QMessageBoxHandler* handler);
};

#endif // QMESSAGEBOX_BIND_H
