#ifndef QBOXLAYOUTHANDLER_H
#define QBOXLAYOUTHANDLER_H

#include <QObject>

class QBoxLayoutHandler : public QObject {
    Q_OBJECT
public:
    explicit QBoxLayoutHandler(QObject* parent = nullptr);
    ~QBoxLayoutHandler();

    void setGeometryChangedCallback(void (*callback)());

public slots:
    void onGeometryChanged();

private:
    void (*m_geometryChangedCallback)();
};

#endif // QBOXLAYOUTHANDLER_H
