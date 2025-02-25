#include "QLabelBind.h"
#include "qlabel.h"

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

// 追加機能
void QLabel_setMargin(void* label, int margin) {
    static_cast<QLabelBind*>(label)->setMargin(margin);
}

int QLabel_margin(void* label) {
    return static_cast<QLabelBind*>(label)->margin();
}

void QLabel_setIndent(void* label, int indent) {
    static_cast<QLabelBind*>(label)->setIndent(indent);
}

int QLabel_indent(void* label) {
    return static_cast<QLabelBind*>(label)->indent();
}

void QLabel_setScaledContents(void* label, bool scaled) {
    static_cast<QLabelBind*>(label)->setScaledContents(scaled);
}

bool QLabel_hasScaledContents(void* label) {
    return static_cast<QLabelBind*>(label)->hasScaledContents();
}

void* QLabel_buddy(void* label) {
    return static_cast<QLabelBind*>(label)->buddy();
}

void QLabel_setBuddy(void* label, void* buddy) {
    static_cast<QLabelBind*>(label)->setBuddy(buddy);
}

bool QLabel_hasSelectedText(void* label) {
    return static_cast<QLabelBind*>(label)->hasSelectedText();
}

const char* QLabel_selectedText(void* label) {
    return static_cast<QLabelBind*>(label)->selectedText();
}

int QLabel_selectionStart(void* label) {
    return static_cast<QLabelBind*>(label)->selectionStart();
}

void QLabel_setSelection(void* label, int start, int length) {
    static_cast<QLabelBind*>(label)->setSelection(start, length);
}

void* QLabel_pixmap(void* label) {
    return static_cast<QLabelBind*>(label)->pixmap();
}

void QLabel_setPixmap(void* label, void* pixmap) {
    static_cast<QLabelBind*>(label)->setPixmap(pixmap);
}

void* QLabel_movie(void* label) {
    return static_cast<QLabelBind*>(label)->movie();
}

void QLabel_setMovie(void* label, void* movie) {
    static_cast<QLabelBind*>(label)->setMovie(movie);
}

void* QLabel_picture(void* label) {
    return static_cast<QLabelBind*>(label)->picture();
}

void QLabel_setPicture(void* label, void* picture) {
    static_cast<QLabelBind*>(label)->setPicture(picture);
}

void QLabel_setNumInt(void* label, int num) {
    static_cast<QLabelBind*>(label)->setNum(num);
}

void QLabel_setNumDouble(void* label, double num) {
    static_cast<QLabelBind*>(label)->setNum(num);
}

void QLabel_setTextInteractionFlags(void* label, int flags) {
    static_cast<QLabelBind*>(label)->setTextInteractionFlags(flags);
}

int QLabel_textInteractionFlags(void* label) {
    return static_cast<QLabelBind*>(label)->textInteractionFlags();
}

// シグナル用コールバック
void QLabel_setLinkActivatedCallback(void* label, void (*callback)(void*, const char*)) {
    static_cast<QLabelBind*>(label)->setLinkActivatedCallback(
        reinterpret_cast<QLabelBind::LinkActivatedCallback>(callback)
    );
}

void QLabel_setLinkHoveredCallback(void* label, void (*callback)(void*, const char*)) {
    static_cast<QLabelBind*>(label)->setLinkHoveredCallback(
        reinterpret_cast<QLabelBind::LinkHoveredCallback>(callback)
    );
}

}
