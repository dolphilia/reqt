#include "qt6binding.h"
#include <stdio.h>

void onActionTriggered(void* action) {
    printf("Action triggered\n");
}

void onMovableChanged(bool movable) {
    printf("Movable changed: %s\n", movable ? "true" : "false");
}

void onOrientationChanged(int orientation) {
    printf("Orientation changed: %d\n", orientation);
}

void onToolButtonClicked() {
    printf("Tool button clicked\n");
}

void onToolButtonToggled(bool checked) {
    printf("Tool button toggled: %s\n", checked ? "true" : "false");
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QMainWindow_create(NULL);
    QWidget_resize(window, 600, 400);
    QWidget_setWindowTitle(window, "QToolBar and QToolButton Example");
    
    // Create toolbar
    void *toolbar = QToolBar_create(window);
    QToolBar_setMovable(toolbar, true);
    QToolBar_setAllowedAreas(toolbar, QTOOLBAR_AREA_ALL);
    QToolBar_setToolButtonStyle(toolbar, QTOOLBUTTON_STYLE_TEXT_BESIDE_ICON);
    
    // Create tool buttons
    void *button1 = QToolButton_create(NULL);
    QToolButton_setText(button1, "Normal Button");
    QToolButton_setAutoRaise(button1, true);
    QToolButton_setClickedCallback(button1, onToolButtonClicked);
    
    void *button2 = QToolButton_create(NULL);
    QToolButton_setText(button2, "Toggle Button");
    QToolButton_setAutoRaise(button2, true);
    QToolButton_setCheckable(button2, true);
    QToolButton_setToggledCallback(button2, onToolButtonToggled);
    
    void *button3 = QToolButton_create(NULL);
    QToolButton_setText(button3, "Arrow Button");
    QToolButton_setAutoRaise(button3, true);
    QToolButton_setArrowType(button3, QTOOLBUTTON_ARROW_DOWN);
    
    // Add buttons to toolbar
    QToolBar_addWidget(toolbar, button1);
    QToolBar_addSeparator(toolbar);
    QToolBar_addWidget(toolbar, button2);
    QToolBar_addSeparator(toolbar);
    QToolBar_addWidget(toolbar, button3);
    
    // Set toolbar callbacks
    QToolBar_setActionTriggeredCallback(toolbar, onActionTriggered);
    QToolBar_setMovableChangedCallback(toolbar, onMovableChanged);
    QToolBar_setOrientationChangedCallback(toolbar, onOrientationChanged);
    
    // Add toolbar to main window
    QMainWindow_addToolBar(window, toolbar);
    
    // Show window
    QWidget_show(window);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QWidget_delete(button1);
    QWidget_delete(button2);
    QWidget_delete(button3);
    QWidget_delete(toolbar);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
