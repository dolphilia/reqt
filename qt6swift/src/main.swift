import Foundation

enum Qt {
    class QApplication {
        public var pointer: UnsafeMutableRawPointer?
        
        // // 基本操作
        // void* QApplication_create(int argc, char* argv[]);

        init(argc: Int32, argv: UnsafeMutablePointer<UnsafeMutablePointer<CChar>?>) {
            self.pointer = QApplication_create(argc, argv)
        }
        // void QApplication_delete(void* app);
        deinit {
            QApplication_delete(self.pointer)
        }
        // int QApplication_exec(void* app);

        func exec() -> Int32 {
            return Int32(QApplication_exec(self.pointer))
        }
        // void QApplication_processEvents(void* app);

        func processEvents() {
            QApplication_processEvents(self.pointer)
        }
    }

    class QWidget {
        public var pointer: UnsafeMutableRawPointer?
        

        // // QWidget creation/deletion
        // void* QWidget_create(void* parent);

        init(pointer: UnsafeMutableRawPointer) {
            self.pointer = QWidget_create(pointer)
        }
        // void QWidget_delete(void* widget);
        deinit {
            QWidget_delete(pointer)
        }
    }

    class QMenuBar {
        public var pointer: UnsafeMutableRawPointer?
        
        // // QMenuBar作成・削除
        // void* QMenuBar_create(void* parent);

        init(pointer: UnsafeMutableRawPointer) {
            self.pointer = QMenuBar_create(pointer)
        }
        // void QMenuBar_delete(void* menuBar);
        deinit {
            QMenuBar_delete(pointer)
        }
    }

    class QStatusBar {
        public var pointer: UnsafeMutableRawPointer?
        
        // // QStatusBar作成・削除
        // void* QStatusBar_create(void* parent);

        init(pointer: UnsafeMutableRawPointer) {
            self.pointer = QStatusBar_create(pointer)
        }
        // void QStatusBar_delete(void* statusBar);
        deinit {
            QStatusBar_delete(pointer)
        }
    }

    class QMainWindow {
        public var pointer: UnsafeMutableRawPointer?
        
        // // QMainWindow作成・削除
        // void* QMainWindow_create(void* parent);

        init(pointer: UnsafeMutableRawPointer) {
            self.pointer = QMainWindow_create(pointer)
        }

        // void QMainWindow_delete(void* mainWindow);

        deinit {
            QMainWindow_delete(pointer)
        }

        // // セントラルウィジェット
        // void QMainWindow_setCentralWidget(void* mainWindow, void* widget);

        func setCentralWidget(widget: QWidget) {
            QMainWindow_setCentralWidget(pointer, widget.pointer)
        }
        // void* QMainWindow_centralWidget(void* mainWindow);

        func centralWidget() -> QWidget {
            return QWidget(pointer: QMainWindow_centralWidget(pointer))
        }
        // void* QMainWindow_takeCentralWidget(void* mainWindow);

        func takeCentralWidget() -> QWidget {
            return QWidget(pointer: QMainWindow_takeCentralWidget(pointer))
        }

        // // メニューバー
        // void* QMainWindow_menuBar(void* mainWindow);

        func menuBar() -> QMenuBar {
            return QMenuBar(pointer: QMainWindow_menuBar(pointer))
        }
        // void QMainWindow_setMenuBar(void* mainWindow, void* menuBar);
        
        func setMenuBar(menuBar: QMenuBar) {
            QMainWindow_setMenuBar(pointer, menuBar.pointer)
        }

        // // ステータスバー
        // void* QMainWindow_statusBar(void* mainWindow);

        
        func statusBar() -> QStatusBar {
            return QStatusBar(pointer: QMainWindow_statusBar(pointer))
        }

        // void QMainWindow_setStatusBar(void* mainWindow, void* statusBar);
        
        func setStatusBar(statusBar: QStatusBar) {
            QMainWindow_setStatusBar(pointer, statusBar.pointer)
        }

        // // ツールバー
        // void QMainWindow_addToolBar(void* mainWindow, void* toolBar);
        // void QMainWindow_addToolBarBreak(void* mainWindow);
        // void QMainWindow_insertToolBar(void* mainWindow, void* before, void* toolBar);
        // void QMainWindow_insertToolBarBreak(void* mainWindow, void* before);
        // void QMainWindow_removeToolBar(void* mainWindow, void* toolBar);
        // void QMainWindow_removeToolBarBreak(void* mainWindow, void* before);

        // // ドックウィジェット
        // void QMainWindow_addDockWidget(void* mainWindow, int area, void* dockWidget);
        // void QMainWindow_removeDockWidget(void* mainWindow, void* dockWidget);
        // void QMainWindow_setDockOptions(void* mainWindow, int options);
        // int QMainWindow_dockOptions(void* mainWindow);

        // // ウィンドウ状態
        // void QMainWindow_saveState(void* mainWindow, int version);
        // void QMainWindow_restoreState(void* mainWindow, const char* state, int version);

        // // レイアウト
        // void QMainWindow_setAnimated(void* mainWindow, bool enabled);
        // void QMainWindow_setDockNestingEnabled(void* mainWindow, bool enabled);
        // bool QMainWindow_isAnimated(void* mainWindow);
        // bool QMainWindow_isDockNestingEnabled(void* mainWindow);

        // // サイズ制約
        // void QMainWindow_setUnifiedTitleAndToolBarOnMac(void* mainWindow, bool set);
        // bool QMainWindow_unifiedTitleAndToolBarOnMac(void* mainWindow);
    }
}

// メイン関数
var args = CommandLine.arguments
var argc = Int32(args.count)
var argv = args.map { strdup($0) }

// QApplicationの作成
let app = QApplication_create(Int32(argc), &argv)

// メインウィンドウの作成
let window = QMainWindow_create(UnsafeMutableRawPointer?(nil))

// ラベルの作成
let labelText = "Hello from Qt6 and Swift!".cString(using: .utf8)!
let label = QLabel_create(labelText, window)
QWidget_setGeometry(label, 20, 20, 200, 30)

// ボタンの作成
let buttonText = "Click Me!".cString(using: .utf8)!
let button = QPushButton_create(buttonText, window)
QWidget_setGeometry(button, 20, 60, 100, 30)

// ウィンドウを表示
QWidget_show(window)

// イベントループの開始
let result = QApplication_exec(app)

// メモリの解放
for arg in argv {
    free(arg)
}

exit(Int32(result))
