#include "qt6.h"
#include <stdio.h>

// コールバック関数
void onStateChanged(void* checkbox, int state) {
    const char* stateStr;
    switch (state) {
        case QCHECKBOX_UNCHECKED:
            stateStr = "unchecked";
            break;
        case QCHECKBOX_PARTIALLY_CHECKED:
            stateStr = "partially checked";
            break;
        case QCHECKBOX_CHECKED:
            stateStr = "checked";
            break;
        default:
            stateStr = "unknown";
    }
    printf("Checkbox state changed: %s\n", stateStr);
}

void onClicked(void* checkbox, bool checked) {
    printf("Checkbox clicked: %s\n", checked ? "true" : "false");
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "QCheckBox Example");
    QWidget_resize(window, 300, 200);
    
    // レイアウトの作成
    void* layout = QVBoxLayout_create(window);
    QVBoxLayout_setSpacing(layout, 10);
    QVBoxLayout_setContentsMargins(layout, 20, 20, 20, 20);
    
    // 通常のチェックボックス
    void* checkbox1 = QCheckBox_create("Normal Checkbox", window);
    QCheckBox_setClickedCallback(checkbox1, onClicked);
    QVBoxLayout_addWidget(layout, checkbox1);
    
    // トライステートチェックボックス
    void* checkbox2 = QCheckBox_create("Tristate Checkbox", window);
    QCheckBox_setTristate(checkbox2, true);
    QCheckBox_setStateChangedCallback(checkbox2, onStateChanged);
    QVBoxLayout_addWidget(layout, checkbox2);
    
    // 初期状態が選択されているチェックボックス
    void* checkbox3 = QCheckBox_create("Initially Checked", window);
    QCheckBox_setChecked(checkbox3, true);
    QCheckBox_setStateChangedCallback(checkbox3, onStateChanged);
    QVBoxLayout_addWidget(layout, checkbox3);
    
    // 無効化されたチェックボックス
    void* checkbox4 = QCheckBox_create("Disabled Checkbox", window);
    QCheckBox_setEnabled(checkbox4, false);
    QVBoxLayout_addWidget(layout, checkbox4);
    
    // 部分的にチェックされたチェックボックス
    void* checkbox5 = QCheckBox_create("Partially Checked", window);
    QCheckBox_setTristate(checkbox5, true);
    QCheckBox_setCheckState(checkbox5, QCHECKBOX_PARTIALLY_CHECKED);
    QCheckBox_setStateChangedCallback(checkbox5, onStateChanged);
    QVBoxLayout_addWidget(layout, checkbox5);
    
    // ウィンドウの表示
    QWidget_show(window);
    
    // イベントループの開始
    int result = QApplication_exec();
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
