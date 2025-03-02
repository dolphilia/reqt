#ifndef QSTATUSBAR_BIND_H
#define QSTATUSBAR_BIND_H

#include <QStatusBar>

class QStatusBarBind {
public:
    static QStatusBar* create(QWidget* parent = nullptr);
    static void destroy(QStatusBar* statusBar);
    static void showMessage(QStatusBar* statusBar, const char* message);
    static void clearMessage(QStatusBar* statusBar);
    static void setEnabled(QStatusBar* statusBar, bool enabled);
    static bool isEnabled(QStatusBar* statusBar);
};

#endif // QSTATUSBAR_BIND_H
