#include "QCheckBoxBind.h"
#include "QCheckBoxHandler.h"
#include <QString>

QCheckBox* QCheckBoxBind::create(const char* text, QWidget* parent) {
    if (text) {
        return new QCheckBox(QString::fromUtf8(text), parent);
    }
    return new QCheckBox(parent);
}

void QCheckBoxBind::destroy(QCheckBox* checkbox) {
    if (checkbox) {
        // ハンドラーの削除
        QObject* handler = checkbox->findChild<CheckBoxHandler*>();
        if (handler) {
            delete handler;
        }
        delete checkbox;
    }
}

void QCheckBoxBind::setText(QCheckBox* checkbox, const char* text) {
    if (checkbox && text) {
        checkbox->setText(QString::fromUtf8(text));
    }
}

const char* QCheckBoxBind::text(QCheckBox* checkbox) {
    if (checkbox) {
        static QString str;
        str = checkbox->text();
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QCheckBoxBind::setChecked(QCheckBox* checkbox, bool checked) {
    if (checkbox) {
        checkbox->setChecked(checked);
    }
}

bool QCheckBoxBind::isChecked(QCheckBox* checkbox) {
    return checkbox ? checkbox->isChecked() : false;
}

void QCheckBoxBind::setTristate(QCheckBox* checkbox, bool tristate) {
    if (checkbox) {
        checkbox->setTristate(tristate);
    }
}

bool QCheckBoxBind::isTristate(QCheckBox* checkbox) {
    return checkbox ? checkbox->isTristate() : false;
}

void QCheckBoxBind::setCheckState(QCheckBox* checkbox, int state) {
    if (checkbox) {
        checkbox->setCheckState(static_cast<Qt::CheckState>(state));
    }
}

int QCheckBoxBind::checkState(QCheckBox* checkbox) {
    return checkbox ? static_cast<int>(checkbox->checkState()) : 0;
}

void QCheckBoxBind::setEnabled(QCheckBox* checkbox, bool enabled) {
    if (checkbox) {
        checkbox->setEnabled(enabled);
    }
}

bool QCheckBoxBind::isEnabled(QCheckBox* checkbox) {
    return checkbox ? checkbox->isEnabled() : false;
}

void QCheckBoxBind::setStateChangedCallback(QCheckBox* checkbox, QCheckBoxStateChangedCallback callback) {
    if (checkbox) {
        // 既存のハンドラーを削除
        QObject* existingHandler = checkbox->findChild<CheckBoxHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        CheckBoxHandler* handler = new CheckBoxHandler();
        handler->setParent(checkbox);
        handler->setStateChangedCallback(callback);
        QObject::connect(checkbox, &QCheckBox::stateChanged, handler, &CheckBoxHandler::onStateChanged);
    }
}

void QCheckBoxBind::setToggledCallback(QCheckBox* checkbox, QCheckBoxToggledCallback callback) {
    if (checkbox) {
        // 既存のハンドラーを削除
        QObject* existingHandler = checkbox->findChild<CheckBoxHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        CheckBoxHandler* handler = new CheckBoxHandler();
        handler->setParent(checkbox);
        handler->setToggledCallback(callback);
        QObject::connect(checkbox, &QCheckBox::toggled, handler, &CheckBoxHandler::onToggled);
    }
}

void QCheckBoxBind::setClickedCallback(QCheckBox* checkbox, QCheckBoxToggledCallback callback) {
    if (checkbox) {
        // 既存のハンドラーを削除
        QObject* existingHandler = checkbox->findChild<CheckBoxHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        CheckBoxHandler* handler = new CheckBoxHandler();
        handler->setParent(checkbox);
        handler->setToggledCallback(callback);
        QObject::connect(checkbox, &QCheckBox::clicked, handler, &CheckBoxHandler::onToggled);
    }
}
