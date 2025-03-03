#include "qt6.h"
#include <stdio.h>

void onCurrentChanged(int index) {
    printf("Current page changed to: %d\n", index);
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QToolBox Example");
    
    // Create tool box
    void *toolbox = QToolBox_create(window);
    QWidget_resize(toolbox, 380, 280);
    QWidget_move(toolbox, 10, 10);
    
    // Create pages
    void *page1 = QWidget_create(NULL);
    void *page2 = QWidget_create(NULL);
    void *page3 = QWidget_create(NULL);
    
    // Add some content to pages
    void *button1 = QPushButton_create("Button 1", page1);
    void *button2 = QPushButton_create("Button 2", page2);
    void *button3 = QPushButton_create("Button 3", page3);
    
    QWidget_move(button1, 10, 10);
    QWidget_move(button2, 10, 10);
    QWidget_move(button3, 10, 10);
    
    // Add pages to tool box
    QToolBox_addItem(toolbox, page1, "Page 1");
    QToolBox_addItem(toolbox, page2, "Page 2");
    QToolBox_addItem(toolbox, page3, "Page 3");
    
    // Set tooltips
    QToolBox_setItemToolTip(toolbox, 0, "First page");
    QToolBox_setItemToolTip(toolbox, 1, "Second page");
    QToolBox_setItemToolTip(toolbox, 2, "Third page");
    
    // Set callback
    QToolBox_setCurrentChangedCallback(toolbox, onCurrentChanged);
    
    // Show widgets
    QWidget_show(window);
    QWidget_show(toolbox);
    
    // Run application
    int result = QApplication_exec();
    
    // Cleanup
    QWidget_delete(button1);
    QWidget_delete(button2);
    QWidget_delete(button3);
    QWidget_delete(page1);
    QWidget_delete(page2);
    QWidget_delete(page3);
    QWidget_delete(toolbox);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
