#ifndef QSORTFILTERPROXYMODEL_BIND_H
#define QSORTFILTERPROXYMODEL_BIND_H

#include <QSortFilterProxyModel>
#include <QRegularExpression>
#include "QSortFilterProxyModelHandler.h"

// カスタムプロキシモデルクラス
class CustomSortFilterProxyModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    explicit CustomSortFilterProxyModel(QObject* parent = nullptr) : QSortFilterProxyModel(parent) {}
    void publicInvalidateFilter() { invalidateFilter(); }
    void publicInvalidate() { invalidate(); }
};

class QSortFilterProxyModelBind;

// フレンド宣言を追加
class QSortFilterProxyModel;
class QSortFilterProxyModelBind {
    friend class QSortFilterProxyModel;
public:
    static QSortFilterProxyModel* create(QObject* parent = nullptr);
    static void destroy(QSortFilterProxyModel* proxy);
    
    // Properties
    static bool autoAcceptChildRows(QSortFilterProxyModel* proxy);
    static void setAutoAcceptChildRows(QSortFilterProxyModel* proxy, bool accept);
    static bool dynamicSortFilter(QSortFilterProxyModel* proxy);
    static void setDynamicSortFilter(QSortFilterProxyModel* proxy, bool enable);
    static int filterCaseSensitivity(QSortFilterProxyModel* proxy);
    static void setFilterCaseSensitivity(QSortFilterProxyModel* proxy, int cs);
    static int filterKeyColumn(QSortFilterProxyModel* proxy);
    static void setFilterKeyColumn(QSortFilterProxyModel* proxy, int column);
    static int filterRole(QSortFilterProxyModel* proxy);
    static void setFilterRole(QSortFilterProxyModel* proxy, int role);
    static bool isRecursiveFilteringEnabled(QSortFilterProxyModel* proxy);
    static void setRecursiveFilteringEnabled(QSortFilterProxyModel* proxy, bool recursive);
    static bool isSortLocaleAware(QSortFilterProxyModel* proxy);
    static void setSortLocaleAware(QSortFilterProxyModel* proxy, bool on);
    static int sortCaseSensitivity(QSortFilterProxyModel* proxy);
    static void setSortCaseSensitivity(QSortFilterProxyModel* proxy, int cs);
    static int sortRole(QSortFilterProxyModel* proxy);
    static void setSortRole(QSortFilterProxyModel* proxy, int role);
    static int sortColumn(QSortFilterProxyModel* proxy);
    static int sortOrder(QSortFilterProxyModel* proxy);
    
    // Filter operations
    static void setFilterFixedString(QSortFilterProxyModel* proxy, const char* pattern);
    static void setFilterWildcard(QSortFilterProxyModel* proxy, const char* pattern);
    static void setFilterRegularExpression(QSortFilterProxyModel* proxy, const char* pattern);
    
    // Sort operations
    static void sort(QSortFilterProxyModel* proxy, int column, int order);
    static void invalidate(QSortFilterProxyModel* proxy);
    static void invalidateFilter(QSortFilterProxyModel* proxy);
    
    // Model operations
    static void setSourceModel(QSortFilterProxyModel* proxy, QAbstractItemModel* sourceModel);
    static QAbstractItemModel* sourceModel(QSortFilterProxyModel* proxy);

    // Callback setters
    static void setAutoAcceptChildRowsCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelAutoAcceptChildRowsCallback callback);
    static void setFilterCaseSensitivityCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelFilterCaseSensitivityCallback callback);
    static void setFilterRoleCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelFilterRoleCallback callback);
    static void setRecursiveFilteringEnabledCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelRecursiveFilteringEnabledCallback callback);
    static void setSortCaseSensitivityCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelSortCaseSensitivityCallback callback);
    static void setSortLocaleAwareCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelSortLocaleAwareCallback callback);
    static void setSortRoleCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelSortRoleCallback callback);
};

#endif // QSORTFILTERPROXYMODEL_BIND_H 