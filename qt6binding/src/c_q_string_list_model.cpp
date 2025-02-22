#include "bind_q_string_list_model.h"
#include "c_q_string_list_model.h"

extern "C" {

void* QStringListModel_create(void* parent) {
    return QStringListModelBind::create(static_cast<QObject*>(parent));
}

void QStringListModel_delete(void* model) {
    QStringListModelBind::destroy(static_cast<QStringListModel*>(model));
}

void QStringListModel_addItem(void* model, const char* text) {
    QStringListModelBind::addItem(static_cast<QStringListModel*>(model), text);
}

void QStringListModel_removeItem(void* model, int row) {
    QStringListModelBind::removeItem(static_cast<QStringListModel*>(model), row);
}

void QStringListModel_setItem(void* model, int row, const char* text) {
    QStringListModelBind::setItem(static_cast<QStringListModel*>(model), row, text);
}

const char* QStringListModel_item(void* model, int row) {
    return QStringListModelBind::item(static_cast<QStringListModel*>(model), row);
}

int QStringListModel_rowCount(void* model) {
    return QStringListModelBind::rowCount(static_cast<QStringListModel*>(model));
}

void QStringListModel_clear(void* model) {
    QStringListModelBind::clear(static_cast<QStringListModel*>(model));
}

}
