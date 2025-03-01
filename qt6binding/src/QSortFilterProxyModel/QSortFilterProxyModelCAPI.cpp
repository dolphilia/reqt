#include "QSortFilterProxyModelBind.h"
#include "../../include/qt6/qsortfilterproxymodel.h"

extern "C" {

void* QSortFilterProxyModel_create(void* parent) {
    return QSortFilterProxyModelBind::create(reinterpret_cast<QObject*>(parent));
}

void QSortFilterProxyModel_destroy(void* proxy) {
    QSortFilterProxyModelBind::destroy(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

bool QSortFilterProxyModel_autoAcceptChildRows(void* proxy) {
    return QSortFilterProxyModelBind::autoAcceptChildRows(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setAutoAcceptChildRows(void* proxy, bool accept) {
    QSortFilterProxyModelBind::setAutoAcceptChildRows(reinterpret_cast<QSortFilterProxyModel*>(proxy), accept);
}

bool QSortFilterProxyModel_dynamicSortFilter(void* proxy) {
    return QSortFilterProxyModelBind::dynamicSortFilter(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setDynamicSortFilter(void* proxy, bool enable) {
    QSortFilterProxyModelBind::setDynamicSortFilter(reinterpret_cast<QSortFilterProxyModel*>(proxy), enable);
}

int QSortFilterProxyModel_filterCaseSensitivity(void* proxy) {
    return QSortFilterProxyModelBind::filterCaseSensitivity(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setFilterCaseSensitivity(void* proxy, int cs) {
    QSortFilterProxyModelBind::setFilterCaseSensitivity(reinterpret_cast<QSortFilterProxyModel*>(proxy), cs);
}

int QSortFilterProxyModel_filterKeyColumn(void* proxy) {
    return QSortFilterProxyModelBind::filterKeyColumn(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setFilterKeyColumn(void* proxy, int column) {
    QSortFilterProxyModelBind::setFilterKeyColumn(reinterpret_cast<QSortFilterProxyModel*>(proxy), column);
}

int QSortFilterProxyModel_filterRole(void* proxy) {
    return QSortFilterProxyModelBind::filterRole(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setFilterRole(void* proxy, int role) {
    QSortFilterProxyModelBind::setFilterRole(reinterpret_cast<QSortFilterProxyModel*>(proxy), role);
}

bool QSortFilterProxyModel_isRecursiveFilteringEnabled(void* proxy) {
    return QSortFilterProxyModelBind::isRecursiveFilteringEnabled(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setRecursiveFilteringEnabled(void* proxy, bool recursive) {
    QSortFilterProxyModelBind::setRecursiveFilteringEnabled(reinterpret_cast<QSortFilterProxyModel*>(proxy), recursive);
}

bool QSortFilterProxyModel_isSortLocaleAware(void* proxy) {
    return QSortFilterProxyModelBind::isSortLocaleAware(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setSortLocaleAware(void* proxy, bool on) {
    QSortFilterProxyModelBind::setSortLocaleAware(reinterpret_cast<QSortFilterProxyModel*>(proxy), on);
}

int QSortFilterProxyModel_sortCaseSensitivity(void* proxy) {
    return QSortFilterProxyModelBind::sortCaseSensitivity(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setSortCaseSensitivity(void* proxy, int cs) {
    QSortFilterProxyModelBind::setSortCaseSensitivity(reinterpret_cast<QSortFilterProxyModel*>(proxy), cs);
}

int QSortFilterProxyModel_sortRole(void* proxy) {
    return QSortFilterProxyModelBind::sortRole(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setSortRole(void* proxy, int role) {
    QSortFilterProxyModelBind::setSortRole(reinterpret_cast<QSortFilterProxyModel*>(proxy), role);
}

int QSortFilterProxyModel_sortColumn(void* proxy) {
    return QSortFilterProxyModelBind::sortColumn(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

int QSortFilterProxyModel_sortOrder(void* proxy) {
    return QSortFilterProxyModelBind::sortOrder(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setFilterFixedString(void* proxy, const char* pattern) {
    QSortFilterProxyModelBind::setFilterFixedString(reinterpret_cast<QSortFilterProxyModel*>(proxy), pattern);
}

void QSortFilterProxyModel_setFilterWildcard(void* proxy, const char* pattern) {
    QSortFilterProxyModelBind::setFilterWildcard(reinterpret_cast<QSortFilterProxyModel*>(proxy), pattern);
}

void QSortFilterProxyModel_setFilterRegularExpression(void* proxy, const char* pattern) {
    QSortFilterProxyModelBind::setFilterRegularExpression(reinterpret_cast<QSortFilterProxyModel*>(proxy), pattern);
}

void QSortFilterProxyModel_sort(void* proxy, int column, int order) {
    QSortFilterProxyModelBind::sort(reinterpret_cast<QSortFilterProxyModel*>(proxy), column, order);
}

void QSortFilterProxyModel_invalidate(void* proxy) {
    QSortFilterProxyModelBind::invalidate(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_invalidateFilter(void* proxy) {
    QSortFilterProxyModelBind::invalidateFilter(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setSourceModel(void* proxy, void* sourceModel) {
    QSortFilterProxyModelBind::setSourceModel(
        reinterpret_cast<QSortFilterProxyModel*>(proxy),
        reinterpret_cast<QAbstractItemModel*>(sourceModel)
    );
}

void* QSortFilterProxyModel_sourceModel(void* proxy) {
    return QSortFilterProxyModelBind::sourceModel(reinterpret_cast<QSortFilterProxyModel*>(proxy));
}

void QSortFilterProxyModel_setAutoAcceptChildRowsCallback(void* proxy, QSortFilterProxyModelAutoAcceptChildRowsCallback callback) {
    QSortFilterProxyModelBind::setAutoAcceptChildRowsCallback(
        reinterpret_cast<QSortFilterProxyModel*>(proxy),
        callback
    );
}

void QSortFilterProxyModel_setFilterCaseSensitivityCallback(void* proxy, QSortFilterProxyModelFilterCaseSensitivityCallback callback) {
    QSortFilterProxyModelBind::setFilterCaseSensitivityCallback(
        reinterpret_cast<QSortFilterProxyModel*>(proxy),
        callback
    );
}

void QSortFilterProxyModel_setFilterRoleCallback(void* proxy, QSortFilterProxyModelFilterRoleCallback callback) {
    QSortFilterProxyModelBind::setFilterRoleCallback(
        reinterpret_cast<QSortFilterProxyModel*>(proxy),
        callback
    );
}

void QSortFilterProxyModel_setRecursiveFilteringEnabledCallback(void* proxy, QSortFilterProxyModelRecursiveFilteringEnabledCallback callback) {
    QSortFilterProxyModelBind::setRecursiveFilteringEnabledCallback(
        reinterpret_cast<QSortFilterProxyModel*>(proxy),
        callback
    );
}

void QSortFilterProxyModel_setSortCaseSensitivityCallback(void* proxy, QSortFilterProxyModelSortCaseSensitivityCallback callback) {
    QSortFilterProxyModelBind::setSortCaseSensitivityCallback(
        reinterpret_cast<QSortFilterProxyModel*>(proxy),
        callback
    );
}

void QSortFilterProxyModel_setSortLocaleAwareCallback(void* proxy, QSortFilterProxyModelSortLocaleAwareCallback callback) {
    QSortFilterProxyModelBind::setSortLocaleAwareCallback(
        reinterpret_cast<QSortFilterProxyModel*>(proxy),
        callback
    );
}

void QSortFilterProxyModel_setSortRoleCallback(void* proxy, QSortFilterProxyModelSortRoleCallback callback) {
    QSortFilterProxyModelBind::setSortRoleCallback(
        reinterpret_cast<QSortFilterProxyModel*>(proxy),
        callback
    );
}

} 