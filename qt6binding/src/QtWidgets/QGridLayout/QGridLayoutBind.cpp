#include "QGridLayoutBind.h"
#include "QGridLayoutHandler.h"

QGridLayoutBind::QGridLayoutBind(QWidget* parent)
    : QGridLayout(parent)
    , handler(new QGridLayoutHandler(this)) {
    // QGridLayoutには標準でシグナルがないため、必要に応じてカスタムシグナルを実装できます
    // 例: QComboBoxのように、以下のようにシグナルを接続します
    // connect(this, &QGridLayout::customSignal, handler, &GridLayoutHandler::onCellEmptyChanged);
}

QGridLayoutBind::~QGridLayoutBind() {
    delete handler;
}

void QGridLayoutBind::addWidgetToGrid(QWidget* widget, int row, int column) {
    addWidget(widget, row, column);
}

void QGridLayoutBind::setCellEmptyChangedCallback(QGridLayout_CellEmptyChangedCallback callback) const {
    handler->setCellEmptyChangedCallback(callback);
}
