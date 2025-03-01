#ifndef QSORTFILTERPROXYMODEL_HANDLER_H
#define QSORTFILTERPROXYMODEL_HANDLER_H

#include <QObject>
#include <QSortFilterProxyModel>

typedef void (*QSortFilterProxyModelAutoAcceptChildRowsCallback)(void* proxy, bool autoAcceptChildRows);
typedef void (*QSortFilterProxyModelFilterCaseSensitivityCallback)(void* proxy, int filterCaseSensitivity);
typedef void (*QSortFilterProxyModelFilterRoleCallback)(void* proxy, int filterRole);
typedef void (*QSortFilterProxyModelRecursiveFilteringEnabledCallback)(void* proxy, bool recursiveFilteringEnabled);
typedef void (*QSortFilterProxyModelSortCaseSensitivityCallback)(void* proxy, int sortCaseSensitivity);
typedef void (*QSortFilterProxyModelSortLocaleAwareCallback)(void* proxy, bool sortLocaleAware);
typedef void (*QSortFilterProxyModelSortRoleCallback)(void* proxy, int sortRole);

class QSortFilterProxyModelHandler : public QObject {
    Q_OBJECT

public:
    explicit QSortFilterProxyModelHandler(QObject* parent = nullptr);

    void setAutoAcceptChildRowsCallback(QSortFilterProxyModelAutoAcceptChildRowsCallback callback);
    void setFilterCaseSensitivityCallback(QSortFilterProxyModelFilterCaseSensitivityCallback callback);
    void setFilterRoleCallback(QSortFilterProxyModelFilterRoleCallback callback);
    void setRecursiveFilteringEnabledCallback(QSortFilterProxyModelRecursiveFilteringEnabledCallback callback);
    void setSortCaseSensitivityCallback(QSortFilterProxyModelSortCaseSensitivityCallback callback);
    void setSortLocaleAwareCallback(QSortFilterProxyModelSortLocaleAwareCallback callback);
    void setSortRoleCallback(QSortFilterProxyModelSortRoleCallback callback);

public slots:
    void onAutoAcceptChildRowsChanged(bool autoAcceptChildRows);
    void onFilterCaseSensitivityChanged(Qt::CaseSensitivity filterCaseSensitivity);
    void onFilterRoleChanged(int filterRole);
    void onRecursiveFilteringEnabledChanged(bool recursiveFilteringEnabled);
    void onSortCaseSensitivityChanged(Qt::CaseSensitivity sortCaseSensitivity);
    void onSortLocaleAwareChanged(bool sortLocaleAware);
    void onSortRoleChanged(int sortRole);

private:
    QSortFilterProxyModelAutoAcceptChildRowsCallback autoAcceptChildRowsCallback;
    QSortFilterProxyModelFilterCaseSensitivityCallback filterCaseSensitivityCallback;
    QSortFilterProxyModelFilterRoleCallback filterRoleCallback;
    QSortFilterProxyModelRecursiveFilteringEnabledCallback recursiveFilteringEnabledCallback;
    QSortFilterProxyModelSortCaseSensitivityCallback sortCaseSensitivityCallback;
    QSortFilterProxyModelSortLocaleAwareCallback sortLocaleAwareCallback;
    QSortFilterProxyModelSortRoleCallback sortRoleCallback;
};

#endif // QSORTFILTERPROXYMODEL_HANDLER_H 