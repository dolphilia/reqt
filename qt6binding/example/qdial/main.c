#include <qt6/qapplication.h>
#include <qt6/qwidget.h>
#include <qt6/qdial.h>
#include <stdio.h>

void onValueChanged(void* dial, int value) {
    printf("Value changed: %d\n", value);
}

void onSliderMoved(void* dial, int position) {
    printf("Slider moved: %d\n", position);
}

void onSliderPressed(void* dial) {
    printf("Slider pressed\n");
}

void onSliderReleased(void* dial) {
    printf("Slider released\n");
}

int main(int argc, char *argv[]) {
    void* app = QApplication_create(argc, argv);

    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_resize(window, 300, 300);
    QWidget_setWindowTitle(window, "QDial Example");

    // QDialの作成
    void* dial = QDial_create(window);
    QWidget_resize(dial, 200, 200);
    QWidget_move(dial, 50, 50);

    // ダイアルの設定
    QDial_setRange(dial, 0, 100);        // 範囲を0-100に設定
    QDial_setValue(dial, 50);            // 初期値を50に設定
    QDial_setNotchesVisible(dial, true); // ノッチを表示
    QDial_setNotchTarget(dial, 10.0);    // ノッチの間隔を10に設定
    QDial_setWrapping(dial, true);       // 値の循環を有効化

    // コールバックの設定
    QDial_setValueChangedCallback(dial, onValueChanged);
    QDial_setSliderMovedCallback(dial, onSliderMoved);
    QDial_setSliderPressedCallback(dial, onSliderPressed);
    QDial_setSliderReleasedCallback(dial, onSliderReleased);

    // ウィンドウの表示
    QWidget_show(window);

    // イベントループの開始
    int result = QApplication_exec(app);

    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);

    return result;
}
