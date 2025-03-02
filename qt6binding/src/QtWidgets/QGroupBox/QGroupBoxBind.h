#ifndef BIND_Q_GROUP_BOX_H
#define BIND_Q_GROUP_BOX_H

#include <QGroupBox>

class BindQGroupBox : public QGroupBox {
    Q_OBJECT
public:
    explicit BindQGroupBox(QWidget *parent = nullptr);
    explicit BindQGroupBox(const QString &title, QWidget *parent = nullptr);
    ~BindQGroupBox();

    void setTitle(const QString &title);
    QString title() const;
    void setAlignment(int alignment);
    void setFlat(bool flat);
    bool isFlat() const;
    void setCheckable(bool checkable);
    bool isCheckable() const;
    void setChecked(bool checked);
    bool isChecked() const;
};

#endif // BIND_Q_GROUP_BOX_H
