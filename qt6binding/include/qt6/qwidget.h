#ifndef QWIDGET_C_H
#define QWIDGET_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QWidget creation/deletion
void* QWidget_create(void* parent);
void QWidget_delete(void* widget);

// Public Functions
void QWidget_resize(void* widget, int w, int h);
void QWidget_move(void* widget, int x, int y);
void QWidget_setFixedSize(void* widget, int w, int h);
void QWidget_setFixedHeight(void* widget, int height);
void QWidget_setFixedWidth(void* widget, int width);
void QWidget_setLayout(void* widget, void* layout);
void* QWidget_actions(void* widget);
void QWidget_activateWindow(void* widget);
void QWidget_addAction(void* widget, void* action);
void* QWidget_addActionWithText(void* widget, const char* text);
void* QWidget_addActionWithIconAndText(void* widget, void* icon, const char* text);
void* QWidget_addActionWithTextAndShortcut(void* widget, const char* text, int shortcut);
void* QWidget_addActionWithIconTextAndShortcut(void* widget, void* icon, const char* text, int shortcut);
void QWidget_addActions(void* widget, void* actions);
void QWidget_adjustSize(void* widget);
void* QWidget_backingStore(void* widget);
void* QWidget_childAt(void* widget, int x, int y);
void* QWidget_childAtPoint(void* widget, int x, int y);
void* QWidget_childAtPointF(void* widget, double x, double y);
void QWidget_clearFocus(void* widget);
void QWidget_clearMask(void* widget);
void QWidget_getContentsMargins(void* widget, int* left, int* top, int* right, int* bottom);
int QWidget_contentsRectX(void* widget);
int QWidget_contentsRectY(void* widget);
int QWidget_contentsRectWidth(void* widget);
int QWidget_contentsRectHeight(void* widget);
unsigned long QWidget_effectiveWinId(void* widget);
void QWidget_ensurePolished(void* widget);
void* QWidget_focusProxy(void* widget);
void* QWidget_focusWidget(void* widget);
void* QWidget_fontInfo(void* widget);
void* QWidget_fontMetrics(void* widget);
int QWidget_geometryX(void* widget);
int QWidget_geometryY(void* widget);
int QWidget_geometryWidth(void* widget);
int QWidget_geometryHeight(void* widget);
void* QWidget_grab(void* widget, int x, int y, int width, int height);
void QWidget_grabGesture(void* widget, int gesture, int flags);
void QWidget_grabKeyboard(void* widget);
void QWidget_grabMouse(void* widget);
void QWidget_grabMouseWithCursor(void* widget, void* cursor);
int QWidget_grabShortcut(void* widget, int key, int context);
void* QWidget_graphicsEffect(void* widget);
void* QWidget_graphicsProxyWidget(void* widget);
bool QWidget_hasEditFocus(void* widget);
bool QWidget_hasHeightForWidth(void* widget);
int QWidget_heightForWidth(void* widget, int w);
void* QWidget_inputMethodQuery(void* widget, int query);
void QWidget_insertAction(void* widget, void* before, void* action);
void QWidget_insertActions(void* widget, void* before, void* actions);
bool QWidget_isAncestorOf(void* widget, void* child);
bool QWidget_isEnabledTo(void* widget, void* ancestor);
bool QWidget_isVisibleTo(void* widget, void* ancestor);
bool QWidget_isWindow(void* widget);
void* QWidget_layout(void* widget);
void* QWidget_mask(void* widget);
void QWidget_moveToPoint(void* widget, int x, int y);
void QWidget_moveToQPoint(void* widget, int x, int y);
int QWidget_mapFromX(void* widget, void* parent, int x, int y);
int QWidget_mapFromY(void* widget, void* parent, int x, int y);
int QWidget_mapFromFX(void* widget, void* parent, double x, double y);
int QWidget_mapFromFY(void* widget, void* parent, double x, double y);
int QWidget_mapFromGlobalX(void* widget, int x, int y);
int QWidget_mapFromGlobalY(void* widget, int x, int y);
int QWidget_mapFromGlobalFX(void* widget, double x, double y);
int QWidget_mapFromGlobalFY(void* widget, double x, double y);
int QWidget_mapFromParentX(void* widget, int x, int y);
int QWidget_mapFromParentY(void* widget, int x, int y);
int QWidget_mapFromParentFX(void* widget, double x, double y);
int QWidget_mapFromParentFY(void* widget, double x, double y);
int QWidget_mapToX(void* widget, void* parent, int x, int y);
int QWidget_mapToY(void* widget, void* parent, int x, int y);
int QWidget_mapToFX(void* widget, void* parent, double x, double y);
int QWidget_mapToFY(void* widget, void* parent, double x, double y);
int QWidget_mapToGlobalX(void* widget, int x, int y);
int QWidget_mapToGlobalY(void* widget, int x, int y);
int QWidget_mapToGlobalFX(void* widget, double x, double y);
int QWidget_mapToGlobalFY(void* widget, double x, double y);
int QWidget_mapToParentX(void* widget, int x, int y);
int QWidget_mapToParentY(void* widget, int x, int y);
int QWidget_mapToParentFX(void* widget, double x, double y);
int QWidget_mapToParentFY(void* widget, double x, double y);
void* QWidget_nativeParentWidget(void* widget);
void* QWidget_nextInFocusChain(void* widget);
void QWidget_overrideWindowFlags(void* widget, int flags);
void* QWidget_parentWidget(void* widget);
void* QWidget_previousInFocusChain(void* widget);
void QWidget_releaseKeyboard(void* widget);
void QWidget_releaseMouse(void* widget);
void QWidget_releaseShortcut(void* widget, int id);
void QWidget_removeAction(void* widget, void* action);
void QWidget_renderToPaintDevice(void* widget, void* target, int targetOffsetX, int targetOffsetY, void* sourceRegion, int renderFlags);
void QWidget_renderToPainter(void* widget, void* painter, int targetOffsetX, int targetOffsetY, void* sourceRegion, int renderFlags);
void QWidget_repaintRect(void* widget, int x, int y, int width, int height);
void QWidget_repaintQRect(void* widget, int x, int y, int width, int height);
void QWidget_repaintRegion(void* widget, void* region);
void QWidget_resizeWithSize(void* widget, int width, int height);
bool QWidget_restoreGeometry(void* widget, void* geometry, int size);
void* QWidget_saveGeometry(void* widget, int* size);
void* QWidget_screen(void* widget);
void QWidget_setMaskBitmap(void* widget, void* bitmap);
void QWidget_setMaskRegion(void* widget, void* region);
void QWidget_setParent(void* widget, void* parent);
void QWidget_setParentWithFlags(void* widget, void* parent, int flags);
void QWidget_setScreen(void* widget, void* screen);
void QWidget_setShortcutAutoRepeat(void* widget, int id, bool enable);
void QWidget_setShortcutEnabled(void* widget, int id, bool enable);
void QWidget_setSizeIncrementWithSize(void* widget, int width, int height);
void QWidget_setStyle(void* widget, void* style);
void QWidget_setWindowFlag(void* widget, int flag, bool on);
void QWidget_setWindowRole(void* widget, const char* role);
void QWidget_setWindowState(void* widget, int windowState);
void QWidget_setupUi(void* widget, void* targetWidget);
void QWidget_stackUnder(void* widget, void* w);
bool QWidget_testAttribute(void* widget, int attribute);
bool QWidget_underMouse(void* widget);
void QWidget_ungrabGesture(void* widget, int gesture);
void QWidget_unsetCursor(void* widget);
void QWidget_unsetLayoutDirection(void* widget);
void QWidget_unsetLocale(void* widget);
void QWidget_updateRect(void* widget, int x, int y, int w, int h);
void QWidget_updateQRect(void* widget, int x, int y, int w, int h);
void QWidget_updateRegion(void* widget, void* region);
void QWidget_updateGeometry(void* widget);
void* QWidget_visibleRegion(void* widget);
unsigned long QWidget_winId(void* widget);
void* QWidget_window(void* widget);
void* QWidget_windowHandle(void* widget);
const char* QWidget_windowRole(void* widget);
int QWidget_windowState(void* widget);
int QWidget_windowType(void* widget);

// Properties
int QWidget_x(void* widget);
int QWidget_y(void* widget);
int QWidget_width(void* widget);
int QWidget_height(void* widget);
const char* QWidget_windowTitle(void* widget);
void QWidget_setWindowTitle(void* widget, const char* title);
const char* QWidget_styleSheet(void* widget);
void QWidget_setStyleSheet(void* widget, const char* styleSheet);
void QWidget_setCursor(void* widget, void* cursor);
bool QWidget_autoFillBackground(void* widget);
void QWidget_setAutoFillBackground(void* widget, bool enabled);
int QWidget_backgroundRole(void* widget);
void QWidget_setBackgroundRole(void* widget, int role);
int QWidget_foregroundRole(void* widget);
void QWidget_setForegroundRole(void* widget, int role);
bool QWidget_acceptDrops(void* widget);
void QWidget_setAcceptDrops(void* widget, bool on);
const char* QWidget_accessibleDescription(void* widget);
void QWidget_setAccessibleDescription(void* widget, const char* description);
const char* QWidget_accessibleName(void* widget);
void QWidget_setAccessibleName(void* widget, const char* name);
void QWidget_setBaseSize(void* widget, int width, int height);
int QWidget_baseSizeWidth(void* widget);
int QWidget_baseSizeHeight(void* widget);
int QWidget_childrenRectX(void* widget);
int QWidget_childrenRectY(void* widget);
int QWidget_childrenRectWidth(void* widget);
int QWidget_childrenRectHeight(void* widget);
void* QWidget_childrenRegion(void* widget);
int QWidget_contextMenuPolicy(void* widget);
void QWidget_setContextMenuPolicy(void* widget, int policy);
bool QWidget_isEnabled(void* widget);
bool QWidget_hasFocus(void* widget);
int QWidget_focusPolicy(void* widget);
void QWidget_setFocusPolicy(void* widget, int policy);
void* QWidget_font(void* widget);
void QWidget_setFont(void* widget, void* font);
int QWidget_frameGeometryX(void* widget);
int QWidget_frameGeometryY(void* widget);
int QWidget_frameGeometryWidth(void* widget);
int QWidget_frameGeometryHeight(void* widget);
int QWidget_frameSizeWidth(void* widget);
int QWidget_frameSizeHeight(void* widget);
bool QWidget_isFullScreen(void* widget);
void QWidget_setGeometry(void* widget, int x, int y, int width, int height);
int QWidget_inputMethodHints(void* widget);
void QWidget_setInputMethodHints(void* widget, int hints);
bool QWidget_isActiveWindow(void* widget);
int QWidget_layoutDirection(void* widget);
void QWidget_setLayoutDirection(void* widget, int direction);
void* QWidget_locale(void* widget);
void QWidget_setLocale(void* widget, void* locale);
bool QWidget_isMaximized(void* widget);
int QWidget_maximumHeight(void* widget);
void QWidget_setMaximumHeight(void* widget, int maxh);
int QWidget_maximumWidth(void* widget);
void QWidget_setMaximumWidth(void* widget, int maxw);
void QWidget_setMaximumSize(void* widget, int maxw, int maxh);
bool QWidget_isMinimized(void* widget);
int QWidget_minimumHeight(void* widget);
void QWidget_setMinimumHeight(void* widget, int minh);
int QWidget_minimumWidth(void* widget);
void QWidget_setMinimumWidth(void* widget, int minw);
void QWidget_setMinimumSize(void* widget, int minw, int minh);
int QWidget_minimumSizeHintWidth(void* widget);
int QWidget_minimumSizeHintHeight(void* widget);
bool QWidget_isModal(void* widget);
bool QWidget_hasMouseTracking(void* widget);
void QWidget_setMouseTracking(void* widget, bool enable);
int QWidget_normalGeometryX(void* widget);
int QWidget_normalGeometryY(void* widget);
int QWidget_normalGeometryWidth(void* widget);
int QWidget_normalGeometryHeight(void* widget);
void* QWidget_palette(void* widget);
void QWidget_setPalette(void* widget, void* palette);
int QWidget_posX(void* widget);
int QWidget_posY(void* widget);
int QWidget_rectX(void* widget);
int QWidget_rectY(void* widget);
int QWidget_rectWidth(void* widget);
int QWidget_rectHeight(void* widget);
int QWidget_sizeWidth(void* widget);
int QWidget_sizeHeight(void* widget);
int QWidget_sizeHintWidth(void* widget);
int QWidget_sizeHintHeight(void* widget);
int QWidget_sizeIncrementWidth(void* widget);
int QWidget_sizeIncrementHeight(void* widget);
void QWidget_setSizeIncrement(void* widget, int w, int h);
int QWidget_sizePolicy(void* widget);
void QWidget_setSizePolicy(void* widget, int horizontal, int vertical);
const char* QWidget_statusTip(void* widget);
void QWidget_setStatusTip(void* widget, const char* statusTip);
bool QWidget_hasTabletTracking(void* widget);
void QWidget_setTabletTracking(void* widget, bool enable);
const char* QWidget_toolTip(void* widget);
void QWidget_setToolTip(void* widget, const char* toolTip);
int QWidget_toolTipDuration(void* widget);
void QWidget_setToolTipDuration(void* widget, int msec);
bool QWidget_updatesEnabled(void* widget);
void QWidget_setUpdatesEnabled(void* widget, bool enable);
const char* QWidget_whatsThis(void* widget);
void QWidget_setWhatsThis(void* widget, const char* whatsThis);
const char* QWidget_windowFilePath(void* widget);
void QWidget_setWindowFilePath(void* widget, const char* filePath);
int QWidget_windowFlags(void* widget);
void QWidget_setWindowFlags(void* widget, int flags);
void* QWidget_windowIcon(void* widget);
void QWidget_setWindowIcon(void* widget, void* icon);
int QWidget_windowModality(void* widget);
void QWidget_setWindowModality(void* widget, int modality);
bool QWidget_isWindowModified(void* widget);
double QWidget_windowOpacity(void* widget);
void QWidget_setWindowOpacity(void* widget, double level);

// Static Public Members
void* QWidget_createWindowContainer(void* window, void* parent, int flags);
void* QWidget_find(unsigned long id);
void* QWidget_keyboardGrabber();
void* QWidget_mouseGrabber();
void QWidget_setTabOrder(void* first, void* second);

// Public Slots
void QWidget_show(void* widget);
void QWidget_hide(void* widget);
bool QWidget_isVisible(void* widget);
void QWidget_setVisible(void* widget, bool visible);
bool QWidget_close(void* widget);
void QWidget_lower(void* widget);
void QWidget_raise(void* widget);
void QWidget_repaint(void* widget);
void QWidget_setDisabled(void* widget, bool disable);
void QWidget_setFocus(void* widget);
void QWidget_setHidden(void* widget, bool hidden);
void QWidget_setWindowModified(void* widget, bool modified);
void QWidget_showFullScreen(void* widget);
void QWidget_showMaximized(void* widget);
void QWidget_showMinimized(void* widget);
void QWidget_showNormal(void* widget);
void QWidget_update(void* widget);

// Signals
void QWidget_setCustomContextMenuRequestedCallback(void* widget, void (*callback)(void*, const void*));
void QWidget_setWindowIconChangedCallback(void* widget, void (*callback)(void*, const void*));
void QWidget_setWindowTitleChangedCallback(void* widget, void (*callback)(void*, const void*));

// Color roles
#define QWIDGET_BACKGROUND 10
#define QWIDGET_FOREGROUND 9
#define QWIDGET_WINDOW 0
#define QWIDGET_WINDOWTEXT 1
#define QWIDGET_BASE 9
#define QWIDGET_ALTERNATEBASE 16
#define QWIDGET_TOOLTIBASE 17
#define QWIDGET_TOOLTIPTEXT 18
#define QWIDGET_TEXT 6
#define QWIDGET_BUTTON 1
#define QWIDGET_BUTTONTEXT 8
#define QWIDGET_BRIGHTTEXT 7

#ifdef __cplusplus
}
#endif

#endif // QWIDGET_C_H
