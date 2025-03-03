#ifndef QLABEL_HANDLER_H
#define QLABEL_HANDLER_H

#include <QObject>

class QLabelHandler : public QObject {
    Q_OBJECT
    typedef void (*LinkActivatedCallback)(void*, const char*);
    typedef void (*LinkHoveredCallback)(void*, const char*);
public:
    explicit QLabelHandler(QObject* parent = nullptr);
    void setLinkActivatedCallback(LinkActivatedCallback callback);
    void setLinkHoveredCallback(LinkHoveredCallback callback);
public slots:
    void onLinkActivated(const QString& link) const;
    void onLinkHovered(const QString& link) const;
private:
    LinkActivatedCallback linkActivatedCallback;
    LinkHoveredCallback linkHoveredCallback;
};

#endif // QLABEL_HANDLER_H
