#include <qt6.h>
#include <stdio.h>

// コールバック関数
void onAccepted(void* data) {
    printf("Dialog accepted\n");
}

void onRejected(void* data) {
    printf("Dialog rejected\n");
}

void onFinished(void* data, int result) {
    printf("Dialog finished with result: %d\n", result);
}

int main(int argc, char *argv[]) {
    // アプリケーションの初期化
    void* app = QApplication_create(argc, argv);

    // モーダルダイアログの作成
    void* modalDialog = QDialog_create(NULL, 0);
    QDialog_setModal(modalDialog, true);
    QDialog_setSizeGripEnabled(modalDialog, true);

    // コールバックの設定
    QDialog_setAcceptedCallback(modalDialog, onAccepted, NULL);
    QDialog_setRejectedCallback(modalDialog, onRejected, NULL);
    QDialog_setFinishedCallback(modalDialog, onFinished, NULL);

    // ダイアログの表示とイベントループの実行
    printf("Executing modal dialog...\n");
    int result = QDialog_exec(modalDialog);
    printf("Modal dialog result: %d\n", result);

    // モードレスダイアログの作成
    void* modelessDialog = QDialog_create(NULL, 0);
    QDialog_setModal(modelessDialog, false);
    QDialog_setSizeGripEnabled(modelessDialog, true);

    // コールバックの設定
    QDialog_setAcceptedCallback(modelessDialog, onAccepted, NULL);
    QDialog_setRejectedCallback(modelessDialog, onRejected, NULL);
    QDialog_setFinishedCallback(modelessDialog, onFinished, NULL);

    // ダイアログを表示
    printf("Opening modeless dialog...\n");
    QDialog_open(modelessDialog);

    // イベントループの実行
    int exitCode = QApplication_exec(app);

    // クリーンアップ
    QDialog_delete(modalDialog);
    QDialog_delete(modelessDialog);
    QApplication_delete(app);

    return exitCode;
}
