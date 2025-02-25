#ifndef QLABEL_C_H
#define QLABEL_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QLabel
void* QLabel_create(const char* text, void* parent);
void QLabel_delete(void* label);
void QLabel_setText(void* label, const char* text);
const char* QLabel_text(void* label);
void QLabel_setWordWrap(void* label, bool wrap);
bool QLabel_wordWrap(void* label);
void QLabel_clear(void* label);
void QLabel_setAlignment(void* label, int alignment);
int QLabel_alignment(void* label);
void QLabel_setOpenExternalLinks(void* label, bool open);
bool QLabel_openExternalLinks(void* label);
void QLabel_setTextFormat(void* label, int format);
int QLabel_textFormat(void* label);

// 追加機能
void QLabel_setMargin(void* label, int margin);
int QLabel_margin(void* label);
void QLabel_setIndent(void* label, int indent);
int QLabel_indent(void* label);
void QLabel_setScaledContents(void* label, bool scaled);
bool QLabel_hasScaledContents(void* label);
void* QLabel_buddy(void* label);
void QLabel_setBuddy(void* label, void* buddy);
bool QLabel_hasSelectedText(void* label);
const char* QLabel_selectedText(void* label);
int QLabel_selectionStart(void* label);
void QLabel_setSelection(void* label, int start, int length);
void* QLabel_pixmap(void* label);
void QLabel_setPixmap(void* label, void* pixmap);
void* QLabel_movie(void* label);
void QLabel_setMovie(void* label, void* movie);
void* QLabel_picture(void* label);
void QLabel_setPicture(void* label, void* picture);
void QLabel_setNumInt(void* label, int num);
void QLabel_setNumDouble(void* label, double num);
void QLabel_setTextInteractionFlags(void* label, int flags);
int QLabel_textInteractionFlags(void* label);

// シグナル用コールバック
void QLabel_setLinkActivatedCallback(void* label, void (*callback)(void*, const char*));
void QLabel_setLinkHoveredCallback(void* label, void (*callback)(void*, const char*));

// テキストフォーマット定数
#define QLABEL_PLAINTEXT 0
#define QLABEL_RICHTEXT 1
#define QLABEL_AUTOTEXT 2
#define QLABEL_MARKDOWN 3

// アライメント定数
#define QLABEL_ALIGN_LEFT 0x0001
#define QLABEL_ALIGN_RIGHT 0x0002
#define QLABEL_ALIGN_HCENTER 0x0004
#define QLABEL_ALIGN_JUSTIFY 0x0008
#define QLABEL_ALIGN_TOP 0x0020
#define QLABEL_ALIGN_BOTTOM 0x0040
#define QLABEL_ALIGN_VCENTER 0x0080
#define QLABEL_ALIGN_CENTER 0x0084

// テキストインタラクションフラグ定数
#define QLABEL_NO_TEXT_INTERACTION 0
#define QLABEL_TEXT_SELECTABLE 1
#define QLABEL_TEXT_EDITABLE 2
#define QLABEL_TEXT_BROWSER_INTERACTION 4
#define QLABEL_TEXT_EDITOR_INTERACTION 7

#ifdef __cplusplus
}
#endif

#endif // QLABEL_C_H
