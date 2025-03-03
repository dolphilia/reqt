#include "qt6.h"
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
    
    // Create main widget
    void *widget = QWidget_create(NULL);
    QWidget_resize(widget, 400, 100);
    QWidget_setWindowTitle(widget, "QTabBar Example");
    
    // Create tab bar
    void *tab_bar = QTabBar_create(widget);
    
    // Add tabs
    QTabBar_addTab(tab_bar, "Tab 1");
    QTabBar_addTab(tab_bar, "Tab 2");
    QTabBar_addTab(tab_bar, "Tab 3");
    
    // Enable closable tabs
    QTabBar_setTabsClosable(tab_bar, true);
    
    // Set tooltips
    QTabBar_setTabToolTip(tab_bar, 0, "First Tab");
    QTabBar_setTabToolTip(tab_bar, 1, "Second Tab");
    QTabBar_setTabToolTip(tab_bar, 2, "Third Tab");
    
    // Connect signals
    QTabBar_setCurrentChangedCallback(tab_bar, on_current_changed);
    QTabBar_setTabCloseRequestedCallback(tab_bar, on_tab_close_requested);
    
    // Show widget
    QWidget_show(widget);
    
    // Run application
    int result = QApplication_exec();
    
    // Cleanup
    QTabBar_delete(tab_bar);
    QWidget_delete(widget);
    QApplication_delete(app);
    
    return result;
}
