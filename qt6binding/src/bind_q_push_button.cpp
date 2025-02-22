#include "bind_q_push_button.h"
#include "handler_button_click.h"
#include <QString>
#include <QIcon>

QPushButton* QPushButtonBind::create(const char* text, QWidget* parent) {
    if (text) {
        return new QPushButton(QString::fromUtf8(text), parent);
    }
    return new QPushButton(parent);
}

void QPushButtonBind::destroy(QPushButton* button) {
    if (button) {
        // ハンドラーの削除
        QObject* handler = button->findChild<ButtonClickHandler*>();
        if (handler) {
            delete handler;
        }
        delete button;
    }
}

void QPushButtonBind::setText(QPushButton* button, const char* text) {
    if (button && text) {
        button->setText(QString::fromUtf8(text));
    }
}

const char* QPushButtonBind::text(QPushButton* button) {
    if (button) {
        static QString str;
        str = button->text();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QPushButtonBind::setIcon(QPushButton* button, const char* iconPath) {
    if (button && iconPath) {
        button->setIcon(QIcon(QString::fromUtf8(iconPath)));
    }
}

void QPushButtonBind::setEnabled(QPushButton* button, bool enabled) {
    if (button) {
        button->setEnabled(enabled);
    }
}

bool QPushButtonBind::isEnabled(QPushButton* button) {
    return button ? button->isEnabled() : false;
}

void QPushButtonBind::setCheckable(QPushButton* button, bool checkable) {
    if (button) {
        button->setCheckable(checkable);
    }
}

bool QPushButtonBind::isCheckable(QPushButton* button) {
    return button ? button->isCheckable() : false;
}

void QPushButtonBind::setChecked(QPushButton* button, bool checked) {
    if (button) {
        button->setChecked(checked);
    }
}

bool QPushButtonBind::isChecked(QPushButton* button) {
    return button ? button->isChecked() : false;
}

void QPushButtonBind::setAutoRepeat(QPushButton* button, bool autoRepeat) {
    if (button) {
        button->setAutoRepeat(autoRepeat);
    }
}

bool QPushButtonBind::autoRepeat(QPushButton* button) {
    return button ? button->autoRepeat() : false;
}

void QPushButtonBind::click(QPushButton* button) {
    if (button) {
        button->click();
    }
}

void QPushButtonBind::setFlat(QPushButton* button, bool flat) {
    if (button) {
        button->setFlat(flat);
    }
}

bool QPushButtonBind::isFlat(QPushButton* button) {
    return button ? button->isFlat() : false;
}

void QPushButtonBind::setDefault(QPushButton* button, bool default_) {
    if (button) {
        button->setDefault(default_);
    }
}

bool QPushButtonBind::isDefault(QPushButton* button) {
    return button ? button->isDefault() : false;
}

void QPushButtonBind::setClickCallback(QPushButton* button, QPushButtonClickCallback callback) {
    if (button) {
        // 既存のハンドラーを削除
        QObject* existingHandler = button->findChild<ButtonClickHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        ButtonClickHandler* handler = new ButtonClickHandler(callback);
        handler->setParent(button);
        QObject::connect(button, &QPushButton::clicked, handler, &ButtonClickHandler::onClick);
    }
}

void QPushButtonBind::setPressedCallback(QPushButton* button, QPushButtonClickCallback callback) {
    if (button) {
        // 既存のハンドラーを削除
        QObject* existingHandler = button->findChild<ButtonClickHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        ButtonClickHandler* handler = new ButtonClickHandler(callback);
        handler->setParent(button);
        QObject::connect(button, &QPushButton::pressed, handler, &ButtonClickHandler::onClick);
    }
}

void QPushButtonBind::setReleasedCallback(QPushButton* button, QPushButtonClickCallback callback) {
    if (button) {
        // 既存のハンドラーを削除
        QObject* existingHandler = button->findChild<ButtonClickHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        ButtonClickHandler* handler = new ButtonClickHandler(callback);
        handler->setParent(button);
        QObject::connect(button, &QPushButton::released, handler, &ButtonClickHandler::onClick);
    }
}

extern "C" {

void* QPushButton_create(const char* text, void* parent) {
    return QPushButtonBind::create(text, static_cast<QWidget*>(parent));
}

void QPushButton_delete(void* button) {
    QPushButtonBind::destroy(static_cast<QPushButton*>(button));
}

void QPushButton_setText(void* button, const char* text) {
    QPushButtonBind::setText(static_cast<QPushButton*>(button), text);
}

const char* QPushButton_text(void* button) {
    return QPushButtonBind::text(static_cast<QPushButton*>(button));
}

void QPushButton_setIcon(void* button, const char* iconPath) {
    QPushButtonBind::setIcon(static_cast<QPushButton*>(button), iconPath);
}

void QPushButton_setEnabled(void* button, bool enabled) {
    QPushButtonBind::setEnabled(static_cast<QPushButton*>(button), enabled);
}

bool QPushButton_isEnabled(void* button) {
    return QPushButtonBind::isEnabled(static_cast<QPushButton*>(button));
}

void QPushButton_setCheckable(void* button, bool checkable) {
    QPushButtonBind::setCheckable(static_cast<QPushButton*>(button), checkable);
}

bool QPushButton_isCheckable(void* button) {
    return QPushButtonBind::isCheckable(static_cast<QPushButton*>(button));
}

void QPushButton_setChecked(void* button, bool checked) {
    QPushButtonBind::setChecked(static_cast<QPushButton*>(button), checked);
}

bool QPushButton_isChecked(void* button) {
    return QPushButtonBind::isChecked(static_cast<QPushButton*>(button));
}

void QPushButton_setAutoRepeat(void* button, bool autoRepeat) {
    QPushButtonBind::setAutoRepeat(static_cast<QPushButton*>(button), autoRepeat);
}

bool QPushButton_autoRepeat(void* button) {
    return QPushButtonBind::autoRepeat(static_cast<QPushButton*>(button));
}

void QPushButton_click(void* button) {
    QPushButtonBind::click(static_cast<QPushButton*>(button));
}

void QPushButton_setFlat(void* button, bool flat) {
    QPushButtonBind::setFlat(static_cast<QPushButton*>(button), flat);
}

bool QPushButton_isFlat(void* button) {
    return QPushButtonBind::isFlat(static_cast<QPushButton*>(button));
}

void QPushButton_setDefault(void* button, bool default_) {
    QPushButtonBind::setDefault(static_cast<QPushButton*>(button), default_);
}

bool QPushButton_isDefault(void* button) {
    return QPushButtonBind::isDefault(static_cast<QPushButton*>(button));
}

void QPushButton_setClickCallback(void* button, QPushButtonClickCallback callback) {
    QPushButtonBind::setClickCallback(static_cast<QPushButton*>(button), callback);
}

void QPushButton_setPressedCallback(void* button, QPushButtonClickCallback callback) {
    QPushButtonBind::setPressedCallback(static_cast<QPushButton*>(button), callback);
}

void QPushButton_setReleasedCallback(void* button, QPushButtonClickCallback callback) {
    QPushButtonBind::setReleasedCallback(static_cast<QPushButton*>(button), callback);
}

}
