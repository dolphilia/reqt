#include "QSortFilterProxyModelBind.h"
#include <QString>

QSortFilterProxyModel* QSortFilterProxyModelBind::create(QObject* parent) {
    CustomSortFilterProxyModel* proxy = new CustomSortFilterProxyModel(parent);
    QSortFilterProxyModelHandler* handler = new QSortFilterProxyModelHandler(proxy);

    QObject::connect(proxy, &QSortFilterProxyModel::autoAcceptChildRowsChanged,
                    handler, &QSortFilterProxyModelHandler::onAutoAcceptChildRowsChanged);
    QObject::connect(proxy, &QSortFilterProxyModel::filterCaseSensitivityChanged,
                    handler, &QSortFilterProxyModelHandler::onFilterCaseSensitivityChanged);
    QObject::connect(proxy, &QSortFilterProxyModel::filterRoleChanged,
                    handler, &QSortFilterProxyModelHandler::onFilterRoleChanged);
    QObject::connect(proxy, &QSortFilterProxyModel::recursiveFilteringEnabledChanged,
                    handler, &QSortFilterProxyModelHandler::onRecursiveFilteringEnabledChanged);
    QObject::connect(proxy, &QSortFilterProxyModel::sortCaseSensitivityChanged,
                    handler, &QSortFilterProxyModelHandler::onSortCaseSensitivityChanged);
    QObject::connect(proxy, &QSortFilterProxyModel::sortLocaleAwareChanged,
                    handler, &QSortFilterProxyModelHandler::onSortLocaleAwareChanged);
    QObject::connect(proxy, &QSortFilterProxyModel::sortRoleChanged,
                    handler, &QSortFilterProxyModelHandler::onSortRoleChanged);

    return proxy;
}

void QSortFilterProxyModelBind::destroy(QSortFilterProxyModel* proxy) {
    if (proxy) {
        delete proxy;
    }
}

bool QSortFilterProxyModelBind::autoAcceptChildRows(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->autoAcceptChildRows() : false;
}

void QSortFilterProxyModelBind::setAutoAcceptChildRows(QSortFilterProxyModel* proxy, bool accept) {
    if (proxy) {
        proxy->setAutoAcceptChildRows(accept);
    }
}

bool QSortFilterProxyModelBind::dynamicSortFilter(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->dynamicSortFilter() : false;
}

void QSortFilterProxyModelBind::setDynamicSortFilter(QSortFilterProxyModel* proxy, bool enable) {
    if (proxy) {
        proxy->setDynamicSortFilter(enable);
    }
}

int QSortFilterProxyModelBind::filterCaseSensitivity(QSortFilterProxyModel* proxy) {
    return proxy ? static_cast<int>(proxy->filterCaseSensitivity()) : 0;
}

void QSortFilterProxyModelBind::setFilterCaseSensitivity(QSortFilterProxyModel* proxy, int cs) {
    if (proxy) {
        proxy->setFilterCaseSensitivity(static_cast<Qt::CaseSensitivity>(cs));
    }
}

int QSortFilterProxyModelBind::filterKeyColumn(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->filterKeyColumn() : -1;
}

void QSortFilterProxyModelBind::setFilterKeyColumn(QSortFilterProxyModel* proxy, int column) {
    if (proxy) {
        proxy->setFilterKeyColumn(column);
    }
}

int QSortFilterProxyModelBind::filterRole(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->filterRole() : -1;
}

void QSortFilterProxyModelBind::setFilterRole(QSortFilterProxyModel* proxy, int role) {
    if (proxy) {
        proxy->setFilterRole(role);
    }
}

bool QSortFilterProxyModelBind::isRecursiveFilteringEnabled(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->isRecursiveFilteringEnabled() : false;
}

void QSortFilterProxyModelBind::setRecursiveFilteringEnabled(QSortFilterProxyModel* proxy, bool recursive) {
    if (proxy) {
        proxy->setRecursiveFilteringEnabled(recursive);
    }
}

bool QSortFilterProxyModelBind::isSortLocaleAware(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->isSortLocaleAware() : false;
}

void QSortFilterProxyModelBind::setSortLocaleAware(QSortFilterProxyModel* proxy, bool on) {
    if (proxy) {
        proxy->setSortLocaleAware(on);
    }
}

int QSortFilterProxyModelBind::sortCaseSensitivity(QSortFilterProxyModel* proxy) {
    return proxy ? static_cast<int>(proxy->sortCaseSensitivity()) : 0;
}

void QSortFilterProxyModelBind::setSortCaseSensitivity(QSortFilterProxyModel* proxy, int cs) {
    if (proxy) {
        proxy->setSortCaseSensitivity(static_cast<Qt::CaseSensitivity>(cs));
    }
}

int QSortFilterProxyModelBind::sortRole(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->sortRole() : -1;
}

void QSortFilterProxyModelBind::setSortRole(QSortFilterProxyModel* proxy, int role) {
    if (proxy) {
        proxy->setSortRole(role);
    }
}

int QSortFilterProxyModelBind::sortColumn(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->sortColumn() : -1;
}

int QSortFilterProxyModelBind::sortOrder(QSortFilterProxyModel* proxy) {
    return proxy ? static_cast<int>(proxy->sortOrder()) : 0;
}

void QSortFilterProxyModelBind::setFilterFixedString(QSortFilterProxyModel* proxy, const char* pattern) {
    if (proxy && pattern) {
        proxy->setFilterFixedString(QString::fromUtf8(pattern));
    }
}

void QSortFilterProxyModelBind::setFilterWildcard(QSortFilterProxyModel* proxy, const char* pattern) {
    if (proxy && pattern) {
        proxy->setFilterWildcard(QString::fromUtf8(pattern));
    }
}

void QSortFilterProxyModelBind::setFilterRegularExpression(QSortFilterProxyModel* proxy, const char* pattern) {
    if (proxy && pattern) {
        proxy->setFilterRegularExpression(QString::fromUtf8(pattern));
    }
}

void QSortFilterProxyModelBind::sort(QSortFilterProxyModel* proxy, int column, int order) {
    if (proxy) {
        proxy->sort(column, static_cast<Qt::SortOrder>(order));
    }
}

void QSortFilterProxyModelBind::invalidate(QSortFilterProxyModel* proxy) {
    if (proxy) {
        auto customProxy = qobject_cast<CustomSortFilterProxyModel*>(proxy);
        if (customProxy) {
            customProxy->publicInvalidate();
        }
    }
}

void QSortFilterProxyModelBind::invalidateFilter(QSortFilterProxyModel* proxy) {
    if (proxy) {
        auto customProxy = qobject_cast<CustomSortFilterProxyModel*>(proxy);
        if (customProxy) {
            customProxy->publicInvalidateFilter();
        }
    }
}

void QSortFilterProxyModelBind::setSourceModel(QSortFilterProxyModel* proxy, QAbstractItemModel* sourceModel) {
    if (proxy) {
        proxy->setSourceModel(sourceModel);
    }
}

QAbstractItemModel* QSortFilterProxyModelBind::sourceModel(QSortFilterProxyModel* proxy) {
    return proxy ? proxy->sourceModel() : nullptr;
}

void QSortFilterProxyModelBind::setAutoAcceptChildRowsCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelAutoAcceptChildRowsCallback callback) {
    if (proxy) {
        QSortFilterProxyModelHandler* handler = proxy->findChild<QSortFilterProxyModelHandler*>();
        if (handler) {
            handler->setAutoAcceptChildRowsCallback(callback);
        }
    }
}

void QSortFilterProxyModelBind::setFilterCaseSensitivityCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelFilterCaseSensitivityCallback callback) {
    if (proxy) {
        QSortFilterProxyModelHandler* handler = proxy->findChild<QSortFilterProxyModelHandler*>();
        if (handler) {
            handler->setFilterCaseSensitivityCallback(callback);
        }
    }
}

void QSortFilterProxyModelBind::setFilterRoleCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelFilterRoleCallback callback) {
    if (proxy) {
        QSortFilterProxyModelHandler* handler = proxy->findChild<QSortFilterProxyModelHandler*>();
        if (handler) {
            handler->setFilterRoleCallback(callback);
        }
    }
}

void QSortFilterProxyModelBind::setRecursiveFilteringEnabledCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelRecursiveFilteringEnabledCallback callback) {
    if (proxy) {
        QSortFilterProxyModelHandler* handler = proxy->findChild<QSortFilterProxyModelHandler*>();
        if (handler) {
            handler->setRecursiveFilteringEnabledCallback(callback);
        }
    }
}

void QSortFilterProxyModelBind::setSortCaseSensitivityCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelSortCaseSensitivityCallback callback) {
    if (proxy) {
        QSortFilterProxyModelHandler* handler = proxy->findChild<QSortFilterProxyModelHandler*>();
        if (handler) {
            handler->setSortCaseSensitivityCallback(callback);
        }
    }
}

void QSortFilterProxyModelBind::setSortLocaleAwareCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelSortLocaleAwareCallback callback) {
    if (proxy) {
        QSortFilterProxyModelHandler* handler = proxy->findChild<QSortFilterProxyModelHandler*>();
        if (handler) {
            handler->setSortLocaleAwareCallback(callback);
        }
    }
}

void QSortFilterProxyModelBind::setSortRoleCallback(QSortFilterProxyModel* proxy, QSortFilterProxyModelSortRoleCallback callback) {
    if (proxy) {
        QSortFilterProxyModelHandler* handler = proxy->findChild<QSortFilterProxyModelHandler*>();
        if (handler) {
            handler->setSortRoleCallback(callback);
        }
    }
} 