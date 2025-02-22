#include "qt6binding.h"
#include "c_q_slider.h"
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
    QWidget_setWindowTitle(window, "QSlider Example");
    
    // Create horizontal slider
    void *h_slider = QSlider_create(window);
    QSlider_setOrientation(h_slider, QSLIDER_HORIZONTAL);
    QWidget_move(h_slider, 50, 50);
    QWidget_resize(h_slider, 300, 30);
    
    // Configure horizontal slider
    QSlider_setRange(h_slider, 0, 100);
    QSlider_setValue(h_slider, 50);
    QSlider_setTickPosition(h_slider, QSLIDER_TICKS_BELOW);
    QSlider_setTickInterval(h_slider, 10);
    
    // Create vertical slider
    void *v_slider = QSlider_createWithOrientation(QSLIDER_VERTICAL, window);
    QWidget_move(v_slider, 50, 100);
    QWidget_resize(v_slider, 30, 150);
    
    // Configure vertical slider
    QSlider_setRange(v_slider, 0, 100);
    QSlider_setValue(v_slider, 50);
    QSlider_setTickPosition(v_slider, QSLIDER_TICKS_BOTH);
    QSlider_setTickInterval(v_slider, 20);
    QSlider_setInvertedAppearance(v_slider, 1);
    
    // Connect signals for horizontal slider
    QSlider_setValueChangedCallback(h_slider, on_value_changed);
    QSlider_setSliderMovedCallback(h_slider, on_slider_moved);
    QSlider_setSliderPressedCallback(h_slider, on_slider_pressed);
    QSlider_setSliderReleasedCallback(h_slider, on_slider_released);
    QSlider_setRangeChangedCallback(h_slider, on_range_changed);
    QSlider_setActionTriggeredCallback(h_slider, on_action_triggered);
    
    // Show window and widgets
    QWidget_show(window);
    QWidget_show(h_slider);
    QWidget_show(v_slider);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QSlider_delete(h_slider);
    QSlider_delete(v_slider);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
