#include "bind_q_label.h"

QLabelBind::QLabelBind(const QString& text, QWidget* parent)
    : QLabel(text, parent)
{
}

QLabelBind::~QLabelBind()
{
}

void QLabelBind::setText(const char* text)
{
    QLabel::setText(QString::fromUtf8(text));
}

const char* QLabelBind::text() const
{
    return QLabel::text().toUtf8().constData();
}

void QLabelBind::setAlignment(int alignment)
{
    QLabel::setAlignment(static_cast<Qt::Alignment>(alignment));
}

int QLabelBind::alignment() const
{
    return static_cast<int>(QLabel::alignment());
}

void QLabelBind::setWordWrap(bool on)
{
    QLabel::setWordWrap(on);
}

bool QLabelBind::wordWrap() const
{
    return QLabel::wordWrap();
}

void QLabelBind::clear()
{
    QLabel::clear();
}

void QLabelBind::setMargin(int margin)
{
    QLabel::setMargin(margin);
}

int QLabelBind::margin() const
{
    return QLabel::margin();
}

void QLabelBind::setIndent(int indent)
{
    QLabel::setIndent(indent);
}

int QLabelBind::indent() const
{
    return QLabel::indent();
}

void QLabelBind::setOpenExternalLinks(bool open)
{
    QLabel::setOpenExternalLinks(open);
}

bool QLabelBind::openExternalLinks() const
{
    return QLabel::openExternalLinks();
}

void QLabelBind::setTextFormat(int format)
{
    QLabel::setTextFormat(static_cast<Qt::TextFormat>(format));
}

int QLabelBind::textFormat() const
{
    return static_cast<int>(QLabel::textFormat());
}

void QLabelBind::setScaledContents(bool scaled)
{
    QLabel::setScaledContents(scaled);
}
