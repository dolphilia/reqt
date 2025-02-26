#include "QApplicationBind.h"
#include "qapplication.h"

extern "C" {

void* QApplication_create(int argc, char* argv[]) {
    return QApplicationBind::create(argc, argv);
}

void QApplication_delete(void* app) {
    QApplicationBind::destroy(static_cast<QApplication*>(app));
}

int QApplication_exec(void* app) {
    return QApplicationBind::exec(static_cast<QApplication*>(app));
}

void QApplication_processEvents(void* app) {
    QApplicationBind::processEvents(static_cast<QApplication*>(app));
}

}
