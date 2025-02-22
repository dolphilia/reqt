#include "bind_q_style.h"
#include "c_q_style.h"

extern "C" {

void* QStyle_getStyle(const char* styleName) {
    return QStyleBind::getStyle(styleName);
}

void QStyle_getAvailableStyles(const char*** styles, int* count) {
    QStyleBind::getAvailableStyles(styles, count);
}

void QStyle_freeStyleList(const char** styles, int count) {
    QStyleBind::freeStyleList(styles, count);
}

void QStyle_setStyle(void* style) {
    QStyleBind::setStyle(static_cast<QStyle*>(style));
}

}
