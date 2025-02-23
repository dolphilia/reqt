#include "bind_q_widget.h"

BindQWidget::BindQWidget(QWidget *parent)
    : QWidget(parent)
{
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
    QWidget::setFixedWidth(width);
}
