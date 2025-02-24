#include <qt6.h>
#include <stdio.h>

void splitterMoved(void* splitter, int pos, int index) {
    printf("Splitter moved to position %d at index %d\n", pos, index);
}

int main(int argc, char *argv[]) {
    // アプリケーションの初期化
    void *app = QApplication_create(argc, argv);

    // メインウィンドウの作成
    void *window = QMainWindow_create(NULL);
    QWidget_resize(window, 600, 400);
    QWidget_setWindowTitle(window, "QSplitter Example");

    // 中央ウィジェットの作成
    void *centralWidget = QWidget_create(NULL);
    QMainWindow_setCentralWidget(window, centralWidget);

    // 水平方向のスプリッターを作成
    void *splitter = QSplitter_createWithOrientation(1, centralWidget); // Qt::Horizontal = 1

    // 左側のテキストエディット
    void *leftEdit = QTextEdit_create(NULL);
    QTextEdit_setText(leftEdit, "Left Editor");
    QSplitter_addWidget(splitter, leftEdit);

    // 右側のテキストエディット
    void *rightEdit = QTextEdit_create(NULL);
    QTextEdit_setText(rightEdit, "Right Editor");
    QSplitter_addWidget(splitter, rightEdit);

    // スプリッターの初期サイズを設定
    int sizes[] = {300, 300};
    QSplitter_setSizes(splitter, sizes, 2);

    // スプリッターの移動コールバックを設定
    QSplitter_setSplitterMovedCallback(splitter, splitterMoved);

    // ウィンドウの表示
    QWidget_show(window);

    // イベントループの開始
    int result = QApplication_exec(app);

    // クリーンアップ
    QWidget_delete(leftEdit);
    QWidget_delete(rightEdit);
    QWidget_delete(splitter);
    QWidget_delete(centralWidget);
    QWidget_delete(window);
    QApplication_delete(app);

    return result;
}
