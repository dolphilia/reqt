#include "qt6.h"
#include <stdio.h>

void on_triggered(void* action) {
    const char* text = QMenuBar_actionText(NULL, action);
    printf("Action triggered: %s\n", text);
}

void on_hovered(void* action) {
    const char* text = QMenuBar_actionText(NULL, action);
    printf("Action hovered: %s\n", text);
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 800, 600);
    QWidget_setWindowTitle(window, "QMenuBar Example");
    
    // Create menu bar
    void *menu_bar = QMenuBar_create(window);
    
    // Create File menu
    void *file_menu = QMenuBar_addMenu(menu_bar, "File");
    void *new_action = QMenu_addAction(file_menu, "New");
    void *open_action = QMenu_addAction(file_menu, "Open");
    void *save_action = QMenu_addAction(file_menu, "Save");
    QMenu_addSeparator(file_menu);
    
    // Add Recent Files submenu
    void *recent_menu = QMenu_createWithTitle("Recent Files", NULL);
    QMenu_addAction(recent_menu, "Document 1.txt");
    QMenu_addAction(recent_menu, "Document 2.txt");
    QMenu_addAction(recent_menu, "Document 3.txt");
    QMenu_addMenu(file_menu, recent_menu);
    
    QMenu_addSeparator(file_menu);
    void *exit_action = QMenu_addAction(file_menu, "Exit");
    
    // Create Edit menu
    void *edit_menu = QMenuBar_addMenu(menu_bar, "Edit");
    void *undo_action = QMenu_addAction(edit_menu, "Undo");
    void *redo_action = QMenu_addAction(edit_menu, "Redo");
    QMenu_addSeparator(edit_menu);
    void *cut_action = QMenu_addAction(edit_menu, "Cut");
    void *copy_action = QMenu_addAction(edit_menu, "Copy");
    void *paste_action = QMenu_addAction(edit_menu, "Paste");
    
    // Create View menu
    void *view_menu = QMenuBar_addMenu(menu_bar, "View");
    void *toolbar_action = QMenu_addAction(view_menu, "Show Toolbar");
    void *statusbar_action = QMenu_addAction(view_menu, "Show Status Bar");
    QMenu_setActionCheckable(view_menu, toolbar_action, 1);
    QMenu_setActionCheckable(view_menu, statusbar_action, 1);
    QMenu_setActionChecked(view_menu, toolbar_action, 1);
    QMenu_setActionChecked(view_menu, statusbar_action, 1);
    
    // Create Help menu
    void *help_menu = QMenuBar_addMenu(menu_bar, "Help");
    void *about_action = QMenu_addAction(help_menu, "About");
    
    // Connect signals
    QMenuBar_setTriggeredCallback(menu_bar, on_triggered);
    QMenuBar_setHoveredCallback(menu_bar, on_hovered);
    
    // Show window
    QWidget_show(window);
    
    // Run application
    int result = QApplication_exec();
    
    // Cleanup
    QMenu_delete(recent_menu);
    QMenu_delete(file_menu);
    QMenu_delete(edit_menu);
    QMenu_delete(view_menu);
    QMenu_delete(help_menu);
    QMenuBar_delete(menu_bar);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
