#ifndef QSORTFILTERPROXYMODEL_C_H
#define QSORTFILTERPROXYMODEL_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Destruction
void* QSortFilterProxyModel_create(void* parent);
void QSortFilterProxyModel_destroy(void* proxy);

// Properties
bool QSortFilterProxyModel_autoAcceptChildRows(void* proxy);
void QSortFilterProxyModel_setAutoAcceptChildRows(void* proxy, bool accept);
bool QSortFilterProxyModel_dynamicSortFilter(void* proxy);
void QSortFilterProxyModel_setDynamicSortFilter(void* proxy, bool enable);
int QSortFilterProxyModel_filterCaseSensitivity(void* proxy);
void QSortFilterProxyModel_setFilterCaseSensitivity(void* proxy, int cs);
int QSortFilterProxyModel_filterKeyColumn(void* proxy);
void QSortFilterProxyModel_setFilterKeyColumn(void* proxy, int column);
int QSortFilterProxyModel_filterRole(void* proxy);
void QSortFilterProxyModel_setFilterRole(void* proxy, int role);
bool QSortFilterProxyModel_isRecursiveFilteringEnabled(void* proxy);
void QSortFilterProxyModel_setRecursiveFilteringEnabled(void* proxy, bool recursive);
bool QSortFilterProxyModel_isSortLocaleAware(void* proxy);
void QSortFilterProxyModel_setSortLocaleAware(void* proxy, bool on);
int QSortFilterProxyModel_sortCaseSensitivity(void* proxy);
void QSortFilterProxyModel_setSortCaseSensitivity(void* proxy, int cs);
int QSortFilterProxyModel_sortRole(void* proxy);
void QSortFilterProxyModel_setSortRole(void* proxy, int role);
int QSortFilterProxyModel_sortColumn(void* proxy);
int QSortFilterProxyModel_sortOrder(void* proxy);

// Filter operations
void QSortFilterProxyModel_setFilterFixedString(void* proxy, const char* pattern);
void QSortFilterProxyModel_setFilterWildcard(void* proxy, const char* pattern);
void QSortFilterProxyModel_setFilterRegularExpression(void* proxy, const char* pattern);

// Sort operations
void QSortFilterProxyModel_sort(void* proxy, int column, int order);
void QSortFilterProxyModel_invalidate(void* proxy);
void QSortFilterProxyModel_invalidateFilter(void* proxy);

// Model operations
void QSortFilterProxyModel_setSourceModel(void* proxy, void* sourceModel);
void* QSortFilterProxyModel_sourceModel(void* proxy);

// Callback setters
typedef void (*QSortFilterProxyModelAutoAcceptChildRowsCallback)(void* proxy, bool autoAcceptChildRows);
typedef void (*QSortFilterProxyModelFilterCaseSensitivityCallback)(void* proxy, int filterCaseSensitivity);
typedef void (*QSortFilterProxyModelFilterRoleCallback)(void* proxy, int filterRole);
typedef void (*QSortFilterProxyModelRecursiveFilteringEnabledCallback)(void* proxy, bool recursiveFilteringEnabled);
typedef void (*QSortFilterProxyModelSortCaseSensitivityCallback)(void* proxy, int sortCaseSensitivity);
typedef void (*QSortFilterProxyModelSortLocaleAwareCallback)(void* proxy, bool sortLocaleAware);
typedef void (*QSortFilterProxyModelSortRoleCallback)(void* proxy, int sortRole);

void QSortFilterProxyModel_setAutoAcceptChildRowsCallback(void* proxy, QSortFilterProxyModelAutoAcceptChildRowsCallback callback);
void QSortFilterProxyModel_setFilterCaseSensitivityCallback(void* proxy, QSortFilterProxyModelFilterCaseSensitivityCallback callback);
void QSortFilterProxyModel_setFilterRoleCallback(void* proxy, QSortFilterProxyModelFilterRoleCallback callback);
void QSortFilterProxyModel_setRecursiveFilteringEnabledCallback(void* proxy, QSortFilterProxyModelRecursiveFilteringEnabledCallback callback);
void QSortFilterProxyModel_setSortCaseSensitivityCallback(void* proxy, QSortFilterProxyModelSortCaseSensitivityCallback callback);
void QSortFilterProxyModel_setSortLocaleAwareCallback(void* proxy, QSortFilterProxyModelSortLocaleAwareCallback callback);
void QSortFilterProxyModel_setSortRoleCallback(void* proxy, QSortFilterProxyModelSortRoleCallback callback);

// Constants
#define QSORTFILTERPROXYMODEL_CASESENSITIVE 0
#define QSORTFILTERPROXYMODEL_CASEINSENSITIVE 1

#define QSORTFILTERPROXYMODEL_ASCENDING 0
#define QSORTFILTERPROXYMODEL_DESCENDING 1

#ifdef __cplusplus
}
#endif

#endif // QSORTFILTERPROXYMODEL_C_H 