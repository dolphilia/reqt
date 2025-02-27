#ifndef QPAINTDEVICE_C_H
#define QPAINTDEVICE_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

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
int QPaintDevice_metricValue(void* device, int metric);

// プロパティ取得
int QPaintDevice_colorCount(void* device);
int QPaintDevice_depth(void* device);
double QPaintDevice_devicePixelRatio(void* device);
double QPaintDevice_devicePixelRatioF(void* device);
int QPaintDevice_height(void* device);
int QPaintDevice_heightMM(void* device);
int QPaintDevice_logicalDpiX(void* device);
int QPaintDevice_logicalDpiY(void* device);
bool QPaintDevice_paintingActive(void* device);
int QPaintDevice_physicalDpiX(void* device);
int QPaintDevice_physicalDpiY(void* device);
int QPaintDevice_width(void* device);
int QPaintDevice_widthMM(void* device);

#ifdef __cplusplus
}
#endif

#endif // QPAINTDEVICE_C_H
