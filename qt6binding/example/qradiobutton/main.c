#include "qt6.h"
#include <stdio.h>

void on_toggled(void* obj, bool checked) {
    printf("Radio button toggled: %s\n", checked ? "checked" : "unchecked");
}

void on_clicked(void* obj, bool checked) {
    printf("Radio button clicked: %s\n", checked ? "checked" : "unchecked");
}

void on_pressed(void* obj) {
    printf("Radio button pressed\n");
}

void on_released(void* obj) {
    printf("Radio button released\n");
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 300, 200);
    QWidget_setWindowTitle(window, "QRadioButton Example");
    
    // Create radio buttons for gender selection
    void *gender_label = QLabel_create("Gender:", window);
    QWidget_move(gender_label, 20, 20);
    
    void *male_radio = QRadioButton_createWithText("Male", window);
    QWidget_move(male_radio, 20, 50);
    
    void *female_radio = QRadioButton_createWithText("Female", window);
    QWidget_move(female_radio, 20, 80);
    
    void *other_radio = QRadioButton_createWithText("Other", window);
    QWidget_move(other_radio, 20, 110);
    
    // Create radio buttons for age group selection
    void *age_label = QLabel_create("Age Group:", window);
    QWidget_move(age_label, 150, 20);
    
    void *age1_radio = QRadioButton_createWithText("Under 18", window);
    QWidget_move(age1_radio, 150, 50);
    
    void *age2_radio = QRadioButton_createWithText("18-30", window);
    QWidget_move(age2_radio, 150, 80);
    
    void *age3_radio = QRadioButton_createWithText("Over 30", window);
    QWidget_move(age3_radio, 150, 110);
    
    // Set initial selection
    QRadioButton_setChecked(male_radio, 1);
    QRadioButton_setChecked(age2_radio, 1);
    
    // Connect signals for male radio button
    QRadioButton_setToggledCallback(male_radio, on_toggled);
    QRadioButton_setClickedCallback(male_radio, on_clicked);
    QRadioButton_setPressedCallback(male_radio, on_pressed);
    QRadioButton_setReleasedCallback(male_radio, on_released);
    
    // Show window and widgets
    QWidget_show(window);
    QWidget_show(gender_label);
    QWidget_show(male_radio);
    QWidget_show(female_radio);
    QWidget_show(other_radio);
    QWidget_show(age_label);
    QWidget_show(age1_radio);
    QWidget_show(age2_radio);
    QWidget_show(age3_radio);
    
    // Run application
    int result = QApplication_exec();
    
    // Cleanup
    QRadioButton_delete(male_radio);
    QRadioButton_delete(female_radio);
    QRadioButton_delete(other_radio);
    QRadioButton_delete(age1_radio);
    QRadioButton_delete(age2_radio);
    QRadioButton_delete(age3_radio);
    QLabel_delete(gender_label);
    QLabel_delete(age_label);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
