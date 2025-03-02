#include "QGroupBoxBind.h"

BindQGroupBox::BindQGroupBox(QWidget *parent)
    : QGroupBox(parent)
{
}

BindQGroupBox::BindQGroupBox(const QString &title, QWidget *parent)
    : QGroupBox(title, parent)
{
}

BindQGroupBox::~BindQGroupBox()
{
}

void BindQGroupBox::setTitle(const QString &title)
{
    QGroupBox::setTitle(title);
}

QString BindQGroupBox::title() const
{
    return QGroupBox::title();
}

void BindQGroupBox::setAlignment(int alignment)
{
    QGroupBox::setAlignment(static_cast<Qt::Alignment>(alignment));
}

void BindQGroupBox::setFlat(bool flat)
{
    QGroupBox::setFlat(flat);
}

bool BindQGroupBox::isFlat() const
{
    return QGroupBox::isFlat();
}

void BindQGroupBox::setCheckable(bool checkable)
{
    QGroupBox::setCheckable(checkable);
}

bool BindQGroupBox::isCheckable() const
{
    return QGroupBox::isCheckable();
}

void BindQGroupBox::setChecked(bool checked)
{
    QGroupBox::setChecked(checked);
}

bool BindQGroupBox::isChecked() const
{
    return QGroupBox::isChecked();
}
