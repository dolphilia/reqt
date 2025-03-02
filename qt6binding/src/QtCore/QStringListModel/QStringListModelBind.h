#ifndef QSTRINGLISTMODEL_BIND_H
#define QSTRINGLISTMODEL_BIND_H

#include <QStringListModel>
#include <QStringList>

class QStringListModelBind : public QStringListModel {
    Q_OBJECT

public:
    explicit QStringListModelBind(QObject* parent = nullptr);
    ~QStringListModelBind() override;

    static void* create(QObject* parent);
    static void destroy(QStringListModel* model);
    static void addItem(QStringListModel* model, const char* text);
    static void removeItem(QStringListModel* model, int row);
    static void setItem(QStringListModel* model, int row, const char* text);
    static const char* item(QStringListModel* model, int row);
    static int rowCount(QStringListModel* model);
    static void clear(QStringListModel* model);
};

#endif // QSTRINGLISTMODEL_BIND_H
