#include "bind_q_style.h"
#include <QStringList>

QStyle* QStyleBind::getStyle(const char* styleName) {
    if (!styleName) return nullptr;
    return QStyleFactory::create(QString::fromUtf8(styleName));
}

void QStyleBind::getAvailableStyles(const char*** styles, int* count) {
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

void QStyleBind::freeStyleList(const char** styles, int count) {
    if (styles) {
        for (int i = 0; i < count; ++i) {
            delete[] styles[i];
        }
        delete[] styles;
    }
}

void QStyleBind::setStyle(QStyle* style) {
    if (style) {
        QApplication::setStyle(style);
    }
}
