#include "QPaintDeviceBind.h"

int QPaintDeviceBind::metricValue(QPaintDevice* device, int metric) {
    if (!device) {
        return 0;
    }
    
    // メトリック値に応じて適切なパブリックメソッドを呼び出す
    switch (metric) {
        case 0: // PdmWidth
            return device->width();
        case 1: // PdmHeight
            return device->height();
        case 2: // PdmWidthMM
            return device->widthMM();
        case 3: // PdmHeightMM
            return device->heightMM();
        case 4: // PdmNumColors
            return device->colorCount();
        case 5: // PdmDepth
            return device->depth();
        case 6: // PdmDpiX
            return device->logicalDpiX();
        case 7: // PdmDpiY
            return device->logicalDpiY();
        case 8: // PdmPhysicalDpiX
            return device->physicalDpiX();
        case 9: // PdmPhysicalDpiY
            return device->physicalDpiY();
        case 10: // PdmDevicePixelRatio
            return static_cast<int>(device->devicePixelRatio());
        case 11: // PdmDevicePixelRatioF
            // devicePixelRatioFはdoubleを返すため、整数に変換する必要がある
            return static_cast<int>(device->devicePixelRatioF() * 100); // 小数点以下2桁を保持
        default:
            return 0;
    }
}

int QPaintDeviceBind::colorCount(QPaintDevice* device) {
    if (device) {
        return device->colorCount();
    }
    return 0;
}

int QPaintDeviceBind::depth(QPaintDevice* device) {
    if (device) {
        return device->depth();
    }
    return 0;
}

double QPaintDeviceBind::devicePixelRatio(QPaintDevice* device) {
    if (device) {
        return device->devicePixelRatio();
    }
    return 1.0;
}

double QPaintDeviceBind::devicePixelRatioF(QPaintDevice* device) {
    if (device) {
        return device->devicePixelRatioF();
    }
    return 1.0;
}

int QPaintDeviceBind::height(QPaintDevice* device) {
    if (device) {
        return device->height();
    }
    return 0;
}

int QPaintDeviceBind::heightMM(QPaintDevice* device) {
    if (device) {
        return device->heightMM();
    }
    return 0;
}

int QPaintDeviceBind::logicalDpiX(QPaintDevice* device) {
    if (device) {
        return device->logicalDpiX();
    }
    return 0;
}

int QPaintDeviceBind::logicalDpiY(QPaintDevice* device) {
    if (device) {
        return device->logicalDpiY();
    }
    return 0;
}

bool QPaintDeviceBind::paintingActive(QPaintDevice* device) {
    if (device) {
        return device->paintingActive();
    }
    return false;
}

int QPaintDeviceBind::physicalDpiX(QPaintDevice* device) {
    if (device) {
        return device->physicalDpiX();
    }
    return 0;
}

int QPaintDeviceBind::physicalDpiY(QPaintDevice* device) {
    if (device) {
        return device->physicalDpiY();
    }
    return 0;
}

int QPaintDeviceBind::width(QPaintDevice* device) {
    if (device) {
        return device->width();
    }
    return 0;
}

int QPaintDeviceBind::widthMM(QPaintDevice* device) {
    if (device) {
        return device->widthMM();
    }
    return 0;
}
