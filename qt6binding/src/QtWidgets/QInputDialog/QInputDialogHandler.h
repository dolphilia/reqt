#ifndef QINPUTDIALOG_HANDLER_H
#define QINPUTDIALOG_HANDLER_H

#include <QObject>
#include <QInputDialog>

// コールバック関数の型定義
typedef void (*QInputDialogDoubleValueChangedCallback)(QObject*, double);
typedef void (*QInputDialogDoubleValueSelectedCallback)(QObject*, double);
typedef void (*QInputDialogIntValueChangedCallback)(QObject*, int);
typedef void (*QInputDialogIntValueSelectedCallback)(QObject*, int);
typedef void (*QInputDialogTextValueChangedCallback)(QObject*, const char*);
typedef void (*QInputDialogTextValueSelectedCallback)(QObject*, const char*);

class QInputDialogHandler : public QObject {
    Q_OBJECT

public:
    explicit QInputDialogHandler(QObject* parent = nullptr);
    ~QInputDialogHandler();

    // コールバック設定メソッド
    void setDoubleValueChangedCallback(QInputDialogDoubleValueChangedCallback callback);
    void setDoubleValueSelectedCallback(QInputDialogDoubleValueSelectedCallback callback);
    void setIntValueChangedCallback(QInputDialogIntValueChangedCallback callback);
    void setIntValueSelectedCallback(QInputDialogIntValueSelectedCallback callback);
    void setTextValueChangedCallback(QInputDialogTextValueChangedCallback callback);
    void setTextValueSelectedCallback(QInputDialogTextValueSelectedCallback callback);

public slots:
    void onDoubleValueChanged(double value);
    void onDoubleValueSelected(double value);
    void onIntValueChanged(int value);
    void onIntValueSelected(int value);
    void onTextValueChanged(const QString& text);
    void onTextValueSelected(const QString& text);

private:
    QInputDialogDoubleValueChangedCallback m_doubleValueChangedCallback;
    QInputDialogDoubleValueSelectedCallback m_doubleValueSelectedCallback;
    QInputDialogIntValueChangedCallback m_intValueChangedCallback;
    QInputDialogIntValueSelectedCallback m_intValueSelectedCallback;
    QInputDialogTextValueChangedCallback m_textValueChangedCallback;
    QInputDialogTextValueSelectedCallback m_textValueSelectedCallback;
};

#endif // QINPUTDIALOG_HANDLER_H 