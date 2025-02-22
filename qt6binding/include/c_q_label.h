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

#ifdef __cplusplus
}
#endif

#endif // QLABEL_C_H
