#include "qt6.h"
#include <stdio.h>

void printColorSpaceInfo(void* colorSpace) {
    if (!QColorSpace_isValid(colorSpace)) {
        printf("ColorSpace is not valid\n");
        return;
    }
    
    // 色空間の基本情報を表示
    const char* desc = QColorSpace_description(colorSpace);
    printf("Description: %s\n", desc ? desc : "None");
    
    // カラーモデルを表示
    int colorModel = QColorSpace_colorModel(colorSpace);
    printf("Color Model: ");
    switch (colorModel) {
        case QCOLORSPACE_COLOR_MODEL_UNDEFINED:
            printf("Undefined\n");
            break;
        case QCOLORSPACE_COLOR_MODEL_RGB:
            printf("RGB\n");
            break;
        case QCOLORSPACE_COLOR_MODEL_GRAY:
            printf("Gray\n");
            break;
        case QCOLORSPACE_COLOR_MODEL_CMYK:
            printf("CMYK\n");
            break;
        default:
            printf("Unknown (%d)\n", colorModel);
    }
    
    // プライマリを表示
    int primaries = QColorSpace_primaries(colorSpace);
    printf("Primaries: ");
    switch (primaries) {
        case QCOLORSPACE_PRIMARIES_CUSTOM:
            printf("Custom\n");
            break;
        case QCOLORSPACE_PRIMARIES_SRGB:
            printf("sRGB\n");
            break;
        case QCOLORSPACE_PRIMARIES_ADOBE_RGB:
            printf("Adobe RGB\n");
            break;
        case QCOLORSPACE_PRIMARIES_DCI_P3_D65:
            printf("DCI-P3 (D65)\n");
            break;
        case QCOLORSPACE_PRIMARIES_PRO_PHOTO_RGB:
            printf("ProPhoto RGB\n");
            break;
        case QCOLORSPACE_PRIMARIES_BT2020:
            printf("BT.2020\n");
            break;
        default:
            printf("Unknown (%d)\n", primaries);
    }
    
    // 転送関数を表示
    int transferFunction = QColorSpace_transferFunction(colorSpace);
    printf("Transfer Function: ");
    switch (transferFunction) {
        case QCOLORSPACE_TRANSFER_FUNCTION_CUSTOM:
            printf("Custom\n");
            break;
        case QCOLORSPACE_TRANSFER_FUNCTION_LINEAR:
            printf("Linear\n");
            break;
        case QCOLORSPACE_TRANSFER_FUNCTION_GAMMA:
            printf("Gamma\n");
            break;
        case QCOLORSPACE_TRANSFER_FUNCTION_SRGB:
            printf("sRGB\n");
            break;
        case QCOLORSPACE_TRANSFER_FUNCTION_PRO_PHOTO_RGB:
            printf("ProPhoto RGB\n");
            break;
        case QCOLORSPACE_TRANSFER_FUNCTION_PQ:
            printf("PQ\n");
            break;
        case QCOLORSPACE_TRANSFER_FUNCTION_HLG:
            printf("HLG\n");
            break;
        default:
            printf("Unknown (%d)\n", transferFunction);
    }
    
    // ガンマ値を表示
    float gamma = QColorSpace_gamma(colorSpace);
    printf("Gamma: %.2f\n", gamma);
    
    // ホワイトポイントを表示
    float x, y;
    QColorSpace_whitePoint(colorSpace, &x, &y);
    printf("White Point: (%.4f, %.4f)\n", x, y);
    
    // 変換モデルを表示
    int transformModel = QColorSpace_transformModel(colorSpace);
    printf("Transform Model: ");
    switch (transformModel) {
        case QCOLORSPACE_TRANSFORM_MODEL_THREE_COMPONENT_MATRIX:
            printf("Three Component Matrix\n");
            break;
        case QCOLORSPACE_TRANSFORM_MODEL_ELEMENT_LIST_PROCESSING:
            printf("Element List Processing\n");
            break;
        default:
            printf("Unknown (%d)\n", transformModel);
    }
    
    printf("\n");
}

int main(int argc, char *argv[]) {
    // QApplicationの作成
    void* app = QApplication_create(argc, argv);
    
    printf("=== QColorSpace Example ===\n\n");
    
    // 1. デフォルトの色空間（sRGB）を作成
    void* srgbColorSpace = QColorSpace_create();
    printf("Default ColorSpace (sRGB):\n");
    printColorSpaceInfo(srgbColorSpace);
    
    // 2. 名前付き色空間を作成
    void* adobeRgbColorSpace = QColorSpace_createFromNamedColorSpace(QCOLORSPACE_ADOBE_RGB);
    printf("Adobe RGB ColorSpace:\n");
    printColorSpaceInfo(adobeRgbColorSpace);
    
    // 3. プライマリとガンマ値から色空間を作成
    void* customGammaColorSpace = QColorSpace_createFromPrimariesAndGamma(QCOLORSPACE_PRIMARIES_SRGB, 2.2f);
    printf("Custom Gamma ColorSpace:\n");
    printColorSpaceInfo(customGammaColorSpace);
    
    // 4. プライマリと転送関数から色空間を作成
    void* customTransferColorSpace = QColorSpace_createFromPrimariesAndTransferFunction(
        QCOLORSPACE_PRIMARIES_PRO_PHOTO_RGB, 
        QCOLORSPACE_TRANSFER_FUNCTION_LINEAR, 
        0.0f);
    printf("Custom Transfer Function ColorSpace:\n");
    printColorSpaceInfo(customTransferColorSpace);
    
    // 5. 色空間の説明を設定
    QColorSpace_setDescription(customTransferColorSpace, "My Custom ProPhoto RGB Linear");
    printf("After setting description:\n");
    printColorSpaceInfo(customTransferColorSpace);
    
    // 6. 色空間変換を作成
    void* transform = QColorSpace_transformationToColorSpace(srgbColorSpace, adobeRgbColorSpace);
    if (transform) {
        printf("Created color transformation from sRGB to Adobe RGB\n\n");
        QColorTransform_delete(transform);
    }
    
    // クリーンアップ
    QColorSpace_delete(srgbColorSpace);
    QColorSpace_delete(adobeRgbColorSpace);
    QColorSpace_delete(customGammaColorSpace);
    QColorSpace_delete(customTransferColorSpace);
    
    QApplication_delete(app);
    
    return 0;
}
