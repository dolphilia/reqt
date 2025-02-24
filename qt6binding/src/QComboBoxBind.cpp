#include "QComboBoxBind.h"
#include "QComboBoxHandler.h"
#include <QString>

QComboBox* QComboBoxBind::create(QWidget* parent) {
    return new QComboBox(parent);
}

void QComboBoxBind::destroy(QComboBox* comboBox) {
    if (comboBox) {
        // ハンドラーの削除
        QObject* handler = comboBox->findChild<ComboBoxHandler*>();
        if (handler) {
            delete handler;
        }
        delete comboBox;
    }
}

void QComboBoxBind::addItem(QComboBox* comboBox, const char* text) {
    if (comboBox && text) {
        comboBox->addItem(QString::fromUtf8(text));
    }
}

void QComboBoxBind::addItems(QComboBox* comboBox, const char** items, int count) {
    if (comboBox && items) {
        QStringList list;
        for (int i = 0; i < count; ++i) {
            if (items[i]) {
                list << QString::fromUtf8(items[i]);
            }
        }
        comboBox->addItems(list);
    }
}

void QComboBoxBind::clear(QComboBox* comboBox) {
    if (comboBox) {
        comboBox->clear();
    }
}

const char* QComboBoxBind::currentText(QComboBox* comboBox) {
    if (comboBox) {
        static QString str;
        str = comboBox->currentText();
        return str.toUtf8().constData();
    }
    return nullptr;
}

int QComboBoxBind::currentIndex(QComboBox* comboBox) {
    return comboBox ? comboBox->currentIndex() : -1;
}

int QComboBoxBind::count(QComboBox* comboBox) {
    return comboBox ? comboBox->count() : 0;
}

const char* QComboBoxBind::itemText(QComboBox* comboBox, int index) {
    if (comboBox) {
        static QString str;
        str = comboBox->itemText(index);
        return str.toUtf8().constData();
    }
    return nullptr;
}

void QComboBoxBind::setCurrentIndex(QComboBox* comboBox, int index) {
    if (comboBox) {
        comboBox->setCurrentIndex(index);
    }
}

void QComboBoxBind::setCurrentText(QComboBox* comboBox, const char* text) {
    if (comboBox && text) {
        comboBox->setCurrentText(QString::fromUtf8(text));
    }
}

void QComboBoxBind::setEditable(QComboBox* comboBox, bool editable) {
    if (comboBox) {
        comboBox->setEditable(editable);
    }
}

bool QComboBoxBind::isEditable(QComboBox* comboBox) {
    return comboBox ? comboBox->isEditable() : false;
}

void QComboBoxBind::setEnabled(QComboBox* comboBox, bool enabled) {
    if (comboBox) {
        comboBox->setEnabled(enabled);
    }
}

bool QComboBoxBind::isEnabled(QComboBox* comboBox) {
    return comboBox ? comboBox->isEnabled() : false;
}

void QComboBoxBind::setCurrentIndexChangedCallback(QComboBox* comboBox, QComboBoxCurrentIndexChangedCallback callback) {
    if (comboBox) {
        // 既存のハンドラーを削除
        QObject* existingHandler = comboBox->findChild<ComboBoxHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        ComboBoxHandler* handler = new ComboBoxHandler(callback, nullptr);
        handler->setParent(comboBox);
        QObject::connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                        handler, &ComboBoxHandler::onCurrentIndexChanged);
    }
}

void QComboBoxBind::setCurrentTextChangedCallback(QComboBox* comboBox, QComboBoxCurrentTextChangedCallback callback) {
    if (comboBox) {
        // 既存のハンドラーを削除
        QObject* existingHandler = comboBox->findChild<ComboBoxHandler*>();
        if (existingHandler) {
            delete existingHandler;
        }
        
        // 新しいハンドラーを作成
        ComboBoxHandler* handler = new ComboBoxHandler(nullptr, callback);
        handler->setParent(comboBox);
        QObject::connect(comboBox, &QComboBox::currentTextChanged,
                        handler, &ComboBoxHandler::onCurrentTextChanged);
    }
}
