#include "qt6.h"
#include <stdio.h>
#include <unistd.h>

void on_value_changed(void* obj, int value) {
    printf("Progress value changed to: %d%%\n", value);
}

void simulate_progress(void* progress_bar) {
    for (int i = 0; i <= 100; i += 10) {
        QProgressBar_setValue(progress_bar, i);
        usleep(500000); // 0.5秒待機
    }
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 400, 100);
    QWidget_setWindowTitle(window, "QProgressBar Example");
    
    // Create progress bar
    void *progress_bar = QProgressBar_create(window);
    QProgressBar_setRange(progress_bar, 0, 100);
    QProgressBar_setFormat(progress_bar, "%p%");
    QProgressBar_setTextVisible(progress_bar, 1);
    
    // Set initial value
    QProgressBar_setValue(progress_bar, 0);
    
    // Connect signal
    QProgressBar_setValueChangedCallback(progress_bar, on_value_changed);
    
    // Show window
    QWidget_show(window);
    
    // Start progress simulation in the background
    simulate_progress(progress_bar);
    
    // Run application
    int result = QApplication_exec();
    
    // Cleanup
    QProgressBar_delete(progress_bar);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
