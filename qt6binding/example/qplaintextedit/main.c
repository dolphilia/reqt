#include <qt6/qapplication.h>
#include <qt6/qplaintextedit.h>
#include <qt6/qwidget.h>
#include <stdio.h>

void onTextChanged() {
    printf("Text changed\n");
}

void onCursorPositionChanged() {
    printf("Cursor position changed\n");
}

void onCopyAvailable(bool available) {
    printf("Copy available: %s\n", available ? "true" : "false");
}

void onUndoAvailable(bool available) {
    printf("Undo available: %s\n", available ? "true" : "false");
}

void onRedoAvailable(bool available) {
    printf("Redo available: %s\n", available ? "true" : "false");
}

void onSelectionChanged() {
    printf("Selection changed\n");
}

int main(int argc, char *argv[]) {
    void* app = QApplication_create(argc, argv);

    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QPlainTextEdit Example");

    // QPlainTextEditの作成
    void* editor = QPlainTextEdit_create(window);
    QWidget_resize(editor, 380, 280);
    QWidget_move(editor, 10, 10);

    // 初期テキストの設定
    QPlainTextEdit_setPlainText(editor, "Hello, QPlainTextEdit!\nThis is a sample text.\nTry editing this text.");

    // コールバックの設定
    QPlainTextEdit_setTextChangedCallback(editor, onTextChanged);
    QPlainTextEdit_setCursorPositionChangedCallback(editor, onCursorPositionChanged);
    QPlainTextEdit_setCopyAvailableCallback(editor, onCopyAvailable);
    QPlainTextEdit_setUndoAvailableCallback(editor, onUndoAvailable);
    QPlainTextEdit_setRedoAvailableCallback(editor, onRedoAvailable);
    QPlainTextEdit_setSelectionChangedCallback(editor, onSelectionChanged);

    // ウィンドウの表示
    QWidget_show(window);

    // イベントループの開始
    int result = QApplication_exec(app);

    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);

    return result;
}
