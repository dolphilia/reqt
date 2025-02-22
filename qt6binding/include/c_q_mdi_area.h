#ifndef QMDIAREA_C_H
#define QMDIAREA_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QMdiArea作成・削除
void* QMdiArea_create(void* parent);
void QMdiArea_delete(void* mdiArea);

// サブウィンドウ管理
void* QMdiArea_addSubWindow(void* mdiArea, void* widget);
void QMdiArea_removeSubWindow(void* mdiArea, void* widget);
void* QMdiArea_activeSubWindow(void* mdiArea);
void** QMdiArea_subWindowList(void* mdiArea, int* count);
void QMdiArea_freeSubWindowList(void** list);

// ビューモード
void QMdiArea_setViewMode(void* mdiArea, int mode);
int QMdiArea_viewMode(void* mdiArea);

// ウィンドウ配置
void QMdiArea_tileSubWindows(void* mdiArea);
void QMdiArea_cascadeSubWindows(void* mdiArea);
void QMdiArea_closeActiveSubWindow(void* mdiArea);
void QMdiArea_closeAllSubWindows(void* mdiArea);
void QMdiArea_activateNextSubWindow(void* mdiArea);
void QMdiArea_activatePreviousSubWindow(void* mdiArea);

// スクロールバー
void QMdiArea_setHorizontalScrollBarPolicy(void* mdiArea, int policy);
void QMdiArea_setVerticalScrollBarPolicy(void* mdiArea, int policy);
int QMdiArea_horizontalScrollBarPolicy(void* mdiArea);
int QMdiArea_verticalScrollBarPolicy(void* mdiArea);

// 背景
void QMdiArea_setBackground(void* mdiArea, void* brush);
void QMdiArea_setActivationOrder(void* mdiArea, int order);
int QMdiArea_activationOrder(void* mdiArea);

// タブ設定
void QMdiArea_setTabsClosable(void* mdiArea, bool closable);
bool QMdiArea_tabsClosable(void* mdiArea);
void QMdiArea_setTabsMovable(void* mdiArea, bool movable);
bool QMdiArea_tabsMovable(void* mdiArea);
void QMdiArea_setTabShape(void* mdiArea, int shape);
int QMdiArea_tabShape(void* mdiArea);
void QMdiArea_setTabPosition(void* mdiArea, int position);
int QMdiArea_tabPosition(void* mdiArea);

// ビューモード定数
#define QMDIAREA_SUBWINDOWVIEW 0
#define QMDIAREA_TABBEDVIEW 1

// アクティベーション順序定数
#define QMDIAREA_CREATION_ORDER 0
#define QMDIAREA_STACK_ORDER 1
#define QMDIAREA_ACTIVATION_HISTORY_ORDER 2

// コールバック関数
typedef void (*QMdiAreaSubWindowActivatedCallback)(void* mdiArea, void* subWindow);

void QMdiArea_setSubWindowActivatedCallback(void* mdiArea, QMdiAreaSubWindowActivatedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QMDIAREA_C_H
