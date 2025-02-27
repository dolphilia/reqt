#include "QColorSpaceBind.h"

extern "C" {

// コンストラクタ
void* QColorSpace_create() {
    return QColorSpaceBind::create();
}

void* QColorSpace_createFromNamedColorSpace(int namedColorSpace) {
    return QColorSpaceBind::createFromNamedColorSpace(namedColorSpace);
}

void* QColorSpace_createFromPrimariesAndGamma(int primaries, float gamma) {
    return QColorSpaceBind::createFromPrimariesAndGamma(primaries, gamma);
}

void* QColorSpace_createFromPrimariesAndTransferFunction(int primaries, int transferFunction, float gamma) {
    return QColorSpaceBind::createFromPrimariesAndTransferFunction(primaries, transferFunction, gamma);
}

void* QColorSpace_createFromWhitePointAndTransferFunction(float whitePointX, float whitePointY, int transferFunction, float gamma) {
    return QColorSpaceBind::createFromWhitePointAndTransferFunction(whitePointX, whitePointY, transferFunction, gamma);
}

void* QColorSpace_createFromPoints(float whitePointX, float whitePointY, 
                                 float redPointX, float redPointY, 
                                 float greenPointX, float greenPointY, 
                                 float bluePointX, float bluePointY, 
                                 int transferFunction, float gamma) {
    return QColorSpaceBind::createFromPoints(whitePointX, whitePointY, 
                                           redPointX, redPointY, 
                                           greenPointX, greenPointY, 
                                           bluePointX, bluePointY, 
                                           transferFunction, gamma);
}

void* QColorSpace_createFromIccProfile(const char* iccProfile, int size) {
    return QColorSpaceBind::createFromIccProfile(iccProfile, size);
}

// デストラクタ
void QColorSpace_delete(void* colorSpace) {
    QColorSpaceBind::destroy(static_cast<QColorSpace*>(colorSpace));
}

// プロパティ取得
int QColorSpace_colorModel(void* colorSpace) {
    return QColorSpaceBind::colorModel(static_cast<QColorSpace*>(colorSpace));
}

const char* QColorSpace_description(void* colorSpace) {
    return QColorSpaceBind::description(static_cast<QColorSpace*>(colorSpace));
}

float QColorSpace_gamma(void* colorSpace) {
    return QColorSpaceBind::gamma(static_cast<QColorSpace*>(colorSpace));
}

const char* QColorSpace_iccProfile(void* colorSpace, int* size) {
    return QColorSpaceBind::iccProfile(static_cast<QColorSpace*>(colorSpace), size);
}

bool QColorSpace_isValid(void* colorSpace) {
    return QColorSpaceBind::isValid(static_cast<QColorSpace*>(colorSpace));
}

bool QColorSpace_isValidTarget(void* colorSpace) {
    return QColorSpaceBind::isValidTarget(static_cast<QColorSpace*>(colorSpace));
}

int QColorSpace_primaries(void* colorSpace) {
    return QColorSpaceBind::primaries(static_cast<QColorSpace*>(colorSpace));
}

void QColorSpace_whitePoint(void* colorSpace, float* x, float* y) {
    QColorSpaceBind::whitePoint(static_cast<QColorSpace*>(colorSpace), x, y);
}

int QColorSpace_transferFunction(void* colorSpace) {
    return QColorSpaceBind::transferFunction(static_cast<QColorSpace*>(colorSpace));
}

int QColorSpace_transformModel(void* colorSpace) {
    return QColorSpaceBind::transformModel(static_cast<QColorSpace*>(colorSpace));
}

// プロパティ設定
void QColorSpace_setDescription(void* colorSpace, const char* description) {
    QColorSpaceBind::setDescription(static_cast<QColorSpace*>(colorSpace), description);
}

void QColorSpace_setPrimaries(void* colorSpace, int primariesId) {
    QColorSpaceBind::setPrimaries(static_cast<QColorSpace*>(colorSpace), primariesId);
}

void QColorSpace_setPrimariesFromPoints(void* colorSpace, 
                                      float whitePointX, float whitePointY, 
                                      float redPointX, float redPointY, 
                                      float greenPointX, float greenPointY, 
                                      float bluePointX, float bluePointY) {
    QColorSpaceBind::setPrimariesFromPoints(static_cast<QColorSpace*>(colorSpace), 
                                          whitePointX, whitePointY, 
                                          redPointX, redPointY, 
                                          greenPointX, greenPointY, 
                                          bluePointX, bluePointY);
}

void QColorSpace_setTransferFunction(void* colorSpace, int transferFunction, float gamma) {
    QColorSpaceBind::setTransferFunction(static_cast<QColorSpace*>(colorSpace), transferFunction, gamma);
}

void QColorSpace_setWhitePoint(void* colorSpace, float x, float y) {
    QColorSpaceBind::setWhitePoint(static_cast<QColorSpace*>(colorSpace), x, y);
}

// 変換
void* QColorSpace_transformationToColorSpace(void* source, void* target) {
    return QColorSpaceBind::transformationToColorSpace(static_cast<QColorSpace*>(source), static_cast<QColorSpace*>(target));
}

// QColorTransformの削除
void QColorTransform_delete(void* transform) {
    if (transform) {
        delete static_cast<QColorTransform*>(transform);
    }
}

}
