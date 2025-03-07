#ifndef QCOLOR_C_H
#define QCOLOR_C_H

#ifdef __cplusplus
extern "C" {
#endif

//-- Public Functions
void QColor_delete(void* color);
void* QColor_create(); // QColor()
void* QColor_createWithRgb(int color); // QColor(QRgb color)
void* QColor_createWithRgba64(int rgba64); // QColor(QRgba64 rgba64)
void* QColor_createWithString(const char* name); // QColor(const QString &name)
void* QColor_createWithRgba(int r, int g, int b, int a); // QColor(int r, int g, int b, int a = 255)
void* QColor_createWithLatin1StringView(const char* name); // QColor(QLatin1StringView name)
void* QColor_createWithGlobalColor(int color); // QColor(Qt::GlobalColor color)
void* QColor_createWithName(const char* name); // QColor(const char *name)
int QColor_alpha(void* color); // int alpha() const
float QColor_alphaF(void* color); // float alphaF() const
int QColor_black(void* color); // int black() const
float QColor_blackF(void* color); // float blackF() const
int QColor_blue(void* color); // int blue() const
float QColor_blueF(void* color); // float blueF() const
void* QColor_convertTo(void* color, int colorSpec); // QColor convertTo(QColor::Spec colorSpec) const
int QColor_cyan(void* color); // int cyan() const
float QColor_cyanF(void* color); // float cyanF() const
void* QColor_darker(void* color, int factor); // QColor darker(int factor = 200) const
void QColor_getCmyk(void* color, int* c, int* m, int* y, int* k, int* a); // void getCmyk(int *c, int *m, int *y, int *k, int *a = nullptr) const
void getCmykF(void* color, float* c, float* m, float* y, float* k, float* a); // void getCmykF(float *c, float *m, float *y, float *k, float *a = nullptr) const
void QColor_getHsl(void* color, int* h, int* s, int* l, int* a); // void getHsl(int *h, int *s, int *l, int *a = nullptr) const
void QColor_getHslF(void* color, float* h, float* s, float* l, float* a); // void getHslF(float *h, float *s, float *l, float *a = nullptr) const
void QColor_getHsv(void* color, int* h, int* s, int* v, int* a); // void getHsv(int *h, int *s, int *v, int *a = nullptr) const
void QColor_getHsvF(void* color, float* h, float* s, float* v, float* a); // void getHsvF(float *h, float *s, float *v, float *a = nullptr) const
void QColor_getRgb(void* color, int* r, int* g, int* b, int* a); // void getRgb(int *r, int *g, int *b, int *a = nullptr) const
void QColor_getRgbF(void* color, float* r, float* g, float* b, float* a); // void getRgbF(float *r, float *g, float *b, float *a = nullptr) const
int QColor_green(void* color); // int green() const
float QColor_greenF(void* color); // float greenF() const
int QColor_hslHue(void* color); // int hslHue() const
float QColor_hslHueF(void* color); // float hslHueF() const
int QColor_hslSaturation(void* color); // int hslSaturation() const
float QColor_hslSaturationF(void* color); // float hslSaturationF() const
int QColor_hsvHue(void* color); // int hsvHue() const
float QColor_hsvHueF(void* color); // float hsvHueF() const
int QColor_hsvSaturation(void* color); // int hsvSaturation() const
float QColor_hsvSaturationF(void* color); // float hsvSaturationF() const
int QColor_hue(void* color); // int hue() const
float QColor_hueF(void* color); // float hueF() const
bool QColor_isValid(void* color); // bool isValid() const
void* QColor_lighter(void* color, int factor); // QColor lighter(int factor = 150) const
int QColor_lightness(void* color); // int lightness() const
float QColor_lightnessF(void* color); // float lightnessF() const
int QColor_magenta(void* color); // int magenta() const
float QColor_magentaF(void* color); // float magentaF() const
const char* QColor_name(void* color); // QString name(QColor::NameFormat format = HexRgb) const
int QColor_red(void* color); // int red() const
float QColor_redF(void* color); // float redF() const
int QColor_rgb(void* color); // QRgb rgb() const
int QColor_rgba64(void* color); // QRgba64 rgba64() const
int QColor_rgba(void* color); // QRgb rgba() const
int QColor_saturation(void* color); // int saturation() const
float QColor_saturationF(void* color); // float saturationF() const
void QColor_setAlpha(void* color, int alpha); // void setAlpha(int alpha)
void QColor_setAlphaF(void* color, float alpha); // void setAlphaF(float alpha)
void QColor_setBlue(void* color, int blue); // void setBlue(int blue)
void QColor_setBlueF(void* color, float blue); // void setBlueF(float blue)
void QColor_setCmyk(void* color, int c, int m, int y, int k, int a); // void setCmyk(int c, int m, int y, int k, int a = 255)
void QColor_setCmykF(void* color, float c, float m, float y, float k, float a); // void setCmykF(float c, float m, float y, float k, float a = 1.0)
void QColor_setGreen(void* color, int green); // void setGreen(int green)
void QColor_setGreenF(void* color, float green); // void setGreenF(float green)
void QColor_setHsl(void* color, int h, int s, int l, int a); // void setHsl(int h, int s, int l, int a = 255)
void QColor_setHslF(void* color, float h, float s, float l, float a); // void setHslF(float h, float s, float l, float a = 1.0)
void QColor_setHsv(void* color, int h, int s, int v, int a); // void setHsv(int h, int s, int v, int a = 255)
void QColor_setHsvF(void* color, float h, float s, float v, float a); // void setHsvF(float h, float s, float v, float a = 1.0)
void QColor_setRed(void* color, int red); // void setRed(int red)
void QColor_setRedF(void* color, float red); // void setRedF(float red)
void QColor_setRgbByRgba(void* color, int r, int g, int b, int a); // void setRgb(int r, int g, int b, int a = 255)
void QColor_setRgbByInt(void* color, int rgb); // void setRgb(QRgb rgb)
void QColor_setRgba64(void* color, int rgba); // void setRgba64(QRgba64 rgba)
void QColor_setRgbF(void* color, float r, float g, float b, float a); // void setRgbF(float r, float g, float b, float a = 1.0)
void QColor_setRgba(void* color, int rgba); // void setRgba(QRgb rgba)
int QColor_spec(void* color); // QColor::Spec spec() const
void* QColor_toCmyk(void* color); // QColor toCmyk() const
void* QColor_toExtendedRgb(void* color); // QColor toExtendedRgb() const
void* QColor_toHsl(void* color); // QColor toHsl() const
void* QColor_toHsv(void* color); // QColor toHsv() const
void* QColor_toRgb(void* color); // QColor toRgb() const
int QColor_value(void* color); // int value() const
float QColor_valueF(void* color); // float valueF() const
int QColor_yellow(void* color); // int yellow() const
float QColor_yellowF(void* color); // float yellowF() const
void* QColor_operatorQVariant(void* color); // QVariant operator QVariant() const
bool QColor_operatorNotEqual(void* color, void* other); // bool operator!=(const QColor &color) const
void* QColor_operatorAssignGlobalColor(void* color, int globalColor); // QColor & operator=(Qt::GlobalColor color)
bool QColor_operatorEqual(void* color, void* other); // bool operator==(const QColor &color) const
//-- Static Public Members
char** QColor_colorNames(int* count); // QStringList colorNames()
void* QColor_fromCmyk(int c, int m, int y, int k, int a); // QColor fromCmyk(int c, int m, int y, int k, int a = 255)
void* QColor_fromCmykF(float c, float m, float y, float k, float a); // QColor fromCmykF(float c, float m, float y, float k, float a = 1.0)
void* QColor_fromHsl(int h, int s, int l, int a); // QColor fromHsl(int h, int s, int l, int a = 255)
void* QColor_fromHslF(float h, float s, float l, float a); // QColor fromHslF(float h, float s, float l, float a = 1.0)
void* QColor_fromHsv(int h, int s, int v, int a); // QColor fromHsv(int h, int s, int v, int a = 255)
void* QColor_fromHsvF(float h, float s, float v, float a); // QColor fromHsvF(float h, float s, float v, float a = 1.0)
void* QColor_fromRgbByInt(int rgb); // QColor fromRgb(QRgb rgb)
void* QColor_fromRgbByRgba(int r, int g, int b, int a); // QColor fromRgb(int r, int g, int b, int a = 255)
void* QColor_fromRgba64(int rgba64); // QColor fromRgba64(QRgba64 rgba64)
void* QColor_fromRgba64WithUShort(unsigned short r, unsigned short g, unsigned short b, unsigned short a); // QColor fromRgba64(ushort r, ushort g, ushort b, ushort a = USHRT_MAX)
void* QColor_fromRgbF(float r, float g, float b, float a); // QColor fromRgbF(float r, float g, float b, float a = 1.0)
void* QColor_fromRgba(int rgba); // QColor fromRgba(QRgb rgba)
void* QColor_fromString(void* color, const char* name); // (since 6.4) QColor fromString(QAnyStringView name)
bool QColor_isValidColorName(const char* name); // (since 6.4) bool isValidColorName(QAnyStringView name)

#ifdef __cplusplus
}
#endif

#endif // QCOLOR_C_H
