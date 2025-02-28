#include <qt6.h>
#include <stdio.h>

// ボタンクリックコールバック
void onButtonClicked(void* data, void* button) {
    printf("Button clicked\n");
}

int main(int argc, char *argv[]) {
    // アプリケーションの初期化
    void* app = QApplication_create(argc, argv);

    // 情報メッセージボックス
    int result = QMessageBox_information(
        NULL,
        "Information",
        "This is an information message.",
        QMessageBox_Ok,
        QMessageBox_Ok
    );
    printf("Information result: %d\n", result);

    // 警告メッセージボックス
    result = QMessageBox_warning(
        NULL,
        "Warning",
        "This is a warning message.",
        QMessageBox_Ok | QMessageBox_Cancel,
        QMessageBox_Ok
    );
    printf("Warning result: %d\n", result);

    // エラーメッセージボックス
    result = QMessageBox_critical(
        NULL,
        "Error",
        "This is an error message.",
        QMessageBox_Ok,
        QMessageBox_Ok
    );
    printf("Error result: %d\n", result);

    // 質問メッセージボックス
    result = QMessageBox_question(
        NULL,
        "Question",
        "Do you want to proceed?",
        QMessageBox_Yes | QMessageBox_No,
        QMessageBox_Yes
    );
    printf("Question result: %d\n", result);

    // カスタムメッセージボックス
    void* messageBox = QMessageBox_create(NULL);
    QMessageBox_setWindowTitle(messageBox, "Custom MessageBox");
    QMessageBox_setText(messageBox, "Main text");
    QMessageBox_setInformativeText(messageBox, "Additional information");
    QMessageBox_setDetailedText(messageBox, "Detailed explanation can be shown by clicking 'Show Details...'");
    QMessageBox_setIcon(messageBox, QMessageBox_Information);
    QMessageBox_setStandardButtons(messageBox, QMessageBox_Ok | QMessageBox_Cancel | QMessageBox_Help);
    QMessageBox_setDefaultButtonStandard(messageBox, QMessageBox_Ok);

    // チェックボックスの追加
    void* checkBox = QCheckBox_create("Don't show this message again", NULL);
    QMessageBox_setCheckBox(messageBox, checkBox);

    // ボタンクリックコールバックの設定
    QMessageBox_setButtonClickedCallback(messageBox, onButtonClicked, NULL);

    // メッセージボックスの表示
    result = QMessageBox_exec(messageBox);
    printf("Custom dialog result: %d\n", result);

    // About Qtダイアログの表示
    QMessageBox_aboutQt(NULL, "About Qt");

    // クリーンアップ
    QMessageBox_delete(messageBox);
    QApplication_delete(app);

    return 0;
}
