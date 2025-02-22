#ifndef QAPPLICATION_BIND_H
#define QAPPLICATION_BIND_H

#include <QApplication>

class QApplicationBind {
public:
    static QApplication* create(int argc, char* argv[]);
    static void destroy(QApplication* app);
    static int exec(QApplication* app);
};

#endif // QAPPLICATION_BIND_H
