#include "qt6.h"
#include <stdio.h>

void on_value_changed(int value) {
    printf("Value changed: %d\n", value);
}

void on_slider_moved(int position) {
    printf("Slider moved to position: %d\n", position);
}

void on_slider_pressed() {
    printf("Slider pressed\n");
}

void on_slider_released() {
    printf("Slider released\n");
}

void on_range_changed(int min, int max) {
    printf("Range changed: min=%d, max=%d\n", min, max);
}

void on_action_triggered(int action) {
    printf("Action triggered: %d\n", action);
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QScrollBar Example");
    
    // Create labels
    void *h_label = QLabel_create("Horizontal ScrollBar:", window);
    QWidget_move(h_label, 20, 20);
    
    void *v_label = QLabel_create("Vertical ScrollBar:", window);
    QWidget_move(v_label, 20, 100);
    
    // Create horizontal scrollbar
    void *h_scroll = QScrollBar_create(window);
    QWidget_move(h_scroll, 20, 50);
    QWidget_resize(h_scroll, 300, 20);
    QScrollBar_setOrientation(h_scroll, QSCROLLBAR_HORIZONTAL);
    QScrollBar_setRange(h_scroll, 0, 100);
    QScrollBar_setValue(h_scroll, 50);
    QScrollBar_setSingleStep(h_scroll, 1);
    QScrollBar_setPageStep(h_scroll, 10);
    
    // Create vertical scrollbar
    void *v_scroll = QScrollBar_createWithOrientation(QSCROLLBAR_VERTICAL, window);
    QWidget_move(v_scroll, 20, 130);
    QWidget_resize(v_scroll, 20, 150);
    QScrollBar_setRange(v_scroll, 0, 100);
    QScrollBar_setValue(v_scroll, 50);
    QScrollBar_setSingleStep(v_scroll, 5);
    QScrollBar_setPageStep(v_scroll, 20);
    QScrollBar_setInvertedAppearance(v_scroll, true);
    
    // Connect signals for horizontal scrollbar
    QScrollBar_setValueChangedCallback(h_scroll, on_value_changed);
    QScrollBar_setSliderMovedCallback(h_scroll, on_slider_moved);
    QScrollBar_setSliderPressedCallback(h_scroll, on_slider_pressed);
    QScrollBar_setSliderReleasedCallback(h_scroll, on_slider_released);
    QScrollBar_setRangeChangedCallback(h_scroll, on_range_changed);
    QScrollBar_setActionTriggeredCallback(h_scroll, on_action_triggered);
    
    // Show window and widgets
    QWidget_show(window);
    QWidget_show(h_label);
    QWidget_show(v_label);
    QWidget_show(h_scroll);
    QWidget_show(v_scroll);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QScrollBar_delete(h_scroll);
    QScrollBar_delete(v_scroll);
    QLabel_delete(h_label);
    QLabel_delete(v_label);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
