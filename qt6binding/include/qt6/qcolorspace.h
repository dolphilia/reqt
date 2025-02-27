#ifndef QCOLORSPACE_C_H
#define QCOLORSPACE_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QColorSpace ColorModel
#define QCOLORSPACE_COLOR_MODEL_UNDEFINED 0
#define QCOLORSPACE_COLOR_MODEL_RGB 1
#define QCOLORSPACE_COLOR_MODEL_GRAY 2
#define QCOLORSPACE_COLOR_MODEL_CMYK 3

// QColorSpace NamedColorSpace
#define QCOLORSPACE_SRGB 0
#define QCOLORSPACE_SRGB_LINEAR 1
#define QCOLORSPACE_ADOBE_RGB 2
#define QCOLORSPACE_DISPLAY_P3 3
#define QCOLORSPACE_PRO_PHOTO_RGB 4
#define QCOLORSPACE_BT709 5
#define QCOLORSPACE_BT2020 6
#define QCOLORSPACE_BT2100_PQ 7
#define QCOLORSPACE_BT2100_HLG 8

// QColorSpace Primaries
#define QCOLORSPACE_PRIMARIES_CUSTOM 0
#define QCOLORSPACE_PRIMARIES_SRGB 1
#define QCOLORSPACE_PRIMARIES_ADOBE_RGB 2
#define QCOLORSPACE_PRIMARIES_DCI_P3_D65 3
#define QCOLORSPACE_PRIMARIES_PRO_PHOTO_RGB 4
#define QCOLORSPACE_PRIMARIES_BT2020 5

// QColorSpace TransferFunction
#define QCOLORSPACE_TRANSFER_FUNCTION_CUSTOM 0
#define QCOLORSPACE_TRANSFER_FUNCTION_LINEAR 1
#define QCOLORSPACE_TRANSFER_FUNCTION_GAMMA 2
#define QCOLORSPACE_TRANSFER_FUNCTION_SRGB 3
#define QCOLORSPACE_TRANSFER_FUNCTION_PRO_PHOTO_RGB 4
#define QCOLORSPACE_TRANSFER_FUNCTION_PQ 5
#define QCOLORSPACE_TRANSFER_FUNCTION_HLG 6

// QColorSpace TransformModel
#define QCOLORSPACE_TRANSFORM_MODEL_THREE_COMPONENT_MATRIX 0
#define QCOLORSPACE_TRANSFORM_MODEL_ELEMENT_LIST_PROCESSING 1

// コンストラクタ
void* QColorSpace_create();
void* QColorSpace_createFromNamedColorSpace(int namedColorSpace);
void* QColorSpace_createFromPrimariesAndGamma(int primaries, float gamma);
void* QColorSpace_createFromPrimariesAndTransferFunction(int primaries, int transferFunction, float gamma);
void* QColorSpace_createFromWhitePointAndTransferFunction(float whitePointX, float whitePointY, int transferFunction, float gamma);
void* QColorSpace_createFromPoints(float whitePointX, float whitePointY, 
                                 float redPointX, float redPointY, 
                                 float greenPointX, float greenPointY, 
                                 float bluePointX, float bluePointY, 
                                 int transferFunction, float gamma);
void* QColorSpace_createFromIccProfile(const char* iccProfile, int size);

// デストラクタ
void QColorSpace_delete(void* colorSpace);

// プロパティ取得
int QColorSpace_colorModel(void* colorSpace);
const char* QColorSpace_description(void* colorSpace);
float QColorSpace_gamma(void* colorSpace);
const char* QColorSpace_iccProfile(void* colorSpace, int* size);
bool QColorSpace_isValid(void* colorSpace);
bool QColorSpace_isValidTarget(void* colorSpace);
int QColorSpace_primaries(void* colorSpace);
void QColorSpace_whitePoint(void* colorSpace, float* x, float* y);
int QColorSpace_transferFunction(void* colorSpace);
int QColorSpace_transformModel(void* colorSpace);

// プロパティ設定
void QColorSpace_setDescription(void* colorSpace, const char* description);
void QColorSpace_setPrimaries(void* colorSpace, int primariesId);
void QColorSpace_setPrimariesFromPoints(void* colorSpace, 
                                      float whitePointX, float whitePointY, 
                                      float redPointX, float redPointY, 
                                      float greenPointX, float greenPointY, 
                                      float bluePointX, float bluePointY);
void QColorSpace_setTransferFunction(void* colorSpace, int transferFunction, float gamma);
void QColorSpace_setWhitePoint(void* colorSpace, float x, float y);

// 変換
void* QColorSpace_transformationToColorSpace(void* source, void* target);
void QColorTransform_delete(void* transform);

#ifdef __cplusplus
}
#endif

#endif // QCOLORSPACE_C_H
