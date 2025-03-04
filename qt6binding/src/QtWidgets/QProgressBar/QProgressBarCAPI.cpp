#include "QProgressBarBind.h"

extern "C" {

void* QProgressBar_create(void* parent) {
    return new QProgressBarBind(static_cast<QWidget*>(parent));
}

void QProgressBar_delete(void* progressBar) {
    delete static_cast<QProgressBarBind*>(progressBar);
}

void QProgressBar_setValue(void* progressBar, int value) {
    static_cast<QProgressBarBind*>(progressBar)->setValue(value);
}

int QProgressBar_value(void* progressBar) {
    return static_cast<QProgressBarBind*>(progressBar)->value();
}

void QProgressBar_setRange(void* progressBar, int minimum, int maximum) {
    static_cast<QProgressBarBind*>(progressBar)->setRange(minimum, maximum);
}

int QProgressBar_minimum(void* progressBar) {
    return static_cast<QProgressBarBind*>(progressBar)->minimum();
}

int QProgressBar_maximum(void* progressBar) {
    return static_cast<QProgressBarBind*>(progressBar)->maximum();
}

void QProgressBar_reset(void* progressBar) {
    static_cast<QProgressBarBind*>(progressBar)->reset();
}

void QProgressBar_setFormat(void* progressBar, const char* format) {
    static_cast<QProgressBarBind*>(progressBar)->setFormat(QString::fromUtf8(format));
}

const char* QProgressBar_format(void* progressBar) {
    QString format = static_cast<QProgressBarBind*>(progressBar)->format();
    return qstrdup(format.toUtf8().constData());
}

void QProgressBar_resetFormat(void* progressBar) {
    static_cast<QProgressBarBind*>(progressBar)->resetFormat();
}

void QProgressBar_setTextVisible(void* progressBar, bool visible) {
    static_cast<QProgressBarBind*>(progressBar)->setTextVisible(visible);
}

bool QProgressBar_isTextVisible(void* progressBar) {
    return static_cast<QProgressBarBind*>(progressBar)->isTextVisible();
}

void QProgressBar_setOrientation(void* progressBar, int orientation) {
    static_cast<QProgressBarBind*>(progressBar)->setOrientation(static_cast<Qt::Orientation>(orientation));
}

int QProgressBar_orientation(void* progressBar) {
    return static_cast<int>(static_cast<QProgressBarBind*>(progressBar)->orientation());
}

void QProgressBar_setInvertedAppearance(void* progressBar, bool invert) {
    static_cast<QProgressBarBind*>(progressBar)->setInvertedAppearance(invert);
}

bool QProgressBar_invertedAppearance(void* progressBar) {
    return static_cast<QProgressBarBind*>(progressBar)->invertedAppearance();
}

void QProgressBar_setTextDirection(void* progressBar, int direction) {
    static_cast<QProgressBarBind*>(progressBar)->setTextDirection(static_cast<QProgressBar::Direction>(direction));
}

int QProgressBar_textDirection(void* progressBar) {
    return static_cast<int>(static_cast<QProgressBarBind*>(progressBar)->textDirection());
}

typedef void (*QProgressBar_ValueChangedCallback)(void*, int);

void QProgressBar_setValueChangedCallback(void* progressBar, QProgressBar_ValueChangedCallback callback) {
    static_cast<QProgressBarBind*>(progressBar)->setValueChangedCallback(callback);
}

}
