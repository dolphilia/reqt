#include "qt6binding.h"
#include <stdio.h>

void print_color_info(void* color) {
    int r, g, b, a;
    QColor_getRgb(color, &r, &g, &b, &a);
    printf("RGB: (%d, %d, %d, %d)\n", r, g, b, a);

    int h, s, v;
    QColor_getHsv(color, &h, &s, &v, &a);
    printf("HSV: (%d, %d, %d, %d)\n", h, s, v, a);

    int c, m, y, k;
    QColor_getCmyk(color, &c, &m, &y, &k, &a);
    printf("CMYK: (%d, %d, %d, %d, %d)\n", c, m, y, k, a);

    printf("Name: %s\n", QColor_name(color));
    printf("Valid: %s\n", QColor_isValid(color) ? "true" : "false");
    printf("\n");
}

int main() {
    // Create colors in different ways
    printf("Creating colors in different ways:\n");
    
    // Default constructor
    void* color1 = QColor_create();
    printf("Default color:\n");
    print_color_info(color1);

    // RGB constructor
    void* color2 = QColor_createWithRgb(255, 0, 0, 255);
    printf("Red color:\n");
    print_color_info(color2);

    // Named color
    void* color3 = QColor_createWithName("blue");
    printf("Blue color:\n");
    print_color_info(color3);

    // Color manipulation
    printf("Color manipulation:\n");

    // Set RGB
    QColor_setRgb(color1, 0, 255, 0, 255);
    printf("After setting RGB to green:\n");
    print_color_info(color1);

    // Set HSV
    QColor_setHsv(color1, 240, 255, 255, 255);
    printf("After setting HSV to blue:\n");
    print_color_info(color1);

    // Set CMYK
    QColor_setCmyk(color1, 100, 0, 0, 0, 255);
    printf("After setting CMYK to cyan:\n");
    print_color_info(color1);

    // Lighter and darker colors
    void* lighter = QColor_lighter(color2, 150);
    printf("Lighter red:\n");
    print_color_info(lighter);

    void* darker = QColor_darker(color2, 200);
    printf("Darker red:\n");
    print_color_info(darker);

    // Named colors
    void* namedColor = QColor_create();
    QColor_setNamedColor(namedColor, "darkturquoise");
    printf("Dark turquoise color:\n");
    print_color_info(namedColor);

    // Cleanup
    QColor_delete(color1);
    QColor_delete(color2);
    QColor_delete(color3);
    QColor_delete(lighter);
    QColor_delete(darker);
    QColor_delete(namedColor);

    return 0;
}
