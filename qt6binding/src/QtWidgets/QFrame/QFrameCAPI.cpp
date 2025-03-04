#include "QFrameBind.h"

extern "C" {

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
void* QFrame_create(void* parent, unsigned int flags) {
    return new QFrameBind(static_cast<QWidget*>(parent), static_cast<Qt::WindowFlags>(flags));
}

void QFrame_delete(void* frame) {
    delete static_cast<QFrameBind*>(frame);
}

// プロパティ取得
void* QFrame_frameRect(void* frame) {
    return new QRect(static_cast<QFrameBind*>(frame)->frameRect());
}

int QFrame_frameShadow(void* frame) {
    QFrame::Shadow shadow = static_cast<QFrameBind*>(frame)->frameShadow();
    switch (shadow) {
        case QFrame::Plain: return QFRAME_SHADOW_PLAIN;
        case QFrame::Raised: return QFRAME_SHADOW_RAISED;
        case QFrame::Sunken: return QFRAME_SHADOW_SUNKEN;
        default: return QFRAME_SHADOW_PLAIN;
    }
}

int QFrame_frameShape(void* frame) {
    QFrame::Shape shape = static_cast<QFrameBind*>(frame)->frameShape();
    switch (shape) {
        case QFrame::NoFrame: return QFRAME_SHAPE_NOFRAME;
        case QFrame::Box: return QFRAME_SHAPE_BOX;
        case QFrame::Panel: return QFRAME_SHAPE_PANEL;
        case QFrame::StyledPanel: return QFRAME_SHAPE_STYLED_PANEL;
        case QFrame::HLine: return QFRAME_SHAPE_HLINE;
        case QFrame::VLine: return QFRAME_SHAPE_VLINE;
        case QFrame::WinPanel: return QFRAME_SHAPE_WINPANEL;
        default: return QFRAME_SHAPE_NOFRAME;
    }
}

int QFrame_frameStyle(void* frame) {
    return static_cast<QFrameBind*>(frame)->frameStyle();
}

int QFrame_frameWidth(void* frame) {
    return static_cast<QFrameBind*>(frame)->frameWidth();
}

int QFrame_lineWidth(void* frame) {
    return static_cast<QFrameBind*>(frame)->lineWidth();
}

int QFrame_midLineWidth(void* frame) {
    return static_cast<QFrameBind*>(frame)->midLineWidth();
}

void* QFrame_sizeHint(void* frame) {
    return new QSize(static_cast<QFrameBind*>(frame)->sizeHint());
}

// プロパティ設定
void QFrame_setFrameRect(void* frame, void* rect) {
    static_cast<QFrameBind*>(frame)->setFrameRect(*static_cast<QRect*>(rect));
}

void QFrame_setFrameShadow(void* frame, int shadow) {
    QFrame::Shadow qshadow;
    switch (shadow) {
        case QFRAME_SHADOW_PLAIN: qshadow = QFrame::Plain; break;
        case QFRAME_SHADOW_RAISED: qshadow = QFrame::Raised; break;
        case QFRAME_SHADOW_SUNKEN: qshadow = QFrame::Sunken; break;
        default: qshadow = QFrame::Plain; break;
    }
    static_cast<QFrameBind*>(frame)->setFrameShadow(qshadow);
}

void QFrame_setFrameShape(void* frame, int shape) {
    QFrame::Shape qshape;
    switch (shape) {
        case QFRAME_SHAPE_NOFRAME: qshape = QFrame::NoFrame; break;
        case QFRAME_SHAPE_BOX: qshape = QFrame::Box; break;
        case QFRAME_SHAPE_PANEL: qshape = QFrame::Panel; break;
        case QFRAME_SHAPE_STYLED_PANEL: qshape = QFrame::StyledPanel; break;
        case QFRAME_SHAPE_HLINE: qshape = QFrame::HLine; break;
        case QFRAME_SHAPE_VLINE: qshape = QFrame::VLine; break;
        case QFRAME_SHAPE_WINPANEL: qshape = QFrame::WinPanel; break;
        default: qshape = QFrame::NoFrame; break;
    }
    static_cast<QFrameBind*>(frame)->setFrameShape(qshape);
}

void QFrame_setFrameStyle(void* frame, int style) {
    static_cast<QFrameBind*>(frame)->setFrameStyle(style);
}

void QFrame_setLineWidth(void* frame, int width) {
    static_cast<QFrameBind*>(frame)->setLineWidth(width);
}

void QFrame_setMidLineWidth(void* frame, int width) {
    static_cast<QFrameBind*>(frame)->setMidLineWidth(width);
}

}
