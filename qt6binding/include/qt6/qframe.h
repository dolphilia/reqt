#ifndef QFRAME_C_H
#define QFRAME_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QFrame::Shadow 列挙型の定数
#define QFRAME_SHADOW_PLAIN 0x0010
#define QFRAME_SHADOW_RAISED 0x0020
#define QFRAME_SHADOW_SUNKEN 0x0030

// QFrame::Shape 列挙型の定数
#define QFRAME_SHAPE_NOFRAME 0
#define QFRAME_SHAPE_BOX 0x0001
#define QFRAME_SHAPE_PANEL 0x0002
#define QFRAME_SHAPE_STYLED_PANEL 0x0006
#define QFRAME_SHAPE_HLINE 0x0004
#define QFRAME_SHAPE_VLINE 0x0005
#define QFRAME_SHAPE_WINPANEL 0x0003

// QFrame::StyleMask 列挙型の定数
#define QFRAME_STYLE_MASK_SHADOW_MASK 0x00f0
#define QFRAME_STYLE_MASK_SHAPE_MASK 0x000f

// コンストラクタ/デストラクタ
void* QFrame_create(void* parent, unsigned int flags);
void QFrame_delete(void* frame);

// プロパティ取得
void* QFrame_frameRect(void* frame);
int QFrame_frameShadow(void* frame);
int QFrame_frameShape(void* frame);
int QFrame_frameStyle(void* frame);
int QFrame_frameWidth(void* frame);
int QFrame_lineWidth(void* frame);
int QFrame_midLineWidth(void* frame);
void* QFrame_sizeHint(void* frame);

// プロパティ設定
void QFrame_setFrameRect(void* frame, void* rect);
void QFrame_setFrameShadow(void* frame, int shadow);
void QFrame_setFrameShape(void* frame, int shape);
void QFrame_setFrameStyle(void* frame, int style);
void QFrame_setLineWidth(void* frame, int width);
void QFrame_setMidLineWidth(void* frame, int width);

#ifdef __cplusplus
}
#endif

#endif // QFRAME_C_H
