#include "QAbstractButtonBind.h"
#include "QAbstractButtonHandler.h"
#include <QVariant>

// QAbstractButtonは抽象クラスなので、実際にはQPushButtonなどの具体的なサブクラスを使用する必要がある
// ここでは、QAbstractButtonのインスタンスを作成することはできないため、createメソッドはnullptrを返す
QAbstractButton* QAbstractButtonBind::create(QWidget* parent) {
    // QAbstractButtonは抽象クラスなのでインスタンス化できない
    return nullptr;
}

void QAbstractButtonBind::destroy(QAbstractButton* button) {
    if (button) {
        QAbstractButtonHandler* handler = getHandler(button);
        if (handler) {
            delete handler;
        }
        delete button;
    }
}

bool QAbstractButtonBind::autoExclusive(QAbstractButton* button) {
    if (button) {
        return button->autoExclusive();
    }
    return false;
}

bool QAbstractButtonBind::autoRepeat(QAbstractButton* button) {
    if (button) {
        return button->autoRepeat();
    }
    return false;
}

int QAbstractButtonBind::autoRepeatDelay(QAbstractButton* button) {
    if (button) {
        return button->autoRepeatDelay();
    }
    return 0;
}

int QAbstractButtonBind::autoRepeatInterval(QAbstractButton* button) {
    if (button) {
        return button->autoRepeatInterval();
    }
    return 0;
}

QButtonGroup* QAbstractButtonBind::group(QAbstractButton* button) {
    if (button) {
        return button->group();
    }
    return nullptr;
}

QIcon* QAbstractButtonBind::icon(QAbstractButton* button) {
    if (button) {
        return new QIcon(button->icon());
    }
    return nullptr;
}

QSize* QAbstractButtonBind::iconSize(QAbstractButton* button) {
    if (button) {
        return new QSize(button->iconSize());
    }
    return nullptr;
}

bool QAbstractButtonBind::isCheckable(QAbstractButton* button) {
    if (button) {
        return button->isCheckable();
    }
    return false;
}

bool QAbstractButtonBind::isChecked(QAbstractButton* button) {
    if (button) {
        return button->isChecked();
    }
    return false;
}

bool QAbstractButtonBind::isDown(QAbstractButton* button) {
    if (button) {
        return button->isDown();
    }
    return false;
}

QKeySequence* QAbstractButtonBind::shortcut(QAbstractButton* button) {
    if (button) {
        return new QKeySequence(button->shortcut());
    }
    return nullptr;
}

QString* QAbstractButtonBind::text(QAbstractButton* button) {
    if (button) {
        return new QString(button->text());
    }
    return nullptr;
}

void QAbstractButtonBind::setAutoExclusive(QAbstractButton* button, bool autoExclusive) {
    if (button) {
        button->setAutoExclusive(autoExclusive);
    }
}

void QAbstractButtonBind::setAutoRepeat(QAbstractButton* button, bool autoRepeat) {
    if (button) {
        button->setAutoRepeat(autoRepeat);
    }
}

void QAbstractButtonBind::setAutoRepeatDelay(QAbstractButton* button, int delay) {
    if (button) {
        button->setAutoRepeatDelay(delay);
    }
}

void QAbstractButtonBind::setAutoRepeatInterval(QAbstractButton* button, int interval) {
    if (button) {
        button->setAutoRepeatInterval(interval);
    }
}

void QAbstractButtonBind::setCheckable(QAbstractButton* button, bool checkable) {
    if (button) {
        button->setCheckable(checkable);
    }
}

void QAbstractButtonBind::setDown(QAbstractButton* button, bool down) {
    if (button) {
        button->setDown(down);
    }
}

void QAbstractButtonBind::setIcon(QAbstractButton* button, QIcon* icon) {
    if (button && icon) {
        button->setIcon(*icon);
    }
}

void QAbstractButtonBind::setIconSize(QAbstractButton* button, QSize* size) {
    if (button && size) {
        button->setIconSize(*size);
    }
}

void QAbstractButtonBind::setShortcut(QAbstractButton* button, QKeySequence* shortcut) {
    if (button && shortcut) {
        button->setShortcut(*shortcut);
    }
}

void QAbstractButtonBind::setText(QAbstractButton* button, const char* text) {
    if (button && text) {
        button->setText(QString::fromUtf8(text));
    }
}

void QAbstractButtonBind::setChecked(QAbstractButton* button, bool checked) {
    if (button) {
        button->setChecked(checked);
    }
}

void QAbstractButtonBind::animateClick(QAbstractButton* button) {
    if (button) {
        button->animateClick();
    }
}

void QAbstractButtonBind::click(QAbstractButton* button) {
    if (button) {
        button->click();
    }
}

void QAbstractButtonBind::toggle(QAbstractButton* button) {
    if (button) {
        button->toggle();
    }
}

void QAbstractButtonBind::setClickedCallback(QAbstractButton* button, void (*callback)(void*, bool), void* data) {
    if (button) {
        QAbstractButtonHandler* handler = getHandler(button);
        if (!handler) {
            handler = new QAbstractButtonHandler(button, button);
            setHandler(button, handler);
        }
        handler->clickedCallback = callback;
        handler->clickedData = data;
    }
}

void QAbstractButtonBind::setPressedCallback(QAbstractButton* button, void (*callback)(void*), void* data) {
    if (button) {
        QAbstractButtonHandler* handler = getHandler(button);
        if (!handler) {
            handler = new QAbstractButtonHandler(button, button);
            setHandler(button, handler);
        }
        handler->pressedCallback = callback;
        handler->pressedData = data;
    }
}

void QAbstractButtonBind::setReleasedCallback(QAbstractButton* button, void (*callback)(void*), void* data) {
    if (button) {
        QAbstractButtonHandler* handler = getHandler(button);
        if (!handler) {
            handler = new QAbstractButtonHandler(button, button);
            setHandler(button, handler);
        }
        handler->releasedCallback = callback;
        handler->releasedData = data;
    }
}

void QAbstractButtonBind::setToggledCallback(QAbstractButton* button, void (*callback)(void*, bool), void* data) {
    if (button) {
        QAbstractButtonHandler* handler = getHandler(button);
        if (!handler) {
            handler = new QAbstractButtonHandler(button, button);
            setHandler(button, handler);
        }
        handler->toggledCallback = callback;
        handler->toggledData = data;
    }
}

QAbstractButtonHandler* QAbstractButtonBind::getHandler(QAbstractButton* button) {
    if (button) {
        QVariant variant = button->property("handler");
        if (variant.isValid()) {
            return variant.value<QAbstractButtonHandler*>();
        }
    }
    return nullptr;
}

void QAbstractButtonBind::setHandler(QAbstractButton* button, QAbstractButtonHandler* handler) {
    if (button) {
        button->setProperty("handler", QVariant::fromValue(handler));
    }
}
