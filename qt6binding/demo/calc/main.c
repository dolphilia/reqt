#include "qt6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// グローバル変数
void* display;
double firstNumber = 0.0;
int waitingForSecondNumber = 0;
char pendingOperator[4] = "";  // サイズを4バイトに変更（3バイト + NULL終端）

// 数字ボタンのコールバック関数
void onDigit0() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "0");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") != 0) {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s0", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit1() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "1");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "1");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s1", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit2() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "2");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "2");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s2", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit3() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "3");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "3");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s3", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit4() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "4");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "4");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s4", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit5() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "5");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "5");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s5", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit6() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "6");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "6");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s6", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit7() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "7");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "7");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s7", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit8() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "8");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "8");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s8", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

void onDigit9() {
    if (waitingForSecondNumber) {
        QLineEdit_setText(display, "9");
        waitingForSecondNumber = 0;
    } else {
        const char* currentText = QLineEdit_text(display);
        if (strcmp(currentText, "0") == 0) {
            QLineEdit_setText(display, "9");
        } else {
            char newText[32];
            snprintf(newText, sizeof(newText), "%s9", currentText);
            QLineEdit_setText(display, newText);
        }
    }
}

// 演算子ボタンのコールバック関数
void onPlusOperator() {
    firstNumber = atof(QLineEdit_text(display));
    strcpy(pendingOperator, "+");
    waitingForSecondNumber = 1;
}

void onMinusOperator() {
    firstNumber = atof(QLineEdit_text(display));
    strcpy(pendingOperator, "-");
    waitingForSecondNumber = 1;
}

void onMultiplyOperator() {
    firstNumber = atof(QLineEdit_text(display));
    strcpy(pendingOperator, "×");
    waitingForSecondNumber = 1;
}

void onDivideOperator() {
    firstNumber = atof(QLineEdit_text(display));
    strcpy(pendingOperator, "÷");
    waitingForSecondNumber = 1;
}

void onEqualPressed() {
    double secondNumber = atof(QLineEdit_text(display));
    double result = 0.0;
    char resultText[32];

    if (strcmp(pendingOperator, "+") == 0) {
        result = firstNumber + secondNumber;
    } else if (strcmp(pendingOperator, "-") == 0) {
        result = firstNumber - secondNumber;
    } else if (strcmp(pendingOperator, "×") == 0) {
        result = firstNumber * secondNumber;
    } else if (strcmp(pendingOperator, "÷") == 0) {
        if (secondNumber != 0) {
            result = firstNumber / secondNumber;
        } else {
            QLineEdit_setText(display, "Error");
            return;
        }
    }

    snprintf(resultText, sizeof(resultText), "%.10g", result);
    QLineEdit_setText(display, resultText);
    waitingForSecondNumber = 1;
}

void onClearPressed() {
    QLineEdit_setText(display, "0");
    firstNumber = 0.0;
    waitingForSecondNumber = 0;
    pendingOperator[0] = '\0';
}

void onPointPressed() {
    const char* currentText = QLineEdit_text(display);
    if (strchr(currentText, '.') == NULL) {
        char newText[32];
        snprintf(newText, sizeof(newText), "%s.", currentText);
        QLineEdit_setText(display, newText);
    }
}

void* createButton(const char* text, void* parent) {
    void* button = QPushButton_create(text, parent);
    QWidget_setFixedSize(button, 60, 60);
    QWidget_setStyleSheet(button, "QPushButton { font-size: 18px; }");
    return button;
}

int main(int argc, char* argv[]) {
    void* app = QApplication_create(argc, argv);
    
    // メインウィンドウの作成
    void* window = QWidget_create(NULL);
    QWidget_setWindowTitle(window, "電卓");
    QWidget_setFixedSize(window, 300, 400);
    
    // メインレイアウト
    void* mainLayout = QVBoxLayout_create(window);
    
    // ディスプレイの作成
    display = QLineEdit_create("0", window);
    QWidget_setStyleSheet(display, "QLineEdit { font-size: 24px; padding: 5px; }");
    QLineEdit_setReadOnly(display, true);
    QVBoxLayout_addWidget(mainLayout, display);
    
    // ボタングリッドの作成
    void* buttonGrid = QGridLayout_create();
    
    // 数字ボタンの作成と配置
    void* button7 = createButton("7", window);
    void* button8 = createButton("8", window);
    void* button9 = createButton("9", window);
    void* button4 = createButton("4", window);
    void* button5 = createButton("5", window);
    void* button6 = createButton("6", window);
    void* button1 = createButton("1", window);
    void* button2 = createButton("2", window);
    void* button3 = createButton("3", window);
    void* button0 = createButton("0", window);
    
    QPushButton_setClickCallback(button0, onDigit0);
    QPushButton_setClickCallback(button1, onDigit1);
    QPushButton_setClickCallback(button2, onDigit2);
    QPushButton_setClickCallback(button3, onDigit3);
    QPushButton_setClickCallback(button4, onDigit4);
    QPushButton_setClickCallback(button5, onDigit5);
    QPushButton_setClickCallback(button6, onDigit6);
    QPushButton_setClickCallback(button7, onDigit7);
    QPushButton_setClickCallback(button8, onDigit8);
    QPushButton_setClickCallback(button9, onDigit9);
    
    QGridLayout_addWidget(buttonGrid, button7, 0, 0);
    QGridLayout_addWidget(buttonGrid, button8, 0, 1);
    QGridLayout_addWidget(buttonGrid, button9, 0, 2);
    QGridLayout_addWidget(buttonGrid, button4, 1, 0);
    QGridLayout_addWidget(buttonGrid, button5, 1, 1);
    QGridLayout_addWidget(buttonGrid, button6, 1, 2);
    QGridLayout_addWidget(buttonGrid, button1, 2, 0);
    QGridLayout_addWidget(buttonGrid, button2, 2, 1);
    QGridLayout_addWidget(buttonGrid, button3, 2, 2);
    QGridLayout_addWidget(buttonGrid, button0, 3, 1);
    
    // 演算子ボタン
    void* buttonPlus = createButton("+", window);
    void* buttonMinus = createButton("-", window);
    void* buttonMult = createButton("×", window);
    void* buttonDiv = createButton("÷", window);
    QPushButton_setClickCallback(buttonPlus, onPlusOperator);
    QPushButton_setClickCallback(buttonMinus, onMinusOperator);
    QPushButton_setClickCallback(buttonMult, onMultiplyOperator);
    QPushButton_setClickCallback(buttonDiv, onDivideOperator);
    QGridLayout_addWidget(buttonGrid, buttonPlus, 0, 3);
    QGridLayout_addWidget(buttonGrid, buttonMinus, 1, 3);
    QGridLayout_addWidget(buttonGrid, buttonMult, 2, 3);
    QGridLayout_addWidget(buttonGrid, buttonDiv, 3, 3);
    
    // その他のボタン
    void* buttonPoint = createButton(".", window);
    void* buttonEqual = createButton("=", window);
    void* buttonClear = createButton("C", window);
    QPushButton_setClickCallback(buttonPoint, onPointPressed);
    QPushButton_setClickCallback(buttonEqual, onEqualPressed);
    QPushButton_setClickCallback(buttonClear, onClearPressed);
    QGridLayout_addWidget(buttonGrid, buttonPoint, 3, 2);
    QGridLayout_addWidget(buttonGrid, buttonEqual, 3, 0);
    QGridLayout_addWidget(buttonGrid, buttonClear, 4, 0);
    
    QVBoxLayout_addLayout(mainLayout, buttonGrid);
    
    // ウィンドウの表示
    QWidget_show(window);
    QApplication_exec();
    
    // クリーンアップ
    QWidget_delete(window);
    QApplication_delete(app);
    
    return 0;
}
