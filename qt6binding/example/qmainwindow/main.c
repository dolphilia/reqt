#include "qt6binding.h"
#include <stdio.h>

// コールバック関数
void onMenuItemTriggered(void* action) {
    printf("Menu item triggered\n");
}

void onButtonClicked(void* button) {
    printf("Button clicked\n");
}

void onDockWidgetVisibilityChanged(void* dockWidget, bool visible) {
    printf("Dock widget visibility changed: %s\n", visible ? "visible" : "hidden");
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QMainWindow_create(NULL);
    QWidget_setWindowTitle(window, "QMainWindow Example");
    QWidget_resize(window, 800, 600);
    
    // セントラルウィジェットの作成
    void* centralWidget = QWidget_create(NULL);
    void* layout = QVBoxLayout_create(centralWidget);
    QVBoxLayout_setSpacing(layout, 10);
    QVBoxLayout_setContentsMargins(layout, 20, 20, 20, 20);
    
    // セントラルウィジェットにコンテンツを追加
    void* label = QLabel_create("Central Widget", centralWidget);
    QVBoxLayout_addWidget(layout, label);
    
    void* button = QPushButton_create("Click Me", centralWidget);
    QPushButton_setClickCallback(button, onButtonClicked);
    QVBoxLayout_addWidget(layout, button);
    
    QMainWindow_setCentralWidget(window, centralWidget);
    
    // 左側のドックウィジェット
    void* leftDock = QDockWidget_create("Left Tools", window);
    QDockWidget_setAllowedAreas(leftDock, QDOCKWIDGET_LEFTAREA | QDOCKWIDGET_RIGHTAREA);
    QDockWidget_setFeatures(leftDock, 
        QDOCKWIDGET_DOCKWIDGETCLOSABLE | 
        QDOCKWIDGET_DOCKWIDGETMOVABLE | 
        QDOCKWIDGET_DOCKWIDGETFLOATABLE);
    QDockWidget_setVisibilityChangedCallback(leftDock, onDockWidgetVisibilityChanged);
    
    void* leftWidget = QWidget_create(NULL);
    void* leftLayout = QVBoxLayout_create(leftWidget);
    void* toolButton1 = QPushButton_create("Tool 1", leftWidget);
    void* toolButton2 = QPushButton_create("Tool 2", leftWidget);
    QVBoxLayout_addWidget(leftLayout, toolButton1);
    QVBoxLayout_addWidget(leftLayout, toolButton2);
    QVBoxLayout_addStretch(leftLayout, 1);
    QDockWidget_setWidget(leftDock, leftWidget);
    
    QMainWindow_addDockWidget(window, QDOCKWIDGET_LEFTAREA, leftDock);
    
    // 右側のドックウィジェット
    void* rightDock = QDockWidget_create("Right Properties", window);
    QDockWidget_setAllowedAreas(rightDock, QDOCKWIDGET_LEFTAREA | QDOCKWIDGET_RIGHTAREA);
    QDockWidget_setFeatures(rightDock, 
        QDOCKWIDGET_DOCKWIDGETCLOSABLE | 
        QDOCKWIDGET_DOCKWIDGETMOVABLE | 
        QDOCKWIDGET_DOCKWIDGETFLOATABLE);
    QDockWidget_setVisibilityChangedCallback(rightDock, onDockWidgetVisibilityChanged);
    
    void* rightWidget = QWidget_create(NULL);
    void* rightLayout = QVBoxLayout_create(rightWidget);
    void* propertyLabel = QLabel_create("Properties:", rightWidget);
    void* propertyEdit = QLineEdit_create("", rightWidget);
    QVBoxLayout_addWidget(rightLayout, propertyLabel);
    QVBoxLayout_addWidget(rightLayout, propertyEdit);
    QVBoxLayout_addStretch(rightLayout, 1);
    QDockWidget_setWidget(rightDock, rightWidget);
    
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
