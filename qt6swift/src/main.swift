import Foundation

enum Qt {
    class QApplication {
        public var pointer: UnsafeMutableRawPointer?
        
        init(pointer: UnsafeMutableRawPointer) {
            var args = CommandLine.arguments
            var argc = Int32(args.count)
            var argv = args.map { strdup($0) }
            self.pointer = QApplication_create(argc, &argv)
        }
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
