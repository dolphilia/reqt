#include "qt6.h"
#include <stdio.h>

void onValueChanged(double value) {
    printf("Value changed: %f\n", value);
}

void onEditingFinished() {
    printf("Editing finished\n");
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 300, 200);
    QWidget_setWindowTitle(window, "QDoubleSpinBox Example");
    
    // Create double spin box
    void *spinbox = QDoubleSpinBox_create(window);
    QWidget_resize(spinbox, 200, 30);
    QWidget_move(spinbox, 50, 50);
    
    // Configure double spin box
    QDoubleSpinBox_setRange(spinbox, 0.0, 100.0);
    QDoubleSpinBox_setValue(spinbox, 50.0);
    QDoubleSpinBox_setSingleStep(spinbox, 0.5);
    QDoubleSpinBox_setDecimals(spinbox, 2);
    QDoubleSpinBox_setPrefix(spinbox, "$");
    QDoubleSpinBox_setSuffix(spinbox, " USD");
    
    // Set callbacks
    QDoubleSpinBox_setValueChangedCallback(spinbox, onValueChanged);
    QDoubleSpinBox_setEditingFinishedCallback(spinbox, onEditingFinished);
    
    // Show widgets
    QWidget_show(window);
    QWidget_show(spinbox);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QWidget_delete(spinbox);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
