#include "qt6.h"
#include <stdio.h>

static void* g_menu = NULL;

void on_about_to_show() {
    printf("Menu is about to show\n");
}

void on_about_to_hide() {
    printf("Menu is about to hide\n");
}

void on_triggered(void* action) {
    const char* text = QMenu_actionText(NULL, action);
    printf("Action triggered: %s\n", text);
}

void on_hovered(void* action) {
    const char* text = QMenu_actionText(NULL, action);
    printf("Action hovered: %s\n", text);
}

void on_button_clicked(void* button) {
    if (g_menu) {
        QMenu_popup(g_menu, 150, 150);
    }
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QMenu Example");
    
    // Create menu
    g_menu = QMenu_createWithTitle("File", window);
    
    // Add actions
    void *new_action = QMenu_addAction(g_menu, "New");
    void *open_action = QMenu_addAction(g_menu, "Open");
    void *save_action = QMenu_addAction(g_menu, "Save");
    QMenu_addSeparator(g_menu);
    
    // Create submenu
    void *recent_menu = QMenu_createWithTitle("Recent Files", NULL);
    QMenu_addAction(recent_menu, "Document 1.txt");
    QMenu_addAction(recent_menu, "Document 2.txt");
    QMenu_addAction(recent_menu, "Document 3.txt");
    QMenu_addMenu(g_menu, recent_menu);
    
    QMenu_addSeparator(g_menu);
    
    // Add checkable action
    void *auto_save = QMenu_addAction(g_menu, "Auto Save");
    QMenu_setActionCheckable(g_menu, auto_save, true);
    QMenu_setActionChecked(g_menu, auto_save, true);
    
    QMenu_addSeparator(g_menu);
    
    // Add exit action
    void *exit_action = QMenu_addAction(g_menu, "Exit");
    
    // Connect signals
    QMenu_setAboutToShowCallback(g_menu, on_about_to_show);
    QMenu_setAboutToHideCallback(g_menu, on_about_to_hide);
    QMenu_setTriggeredCallback(g_menu, on_triggered);
    QMenu_setHoveredCallback(g_menu, on_hovered);
    
    // Create a button to show the menu
    void *button = QPushButton_create("Show Menu", window);
    QWidget_move(button, 150, 120);
    
    // Show window and button
    QWidget_show(window);
    QWidget_show(button);
    
    // Show menu when button is clicked
    QPushButton_setClickCallback(button, on_button_clicked);
    
    // Run application
    int result = QApplication_exec();
    
    // Cleanup
    QMenu_delete(recent_menu);
    QMenu_delete(g_menu);
    QPushButton_delete(button);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
