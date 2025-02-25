#include "QLabelBind.h"

QLabelBind::QLabelBind(const QString& text, QWidget* parent)
    : QLabel(text, parent)
    , m_linkActivatedCallback(nullptr)
    , m_linkHoveredCallback(nullptr)
{
    connect(this, &QLabel::linkActivated, this, [this](const QString& link) {
        if (m_linkActivatedCallback) {
            m_linkActivatedCallback(this, link.toUtf8().constData());
        }
    });
    
    connect(this, &QLabel::linkHovered, this, [this](const QString& link) {
        if (m_linkHoveredCallback) {
            m_linkHoveredCallback(this, link.toUtf8().constData());
        }
    });
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

bool QLabelBind::hasScaledContents() const
{
    return QLabel::hasScaledContents();
}

void* QLabelBind::buddy() const
{
    return QLabel::buddy();
}

void QLabelBind::setBuddy(void* buddy)
{
    QLabel::setBuddy(static_cast<QWidget*>(buddy));
}

bool QLabelBind::hasSelectedText() const
{
    return QLabel::hasSelectedText();
}

const char* QLabelBind::selectedText() const
{
    return QLabel::selectedText().toUtf8().constData();
}

int QLabelBind::selectionStart() const
{
    return QLabel::selectionStart();
}

void QLabelBind::setSelection(int start, int length)
{
    QLabel::setSelection(start, length);
}

void* QLabelBind::pixmap() const
{
    QPixmap pix = QLabel::pixmap();
    if (pix.isNull()) {
        return nullptr;
    }
    return new QPixmap(pix);
}

void QLabelBind::setPixmap(void* pixmap)
{
    QLabel::setPixmap(*static_cast<QPixmap*>(pixmap));
}

void* QLabelBind::movie() const
{
    return QLabel::movie();
}

void QLabelBind::setMovie(void* movie)
{
    QLabel::setMovie(static_cast<QMovie*>(movie));
}

void* QLabelBind::picture() const
{
    QPicture pic = QLabel::picture();
    if (pic.isNull()) {
        return nullptr;
    }
    return new QPicture(pic);
}

void QLabelBind::setPicture(void* picture)
{
    QLabel::setPicture(*static_cast<QPicture*>(picture));
}

void QLabelBind::setNum(int num)
{
    QLabel::setNum(num);
}

void QLabelBind::setNum(double num)
{
    QLabel::setNum(num);
}

void QLabelBind::setTextInteractionFlags(int flags)
{
    QLabel::setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(flags));
}

int QLabelBind::textInteractionFlags() const
{
    return static_cast<int>(QLabel::textInteractionFlags());
}

void QLabelBind::setLinkActivatedCallback(LinkActivatedCallback callback)
{
    m_linkActivatedCallback = callback;
}

void QLabelBind::setLinkHoveredCallback(LinkHoveredCallback callback)
{
    m_linkHoveredCallback = callback;
}
