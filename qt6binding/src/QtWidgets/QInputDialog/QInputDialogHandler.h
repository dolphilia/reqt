#ifndef QINPUTDIALOG_HANDLER_H
#define QINPUTDIALOG_HANDLER_H

#include <QObject>

class QInputDialogHandler : public QObject {
    Q_OBJECT
    typedef void (*DoubleValueChangedCallback)(void*, double);
    typedef void (*DoubleValueSelectedCallback)(void*, double);
    typedef void (*IntValueChangedCallback)(void*, int);
    typedef void (*IntValueSelectedCallback)(void*, int);
    typedef void (*TextValueChangedCallback)(void*, const char*);
    typedef void (*TextValueSelectedCallback)(void*, const char*);
public:
    explicit QInputDialogHandler(QObject* parent = nullptr);
    
    void setDoubleValueChangedCallback(DoubleValueChangedCallback callback);
    void setDoubleValueSelectedCallback(DoubleValueSelectedCallback callback);
    void setIntValueChangedCallback(IntValueChangedCallback callback);
    void setIntValueSelectedCallback(IntValueSelectedCallback callback);
    void setTextValueChangedCallback(TextValueChangedCallback callback);
    void setTextValueSelectedCallback(TextValueSelectedCallback callback);
    
public slots:
    void onDoubleValueChanged(double value) const;
    void onDoubleValueSelected(double value) const;
    void onIntValueChanged(int value) const;
    void onIntValueSelected(int value) const;
    void onTextValueChanged(const QString& text) const;
    void onTextValueSelected(const QString& text) const;
    
private:
    DoubleValueChangedCallback doubleValueChangedCallback;
    DoubleValueSelectedCallback doubleValueSelectedCallback;
    IntValueChangedCallback intValueChangedCallback;
    IntValueSelectedCallback intValueSelectedCallback;
    TextValueChangedCallback textValueChangedCallback;
    TextValueSelectedCallback textValueSelectedCallback;
};

#endif // QINPUTDIALOG_HANDLER_H
