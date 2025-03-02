#ifndef QDIALOG_BIND_H
#define QDIALOG_BIND_H

#include <QDialog>
#include <QSize>

class QDialogHandler;

class QDialogBind {
public:
    // コンストラクタ/デストラクタ
    static QDialog* create(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    static void destroy(QDialog* dialog);
    
    // プロパティ取得
    static bool isSizeGripEnabled(QDialog* dialog);
    static int result(QDialog* dialog);
    static QSize* minimumSizeHint(QDialog* dialog);
    static QSize* sizeHint(QDialog* dialog);
    
    // プロパティ設定
    static void setModal(QDialog* dialog, bool modal);
    static void setResult(QDialog* dialog, int result);
    static void setSizeGripEnabled(QDialog* dialog, bool enabled);
    static void setVisible(QDialog* dialog, bool visible);
    
    // アクション
    static void accept(QDialog* dialog);
    static void done(QDialog* dialog, int result);
    static int exec(QDialog* dialog);
    static void open(QDialog* dialog);
    static void reject(QDialog* dialog);
    
    // シグナルハンドラ設定
    static void setAcceptedCallback(QDialog* dialog, void (*callback)(void*), void* data);
    static void setFinishedCallback(QDialog* dialog, void (*callback)(void*, int), void* data);
    static void setRejectedCallback(QDialog* dialog, void (*callback)(void*), void* data);
    
    // ハンドラ管理
    static QDialogHandler* getHandler(QDialog* dialog);
    static void setHandler(QDialog* dialog, QDialogHandler* handler);
};

#endif // QDIALOG_BIND_H
