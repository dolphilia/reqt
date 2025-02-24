#ifndef QDOCKWIDGET_C_H
#define QDOCKWIDGET_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QDockWidget作成・削除
void* QDockWidget_create(const char* title, void* parent);
void QDockWidget_delete(void* dockWidget);

// ウィジェット管理
void QDockWidget_setWidget(void* dockWidget, void* widget);
void* QDockWidget_widget(void* dockWidget);

// タイトルバー
void QDockWidget_setTitleBarWidget(void* dockWidget, void* widget);
void* QDockWidget_titleBarWidget(void* dockWidget);

// 機能設定
void QDockWidget_setFeatures(void* dockWidget, int features);
int QDockWidget_features(void* dockWidget);
void QDockWidget_setFloating(void* dockWidget, bool floating);
bool QDockWidget_isFloating(void* dockWidget);
void QDockWidget_setAllowedAreas(void* dockWidget, int areas);
int QDockWidget_allowedAreas(void* dockWidget);

// 機能定数
#define QDOCKWIDGET_NOFEATRUES 0x00
#define QDOCKWIDGET_DOCKWIDGETCLOSABLE 0x01
#define QDOCKWIDGET_DOCKWIDGETMOVABLE 0x02
#define QDOCKWIDGET_DOCKWIDGETFLOATABLE 0x04
#define QDOCKWIDGET_DOCKWIDGETVERTICALFLOATABLE 0x08
#define QDOCKWIDGET_DOCKWIDGETHORIZONTALFLOATABLE 0x10
#define QDOCKWIDGET_DOCKWIDGETFEATURESMASK 0xFF

// エリア定数
#define QDOCKWIDGET_NOAREA 0x00
#define QDOCKWIDGET_LEFTAREA 0x01
#define QDOCKWIDGET_RIGHTAREA 0x02
#define QDOCKWIDGET_TOPAREA 0x04
#define QDOCKWIDGET_BOTTOMAREA 0x08
#define QDOCKWIDGET_ALLAREA 0x0F

// コールバック関数
typedef void (*QDockWidgetAllowedAreasChangedCallback)(void* dockWidget, int allowedAreas);
typedef void (*QDockWidgetDockLocationChangedCallback)(void* dockWidget, int area);
typedef void (*QDockWidgetFeaturesChangedCallback)(void* dockWidget, int features);
typedef void (*QDockWidgetTopLevelChangedCallback)(void* dockWidget, bool topLevel);
typedef void (*QDockWidgetVisibilityChangedCallback)(void* dockWidget, bool visible);

void QDockWidget_setAllowedAreasChangedCallback(void* dockWidget, QDockWidgetAllowedAreasChangedCallback callback);
void QDockWidget_setDockLocationChangedCallback(void* dockWidget, QDockWidgetDockLocationChangedCallback callback);
void QDockWidget_setFeaturesChangedCallback(void* dockWidget, QDockWidgetFeaturesChangedCallback callback);
void QDockWidget_setTopLevelChangedCallback(void* dockWidget, QDockWidgetTopLevelChangedCallback callback);
void QDockWidget_setVisibilityChangedCallback(void* dockWidget, QDockWidgetVisibilityChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QDOCKWIDGET_C_H
