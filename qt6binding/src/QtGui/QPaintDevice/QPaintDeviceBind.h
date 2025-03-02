#ifndef QPAINTDEVICE_BIND_H
#define QPAINTDEVICE_BIND_H

#include <QPaintDevice>

class QPaintDeviceBind {
public:
    // PaintDeviceMetric列挙型の値を取得
    static int metricValue(QPaintDevice* device, int metric);
    
    // プロパティ取得
    static int colorCount(QPaintDevice* device);
    static int depth(QPaintDevice* device);
    static double devicePixelRatio(QPaintDevice* device);
    static double devicePixelRatioF(QPaintDevice* device);
    static int height(QPaintDevice* device);
    static int heightMM(QPaintDevice* device);
    static int logicalDpiX(QPaintDevice* device);
    static int logicalDpiY(QPaintDevice* device);
    static bool paintingActive(QPaintDevice* device);
    static int physicalDpiX(QPaintDevice* device);
    static int physicalDpiY(QPaintDevice* device);
    static int width(QPaintDevice* device);
    static int widthMM(QPaintDevice* device);
};

#endif // QPAINTDEVICE_BIND_H
