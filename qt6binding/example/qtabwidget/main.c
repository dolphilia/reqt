#include "qt6binding.h"
#include "c_q_tab_widget.h"
#include <stdio.h>

void on_current_changed(int index) {
    printf("Current tab changed to: %d\n", index);
}

void on_tab_close_requested(int index) {
    printf("Tab close requested: %d\n", index);
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create tab widget
    void *tab_widget = QTabWidget_create(NULL);
    
    // Create widgets for tabs
    void *widget1 = QWidget_create(NULL);
    void *widget2 = QWidget_create(NULL);
    void *widget3 = QWidget_create(NULL);
    
    // Add tabs
    QTabWidget_addTab(tab_widget, widget1, "Tab 1");
    QTabWidget_addTab(tab_widget, widget2, "Tab 2");
    QTabWidget_addTab(tab_widget, widget3, "Tab 3");
    
    // Configure tab widget
    QTabWidget_setTabsClosable(tab_widget, true);
    QTabWidget_setMovable(tab_widget, true);
    QTabWidget_setTabPosition(tab_widget, QTABWIDGET_NORTH);
    
    // Set tooltips
    QTabWidget_setTabToolTip(tab_widget, 0, "First Tab");
    QTabWidget_setTabToolTip(tab_widget, 1, "Second Tab");
    QTabWidget_setTabToolTip(tab_widget, 2, "Third Tab");
    
    // Connect signals
    QTabWidget_setCurrentChangedCallback(tab_widget, on_current_changed);
    QTabWidget_setTabCloseRequestedCallback(tab_widget, on_tab_close_requested);
    
    // Set window properties
    QWidget_resize(tab_widget, 400, 300);
    QWidget_setWindowTitle(tab_widget, "QTabWidget Example");
    
    // Show widget
    QWidget_show(tab_widget);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QWidget_delete(widget1);
    QWidget_delete(widget2);
    QWidget_delete(widget3);
    QTabWidget_delete(tab_widget);
    QApplication_delete(app);
    
    return result;
}
