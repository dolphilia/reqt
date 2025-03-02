#ifndef QCOLORSPACE_BIND_H
#define QCOLORSPACE_BIND_H

#include <QColorSpace>
#include <QPointF>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QVariant>

class QColorSpaceBind {
public:
    // コンストラクタ
    static QColorSpace* create();
    static QColorSpace* createFromNamedColorSpace(int namedColorSpace);
    static QColorSpace* createFromPrimariesAndGamma(int primaries, float gamma);
    static QColorSpace* createFromPrimariesAndTransferFunction(int primaries, int transferFunction, float gamma = 0.0f);
    static QColorSpace* createFromWhitePointAndTransferFunction(float whitePointX, float whitePointY, int transferFunction, float gamma = 0.0f);
    static QColorSpace* createFromPoints(float whitePointX, float whitePointY, 
                                        float redPointX, float redPointY, 
                                        float greenPointX, float greenPointY, 
                                        float bluePointX, float bluePointY, 
                                        int transferFunction, float gamma = 0.0f);
    static QColorSpace* createFromIccProfile(const char* iccProfile, int size);
    
    // デストラクタ
    static void destroy(QColorSpace* colorSpace);
    
    // プロパティ取得
    static int colorModel(QColorSpace* colorSpace);
    static const char* description(QColorSpace* colorSpace);
    static float gamma(QColorSpace* colorSpace);
    static const char* iccProfile(QColorSpace* colorSpace, int* size);
    static bool isValid(QColorSpace* colorSpace);
    static bool isValidTarget(QColorSpace* colorSpace);
    static int primaries(QColorSpace* colorSpace);
    static void whitePoint(QColorSpace* colorSpace, float* x, float* y);
    static int transferFunction(QColorSpace* colorSpace);
    static int transformModel(QColorSpace* colorSpace);
    
    // プロパティ設定
    static void setDescription(QColorSpace* colorSpace, const char* description);
    static void setPrimaries(QColorSpace* colorSpace, int primariesId);
    static void setPrimariesFromPoints(QColorSpace* colorSpace, 
                                      float whitePointX, float whitePointY, 
                                      float redPointX, float redPointY, 
                                      float greenPointX, float greenPointY, 
                                      float bluePointX, float bluePointY);
    static void setTransferFunction(QColorSpace* colorSpace, int transferFunction, float gamma = 0.0f);
    static void setWhitePoint(QColorSpace* colorSpace, float x, float y);
    
    // 変換
    static void* transformationToColorSpace(QColorSpace* source, QColorSpace* target);
};

#endif // QCOLORSPACE_BIND_H
