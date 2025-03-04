#include "QStyleBind.h"
#include <QStyle>
#include <QApplication>
#include <QStyleFactory>
#include <QStringList>

extern "C" {

void* QStyleBind_create(QObject* parent) {
    return new QStyleBind(parent);
}

void QStyleBind_delete(void* styleBind) {
    delete static_cast<QStyleBind*>(styleBind);
}

void* QStyle_getStyle(const char* styleName) {
    if (!styleName) return nullptr;
    return QStyleFactory::create(QString::fromUtf8(styleName));
}

void QStyle_getAvailableStyles(const char*** styles, int* count) {
    QStringList styleNames = QStyleFactory::keys();
    *count = styleNames.size();
    *styles = new const char*[*count];
    
    for (int i = 0; i < *count; ++i) {
        QByteArray ba = styleNames[i].toUtf8();
        char* str = new char[ba.size() + 1];
        strcpy(str, ba.constData());
        (*styles)[i] = str;
    }
}

void QStyle_freeStyleList(const char** styles, int count) {
    if (styles) {
        for (int i = 0; i < count; ++i) {
            delete[] styles[i];
        }
        delete[] styles;
    }
}

void QStyle_setStyle(void* style) {
    if (style) {
        QApplication::setStyle(static_cast<QStyle*>(style));
    }
}

}
