#include "QActionBind.h"
#include <QMenu>
#include <QActionGroup>

QAction* QActionBind::create(QObject* parent) {
    QAction* action = new QAction(parent);
    QActionHandler* handler = new QActionHandler(action);

    QObject::connect(action, &QAction::changed,
                    handler, &QActionHandler::onChanged);
    QObject::connect(action, &QAction::checkableChanged,
                    handler, &QActionHandler::onCheckableChanged);
    QObject::connect(action, &QAction::enabledChanged,
                    handler, &QActionHandler::onEnabledChanged);
    QObject::connect(action, &QAction::hovered,
                    handler, &QActionHandler::onHovered);
    QObject::connect(action, &QAction::toggled,
                    handler, &QActionHandler::onToggled);
    QObject::connect(action, &QAction::triggered,
                    handler, &QActionHandler::onTriggered);
    QObject::connect(action, &QAction::visibleChanged,
                    handler, &QActionHandler::onVisibleChanged);

    return action;
}

QAction* QActionBind::createWithText(const QString& text, QObject* parent) {
    QAction* action = new QAction(text, parent);
    QActionHandler* handler = new QActionHandler(action);

    QObject::connect(action, &QAction::changed,
                    handler, &QActionHandler::onChanged);
    QObject::connect(action, &QAction::checkableChanged,
                    handler, &QActionHandler::onCheckableChanged);
    QObject::connect(action, &QAction::enabledChanged,
                    handler, &QActionHandler::onEnabledChanged);
    QObject::connect(action, &QAction::hovered,
                    handler, &QActionHandler::onHovered);
    QObject::connect(action, &QAction::toggled,
                    handler, &QActionHandler::onToggled);
    QObject::connect(action, &QAction::triggered,
                    handler, &QActionHandler::onTriggered);
    QObject::connect(action, &QAction::visibleChanged,
                    handler, &QActionHandler::onVisibleChanged);

    return action;
}

QAction* QActionBind::createWithIconAndText(const QIcon& icon, const QString& text, QObject* parent) {
    QAction* action = new QAction(icon, text, parent);
    QActionHandler* handler = new QActionHandler(action);

    QObject::connect(action, &QAction::changed,
                    handler, &QActionHandler::onChanged);
    QObject::connect(action, &QAction::checkableChanged,
                    handler, &QActionHandler::onCheckableChanged);
    QObject::connect(action, &QAction::enabledChanged,
                    handler, &QActionHandler::onEnabledChanged);
    QObject::connect(action, &QAction::hovered,
                    handler, &QActionHandler::onHovered);
    QObject::connect(action, &QAction::toggled,
                    handler, &QActionHandler::onToggled);
    QObject::connect(action, &QAction::triggered,
                    handler, &QActionHandler::onTriggered);
    QObject::connect(action, &QAction::visibleChanged,
                    handler, &QActionHandler::onVisibleChanged);

    return action;
}

void QActionBind::destroy(QAction* action) {
    if (action) {
        delete action;
    }
}

QActionGroup* QActionBind::actionGroup(QAction* action) {
    return action ? action->actionGroup() : nullptr;
}

void QActionBind::activate(QAction* action, QAction::ActionEvent event) {
    if (action) {
        action->activate(event);
    }
}

QList<QObject*> QActionBind::associatedObjects(QAction* action) {
    return action ? action->associatedObjects() : QList<QObject*>();
}

bool QActionBind::autoRepeat(QAction* action) {
    return action ? action->autoRepeat() : false;
}

QVariant QActionBind::data(QAction* action) {
    return action ? action->data() : QVariant();
}

QFont QActionBind::font(QAction* action) {
    return action ? action->font() : QFont();
}

QIcon QActionBind::icon(QAction* action) {
    return action ? action->icon() : QIcon();
}

QString QActionBind::iconText(QAction* action) {
    return action ? action->iconText() : QString();
}

bool QActionBind::isCheckable(QAction* action) {
    return action ? action->isCheckable() : false;
}

bool QActionBind::isChecked(QAction* action) {
    return action ? action->isChecked() : false;
}

bool QActionBind::isEnabled(QAction* action) {
    return action ? action->isEnabled() : false;
}

bool QActionBind::isIconVisibleInMenu(QAction* action) {
    return action ? action->isIconVisibleInMenu() : false;
}

bool QActionBind::isSeparator(QAction* action) {
    return action ? action->isSeparator() : false;
}

bool QActionBind::isShortcutVisibleInContextMenu(QAction* action) {
    return action ? action->isShortcutVisibleInContextMenu() : false;
}

bool QActionBind::isVisible(QAction* action) {
    return action ? action->isVisible() : false;
}

QMenu* QActionBind::menu(QAction* action) {
    return action ? action->menu() : nullptr;
}

QAction::MenuRole QActionBind::menuRole(QAction* action) {
    return action ? action->menuRole() : QAction::NoRole;
}

QAction::Priority QActionBind::priority(QAction* action) {
    return action ? action->priority() : QAction::NormalPriority;
}

void QActionBind::setActionGroup(QAction* action, QActionGroup* group) {
    if (action) {
        action->setActionGroup(group);
    }
}

void QActionBind::setAutoRepeat(QAction* action, bool repeat) {
    if (action) {
        action->setAutoRepeat(repeat);
    }
}

void QActionBind::setCheckable(QAction* action, bool checkable) {
    if (action) {
        action->setCheckable(checkable);
    }
}

void QActionBind::setData(QAction* action, const QVariant& data) {
    if (action) {
        action->setData(data);
    }
}

void QActionBind::setFont(QAction* action, const QFont& font) {
    if (action) {
        action->setFont(font);
    }
}

void QActionBind::setIcon(QAction* action, const QIcon& icon) {
    if (action) {
        action->setIcon(icon);
    }
}

void QActionBind::setIconText(QAction* action, const QString& text) {
    if (action) {
        action->setIconText(text);
    }
}

void QActionBind::setIconVisibleInMenu(QAction* action, bool visible) {
    if (action) {
        action->setIconVisibleInMenu(visible);
    }
}

void QActionBind::setMenu(QAction* action, QMenu* menu) {
    if (action) {
        action->setMenu(menu);
    }
}

void QActionBind::setMenuRole(QAction* action, QAction::MenuRole role) {
    if (action) {
        action->setMenuRole(role);
    }
}

void QActionBind::setPriority(QAction* action, QAction::Priority priority) {
    if (action) {
        action->setPriority(priority);
    }
}

void QActionBind::setSeparator(QAction* action, bool separator) {
    if (action) {
        action->setSeparator(separator);
    }
}

void QActionBind::setShortcut(QAction* action, const QKeySequence& shortcut) {
    if (action) {
        action->setShortcut(shortcut);
    }
}

void QActionBind::setShortcutContext(QAction* action, Qt::ShortcutContext context) {
    if (action) {
        action->setShortcutContext(context);
    }
}

void QActionBind::setShortcutVisibleInContextMenu(QAction* action, bool show) {
    if (action) {
        action->setShortcutVisibleInContextMenu(show);
    }
}

void QActionBind::setStatusTip(QAction* action, const QString& tip) {
    if (action) {
        action->setStatusTip(tip);
    }
}

void QActionBind::setText(QAction* action, const QString& text) {
    if (action) {
        action->setText(text);
    }
}

void QActionBind::setToolTip(QAction* action, const QString& tip) {
    if (action) {
        action->setToolTip(tip);
    }
}

void QActionBind::setWhatsThis(QAction* action, const QString& text) {
    if (action) {
        action->setWhatsThis(text);
    }
}

QKeySequence QActionBind::shortcut(QAction* action) {
    return action ? action->shortcut() : QKeySequence();
}

Qt::ShortcutContext QActionBind::shortcutContext(QAction* action) {
    return action ? action->shortcutContext() : Qt::WindowShortcut;
}

bool QActionBind::showStatusText(QAction* action, QObject* object) {
    return action ? action->showStatusText(object) : false;
}

QString QActionBind::statusTip(QAction* action) {
    return action ? action->statusTip() : QString();
}

QString QActionBind::text(QAction* action) {
    return action ? action->text() : QString();
}

QString QActionBind::toolTip(QAction* action) {
    return action ? action->toolTip() : QString();
}

QString QActionBind::whatsThis(QAction* action) {
    return action ? action->whatsThis() : QString();
}

void QActionBind::hover(QAction* action) {
    if (action) {
        action->hover();
    }
}

void QActionBind::resetEnabled(QAction* action) {
    if (action) {
        action->resetEnabled();
    }
}

void QActionBind::setChecked(QAction* action, bool checked) {
    if (action) {
        action->setChecked(checked);
    }
}

void QActionBind::setDisabled(QAction* action, bool disabled) {
    if (action) {
        action->setDisabled(disabled);
    }
}

void QActionBind::setEnabled(QAction* action, bool enabled) {
    if (action) {
        action->setEnabled(enabled);
    }
}

void QActionBind::setVisible(QAction* action, bool visible) {
    if (action) {
        action->setVisible(visible);
    }
}

void QActionBind::toggle(QAction* action) {
    if (action) {
        action->toggle();
    }
}

void QActionBind::trigger(QAction* action) {
    if (action) {
        action->trigger();
    }
}

void QActionBind::setChangedCallback(QAction* action, QActionChangedCallback callback) {
    if (action) {
        QActionHandler* handler = action->findChild<QActionHandler*>();
        if (handler) {
            handler->setChangedCallback(callback);
        }
    }
}

void QActionBind::setCheckableChangedCallback(QAction* action, QActionCheckableChangedCallback callback) {
    if (action) {
        QActionHandler* handler = action->findChild<QActionHandler*>();
        if (handler) {
            handler->setCheckableChangedCallback(callback);
        }
    }
}

void QActionBind::setEnabledChangedCallback(QAction* action, QActionEnabledChangedCallback callback) {
    if (action) {
        QActionHandler* handler = action->findChild<QActionHandler*>();
        if (handler) {
            handler->setEnabledChangedCallback(callback);
        }
    }
}

void QActionBind::setHoveredCallback(QAction* action, QActionHoveredCallback callback) {
    if (action) {
        QActionHandler* handler = action->findChild<QActionHandler*>();
        if (handler) {
            handler->setHoveredCallback(callback);
        }
    }
}

void QActionBind::setToggledCallback(QAction* action, QActionToggledCallback callback) {
    if (action) {
        QActionHandler* handler = action->findChild<QActionHandler*>();
        if (handler) {
            handler->setToggledCallback(callback);
        }
    }
}

void QActionBind::setTriggeredCallback(QAction* action, QActionTriggeredCallback callback) {
    if (action) {
        QActionHandler* handler = action->findChild<QActionHandler*>();
        if (handler) {
            handler->setTriggeredCallback(callback);
        }
    }
}

void QActionBind::setVisibleChangedCallback(QAction* action, QActionVisibleChangedCallback callback) {
    if (action) {
        QActionHandler* handler = action->findChild<QActionHandler*>();
        if (handler) {
            handler->setVisibleChangedCallback(callback);
        }
    }
}
