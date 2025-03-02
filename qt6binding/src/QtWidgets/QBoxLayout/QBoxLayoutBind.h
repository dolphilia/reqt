#ifndef QBOXBIND_H
#define QBOXBIND_H

#include <QBoxLayout>
#include <QSpacerItem>
#include "QBoxLayoutHandler.h"

class BindQBoxLayout : public QBoxLayout {
    Q_OBJECT
public:
    explicit BindQBoxLayout(QBoxLayout::Direction dir, QWidget* parent = nullptr);
    ~BindQBoxLayout();

    // Handler management
    void setHandler(QBoxLayoutHandler* handler);
    QBoxLayoutHandler* handler() const;

    // Layout operations
    void addLayout(QLayout* layout, int stretch = 0);
    void insertLayout(int index, QLayout* layout, int stretch = 0);
    void addWidget(QWidget* widget, int stretch = 0, Qt::Alignment alignment = Qt::Alignment());
    void insertWidget(int index, QWidget* widget, int stretch = 0, Qt::Alignment alignment = Qt::Alignment());

    // Spacer operations
    void addSpacing(int size);
    void addStretch(int stretch = 0);
    void addStrut(int size);
    void insertSpacing(int index, int size);
    void insertStretch(int index, int stretch = 0);

    // Direction management
    Direction direction() const;
    void setDirection(Direction direction);

    // Stretch management
    void setStretch(int index, int stretch);
    bool setStretchFactor(QWidget* widget, int stretch);
    bool setStretchFactor(QLayout* layout, int stretch);
    int stretch(int index) const;

    // Reimplemented from QLayout
    virtual void addItem(QLayoutItem* item) override;
    virtual int count() const override;
    virtual Qt::Orientations expandingDirections() const override;
    virtual bool hasHeightForWidth() const override;
    virtual int heightForWidth(int w) const override;
    virtual void invalidate() override;
    virtual QLayoutItem* itemAt(int index) const override;
    virtual QSize maximumSize() const override;
    virtual int minimumHeightForWidth(int w) const override;
    virtual QSize minimumSize() const override;
    virtual void setGeometry(const QRect& r) override;
    virtual void setSpacing(int spacing) override;
    virtual QSize sizeHint() const override;
    virtual int spacing() const override;
    virtual QLayoutItem* takeAt(int index) override;

private:
    QBoxLayoutHandler* m_handler;
};

#endif // QBOXBIND_H
