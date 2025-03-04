#ifndef QLABEL_BIND_H
#define QLABEL_BIND_H

#include "QLabelHandler.h"
#include <QLabel>

class QLabelBind : public QLabel {
    Q_OBJECT
    typedef void (*QLabel_LinkActivatedCallback)(void*, const char*);
    typedef void (*QLabel_LinkHoveredCallback)(void*, const char*);
public:
    explicit QLabelBind(QWidget* parent = nullptr);
    explicit QLabelBind(const QString& text, QWidget* parent = nullptr);
    ~QLabelBind() override;
    void setLinkActivatedCallback(QLabel_LinkActivatedCallback callback) const;
    void setLinkHoveredCallback(QLabel_LinkHoveredCallback callback) const;
private:
    QLabelHandler* handler;
};

#endif // QLABEL_BIND_H
