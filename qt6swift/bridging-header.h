#ifndef bridging_header_h
#define bridging_header_h

#include "include/qt6/qapplication.h"
#include "include/qt6/qmainwindow.h"
#include "include/qt6/qpushbutton.h"
#include "include/qt6/qlabel.h"
#include "include/qt6/qwidget.h"

// #ifdef __cplusplus
// extern "C" {
// #endif

// // Qt Application
// void* QApplication_create(int argc, char** argv) __attribute__((swift_name("QApplication_create(_:_:)")));
// int QApplication_exec(void* app) __attribute__((swift_name("QApplication_exec(_:)")));

// // Qt MainWindow
// void* QMainWindow_create(void* parent) __attribute__((swift_name("QMainWindow_create(_:)")));
// void QWidget_show(void* widget) __attribute__((swift_name("QWidget_show(_:)")));

// // Qt Widgets
// void* QPushButton_create(const char* text, void* parent) __attribute__((swift_name("QPushButton_create(_:_:)")));
// void* QLabel_create(const char* text, void* parent) __attribute__((swift_name("QLabel_create(_:_:)")));
// void QWidget_setGeometry(void* widget, int x, int y, int width, int height) __attribute__((swift_name("QWidget_setGeometry(_:_:_:_:_:)")));

// #ifdef __cplusplus
// }
// #endif

#endif /* bridging_header_h */
