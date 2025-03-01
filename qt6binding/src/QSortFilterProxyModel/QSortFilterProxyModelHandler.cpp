#include "QSortFilterProxyModelHandler.h"

QSortFilterProxyModelHandler::QSortFilterProxyModelHandler(QObject* parent)
    : QObject(parent)
    , autoAcceptChildRowsCallback(nullptr)
    , filterCaseSensitivityCallback(nullptr)
    , filterRoleCallback(nullptr)
    , recursiveFilteringEnabledCallback(nullptr)
    , sortCaseSensitivityCallback(nullptr)
    , sortLocaleAwareCallback(nullptr)
    , sortRoleCallback(nullptr)
{
}

void QSortFilterProxyModelHandler::setAutoAcceptChildRowsCallback(QSortFilterProxyModelAutoAcceptChildRowsCallback callback) {
    autoAcceptChildRowsCallback = callback;
}

void QSortFilterProxyModelHandler::setFilterCaseSensitivityCallback(QSortFilterProxyModelFilterCaseSensitivityCallback callback) {
    filterCaseSensitivityCallback = callback;
}

void QSortFilterProxyModelHandler::setFilterRoleCallback(QSortFilterProxyModelFilterRoleCallback callback) {
    filterRoleCallback = callback;
}

void QSortFilterProxyModelHandler::setRecursiveFilteringEnabledCallback(QSortFilterProxyModelRecursiveFilteringEnabledCallback callback) {
    recursiveFilteringEnabledCallback = callback;
}

void QSortFilterProxyModelHandler::setSortCaseSensitivityCallback(QSortFilterProxyModelSortCaseSensitivityCallback callback) {
    sortCaseSensitivityCallback = callback;
}

void QSortFilterProxyModelHandler::setSortLocaleAwareCallback(QSortFilterProxyModelSortLocaleAwareCallback callback) {
    sortLocaleAwareCallback = callback;
}

void QSortFilterProxyModelHandler::setSortRoleCallback(QSortFilterProxyModelSortRoleCallback callback) {
    sortRoleCallback = callback;
}

void QSortFilterProxyModelHandler::onAutoAcceptChildRowsChanged(bool autoAcceptChildRows) {
    if (autoAcceptChildRowsCallback) {
        autoAcceptChildRowsCallback(parent(), autoAcceptChildRows);
    }
}

void QSortFilterProxyModelHandler::onFilterCaseSensitivityChanged(Qt::CaseSensitivity filterCaseSensitivity) {
    if (filterCaseSensitivityCallback) {
        filterCaseSensitivityCallback(parent(), static_cast<int>(filterCaseSensitivity));
    }
}

void QSortFilterProxyModelHandler::onFilterRoleChanged(int filterRole) {
    if (filterRoleCallback) {
        filterRoleCallback(parent(), filterRole);
    }
}

void QSortFilterProxyModelHandler::onRecursiveFilteringEnabledChanged(bool recursiveFilteringEnabled) {
    if (recursiveFilteringEnabledCallback) {
        recursiveFilteringEnabledCallback(parent(), recursiveFilteringEnabled);
    }
}

void QSortFilterProxyModelHandler::onSortCaseSensitivityChanged(Qt::CaseSensitivity sortCaseSensitivity) {
    if (sortCaseSensitivityCallback) {
        sortCaseSensitivityCallback(parent(), static_cast<int>(sortCaseSensitivity));
    }
}

void QSortFilterProxyModelHandler::onSortLocaleAwareChanged(bool sortLocaleAware) {
    if (sortLocaleAwareCallback) {
        sortLocaleAwareCallback(parent(), sortLocaleAware);
    }
}

void QSortFilterProxyModelHandler::onSortRoleChanged(int sortRole) {
    if (sortRoleCallback) {
        sortRoleCallback(parent(), sortRole);
    }
} 