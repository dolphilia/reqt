#include "QLabelBind.h"

extern "C" {

void* QLabel_create(const char* text, void* parent) {
    QString qstr = QString::fromUtf8(text);
    return new QLabelBind(qstr, static_cast<QWidget*>(parent));
}

void QLabel_delete(void* label) {
    delete static_cast<QLabelBind*>(label);
}

typedef void (*QLabel_LinkActivatedCallback)(void*, const char*);
typedef void (*QLabel_LinkHoveredCallback)(void*, const char*);

void QLabel_setLinkActivatedCallback(void* label, QLabel_LinkActivatedCallback callback) {
    static_cast<QLabelBind*>(label)->setLinkActivatedCallback(callback);
}

void QLabel_setLinkHoveredCallback(void* label, QLabel_LinkHoveredCallback callback) {
    static_cast<QLabelBind*>(label)->setLinkHoveredCallback(callback);
}

}
