#ifndef QACTION_BIND_H
#define QACTION_BIND_H

#include <QAction>
#include <QIcon>
#include <QFont>
#include <QVariant>
#include <QKeySequence>
#include "QActionHandler.h"
#include "../../include/qt6/qaction.h"

class QActionBind {
public:
    // コンストラクタ/デストラクタ
    static QAction* create(QObject* parent = nullptr);
    static QAction* createWithText(const QString& text, QObject* parent = nullptr);
    static QAction* createWithIconAndText(const QIcon& icon, const QString& text, QObject* parent = nullptr);
    static void destroy(QAction* action);

    // プロパティ
    static QActionGroup* actionGroup(QAction* action);
    static void activate(QAction* action, QAction::ActionEvent event);
    static QList<QObject*> associatedObjects(QAction* action);
    static bool autoRepeat(QAction* action);
    static QVariant data(QAction* action);
    static QFont font(QAction* action);
    static QIcon icon(QAction* action);
    static QString iconText(QAction* action);
    static bool isCheckable(QAction* action);
    static bool isChecked(QAction* action);
    static bool isEnabled(QAction* action);
    static bool isIconVisibleInMenu(QAction* action);
    static bool isSeparator(QAction* action);
    static bool isShortcutVisibleInContextMenu(QAction* action);
    static bool isVisible(QAction* action);
    static QMenu* menu(QAction* action);
    static QAction::MenuRole menuRole(QAction* action);
    static QAction::Priority priority(QAction* action);

    // セッター
    static void setActionGroup(QAction* action, QActionGroup* group);
    static void setAutoRepeat(QAction* action, bool repeat);
    static void setCheckable(QAction* action, bool checkable);
    static void setData(QAction* action, const QVariant& data);
    static void setFont(QAction* action, const QFont& font);
    static void setIcon(QAction* action, const QIcon& icon);
    static void setIconText(QAction* action, const QString& text);
    static void setIconVisibleInMenu(QAction* action, bool visible);
    static void setMenu(QAction* action, QMenu* menu);
    static void setMenuRole(QAction* action, QAction::MenuRole role);
    static void setPriority(QAction* action, QAction::Priority priority);
    static void setSeparator(QAction* action, bool separator);
    static void setShortcut(QAction* action, const QKeySequence& shortcut);
    static void setShortcutContext(QAction* action, Qt::ShortcutContext context);
    static void setShortcutVisibleInContextMenu(QAction* action, bool show);
    static void setStatusTip(QAction* action, const QString& tip);
    static void setText(QAction* action, const QString& text);
    static void setToolTip(QAction* action, const QString& tip);
    static void setWhatsThis(QAction* action, const QString& text);

    // ゲッター
    static QKeySequence shortcut(QAction* action);
    static Qt::ShortcutContext shortcutContext(QAction* action);
    static bool showStatusText(QAction* action, QObject* object = nullptr);
    static QString statusTip(QAction* action);
    static QString text(QAction* action);
    static QString toolTip(QAction* action);
    static QString whatsThis(QAction* action);

    // スロット
    static void hover(QAction* action);
    static void resetEnabled(QAction* action);
    static void setChecked(QAction* action, bool checked);
    static void setDisabled(QAction* action, bool disabled);
    static void setEnabled(QAction* action, bool enabled);
    static void setVisible(QAction* action, bool visible);
    static void toggle(QAction* action);
    static void trigger(QAction* action);

    // コールバック設定
    static void setChangedCallback(QAction* action, QActionChangedCallback callback);
    static void setCheckableChangedCallback(QAction* action, QActionCheckableChangedCallback callback);
    static void setEnabledChangedCallback(QAction* action, QActionEnabledChangedCallback callback);
    static void setHoveredCallback(QAction* action, QActionHoveredCallback callback);
    static void setToggledCallback(QAction* action, QActionToggledCallback callback);
    static void setTriggeredCallback(QAction* action, QActionTriggeredCallback callback);
    static void setVisibleChangedCallback(QAction* action, QActionVisibleChangedCallback callback);
};

#endif // QACTION_BIND_H
