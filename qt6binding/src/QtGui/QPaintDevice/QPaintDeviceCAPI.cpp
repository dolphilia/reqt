#include "QPaintDeviceBind.h"

extern "C" {

// PaintDeviceMetric列挙型の定数
#define QPAINTDEVICE_PDM_WIDTH 0
#define QPAINTDEVICE_PDM_HEIGHT 1
#define QPAINTDEVICE_PDM_WIDTH_MM 2
#define QPAINTDEVICE_PDM_HEIGHT_MM 3
#define QPAINTDEVICE_PDM_NUM_COLORS 4
#define QPAINTDEVICE_PDM_DEPTH 5
#define QPAINTDEVICE_PDM_DEVICE_PIXEL_RATIO 6
#define QPAINTDEVICE_PDM_DEVICE_PIXEL_RATIO_F 7
#define QPAINTDEVICE_PDM_PHYSICAL_DPI_X 8
#define QPAINTDEVICE_PDM_PHYSICAL_DPI_Y 9
#define QPAINTDEVICE_PDM_LOGICAL_DPI_X 10
#define QPAINTDEVICE_PDM_LOGICAL_DPI_Y 11
#define QPAINTDEVICE_PDM_DEVICE_PIXEL_RATIO_F_ENCODED 12

// PaintDeviceMetric列挙型の値を取得
int QPaintDevice_metricValue(void* device, int metric) {
    return QPaintDeviceBind::metricValue(static_cast<QPaintDevice*>(device), metric);
}

// プロパティ取得
int QPaintDevice_colorCount(void* device) {
    return QPaintDeviceBind::colorCount(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_depth(void* device) {
    return QPaintDeviceBind::depth(static_cast<QPaintDevice*>(device));
}

double QPaintDevice_devicePixelRatio(void* device) {
    return QPaintDeviceBind::devicePixelRatio(static_cast<QPaintDevice*>(device));
}

double QPaintDevice_devicePixelRatioF(void* device) {
    return QPaintDeviceBind::devicePixelRatioF(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_height(void* device) {
    return QPaintDeviceBind::height(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_heightMM(void* device) {
    return QPaintDeviceBind::heightMM(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_logicalDpiX(void* device) {
    return QPaintDeviceBind::logicalDpiX(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_logicalDpiY(void* device) {
    return QPaintDeviceBind::logicalDpiY(static_cast<QPaintDevice*>(device));
}

bool QPaintDevice_paintingActive(void* device) {
    return QPaintDeviceBind::paintingActive(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_physicalDpiX(void* device) {
    return QPaintDeviceBind::physicalDpiX(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_physicalDpiY(void* device) {
    return QPaintDeviceBind::physicalDpiY(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_width(void* device) {
    return QPaintDeviceBind::width(static_cast<QPaintDevice*>(device));
}

int QPaintDevice_widthMM(void* device) {
    return QPaintDeviceBind::widthMM(static_cast<QPaintDevice*>(device));
}

}
