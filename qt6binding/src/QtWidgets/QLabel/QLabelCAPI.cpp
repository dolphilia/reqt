#include "QLabelBind.h"
#include "qlabel.h"

extern "C" {

void* QLabel_create(const char* text, void* parent) {
    QString qstr = QString::fromUtf8(text);
    return new QLabelBind(qstr, static_cast<QWidget*>(parent));
}

void QLabel_delete(void* label) {
    delete static_cast<QLabelBind*>(label);
}

void QLabel_setLinkActivatedCallback(void* label, void (*callback)(void*, const char*)) {
    static_cast<QLabelBind*>(label)->setLinkActivatedCallback(callback);
}

void QLabel_setLinkHoveredCallback(void* label, void (*callback)(void*, const char*)) {
    static_cast<QLabelBind*>(label)->setLinkHoveredCallback(callback);
}

}
