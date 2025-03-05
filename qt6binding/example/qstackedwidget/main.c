#include <qt6.h>
#include <stdio.h>

void currentChangedCallback(void* stackedWidget, int index) {
    printf("Current page changed to index %d\n", index);
}

void widgetRemovedCallback(void* stackedWidget, int index) {
    printf("Widget removed at index %d\n", index);
}

// ボタンのコールバック関数
void* g_stackedWidget = NULL;

void prevButtonClicked(void* button) {
    int currentIndex = QStackedWidget_currentIndex(g_stackedWidget);
    int count = QStackedWidget_count(g_stackedWidget);
    int newIndex = (currentIndex - 1 + count) % count;
    QStackedWidget_setCurrentIndex(g_stackedWidget, newIndex);
}

void nextButtonClicked(void* button) {
    int currentIndex = QStackedWidget_currentIndex(g_stackedWidget);
    int count = QStackedWidget_count(g_stackedWidget);
    int newIndex = (currentIndex + 1) % count;
    QStackedWidget_setCurrentIndex(g_stackedWidget, newIndex);
}

int main(int argc, char *argv[]) {
    // アプリケーションの初期化
    void *app = QApplication_create(argc, argv);

    // メインウィンドウの作成
    void *window = QMainWindow_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QStackedWidget Example");

    // 中央ウィジェットの作成
    void *centralWidget = QWidget_create(NULL);
    QMainWindow_setCentralWidget(window, centralWidget);

    // レイアウトの作成
    void *vboxLayout = QVBoxLayout_create(NULL);
    QWidget_setLayout(centralWidget, vboxLayout);

    // スタックウィジェットの作成
    void *stackedWidget = QStackedWidget_create(NULL);
    g_stackedWidget = stackedWidget;
    QVBoxLayout_addWidget(vboxLayout, stackedWidget);

    // ページ1: テキストエディット
    void *page1 = QTextEdit_create(NULL);
    QTextEdit_setText(page1, "This is page 1");
    int index1 = QStackedWidget_addWidget(stackedWidget, page1);

    // ページ2: ラベル
    void *page2 = QLabel_create("This is page 2", NULL);
    QLabel_setAlignment(page2, 0x0084); // Qt::AlignCenter
    int index2 = QStackedWidget_addWidget(stackedWidget, page2);

    // ページ3: プッシュボタン
    void *page3 = QPushButton_create("This is page 3", NULL);
    int index3 = QStackedWidget_addWidget(stackedWidget, page3);

    // コールバックの設定
    QStackedWidget_setCurrentChangedCallback(stackedWidget, currentChangedCallback);
    QStackedWidget_setWidgetRemovedCallback(stackedWidget, widgetRemovedCallback);

    // ページ切り替えボタンの作成
    void *buttonLayout = QHBoxLayout_create(NULL);
    QVBoxLayout_addLayout(vboxLayout, buttonLayout);

    void *prevButton = QPushButton_create("Previous", NULL);
    void *nextButton = QPushButton_create("Next", NULL);
    QHBoxLayout_addWidget(buttonLayout, prevButton);
    QHBoxLayout_addWidget(buttonLayout, nextButton);

    // ボタンのコールバックを設定
    QPushButton_setClickedCallback(prevButton, prevButtonClicked);
    QPushButton_setClickedCallback(nextButton, nextButtonClicked);

    // 初期ページを設定
    QStackedWidget_setCurrentIndex(stackedWidget, 0);

    // ウィンドウの表示
    QWidget_show(window);

    // イベントループの開始
    int result = QApplication_exec();

    // クリーンアップ
    QWidget_delete(page1);
    QWidget_delete(page2);
    QWidget_delete(page3);
    QWidget_delete(prevButton);
    QWidget_delete(nextButton);
    QWidget_delete(stackedWidget);
    QWidget_delete(centralWidget);
    QWidget_delete(window);
    QApplication_delete(app);

    return result;
}
