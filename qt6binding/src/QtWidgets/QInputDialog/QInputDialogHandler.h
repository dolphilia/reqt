#ifndef QINPUTDIALOG_HANDLER_H
#define QINPUTDIALOG_HANDLER_H

#include <QObject>

class QInputDialogHandler : public QObject {
    Q_OBJECT
    typedef void (*QInputDialog_DoubleValueChangedCallback)(void*, double);
    typedef void (*QInputDialog_DoubleValueSelectedCallback)(void*, double);
    typedef void (*QInputDialog_IntValueChangedCallback)(void*, int);
    typedef void (*QInputDialog_IntValueSelectedCallback)(void*, int);
    typedef void (*QInputDialog_TextValueChangedCallback)(void*, const char*);
    typedef void (*QInputDialog_TextValueSelectedCallback)(void*, const char*);
public:
    explicit QInputDialogHandler(QObject* parent = nullptr);
    void setDoubleValueChangedCallback(QInputDialog_DoubleValueChangedCallback callback);
    void setDoubleValueSelectedCallback(QInputDialog_DoubleValueSelectedCallback callback);
    void setIntValueChangedCallback(QInputDialog_IntValueChangedCallback callback);
    void setIntValueSelectedCallback(QInputDialog_IntValueSelectedCallback callback);
    void setTextValueChangedCallback(QInputDialog_TextValueChangedCallback callback);
    void setTextValueSelectedCallback(QInputDialog_TextValueSelectedCallback callback);
public slots:
    void onDoubleValueChanged(double value) const;
    void onDoubleValueSelected(double value) const;
    void onIntValueChanged(int value) const;
    void onIntValueSelected(int value) const;
    void onTextValueChanged(const QString& text) const;
    void onTextValueSelected(const QString& text) const;
private:
    QInputDialog_DoubleValueChangedCallback doubleValueChangedCallback;
    QInputDialog_DoubleValueSelectedCallback doubleValueSelectedCallback;
    QInputDialog_IntValueChangedCallback intValueChangedCallback;
    QInputDialog_IntValueSelectedCallback intValueSelectedCallback;
    QInputDialog_TextValueChangedCallback textValueChangedCallback;
    QInputDialog_TextValueSelectedCallback textValueSelectedCallback;
};

#endif // QINPUTDIALOG_HANDLER_H
