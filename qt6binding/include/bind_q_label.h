#ifndef QLABEL_BIND_H
#define QLABEL_BIND_H

#include <QLabel>
#include <QString>

class QLabelBind : public QLabel {
    Q_OBJECT

public:
    explicit QLabelBind(const QString& text = QString(), QWidget* parent = nullptr);
    ~QLabelBind() override;

    void setText(const char* text);
    const char* text() const;
    void setAlignment(int alignment);
    int alignment() const;
    void setWordWrap(bool on);
    bool wordWrap() const;
    void clear();
    void setMargin(int margin);
    int margin() const;
    void setIndent(int indent);
    int indent() const;
    void setOpenExternalLinks(bool open);
    bool openExternalLinks() const;
    void setTextFormat(int format);
    int textFormat() const;
    void setScaledContents(bool scaled);
    bool hasScaledContents() const;
};

#endif // QLABEL_BIND_H
