#include "qt6binding.h"
#include "c_q_scroll_area.h"
#include <stdio.h>

void on_vertical_scroll_value_changed(int value) {
    printf("Vertical scroll value changed: %d\n", value);
}

void on_horizontal_scroll_value_changed(int value) {
    printf("Horizontal scroll value changed: %d\n", value);
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QScrollArea Example");
    
    // Create scroll area
    void *scroll_area = QScrollArea_create(window);
    QWidget_resize(scroll_area, 380, 280);
    QWidget_move(scroll_area, 10, 10);
    
    // Create content widget
    void *content = QWidget_create(NULL);
    QWidget_resize(content, 800, 600);
    
    // Add some widgets to the content
    void *title = QLabel_create("Scroll Area Content", content);
    QWidget_move(title, 10, 10);
    QWidget_resize(title, 200, 30);
    
    // Create a grid of labels
    int row, col;
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 6; col++) {
            void *label = QLabel_create("Content Block", content);
            QWidget_move(label, 10 + col * 130, 50 + row * 110);
            QWidget_resize(label, 120, 100);
            QWidget_show(label);
        }
    }
    
    // Set content widget to scroll area
    QScrollArea_setWidget(scroll_area, content);
    QScrollArea_setWidgetResizable(scroll_area, false);
    QScrollArea_setHorizontalScrollBarPolicy(scroll_area, QSCROLLAREA_SCROLLBARPOLICY_ALWAYSON);
    QScrollArea_setVerticalScrollBarPolicy(scroll_area, QSCROLLAREA_SCROLLBARPOLICY_ALWAYSON);
    
    // Connect scroll bar signals
    QScrollArea_setVerticalScrollBarValueChangedCallback(scroll_area, on_vertical_scroll_value_changed);
    QScrollArea_setHorizontalScrollBarValueChangedCallback(scroll_area, on_horizontal_scroll_value_changed);
    
    // Show window and widgets
    QWidget_show(window);
    QWidget_show(scroll_area);
    QWidget_show(content);
    QWidget_show(title);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QWidget_delete(content);  // This will delete all child widgets
    QScrollArea_delete(scroll_area);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
