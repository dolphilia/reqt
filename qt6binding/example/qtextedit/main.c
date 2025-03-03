#include "qt6.h"
#include <stdio.h>

void on_text_changed() {
    printf("Text changed\n");
}

void on_copy_available(bool available) {
    printf("Copy available: %s\n", available ? "true" : "false");
}

void on_undo_available(bool available) {
    printf("Undo available: %s\n", available ? "true" : "false");
}

void on_redo_available(bool available) {
    printf("Redo available: %s\n", available ? "true" : "false");
}

void on_selection_changed() {
    printf("Selection changed\n");
}

void on_cursor_position_changed() {
    printf("Cursor position changed\n");
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QWidget_create(NULL);
    QWidget_resize(window, 600, 400);
    QWidget_setWindowTitle(window, "QTextEdit Example");
    
    // Create text edit
    void *text_edit = QTextEdit_create(window);
    QWidget_resize(text_edit, 580, 380);
    QWidget_move(text_edit, 10, 10);
    
    // Set some initial text
    QTextEdit_setPlainText(text_edit, "This is a QTextEdit widget.\n\n"
                                    "Features:\n"
                                    "- Plain text and rich text support\n"
                                    "- Copy, cut, paste operations\n"
                                    "- Undo/redo functionality\n"
                                    "- Text selection\n"
                                    "- Cursor movement\n\n"
                                    "Try editing this text!");
    
    // Connect signal handlers
    QTextEdit_setTextChangedCallback(text_edit, on_text_changed);
    QTextEdit_setCopyAvailableCallback(text_edit, on_copy_available);
    QTextEdit_setUndoAvailableCallback(text_edit, on_undo_available);
    QTextEdit_setRedoAvailableCallback(text_edit, on_redo_available);
    QTextEdit_setSelectionChangedCallback(text_edit, on_selection_changed);
    QTextEdit_setCursorPositionChangedCallback(text_edit, on_cursor_position_changed);
    
    // Configure text edit properties
    QTextEdit_setAcceptRichText(text_edit, true);
    QTextEdit_setWordWrapMode(text_edit, QTEXTEDIT_WORDWRAP_WORD);
    QTextEdit_setLineWrapMode(text_edit, QTEXTEDIT_LINEWRAP_WIDGET);
    QTextEdit_setTabChangesFocus(text_edit, false);
    QTextEdit_setReadOnly(text_edit, false);
    
    // Show window and widgets
    QWidget_show(window);
    QWidget_show(text_edit);
    
    // Run application
    int result = QApplication_exec();
    
    // Cleanup
    QTextEdit_delete(text_edit);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
