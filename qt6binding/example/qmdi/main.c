#include "qt6.h"
#include <stdio.h>

// コールバック関数
void onSubWindowActivated(void* mdiArea, void* subWindow) {
    printf("Sub window activated\n");
}

void onWindowStateChanged(void* subWindow, int oldState, int newState) {
    printf("Window state changed: old=%d new=%d\n", oldState, newState);
}

void onAboutToActivate(void* subWindow) {
    printf("Sub window about to activate\n");
}

void onButtonClicked(void* button) {
    printf("Button clicked\n");
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QMainWindow_create(NULL);
    QWidget_setWindowTitle(window, "QMDI Example");
    QWidget_resize(window, 800, 600);
    
    // MDIエリアの作成
    void* mdiArea = QMdiArea_create(NULL);
    QMdiArea_setViewMode(mdiArea, QMDIAREA_TABBEDVIEW);
    QMdiArea_setTabsClosable(mdiArea, true);
    QMdiArea_setTabsMovable(mdiArea, true);
    QMdiArea_setSubWindowActivatedCallback(mdiArea, onSubWindowActivated);
    
    QMainWindow_setCentralWidget(window, mdiArea);
    
    // サブウィンドウ1の作成
    void* subWindow1 = QMdiSubWindow_create(NULL);
    QWidget_setWindowTitle(subWindow1, "Document 1");
    
    void* content1 = QWidget_create(NULL);
    void* layout1 = QVBoxLayout_create(content1);
    void* label1 = QLabel_create("Document 1 Content", content1);
    void* button1 = QPushButton_create("Action 1", content1);
    QPushButton_setClickCallback(button1, onButtonClicked);
    
    QVBoxLayout_addWidget(layout1, label1);
    QVBoxLayout_addWidget(layout1, button1);
    QVBoxLayout_addStretch(layout1, 1);
    
    QMdiSubWindow_setWidget(subWindow1, content1);
    QMdiSubWindow_setWindowStateChangedCallback(subWindow1, onWindowStateChanged);
    QMdiSubWindow_setAboutToActivateCallback(subWindow1, onAboutToActivate);
    
    // サブウィンドウ2の作成
    void* subWindow2 = QMdiSubWindow_create(NULL);
    QWidget_setWindowTitle(subWindow2, "Document 2");
    
    void* content2 = QWidget_create(NULL);
    void* layout2 = QVBoxLayout_create(content2);
    void* label2 = QLabel_create("Document 2 Content", content2);
    void* edit2 = QLineEdit_create("", content2);
    
    QVBoxLayout_addWidget(layout2, label2);
    QVBoxLayout_addWidget(layout2, edit2);
    QVBoxLayout_addStretch(layout2, 1);
    
    QMdiSubWindow_setWidget(subWindow2, content2);
    QMdiSubWindow_setWindowStateChangedCallback(subWindow2, onWindowStateChanged);
    QMdiSubWindow_setAboutToActivateCallback(subWindow2, onAboutToActivate);
    
    // サブウィンドウ3の作成
    void* subWindow3 = QMdiSubWindow_create(NULL);
    QWidget_setWindowTitle(subWindow3, "Document 3");
    
    void* content3 = QWidget_create(NULL);
    void* layout3 = QVBoxLayout_create(content3);
    void* label3 = QLabel_create("Document 3 Content", content3);
    void* checkbox3 = QCheckBox_create("Option", content3);
    
    QVBoxLayout_addWidget(layout3, label3);
    QVBoxLayout_addWidget(layout3, checkbox3);
    QVBoxLayout_addStretch(layout3, 1);
    
    QMdiSubWindow_setWidget(subWindow3, content3);
    QMdiSubWindow_setWindowStateChangedCallback(subWindow3, onWindowStateChanged);
    QMdiSubWindow_setAboutToActivateCallback(subWindow3, onAboutToActivate);
    
    // MDIエリアにサブウィンドウを追加
    QMdiArea_addSubWindow(mdiArea, subWindow1);
    QMdiArea_addSubWindow(mdiArea, subWindow2);
    QMdiArea_addSubWindow(mdiArea, subWindow3);
    
    // サブウィンドウの表示
    QWidget_show(subWindow1);
    QWidget_show(subWindow2);
    QWidget_show(subWindow3);
    
    // ステータスバーの作成
    void* statusBar = QMainWindow_statusBar(window);
    QStatusBar_showMessage(statusBar, "Ready");
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec();
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
