// #include "qcolor.h"
#include "QColorBind.h"
#include <QVariant>

extern "C" {

//-- Public Functions

void QColor_delete(void* color) {
    delete static_cast<BindQColor*>(color);
}

// QColor()

void* QColor_create() {
    return new BindQColor();
}

// QColor(QRgb color)

void* QColor_createWithRgb(int color) {
    return new BindQColor(color);
}

// QColor(QRgba64 rgba64)

void* QColor_createWithRgba64(int rgba64) {
    return new BindQColor(rgba64);
}

// QColor(const QString &name)

void* QColor_createWithString(const char* name) {
    return new BindQColor(QString::fromUtf8(name));
}

// QColor(int r, int g, int b, int a = 255)

void* QColor_createWithRgba(int r, int g, int b, int a) {
    return new BindQColor(r, g, b, a);
}

// QColor(QLatin1StringView name)

void* QColor_createWithLatin1StringView(const char* name) {
    return new BindQColor(QLatin1StringView(name));
}

// QColor(Qt::GlobalColor color)

void* QColor_createWithGlobalColor(int color) {
    return new BindQColor(static_cast<Qt::GlobalColor>(color));
}

// QColor(const char *name)

void* QColor_createWithName(const char* name) {
    return new BindQColor(QString::fromUtf8(name));
}

// int alpha() const

int QColor_alpha(void* color) {
    return static_cast<BindQColor*>(color)->alpha();
}

// float alphaF() const

float QColor_alphaF(void* color) {
    return static_cast<BindQColor*>(color)->alphaF();
}

// int black() const

int QColor_black(void* color) {
    return static_cast<BindQColor*>(color)->black();
}

// float blackF() const

float QColor_blackF(void* color) {
    return static_cast<BindQColor*>(color)->blackF();
}

// int blue() const

int QColor_blue(void* color) {
    return static_cast<BindQColor*>(color)->blue();
}

// float blueF() const

float QColor_blueF(void* color) {
    return static_cast<BindQColor*>(color)->blueF();
}

// QColor convertTo(QColor::Spec colorSpec) const

void* QColor_convertTo(void* color, int colorSpec) {
    QColor convertTo = static_cast<BindQColor*>(color)->convertTo(static_cast<QColor::Spec>(colorSpec));
    return new BindQColor(convertTo.red(), convertTo.green(), convertTo.blue(), convertTo.alpha());
}

// int cyan() const

int QColor_cyan(void* color) {
    return static_cast<BindQColor*>(color)->cyan();
}

// float cyanF() const

float QColor_cyanF(void* color) {
    return static_cast<BindQColor*>(color)->cyanF();
}

// QColor darker(int factor = 200) const

void* QColor_darker(void* color, int factor) {
    QColor darker = static_cast<BindQColor*>(color)->darker(factor);
    return new BindQColor(darker.red(), darker.green(), darker.blue(), darker.alpha());
}


// void getCmyk(int *c, int *m, int *y, int *k, int *a = nullptr) const

void QColor_getCmyk(void* color, int* c, int* m, int* y, int* k, int* a) {
    static_cast<BindQColor*>(color)->getCmyk(c, m, y, k, a);
}

// void getCmykF(float *c, float *m, float *y, float *k, float *a = nullptr) const

void getCmykF(void* color, float* c, float* m, float* y, float* k, float* a) {
    static_cast<BindQColor*>(color)->getCmykF(c, m, y, k, a);
}

// void getHsl(int *h, int *s, int *l, int *a = nullptr) const

void QColor_getHsl(void* color, int* h, int* s, int* l, int* a) {
    static_cast<BindQColor*>(color)->getHsl(h, s, l, a);
}

// void getHslF(float *h, float *s, float *l, float *a = nullptr) const

void QColor_getHslF(void* color, float* h, float* s, float* l, float* a) {
    static_cast<BindQColor*>(color)->getHslF(h, s, l, a);
}

// void getHsv(int *h, int *s, int *v, int *a = nullptr) const

void QColor_getHsv(void* color, int* h, int* s, int* v, int* a) {
    static_cast<BindQColor*>(color)->getHsv(h, s, v, a);
}

// void getHsvF(float *h, float *s, float *v, float *a = nullptr) const

void QColor_getHsvF(void* color, float* h, float* s, float* v, float* a) {
    static_cast<BindQColor*>(color)->getHsvF(h, s, v, a);
}

// void getRgb(int *r, int *g, int *b, int *a = nullptr) const

void QColor_getRgb(void* color, int* r, int* g, int* b, int* a) {
    static_cast<BindQColor*>(color)->getRgb(r, g, b, a);
}

// void getRgbF(float *r, float *g, float *b, float *a = nullptr) const

void QColor_getRgbF(void* color, float* r, float* g, float* b, float* a) {
    static_cast<BindQColor*>(color)->getRgbF(r, g, b, a);
}

// int green() const

int QColor_green(void* color) {
    return static_cast<BindQColor*>(color)->green();
}

// float greenF() const

float QColor_greenF(void* color) {
    return static_cast<BindQColor*>(color)->greenF();
}

// int hslHue() const

int QColor_hslHue(void* color) {
    return static_cast<BindQColor*>(color)->hslHue();
}

// float hslHueF() const

float QColor_hslHueF(void* color) {
    return static_cast<BindQColor*>(color)->hslHueF();
}

// int hslSaturation() const

int QColor_hslSaturation(void* color) {
    return static_cast<BindQColor*>(color)->hslSaturation();
}

// float hslSaturationF() const

float QColor_hslSaturationF(void* color) {
    return static_cast<BindQColor*>(color)->hslSaturationF();
}

// int hsvHue() const

int QColor_hsvHue(void* color) {
    return static_cast<BindQColor*>(color)->hsvHue();
}

// float hsvHueF() const

float QColor_hsvHueF(void* color) {
    return static_cast<BindQColor*>(color)->hsvHueF();
}

// int hsvSaturation() const

int QColor_hsvSaturation(void* color) {
    return static_cast<BindQColor*>(color)->hsvSaturation();
}

// float hsvSaturationF() const

float QColor_hsvSaturationF(void* color) {
    return static_cast<BindQColor*>(color)->hsvSaturationF();
}

// int hue() const

int QColor_hue(void* color) {
    return static_cast<BindQColor*>(color)->hue();
}

// float hueF() const

float QColor_hueF(void* color) {
    return static_cast<BindQColor*>(color)->hueF();
}

// bool isValid() const

bool QColor_isValid(void* color) {
    return static_cast<BindQColor*>(color)->isValid();
}

// QColor lighter(int factor = 150) const

void* QColor_lighter(void* color, int factor) {
    QColor lighter = static_cast<BindQColor*>(color)->lighter(factor);
    return new BindQColor(lighter.red(), lighter.green(), lighter.blue(), lighter.alpha());
}

// int lightness() const

int QColor_lightness(void* color) {
    return static_cast<BindQColor*>(color)->lightness();
}

// float lightnessF() const

float QColor_lightnessF(void* color) {
    return static_cast<BindQColor*>(color)->lightnessF();
}

// int magenta() const

int QColor_magenta(void* color) {
    return static_cast<BindQColor*>(color)->magenta();
}

// float magentaF() const

float QColor_magentaF(void* color) {
    return static_cast<BindQColor*>(color)->magentaF();
}

// QString name(QColor::NameFormat format = HexRgb) const

const char* QColor_name(void* color) {
    static QString name;
    name = static_cast<BindQColor*>(color)->name();
    return name.toUtf8().constData();
}

// int red() const

int QColor_red(void* color) {
    return static_cast<BindQColor*>(color)->red();
}

// float redF() const

float QColor_redF(void* color) {
    return static_cast<BindQColor*>(color)->redF();
}

// QRgb rgb() const

int QColor_rgb(void* color) {
    return static_cast<BindQColor*>(color)->rgb();
}

// QRgba64 rgba64() const

int QColor_rgba64(void* color) {
    return static_cast<BindQColor*>(color)->rgba64();
}

// QRgb rgba() const

int QColor_rgba(void* color) {
    return static_cast<BindQColor*>(color)->rgba();
}

// int saturation() const

int QColor_saturation(void* color) {
    return static_cast<BindQColor*>(color)->saturation();
}

// float saturationF() const

float QColor_saturationF(void* color) {
    return static_cast<BindQColor*>(color)->saturationF();
}

// void setAlpha(int alpha)

void QColor_setAlpha(void* color, int alpha) {
    static_cast<BindQColor*>(color)->setAlpha(alpha);
}

// void setAlphaF(float alpha)

void QColor_setAlphaF(void* color, float alpha) {
    static_cast<BindQColor*>(color)->setAlphaF(alpha);
}

// void setBlue(int blue)

void QColor_setBlue(void* color, int blue) {
    static_cast<BindQColor*>(color)->setBlue(blue);
}

// void setBlueF(float blue)

void QColor_setBlueF(void* color, float blue) {
    static_cast<BindQColor*>(color)->setBlueF(blue);
}

// void setCmyk(int c, int m, int y, int k, int a = 255)

void QColor_setCmyk(void* color, int c, int m, int y, int k, int a) {
    static_cast<BindQColor*>(color)->setCmyk(c, m, y, k, a);
}

// void setCmykF(float c, float m, float y, float k, float a = 1.0)

void QColor_setCmykF(void* color, float c, float m, float y, float k, float a) {
    static_cast<BindQColor*>(color)->setCmykF(c, m, y, k, a);
}

// void setGreen(int green)

void QColor_setGreen(void* color, int green) {
    static_cast<BindQColor*>(color)->setGreen(green);
}

// void setGreenF(float green)

void QColor_setGreenF(void* color, float green) {
    static_cast<BindQColor*>(color)->setGreenF(green);
}

// void setHsl(int h, int s, int l, int a = 255)

void QColor_setHsl(void* color, int h, int s, int l, int a) {
    static_cast<BindQColor*>(color)->setHsl(h, s, l, a);
}

// void setHslF(float h, float s, float l, float a = 1.0)

void QColor_setHslF(void* color, float h, float s, float l, float a) {
    static_cast<BindQColor*>(color)->setHslF(h, s, l, a);
}

// void setHsv(int h, int s, int v, int a = 255)

void QColor_setHsv(void* color, int h, int s, int v, int a) {
    static_cast<BindQColor*>(color)->setHsv(h, s, v, a);
}

// void setHsvF(float h, float s, float v, float a = 1.0)

void QColor_setHsvF(void* color, float h, float s, float v, float a) {
    static_cast<BindQColor*>(color)->setHsvF(h, s, v, a);
}

// void setRed(int red)

void QColor_setRed(void* color, int red) {
    static_cast<BindQColor*>(color)->setRed(red);
}

// void setRedF(float red)

void QColor_setRedF(void* color, float red) {
    static_cast<BindQColor*>(color)->setRedF(red);
}

// void setRgb(int r, int g, int b, int a = 255)

void QColor_setRgbByRgba(void* color, int r, int g, int b, int a) {
    static_cast<BindQColor*>(color)->setRgb(r, g, b, a);
}

// void setRgb(QRgb rgb)

void QColor_setRgbByInt(void* color, int rgb) {
    static_cast<BindQColor*>(color)->setRgb(rgb);
}

// void setRgba64(QRgba64 rgba)

void QColor_setRgba64(void* color, int rgba) {
    static_cast<BindQColor*>(color)->setRgba64(QRgba64::fromRgba64(rgba));
}

// void setRgbF(float r, float g, float b, float a = 1.0)

void QColor_setRgbF(void* color, float r, float g, float b, float a) {
    static_cast<BindQColor*>(color)->setRgbF(r, g, b, a);
}

// void setRgba(QRgb rgba)

void QColor_setRgba(void* color, int rgba) {
    static_cast<BindQColor*>(color)->setRgba(rgba);
}

// QColor::Spec spec() const

int QColor_spec(void* color) {
    return static_cast<BindQColor*>(color)->spec();
}

// QColor toCmyk() const

void* QColor_toCmyk(void* color) {
    QColor toCmyk = static_cast<BindQColor*>(color)->toCmyk();
    return new BindQColor(toCmyk.red(), toCmyk.green(), toCmyk.blue(), toCmyk.alpha());
}

// QColor toExtendedRgb() const

void* QColor_toExtendedRgb(void* color) {
    QColor toExtendedRgb = static_cast<BindQColor*>(color)->toExtendedRgb();
    return new BindQColor(toExtendedRgb.red(), toExtendedRgb.green(), toExtendedRgb.blue(), toExtendedRgb.alpha());
}

// QColor toHsl() const

void* QColor_toHsl(void* color) {
    QColor toHsl = static_cast<BindQColor*>(color)->toHsl();
    return new BindQColor(toHsl.red(), toHsl.green(), toHsl.blue(), toHsl.alpha());
}

// QColor toHsv() const

void* QColor_toHsv(void* color) {
    QColor toHsv = static_cast<BindQColor*>(color)->toHsv();
    return new BindQColor(toHsv.red(), toHsv.green(), toHsv.blue(), toHsv.alpha());
}

// QColor toRgb() const

void* QColor_toRgb(void* color) {
    QColor toRgb = static_cast<BindQColor*>(color)->toRgb();
    return new BindQColor(toRgb.red(), toRgb.green(), toRgb.blue(), toRgb.alpha());
}

// int value() const

int QColor_value(void* color) {
    return static_cast<BindQColor*>(color)->value();
}

// float valueF() const

float QColor_valueF(void* color) {
    return static_cast<BindQColor*>(color)->valueF();
}

// int yellow() const

int QColor_yellow(void* color) {
    return static_cast<BindQColor*>(color)->yellow();
}

// float yellowF() const

float QColor_yellowF(void* color) {
    return static_cast<BindQColor*>(color)->yellowF();
}

// QVariant operator QVariant() const

void* QColor_operatorQVariant(void* color) {
    QVariant variant = static_cast<BindQColor*>(color)->operator QVariant();
    return new QVariant(variant);
}

// bool operator!=(const QColor &color) const

bool QColor_operatorNotEqual(void* color, void* other) {
    return static_cast<BindQColor*>(color)->operator!=(*static_cast<BindQColor*>(other));
}

// QColor & operator=(Qt::GlobalColor color)
void* QColor_operatorAssignGlobalColor(void* color, int globalColor) {
    Qt::GlobalColor gColor = static_cast<Qt::GlobalColor>(globalColor);
    *static_cast<QColor*>(color) = QColor(gColor);
    return color;
}

// bool operator==(const QColor &color) const

bool QColor_operatorEqual(void* color, void* other) {
    return static_cast<BindQColor*>(color)->operator==(*static_cast<BindQColor*>(other));
}

//-- Static Public Members

// QStringList colorNames()

char** QColor_colorNames(int* count) {
    QStringList list = QColor::colorNames();
    *count = list.size();
    
    char **result = new char*[*count];
    for (int i = 0; i < *count; i++) {
        QByteArray utf8 = list.at(i).toUtf8();
        const char *data = utf8.constData();
        size_t size = utf8.size();
        
        result[i] = new char[size + 1];
        if (size > 0) {
            memcpy(result[i], data, size);
        }
        result[i][size] = '\0';
    }
    
    return result;
}

// QColor fromCmyk(int c, int m, int y, int k, int a = 255)

void* QColor_fromCmyk(int c, int m, int y, int k, int a) {
    QColor qcolor = QColor::fromCmyk(c, m, y, k, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromCmykF(float c, float m, float y, float k, float a = 1.0)

void* QColor_fromCmykF(float c, float m, float y, float k, float a) {
    QColor qcolor = QColor::fromCmykF(c, m, y, k, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromHsl(int h, int s, int l, int a = 255)

void* QColor_fromHsl(int h, int s, int l, int a) {
    QColor qcolor = QColor::fromHsl(h, s, l, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromHslF(float h, float s, float l, float a = 1.0)

void* QColor_fromHslF(float h, float s, float l, float a) {
    QColor qcolor = QColor::fromHslF(h, s, l, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromHsv(int h, int s, int v, int a = 255)

void* QColor_fromHsv(int h, int s, int v, int a) {
    QColor qcolor = QColor::fromHsv(h, s, v, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromHsvF(float h, float s, float v, float a = 1.0)

void* QColor_fromHsvF(float h, float s, float v, float a) {
    QColor qcolor = QColor::fromHsvF(h, s, v, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}


// QColor fromRgb(QRgb rgb)

void* QColor_fromRgbByInt(int rgb) {
    QColor qcolor = QColor::fromRgb(rgb);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromRgb(int r, int g, int b, int a = 255)

void* QColor_fromRgbByRgba(int r, int g, int b, int a) {
    QColor qcolor = QColor::fromRgb(r, g, b, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromRgba64(QRgba64 rgba64)

void* QColor_fromRgba64(int rgba64) {
    QColor qcolor = QColor::fromRgba64(QRgba64::fromRgba64(rgba64));
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromRgba64(ushort r, ushort g, ushort b, ushort a = USHRT_MAX)

void* QColor_fromRgba64WithUShort(unsigned short r, unsigned short g, unsigned short b, unsigned short a) {
    QColor qcolor = QColor::fromRgba64(r, g, b, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromRgbF(float r, float g, float b, float a = 1.0)

void* QColor_fromRgbF(float r, float g, float b, float a) {
    QColor qcolor = QColor::fromRgbF(r, g, b, a);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// QColor fromRgba(QRgb rgba)

void* QColor_fromRgba(int rgba) {
    QColor qcolor = QColor::fromRgba(rgba);
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// (since 6.4) QColor fromString(QAnyStringView name)

void* QColor_fromString(void* color, const char* name) {
    QColor qcolor = static_cast<BindQColor*>(color)->fromString(QString::fromUtf8(name));
    return new BindQColor(qcolor.red(), qcolor.green(), qcolor.blue(), qcolor.alpha());
}

// (since 6.4) bool isValidColorName(QAnyStringView name)

bool QColor_isValidColorName(const char* name) {
    return QColor::isValidColorName(QString::fromUtf8(name));
}

} // extern "C"
