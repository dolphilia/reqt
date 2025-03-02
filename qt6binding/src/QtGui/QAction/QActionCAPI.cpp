#include "QActionBind.h"
#include <QString>
#include <QIcon>
#include <QFont>
#include <QVariant>
#include <QKeySequence>

extern "C" {

void* QAction_create(void* parent) {
    return QActionBind::create(reinterpret_cast<QObject*>(parent));
}

void* QAction_createWithText(const char* text, void* parent) {
    return QActionBind::createWithText(QString::fromUtf8(text), reinterpret_cast<QObject*>(parent));
}

void* QAction_createWithIconAndText(void* icon, const char* text, void* parent) {
    return QActionBind::createWithIconAndText(*reinterpret_cast<QIcon*>(icon), QString::fromUtf8(text), reinterpret_cast<QObject*>(parent));
}

void QAction_delete(void* action) {
    QActionBind::destroy(reinterpret_cast<QAction*>(action));
}

void* QAction_actionGroup(void* action) {
    return QActionBind::actionGroup(reinterpret_cast<QAction*>(action));
}

void QAction_activate(void* action, enum QActionEventType event) {
    QActionBind::activate(reinterpret_cast<QAction*>(action), static_cast<QAction::ActionEvent>(event == QAction_EventTrigger ? QAction::Trigger : QAction::Hover));
}

void* QAction_associatedObjects(void* action) {
    // Note: This returns a QList<QObject*>, which needs special handling in C
    // For now, we return nullptr as this requires more complex memory management
    return nullptr;
}

bool QAction_autoRepeat(void* action) {
    return QActionBind::autoRepeat(reinterpret_cast<QAction*>(action));
}

void* QAction_data(void* action) {
    // Note: Returns QVariant, which needs special handling
    return nullptr;
}

void* QAction_font(void* action) {
    // Note: Returns QFont, which needs special handling
    return nullptr;
}

void* QAction_icon(void* action) {
    // Note: Returns QIcon, which needs special handling
    return nullptr;
}

const char* QAction_iconText(void* action) {
    static QByteArray text;
    text = QActionBind::iconText(reinterpret_cast<QAction*>(action)).toUtf8();
    return text.constData();
}

bool QAction_isCheckable(void* action) {
    return QActionBind::isCheckable(reinterpret_cast<QAction*>(action));
}

bool QAction_isChecked(void* action) {
    return QActionBind::isChecked(reinterpret_cast<QAction*>(action));
}

bool QAction_isEnabled(void* action) {
    return QActionBind::isEnabled(reinterpret_cast<QAction*>(action));
}

bool QAction_isIconVisibleInMenu(void* action) {
    return QActionBind::isIconVisibleInMenu(reinterpret_cast<QAction*>(action));
}

bool QAction_isSeparator(void* action) {
    return QActionBind::isSeparator(reinterpret_cast<QAction*>(action));
}

bool QAction_isShortcutVisibleInContextMenu(void* action) {
    return QActionBind::isShortcutVisibleInContextMenu(reinterpret_cast<QAction*>(action));
}

bool QAction_isVisible(void* action) {
    return QActionBind::isVisible(reinterpret_cast<QAction*>(action));
}

void* QAction_menu(void* action) {
    return QActionBind::menu(reinterpret_cast<QAction*>(action));
}

enum QActionMenuRole QAction_menuRole(void* action) {
    return static_cast<enum QActionMenuRole>(QActionBind::menuRole(reinterpret_cast<QAction*>(action)));
}

enum QActionPriority QAction_priority(void* action) {
    return static_cast<enum QActionPriority>(QActionBind::priority(reinterpret_cast<QAction*>(action)));
}

void QAction_setActionGroup(void* action, void* group) {
    QActionBind::setActionGroup(reinterpret_cast<QAction*>(action), reinterpret_cast<QActionGroup*>(group));
}

void QAction_setAutoRepeat(void* action, bool repeat) {
    QActionBind::setAutoRepeat(reinterpret_cast<QAction*>(action), repeat);
}

void QAction_setCheckable(void* action, bool checkable) {
    QActionBind::setCheckable(reinterpret_cast<QAction*>(action), checkable);
}

void QAction_setData(void* action, void* data) {
    QActionBind::setData(reinterpret_cast<QAction*>(action), *reinterpret_cast<QVariant*>(data));
}

void QAction_setFont(void* action, void* font) {
    QActionBind::setFont(reinterpret_cast<QAction*>(action), *reinterpret_cast<QFont*>(font));
}

void QAction_setIcon(void* action, void* icon) {
    QActionBind::setIcon(reinterpret_cast<QAction*>(action), *reinterpret_cast<QIcon*>(icon));
}

void QAction_setIconText(void* action, const char* text) {
    QActionBind::setIconText(reinterpret_cast<QAction*>(action), QString::fromUtf8(text));
}

void QAction_setIconVisibleInMenu(void* action, bool visible) {
    QActionBind::setIconVisibleInMenu(reinterpret_cast<QAction*>(action), visible);
}

void QAction_setMenu(void* action, void* menu) {
    QActionBind::setMenu(reinterpret_cast<QAction*>(action), reinterpret_cast<QMenu*>(menu));
}

void QAction_setMenuRole(void* action, enum QActionMenuRole role) {
    QActionBind::setMenuRole(reinterpret_cast<QAction*>(action), static_cast<QAction::MenuRole>(role));
}

void QAction_setPriority(void* action, enum QActionPriority priority) {
    QActionBind::setPriority(reinterpret_cast<QAction*>(action), static_cast<QAction::Priority>(priority));
}

void QAction_setSeparator(void* action, bool separator) {
    QActionBind::setSeparator(reinterpret_cast<QAction*>(action), separator);
}

void QAction_setShortcut(void* action, void* shortcut) {
    QActionBind::setShortcut(reinterpret_cast<QAction*>(action), *reinterpret_cast<QKeySequence*>(shortcut));
}

void QAction_setShortcutContext(void* action, int context) {
    QActionBind::setShortcutContext(reinterpret_cast<QAction*>(action), static_cast<Qt::ShortcutContext>(context));
}

void QAction_setShortcutVisibleInContextMenu(void* action, bool show) {
    QActionBind::setShortcutVisibleInContextMenu(reinterpret_cast<QAction*>(action), show);
}

void QAction_setStatusTip(void* action, const char* tip) {
    QActionBind::setStatusTip(reinterpret_cast<QAction*>(action), QString::fromUtf8(tip));
}

void QAction_setText(void* action, const char* text) {
    QActionBind::setText(reinterpret_cast<QAction*>(action), QString::fromUtf8(text));
}

void QAction_setToolTip(void* action, const char* tip) {
    QActionBind::setToolTip(reinterpret_cast<QAction*>(action), QString::fromUtf8(tip));
}

void QAction_setWhatsThis(void* action, const char* text) {
    QActionBind::setWhatsThis(reinterpret_cast<QAction*>(action), QString::fromUtf8(text));
}

void* QAction_shortcut(void* action) {
    // Note: Returns QKeySequence, which needs special handling
    return nullptr;
}

int QAction_shortcutContext(void* action) {
    return static_cast<int>(QActionBind::shortcutContext(reinterpret_cast<QAction*>(action)));
}

bool QAction_showStatusText(void* action, void* object) {
    return QActionBind::showStatusText(reinterpret_cast<QAction*>(action), reinterpret_cast<QObject*>(object));
}

const char* QAction_statusTip(void* action) {
    static QByteArray tip;
    tip = QActionBind::statusTip(reinterpret_cast<QAction*>(action)).toUtf8();
    return tip.constData();
}

const char* QAction_text(void* action) {
    static QByteArray text;
    text = QActionBind::text(reinterpret_cast<QAction*>(action)).toUtf8();
    return text.constData();
}

const char* QAction_toolTip(void* action) {
    static QByteArray tip;
    tip = QActionBind::toolTip(reinterpret_cast<QAction*>(action)).toUtf8();
    return tip.constData();
}

const char* QAction_whatsThis(void* action) {
    static QByteArray text;
    text = QActionBind::whatsThis(reinterpret_cast<QAction*>(action)).toUtf8();
    return text.constData();
}

void QAction_hover(void* action) {
    QActionBind::hover(reinterpret_cast<QAction*>(action));
}

void QAction_resetEnabled(void* action) {
    QActionBind::resetEnabled(reinterpret_cast<QAction*>(action));
}

void QAction_setChecked(void* action, bool checked) {
    QActionBind::setChecked(reinterpret_cast<QAction*>(action), checked);
}

void QAction_setDisabled(void* action, bool disabled) {
    QActionBind::setDisabled(reinterpret_cast<QAction*>(action), disabled);
}

void QAction_setEnabled(void* action, bool enabled) {
    QActionBind::setEnabled(reinterpret_cast<QAction*>(action), enabled);
}

void QAction_setVisible(void* action, bool visible) {
    QActionBind::setVisible(reinterpret_cast<QAction*>(action), visible);
}

void QAction_toggle(void* action) {
    QActionBind::toggle(reinterpret_cast<QAction*>(action));
}

void QAction_trigger(void* action) {
    QActionBind::trigger(reinterpret_cast<QAction*>(action));
}

void QAction_setChangedCallback(void* action, QActionChangedCallback callback) {
    QActionBind::setChangedCallback(reinterpret_cast<QAction*>(action), callback);
}

void QAction_setCheckableChangedCallback(void* action, QActionCheckableChangedCallback callback) {
    QActionBind::setCheckableChangedCallback(reinterpret_cast<QAction*>(action), callback);
}

void QAction_setEnabledChangedCallback(void* action, QActionEnabledChangedCallback callback) {
    QActionBind::setEnabledChangedCallback(reinterpret_cast<QAction*>(action), callback);
}

void QAction_setHoveredCallback(void* action, QActionHoveredCallback callback) {
    QActionBind::setHoveredCallback(reinterpret_cast<QAction*>(action), callback);
}

void QAction_setToggledCallback(void* action, QActionToggledCallback callback) {
    QActionBind::setToggledCallback(reinterpret_cast<QAction*>(action), callback);
}

void QAction_setTriggeredCallback(void* action, QActionTriggeredCallback callback) {
    QActionBind::setTriggeredCallback(reinterpret_cast<QAction*>(action), callback);
}

void QAction_setVisibleChangedCallback(void* action, QActionVisibleChangedCallback callback) {
    QActionBind::setVisibleChangedCallback(reinterpret_cast<QAction*>(action), callback);
}

} // extern "C"
