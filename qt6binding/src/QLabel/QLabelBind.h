#ifndef QLABEL_BIND_H
#define QLABEL_BIND_H

#include <QLabel>
#include <QString>
#include <QPixmap>
#include <QMovie>
#include <QPicture>

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
    
    // 追加機能
    void* buddy() const;
    void setBuddy(void* buddy);
    bool hasSelectedText() const;
    const char* selectedText() const;
    int selectionStart() const;
    void setSelection(int start, int length);
    void* pixmap() const;
    void setPixmap(void* pixmap);
    void* movie() const;
    void setMovie(void* movie);
    void* picture() const;
    void setPicture(void* picture);
    void setNum(int num);
    void setNum(double num);
    void setTextInteractionFlags(int flags);
    int textInteractionFlags() const;
    
    // シグナル用コールバック
    typedef void (*LinkActivatedCallback)(void* label, const char* link);
    typedef void (*LinkHoveredCallback)(void* label, const char* link);
    
    void setLinkActivatedCallback(LinkActivatedCallback callback);
    void setLinkHoveredCallback(LinkHoveredCallback callback);
    
private:
    LinkActivatedCallback m_linkActivatedCallback;
    LinkHoveredCallback m_linkHoveredCallback;
};

#endif // QLABEL_BIND_H
