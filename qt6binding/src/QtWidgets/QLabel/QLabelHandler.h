#ifndef QLABEL_HANDLER_H
#define QLABEL_HANDLER_H

#include <QObject>

class QLabelHandler : public QObject {
    Q_OBJECT
    typedef void (*QLabel_LinkActivatedCallback)(void*, const char*);
    typedef void (*QLabel_LinkHoveredCallback)(void*, const char*);
public:
    explicit QLabelHandler(QObject* parent = nullptr);
    void setLinkActivatedCallback(QLabel_LinkActivatedCallback callback);
    void setLinkHoveredCallback(QLabel_LinkHoveredCallback callback);
public slots:
    void onLinkActivated(const QString& link) const;
    void onLinkHovered(const QString& link) const;
private:
    QLabel_LinkActivatedCallback linkActivatedCallback;
    QLabel_LinkHoveredCallback linkHoveredCallback;
};

#endif // QLABEL_HANDLER_H
