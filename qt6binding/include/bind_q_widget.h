#ifndef BIND_Q_WIDGET_H
#define BIND_Q_WIDGET_H

#include <QWidget>

class BindQWidget : public QWidget {
    Q_OBJECT
public:
    explicit BindQWidget(QWidget *parent = nullptr);
    ~BindQWidget();

    // Style sheet
    void setStyleSheet(const QString &styleSheet);
    QString styleSheet() const;

    // Background
    void setAutoFillBackground(bool enabled);
    bool autoFillBackground() const;

    // Palette
    void setBackgroundRole(QPalette::ColorRole role);
    QPalette::ColorRole backgroundRole() const;
    void setForegroundRole(QPalette::ColorRole role);
    QPalette::ColorRole foregroundRole() const;
};

#endif // BIND_Q_WIDGET_H
