#include "QWidgetBind.h"

BindQWidget::BindQWidget(QWidget *parent)
    : QWidget(parent)
    , customContextMenuRequestedCallback(nullptr)
    , windowIconChangedCallback(nullptr)
    , windowTitleChangedCallback(nullptr)
{
    // シグナルとスロットの接続
    connect(this, &QWidget::customContextMenuRequested, this, &BindQWidget::onCustomContextMenuRequested);
    connect(this, &QWidget::windowIconChanged, this, &BindQWidget::onWindowIconChanged);
    connect(this, &QWidget::windowTitleChanged, this, &BindQWidget::onWindowTitleChanged);
}

BindQWidget::~BindQWidget()
{
}

void BindQWidget::setStyleSheet(const QString &styleSheet)
{
    QWidget::setStyleSheet(styleSheet);
}

QString BindQWidget::styleSheet() const
{
    return QWidget::styleSheet();
}

void BindQWidget::setAutoFillBackground(bool enabled)
{
    QWidget::setAutoFillBackground(enabled);
}

bool BindQWidget::autoFillBackground() const
{
    return QWidget::autoFillBackground();
}

void BindQWidget::setBackgroundRole(QPalette::ColorRole role)
{
    QWidget::setBackgroundRole(role);
}

QPalette::ColorRole BindQWidget::backgroundRole() const
{
    return QWidget::backgroundRole();
}

void BindQWidget::setForegroundRole(QPalette::ColorRole role)
{
    QWidget::setForegroundRole(role);
}

QPalette::ColorRole BindQWidget::foregroundRole() const
{
    return QWidget::foregroundRole();
}

void BindQWidget::setFixedSizeWrapper(int w, int h)
{
    QWidget::setFixedSize(w, h);
}

void BindQWidget::setFixedHeightWrapper(int height)
{
    QWidget::setFixedHeight(height);
}

void BindQWidget::setFixedWidthWrapper(int width)
{
    setFixedWidth(width);
}

void BindQWidget::setCursor(const QCursor &cursor)
{
    QWidget::setCursor(cursor);
}

// Signal callbacks
void BindQWidget::setCustomContextMenuRequestedCallback(WidgetCustomContextMenuRequestedCallback callback)
{
    customContextMenuRequestedCallback = callback;
}

void BindQWidget::setWindowIconChangedCallback(WidgetWindowIconChangedCallback callback)
{
    windowIconChangedCallback = callback;
}

void BindQWidget::setWindowTitleChangedCallback(WidgetWindowTitleChangedCallback callback)
{
    windowTitleChangedCallback = callback;
}

// Private slots
void BindQWidget::onCustomContextMenuRequested(const QPoint &pos)
{
    if (customContextMenuRequestedCallback) {
        customContextMenuRequestedCallback(this, &pos);
    }
}

void BindQWidget::onWindowIconChanged(const QIcon &icon)
{
    if (windowIconChangedCallback) {
        windowIconChangedCallback(this, &icon);
    }
}

void BindQWidget::onWindowTitleChanged(const QString &title)
{
    if (windowTitleChangedCallback) {
        windowTitleChangedCallback(this, &title);
    }
}
