#include "QApplicationBind.h"

QApplication* QApplicationBind::create(int argc, char* argv[]) {
    static int s_argc = argc;
    static char** s_argv = argv;
    static QApplication* app = nullptr;
    
    if (!app) {
        app = new QApplication(s_argc, s_argv);
    }
    return app;
}

void QApplicationBind::destroy(QApplication* app) {
    if (app) {
        delete app;
    }
}

int QApplicationBind::exec(QApplication* app) {
    if (app) {
        return app->exec();
    }
    return -1;
}
