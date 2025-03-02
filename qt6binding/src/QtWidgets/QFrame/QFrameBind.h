#ifndef QFRAME_BIND_H
#define QFRAME_BIND_H

#include <QFrame>
#include <QRect>

class QFrameBind {
public:
    // コンストラクタ/デストラクタ
    static QFrame* create(QWidget* parent, Qt::WindowFlags f = Qt::WindowFlags());
    static void destroy(QFrame* frame);
    
    // プロパティ取得
    static QRect* frameRect(QFrame* frame);
    static QFrame::Shadow frameShadow(QFrame* frame);
    static QFrame::Shape frameShape(QFrame* frame);
    static int frameStyle(QFrame* frame);
    static int frameWidth(QFrame* frame);
    static int lineWidth(QFrame* frame);
    static int midLineWidth(QFrame* frame);
    static QSize* sizeHint(QFrame* frame);
    
    // プロパティ設定
    static void setFrameRect(QFrame* frame, QRect* rect);
    static void setFrameShadow(QFrame* frame, QFrame::Shadow shadow);
    static void setFrameShape(QFrame* frame, QFrame::Shape shape);
    static void setFrameStyle(QFrame* frame, int style);
    static void setLineWidth(QFrame* frame, int width);
    static void setMidLineWidth(QFrame* frame, int width);
};

#endif // QFRAME_BIND_H
