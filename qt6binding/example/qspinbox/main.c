#include "qt6.h"
#include <stdio.h>

void on_value_changed(int value) {
    printf("Value changed: %d\n", value);
}

void on_text_changed(const char* text) {
    printf("Text changed: %s\n", text);
}

void on_editing_finished() {
    printf("Editing finished\n");
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 400, 200);
    QWidget_setWindowTitle(window, "QSpinBox Example");
    
    // Create labels
    void *age_label = QLabel_create("Age:", window);
    QWidget_move(age_label, 20, 20);
    
    void *year_label = QLabel_create("Year:", window);
    QWidget_move(year_label, 20, 60);
    
    void *hex_label = QLabel_create("Hex:", window);
    QWidget_move(hex_label, 20, 100);
    
    // Create age spinbox
    void *age_spin = QSpinBox_create(window);
    QWidget_move(age_spin, 100, 20);
    QSpinBox_setRange(age_spin, 0, 150);
    QSpinBox_setValue(age_spin, 25);
    QSpinBox_setSuffix(age_spin, " years old");
    QSpinBox_setSpecialValueText(age_spin, "Not born yet");
    
    // Create year spinbox
    void *year_spin = QSpinBox_create(window);
    QWidget_move(year_spin, 100, 60);
    QSpinBox_setRange(year_spin, 1900, 2100);
    QSpinBox_setValue(year_spin, 2024);
    QSpinBox_setPrefix(year_spin, "AD ");
    QSpinBox_setAccelerated(year_spin, true);
    
    // Create hex spinbox
    void *hex_spin = QSpinBox_create(window);
    QWidget_move(hex_spin, 100, 100);
    QSpinBox_setRange(hex_spin, 0, 255);
    QSpinBox_setValue(hex_spin, 255);
    QSpinBox_setPrefix(hex_spin, "0x");
    QSpinBox_setDisplayIntegerBase(hex_spin, 16);
    
    // Connect signals for age spinbox
    QSpinBox_setValueChangedCallback(age_spin, on_value_changed);
    QSpinBox_setTextChangedCallback(age_spin, on_text_changed);
    QSpinBox_setEditingFinishedCallback(age_spin, on_editing_finished);
    
    // Show window and widgets
    QWidget_show(window);
    QWidget_show(age_label);
    QWidget_show(year_label);
    QWidget_show(hex_label);
    QWidget_show(age_spin);
    QWidget_show(year_spin);
    QWidget_show(hex_spin);
    
    // Run application
    int result = QApplication_exec();
    
    // Cleanup
    QSpinBox_delete(age_spin);
    QSpinBox_delete(year_spin);
    QSpinBox_delete(hex_spin);
    QLabel_delete(age_label);
    QLabel_delete(year_label);
    QLabel_delete(hex_label);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
