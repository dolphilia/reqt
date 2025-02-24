#include "qt6.h"
#include <stdio.h>

// コールバック関数
void onDockWidgetAllowedAreasChanged(void* dockWidget, int allowedAreas) {
    printf("Dock widget allowed areas changed: %d\n", allowedAreas);
}

void onDockWidgetDockLocationChanged(void* dockWidget, int area) {
    printf("Dock widget location changed: %d\n", area);
}

void onDockWidgetFeaturesChanged(void* dockWidget, int features) {
    printf("Dock widget features changed: %d\n", features);
}

void onDockWidgetTopLevelChanged(void* dockWidget, bool topLevel) {
    printf("Dock widget top level changed: %s\n", topLevel ? "true" : "false");
}

void onDockWidgetVisibilityChanged(void* dockWidget, bool visible) {
    printf("Dock widget visibility changed: %s\n", visible ? "visible" : "hidden");
}

void onButtonClicked(void* button) {
    printf("Button clicked\n");
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QMainWindow_create(NULL);
    QWidget_setWindowTitle(window, "QDockWidget Example");
    QWidget_resize(window, 800, 600);
    
    // セントラルウィジェットの作成
    void* centralWidget = QWidget_create(NULL);
    void* centralLayout = QVBoxLayout_create(centralWidget);
    void* centralLabel = QLabel_create("Central Widget", centralWidget);
    QVBoxLayout_addWidget(centralLayout, centralLabel);
    QMainWindow_setCentralWidget(window, centralWidget);
    
    // 左側のドックウィジェット
    void* leftDock = QDockWidget_create("Tools", window);
    QDockWidget_setAllowedAreas(leftDock, QDOCKWIDGET_LEFTAREA | QDOCKWIDGET_RIGHTAREA);
    QDockWidget_setFeatures(leftDock, 
        QDOCKWIDGET_DOCKWIDGETCLOSABLE | 
        QDOCKWIDGET_DOCKWIDGETMOVABLE | 
        QDOCKWIDGET_DOCKWIDGETFLOATABLE);
    
    void* leftWidget = QWidget_create(NULL);
    void* leftLayout = QVBoxLayout_create(leftWidget);
    void* toolButton1 = QPushButton_create("Tool 1", leftWidget);
    void* toolButton2 = QPushButton_create("Tool 2", leftWidget);
    QPushButton_setClickCallback(toolButton1, onButtonClicked);
    QPushButton_setClickCallback(toolButton2, onButtonClicked);
    QVBoxLayout_addWidget(leftLayout, toolButton1);
    QVBoxLayout_addWidget(leftLayout, toolButton2);
    QVBoxLayout_addStretch(leftLayout, 1);
    QDockWidget_setWidget(leftDock, leftWidget);
    
    // コールバックの設定
    QDockWidget_setAllowedAreasChangedCallback(leftDock, onDockWidgetAllowedAreasChanged);
    QDockWidget_setDockLocationChangedCallback(leftDock, onDockWidgetDockLocationChanged);
    QDockWidget_setFeaturesChangedCallback(leftDock, onDockWidgetFeaturesChanged);
    QDockWidget_setTopLevelChangedCallback(leftDock, onDockWidgetTopLevelChanged);
    QDockWidget_setVisibilityChangedCallback(leftDock, onDockWidgetVisibilityChanged);
    
    QMainWindow_addDockWidget(window, QDOCKWIDGET_LEFTAREA, leftDock);
    
    // 右側のドックウィジェット
    void* rightDock = QDockWidget_create("Properties", window);
    QDockWidget_setAllowedAreas(rightDock, QDOCKWIDGET_LEFTAREA | QDOCKWIDGET_RIGHTAREA);
    QDockWidget_setFeatures(rightDock, 
        QDOCKWIDGET_DOCKWIDGETCLOSABLE | 
        QDOCKWIDGET_DOCKWIDGETMOVABLE | 
        QDOCKWIDGET_DOCKWIDGETFLOATABLE);
    
    void* rightWidget = QWidget_create(NULL);
    void* rightLayout = QVBoxLayout_create(rightWidget);
    void* propertyLabel = QLabel_create("Properties:", rightWidget);
    void* propertyEdit = QLineEdit_create("", rightWidget);
    QVBoxLayout_addWidget(rightLayout, propertyLabel);
    QVBoxLayout_addWidget(rightLayout, propertyEdit);
    QVBoxLayout_addStretch(rightLayout, 1);
    QDockWidget_setWidget(rightDock, rightWidget);
    
    // コールバックの設定
    QDockWidget_setAllowedAreasChangedCallback(rightDock, onDockWidgetAllowedAreasChanged);
    QDockWidget_setDockLocationChangedCallback(rightDock, onDockWidgetDockLocationChanged);
    QDockWidget_setFeaturesChangedCallback(rightDock, onDockWidgetFeaturesChanged);
    QDockWidget_setTopLevelChangedCallback(rightDock, onDockWidgetTopLevelChanged);
    QDockWidget_setVisibilityChangedCallback(rightDock, onDockWidgetVisibilityChanged);
    
    QMainWindow_addDockWidget(window, QDOCKWIDGET_RIGHTAREA, rightDock);
    
    // ステータスバーの作成
    void* statusBar = QMainWindow_statusBar(window);
    QStatusBar_showMessage(statusBar, "Ready");
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec(app);
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
