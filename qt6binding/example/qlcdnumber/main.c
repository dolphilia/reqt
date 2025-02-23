#include "qt6binding.h"
#include <stdio.h>
#include <unistd.h>

void onOverflow() {
    printf("Overflow occurred!\n");
}

int main(int argc, char* argv[]) {
    void* app = QApplication_create(argc, argv);
    void* window = QWidget_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QLCDNumber Example");

    // Create LCD numbers with different modes
    void* lcd1 = QLCDNumber_createWithDigits(8, window);
    void* lcd2 = QLCDNumber_createWithDigits(8, window);
    void* lcd3 = QLCDNumber_createWithDigits(8, window);
    void* lcd4 = QLCDNumber_createWithDigits(8, window);

    // Set size and positions for each LCD number
    QWidget_resize(lcd1, 380, 60);
    QWidget_resize(lcd2, 380, 60);
    QWidget_resize(lcd3, 380, 60);
    QWidget_resize(lcd4, 380, 60);

    QWidget_move(lcd1, 10, 10);
    QWidget_move(lcd2, 10, 80);
    QWidget_move(lcd3, 10, 150);
    QWidget_move(lcd4, 10, 220);

    // Set different modes and styles
    QLCDNumber_setDecMode(lcd1);
    QLCDNumber_setHexMode(lcd2);
    QLCDNumber_setOctMode(lcd3);
    QLCDNumber_setBinMode(lcd4);

    // Set different segment styles
    QLCDNumber_setSegmentStyle(lcd1, QLCDNUMBER_OUTLINE);
    QLCDNumber_setSegmentStyle(lcd2, QLCDNUMBER_FILLED);
    QLCDNumber_setSegmentStyle(lcd3, QLCDNUMBER_FLAT);
    QLCDNumber_setSegmentStyle(lcd4, QLCDNUMBER_FILLED);

    // Set overflow callback
    QLCDNumber_setOverflowCallback(lcd1, onOverflow);

    // Display numbers
    QLCDNumber_displayInt(lcd1, 12345);
    QLCDNumber_displayInt(lcd2, 255);    // Will show FF in hex mode
    QLCDNumber_displayInt(lcd3, 64);     // Will show 100 in oct mode
    QLCDNumber_displayInt(lcd4, 15);     // Will show 1111 in bin mode

    QWidget_show(window);
    QApplication_exec(app);

    // Cleanup
    QWidget_delete(window);
    QApplication_delete(app);

    return 0;
}
