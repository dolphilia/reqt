#include "qprogressbar.h"
#include "QProgressBarBind.h"
#include "QProgressBarHandler.h"
#include <QString>

extern "C" {

void* QProgressBar_create(void* parent)
{
    return new BindQProgressBar(reinterpret_cast<QWidget*>(parent));
}

void QProgressBar_delete(void* progress_bar)
{
    delete static_cast<BindQProgressBar*>(progress_bar);
}

void QProgressBar_setValue(void* progress_bar, int value)
{
    static_cast<BindQProgressBar*>(progress_bar)->setValue(value);
}

int QProgressBar_value(void* progress_bar)
{
    return static_cast<BindQProgressBar*>(progress_bar)->value();
}

void QProgressBar_setRange(void* progress_bar, int minimum, int maximum)
{
    static_cast<BindQProgressBar*>(progress_bar)->setRange(minimum, maximum);
}

int QProgressBar_minimum(void* progress_bar)
{
    return static_cast<BindQProgressBar*>(progress_bar)->minimum();
}

int QProgressBar_maximum(void* progress_bar)
{
    return static_cast<BindQProgressBar*>(progress_bar)->maximum();
}

void QProgressBar_reset(void* progress_bar)
{
    static_cast<BindQProgressBar*>(progress_bar)->reset();
}

void QProgressBar_setFormat(void* progress_bar, const char* format)
{
    static_cast<BindQProgressBar*>(progress_bar)->setFormat(QString::fromUtf8(format));
}

const char* QProgressBar_format(void* progress_bar)
{
    QString format = static_cast<BindQProgressBar*>(progress_bar)->format();
    return qstrdup(format.toUtf8().constData());
}

void QProgressBar_resetFormat(void* progress_bar)
{
    static_cast<BindQProgressBar*>(progress_bar)->resetFormat();
}

void QProgressBar_setTextVisible(void* progress_bar, bool visible)
{
    static_cast<BindQProgressBar*>(progress_bar)->setTextVisible(visible);
}

bool QProgressBar_isTextVisible(void* progress_bar)
{
    return static_cast<BindQProgressBar*>(progress_bar)->isTextVisible();
}

void QProgressBar_setOrientation(void* progress_bar, int orientation)
{
    static_cast<BindQProgressBar*>(progress_bar)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QProgressBar_orientation(void* progress_bar)
{
    return static_cast<int>(static_cast<BindQProgressBar*>(progress_bar)->orientation());
}

void QProgressBar_setInvertedAppearance(void* progress_bar, bool invert)
{
    static_cast<BindQProgressBar*>(progress_bar)->setInvertedAppearance(invert);
}

bool QProgressBar_invertedAppearance(void* progress_bar)
{
    return static_cast<BindQProgressBar*>(progress_bar)->invertedAppearance();
}

void QProgressBar_setTextDirection(void* progress_bar, int direction)
{
    static_cast<BindQProgressBar*>(progress_bar)->setTextDirection(static_cast<QProgressBar::Direction>(direction));
}

int QProgressBar_textDirection(void* progress_bar)
{
    return static_cast<int>(static_cast<BindQProgressBar*>(progress_bar)->textDirection());
}

void QProgressBar_setValueChangedCallback(void* progress_bar, QProgressBarValueChangedCallback callback)
{
    BindQProgressBar* qprogress_bar = static_cast<BindQProgressBar*>(progress_bar);
    ProgressBarHandler* handler = qprogress_bar->handler();
    if (!handler) {
        handler = new ProgressBarHandler(qprogress_bar);
        qprogress_bar->setProgressBarHandler(handler);
    }
    handler->setValueChangedCallback(callback);
}

}
