#include "QPushButtonBind.h"
#include "QPushButtonHandler.h"
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
