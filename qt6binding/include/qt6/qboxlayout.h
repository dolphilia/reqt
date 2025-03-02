#ifndef QT_QBOXLAYOUT_H
#define QT_QBOXLAYOUT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief レイアウトの方向を指定する列挙型
 */
enum QBoxLayoutDirection {
    QBoxLayout_LeftToRight = 0,  /**< 左から右へ */
    QBoxLayout_RightToLeft = 1,  /**< 右から左へ */
    QBoxLayout_TopToBottom = 2,  /**< 上から下へ */
    QBoxLayout_BottomToTop = 3   /**< 下から上へ */
};

/**
 * @brief QBoxLayoutを作成する
 * @param direction レイアウトの方向
 * @param parent 親ウィジェット（NULLの場合もある）
 * @return 作成されたQBoxLayoutのポインタ
 */
void* QBoxLayout_create(int direction, void* parent);

/**
 * @brief QBoxLayoutを削除する
 * @param layout 削除するレイアウト
 */
void QBoxLayout_delete(void* layout);

/**
 * @brief サブレイアウトを追加する
 * @param layout 親レイアウト
 * @param sublayout 追加するサブレイアウト
 * @param stretch ストレッチファクター
 */
void QBoxLayout_addLayout(void* layout, void* sublayout, int stretch);

/**
 * @brief 指定位置にサブレイアウトを挿入する
 * @param layout 親レイアウト
 * @param index 挿入位置
 * @param sublayout 挿入するサブレイアウト
 * @param stretch ストレッチファクター
 */
void QBoxLayout_insertLayout(void* layout, int index, void* sublayout, int stretch);

/**
 * @brief ウィジェットを追加する
 * @param layout レイアウト
 * @param widget 追加するウィジェット
 * @param stretch ストレッチファクター
 * @param alignment 配置フラグ
 */
void QBoxLayout_addWidget(void* layout, void* widget, int stretch, int alignment);

/**
 * @brief 指定位置にウィジェットを挿入する
 * @param layout レイアウト
 * @param index 挿入位置
 * @param widget 挿入するウィジェット
 * @param stretch ストレッチファクター
 * @param alignment 配置フラグ
 */
void QBoxLayout_insertWidget(void* layout, int index, void* widget, int stretch, int alignment);

/**
 * @brief 固定サイズのスペースを追加する
 * @param layout レイアウト
 * @param size スペースのサイズ（ピクセル）
 */
void QBoxLayout_addSpacing(void* layout, int size);

/**
 * @brief 伸縮可能なスペースを追加する
 * @param layout レイアウト
 * @param stretch ストレッチファクター
 */
void QBoxLayout_addStretch(void* layout, int stretch);

/**
 * @brief 固定サイズのストラットを追加する
 * @param layout レイアウト
 * @param size ストラットのサイズ（ピクセル）
 */
void QBoxLayout_addStrut(void* layout, int size);

/**
 * @brief 指定位置に固定サイズのスペースを挿入する
 * @param layout レイアウト
 * @param index 挿入位置
 * @param size スペースのサイズ（ピクセル）
 */
void QBoxLayout_insertSpacing(void* layout, int index, int size);

/**
 * @brief 指定位置に伸縮可能なスペースを挿入する
 * @param layout レイアウト
 * @param index 挿入位置
 * @param stretch ストレッチファクター
 */
void QBoxLayout_insertStretch(void* layout, int index, int stretch);

/**
 * @brief レイアウトの方向を取得する
 * @param layout レイアウト
 * @return レイアウトの方向
 */
int QBoxLayout_direction(void* layout);

/**
 * @brief レイアウトの方向を設定する
 * @param layout レイアウト
 * @param direction 設定する方向
 */
void QBoxLayout_setDirection(void* layout, int direction);

/**
 * @brief アイテムのストレッチファクターを設定する
 * @param layout レイアウト
 * @param index アイテムのインデックス
 * @param stretch ストレッチファクター
 */
void QBoxLayout_setStretch(void* layout, int index, int stretch);

/**
 * @brief ウィジェットのストレッチファクターを設定する
 * @param layout レイアウト
 * @param widget ウィジェット
 * @param stretch ストレッチファクター
 * @return 設定に成功した場合はtrue
 */
bool QBoxLayout_setStretchFactorWidget(void* layout, void* widget, int stretch);

/**
 * @brief サブレイアウトのストレッチファクターを設定する
 * @param layout レイアウト
 * @param sublayout サブレイアウト
 * @param stretch ストレッチファクター
 * @return 設定に成功した場合はtrue
 */
bool QBoxLayout_setStretchFactorLayout(void* layout, void* sublayout, int stretch);

/**
 * @brief アイテムのストレッチファクターを取得する
 * @param layout レイアウト
 * @param index アイテムのインデックス
 * @return ストレッチファクター
 */
int QBoxLayout_stretch(void* layout, int index);

/**
 * @brief レイアウト内のアイテム数を取得する
 * @param layout レイアウト
 * @return アイテム数
 */
int QBoxLayout_count(void* layout);

/**
 * @brief アイテム間のスペースを設定する
 * @param layout レイアウト
 * @param spacing スペースのサイズ（ピクセル）
 */
void QBoxLayout_setSpacing(void* layout, int spacing);

/**
 * @brief アイテム間のスペースを取得する
 * @param layout レイアウト
 * @return スペースのサイズ（ピクセル）
 */
int QBoxLayout_spacing(void* layout);

/**
 * @brief ジオメトリ変更時のコールバックを設定する
 * @param layout レイアウト
 * @param callback コールバック関数
 */
void QBoxLayout_setGeometryChangedCallback(void* layout, void (*callback)());

#ifdef __cplusplus
}
#endif

#endif // QT_QBOXLAYOUT_H
