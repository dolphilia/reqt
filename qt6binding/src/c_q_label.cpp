#include "bind_q_label.h"
#include "c_q_label.h"

extern "C" {

void* QLabel_create(const char* text, void* parent) {
    return new QLabelBind(QString::fromUtf8(text), static_cast<QWidget*>(parent));
}

void QLabel_delete(void* label) {
    delete static_cast<QLabelBind*>(label);
}

void QLabel_setText(void* label, const char* text) {
    static_cast<QLabelBind*>(label)->setText(text);
}

const char* QLabel_text(void* label) {
    return static_cast<QLabelBind*>(label)->text();
}

void QLabel_setWordWrap(void* label, bool wrap) {
    static_cast<QLabelBind*>(label)->setWordWrap(wrap);
}

bool QLabel_wordWrap(void* label) {
    return static_cast<QLabelBind*>(label)->wordWrap();
}

void QLabel_clear(void* label) {
    static_cast<QLabelBind*>(label)->clear();
}

void QLabel_setAlignment(void* label, int alignment) {
    static_cast<QLabelBind*>(label)->setAlignment(alignment);
}

int QLabel_alignment(void* label) {
    return static_cast<QLabelBind*>(label)->alignment();
}

void QLabel_setOpenExternalLinks(void* label, bool open) {
    static_cast<QLabelBind*>(label)->setOpenExternalLinks(open);
}

bool QLabel_openExternalLinks(void* label) {
    return static_cast<QLabelBind*>(label)->openExternalLinks();
}

void QLabel_setTextFormat(void* label, int format) {
    static_cast<QLabelBind*>(label)->setTextFormat(format);
}

int QLabel_textFormat(void* label) {
    return static_cast<QLabelBind*>(label)->textFormat();
}

}
