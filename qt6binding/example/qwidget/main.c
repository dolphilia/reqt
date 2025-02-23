#include "qt6binding.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QWidget Example");
    
    // Create label
    void *label = QLabel_create("Styled Label", window);
    QWidget_resize(label, 200, 100);
    QWidget_move(label, 100, 100);
    
    // Set style sheet for label
    QWidget_setStyleSheet(label, "background-color: #3498db; "
                               "border: 2px solid #2980b9; "
                               "border-radius: 10px; "
                               "color: white; "
                               "padding: 10px;");
    
    // Show widgets
    QWidget_show(window);
    QWidget_show(label);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QWidget_delete(label);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
