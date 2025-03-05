#ifndef C_Q_GROUP_BOX_H
#define C_Q_GROUP_BOX_H

#ifdef __cplusplus
extern "C" {
#endif

// 作成と削除
void* QGroupBox_create(void* parent);
void* QGroupBox_create_with_title(const char* title, void* parent);
void QGroupBox_delete(void* groupBox);

// プロパティの設定と取得
void QGroupBox_setTitle(void* groupBox, const char* title);
const char* QGroupBox_title(void* groupBox);
void QGroupBox_setAlignment(void* groupBox, int alignment);
void QGroupBox_setFlat(void* groupBox, bool flat);
bool QGroupBox_isFlat(void* groupBox);
void QGroupBox_setCheckable(void* groupBox, bool checkable);
bool QGroupBox_isCheckable(void* groupBox);
void QGroupBox_setChecked(void* groupBox, bool checked);
bool QGroupBox_isChecked(void* groupBox);

// ハンドラー関連
typedef void (*QGroupBox_ToggledCallback)(void*, bool);
void QGroupBox_setToggledCallback(void* groupBox, QGroupBox_ToggledCallback callback);

// アライメント定数
#define QGROUPBOX_ALIGN_LEFT 0x0001
#define QGROUPBOX_ALIGN_RIGHT 0x0002
#define QGROUPBOX_ALIGN_HCENTER 0x0004
#define QGROUPBOX_ALIGN_TOP 0x0020
#define QGROUPBOX_ALIGN_BOTTOM 0x0040
#define QGROUPBOX_ALIGN_VCENTER 0x0080
#define QGROUPBOX_ALIGN_CENTER 0x0084

#ifdef __cplusplus
}
#endif

#endif // C_Q_GROUP_BOX_H
