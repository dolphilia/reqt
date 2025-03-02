#include "QBoxLayoutBind.h"

BindQBoxLayout::BindQBoxLayout(QBoxLayout::Direction dir, QWidget* parent)
    : QBoxLayout(dir, parent), m_handler(nullptr)
{
}

BindQBoxLayout::~BindQBoxLayout()
{
    delete m_handler;
}

void BindQBoxLayout::setHandler(QBoxLayoutHandler* handler)
{
    if (m_handler) {
        delete m_handler;
    }
    m_handler = handler;
    if (m_handler) {
        m_handler->setParent(this);
    }
}

QBoxLayoutHandler* BindQBoxLayout::handler() const
{
    return m_handler;
}

// Layout operations
void BindQBoxLayout::addLayout(QLayout* layout, int stretch)
{
    QBoxLayout::addLayout(layout, stretch);
}

void BindQBoxLayout::insertLayout(int index, QLayout* layout, int stretch)
{
    QBoxLayout::insertLayout(index, layout, stretch);
}

void BindQBoxLayout::addWidget(QWidget* widget, int stretch, Qt::Alignment alignment)
{
    QBoxLayout::addWidget(widget, stretch, alignment);
}

void BindQBoxLayout::insertWidget(int index, QWidget* widget, int stretch, Qt::Alignment alignment)
{
    QBoxLayout::insertWidget(index, widget, stretch, alignment);
}

// Spacer operations
void BindQBoxLayout::addSpacing(int size)
{
    QBoxLayout::addSpacing(size);
}

void BindQBoxLayout::addStretch(int stretch)
{
    QBoxLayout::addStretch(stretch);
}

void BindQBoxLayout::addStrut(int size)
{
    QBoxLayout::addStrut(size);
}

void BindQBoxLayout::insertSpacing(int index, int size)
{
    QBoxLayout::insertSpacing(index, size);
}

void BindQBoxLayout::insertStretch(int index, int stretch)
{
    QBoxLayout::insertStretch(index, stretch);
}

// Direction management
QBoxLayout::Direction BindQBoxLayout::direction() const
{
    return QBoxLayout::direction();
}

void BindQBoxLayout::setDirection(Direction direction)
{
    QBoxLayout::setDirection(direction);
}

// Stretch management
void BindQBoxLayout::setStretch(int index, int stretch)
{
    QBoxLayout::setStretch(index, stretch);
}

bool BindQBoxLayout::setStretchFactor(QWidget* widget, int stretch)
{
    return QBoxLayout::setStretchFactor(widget, stretch);
}

bool BindQBoxLayout::setStretchFactor(QLayout* layout, int stretch)
{
    return QBoxLayout::setStretchFactor(layout, stretch);
}

int BindQBoxLayout::stretch(int index) const
{
    return QBoxLayout::stretch(index);
}

// Reimplemented from QLayout
void BindQBoxLayout::addItem(QLayoutItem* item)
{
    QBoxLayout::addItem(item);
}

int BindQBoxLayout::count() const
{
    return QBoxLayout::count();
}

Qt::Orientations BindQBoxLayout::expandingDirections() const
{
    return QBoxLayout::expandingDirections();
}

bool BindQBoxLayout::hasHeightForWidth() const
{
    return QBoxLayout::hasHeightForWidth();
}

int BindQBoxLayout::heightForWidth(int w) const
{
    return QBoxLayout::heightForWidth(w);
}

void BindQBoxLayout::invalidate()
{
    QBoxLayout::invalidate();
}

QLayoutItem* BindQBoxLayout::itemAt(int index) const
{
    return QBoxLayout::itemAt(index);
}

QSize BindQBoxLayout::maximumSize() const
{
    return QBoxLayout::maximumSize();
}

int BindQBoxLayout::minimumHeightForWidth(int w) const
{
    return QBoxLayout::minimumHeightForWidth(w);
}

QSize BindQBoxLayout::minimumSize() const
{
    return QBoxLayout::minimumSize();
}

void BindQBoxLayout::setGeometry(const QRect& r)
{
    QBoxLayout::setGeometry(r);
    if (m_handler) {
        m_handler->onGeometryChanged();
    }
}

void BindQBoxLayout::setSpacing(int spacing)
{
    QBoxLayout::setSpacing(spacing);
}

QSize BindQBoxLayout::sizeHint() const
{
    return QBoxLayout::sizeHint();
}

int BindQBoxLayout::spacing() const
{
    return QBoxLayout::spacing();
}

QLayoutItem* BindQBoxLayout::takeAt(int index)
{
    return QBoxLayout::takeAt(index);
}
