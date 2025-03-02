#ifndef BIND_Q_WIDGET_H
#define BIND_Q_WIDGET_H

#include <QWidget>
#include <QIcon>

// コールバック関数の型定義
typedef void (*WidgetCustomContextMenuRequestedCallback)(void*, const QPoint*);
typedef void (*WidgetWindowIconChangedCallback)(void*, const QIcon*);
typedef void (*WidgetWindowTitleChangedCallback)(void*, const QString*);

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

    // Size
    void setFixedSizeWrapper(int w, int h);
    void setFixedHeightWrapper(int height);
    void setFixedWidthWrapper(int width);
    void setCursor(const QCursor &cursor);

    // Signal callbacks
    void setCustomContextMenuRequestedCallback(WidgetCustomContextMenuRequestedCallback callback);
    void setWindowIconChangedCallback(WidgetWindowIconChangedCallback callback);
    void setWindowTitleChangedCallback(WidgetWindowTitleChangedCallback callback);

private slots:
    void onCustomContextMenuRequested(const QPoint &pos);
    void onWindowIconChanged(const QIcon &icon);
    void onWindowTitleChanged(const QString &title);

private:
    WidgetCustomContextMenuRequestedCallback customContextMenuRequestedCallback;
    WidgetWindowIconChangedCallback windowIconChangedCallback;
    WidgetWindowTitleChangedCallback windowTitleChangedCallback;
};

#endif // BIND_Q_WIDGET_H
