#include "QColorSpaceBind.h"

QColorSpace* QColorSpaceBind::create() {
    return new QColorSpace();
}

QColorSpace* QColorSpaceBind::createFromNamedColorSpace(int namedColorSpace) {
    return new QColorSpace(static_cast<QColorSpace::NamedColorSpace>(namedColorSpace));
}

QColorSpace* QColorSpaceBind::createFromPrimariesAndGamma(int primaries, float gamma) {
    return new QColorSpace(static_cast<QColorSpace::Primaries>(primaries), gamma);
}

QColorSpace* QColorSpaceBind::createFromPrimariesAndTransferFunction(int primaries, int transferFunction, float gamma) {
    return new QColorSpace(static_cast<QColorSpace::Primaries>(primaries), 
                          static_cast<QColorSpace::TransferFunction>(transferFunction), 
                          gamma);
}

QColorSpace* QColorSpaceBind::createFromWhitePointAndTransferFunction(float whitePointX, float whitePointY, int transferFunction, float gamma) {
    return new QColorSpace(QPointF(whitePointX, whitePointY), 
                          static_cast<QColorSpace::TransferFunction>(transferFunction), 
                          gamma);
}

QColorSpace* QColorSpaceBind::createFromPoints(float whitePointX, float whitePointY, 
                                             float redPointX, float redPointY, 
                                             float greenPointX, float greenPointY, 
                                             float bluePointX, float bluePointY, 
                                             int transferFunction, float gamma) {
    return new QColorSpace(QPointF(whitePointX, whitePointY), 
                          QPointF(redPointX, redPointY), 
                          QPointF(greenPointX, greenPointY), 
                          QPointF(bluePointX, bluePointY), 
                          static_cast<QColorSpace::TransferFunction>(transferFunction), 
                          gamma);
}

QColorSpace* QColorSpaceBind::createFromIccProfile(const char* iccProfile, int size) {
    if (iccProfile && size > 0) {
        QByteArray profile(iccProfile, size);
        return new QColorSpace(QColorSpace::fromIccProfile(profile));
    }
    return nullptr;
}

void QColorSpaceBind::destroy(QColorSpace* colorSpace) {
    if (colorSpace) {
        delete colorSpace;
    }
}

int QColorSpaceBind::colorModel(QColorSpace* colorSpace) {
    if (colorSpace) {
        return static_cast<int>(colorSpace->colorModel());
    }
    return 0; // Undefined
}

const char* QColorSpaceBind::description(QColorSpace* colorSpace) {
    if (colorSpace) {
        static QString desc;
        desc = colorSpace->description();
        return desc.toUtf8().constData();
    }
    return nullptr;
}

float QColorSpaceBind::gamma(QColorSpace* colorSpace) {
    if (colorSpace) {
        return colorSpace->gamma();
    }
    return 0.0f;
}

const char* QColorSpaceBind::iccProfile(QColorSpace* colorSpace, int* size) {
    if (colorSpace) {
        static QByteArray profile;
        profile = colorSpace->iccProfile();
        if (size) {
            *size = profile.size();
        }
        return profile.constData();
    }
    if (size) {
        *size = 0;
    }
    return nullptr;
}

bool QColorSpaceBind::isValid(QColorSpace* colorSpace) {
    return colorSpace ? colorSpace->isValid() : false;
}

bool QColorSpaceBind::isValidTarget(QColorSpace* colorSpace) {
    return colorSpace ? colorSpace->isValidTarget() : false;
}

int QColorSpaceBind::primaries(QColorSpace* colorSpace) {
    if (colorSpace) {
        return static_cast<int>(colorSpace->primaries());
    }
    return 0; // Custom
}

void QColorSpaceBind::whitePoint(QColorSpace* colorSpace, float* x, float* y) {
    if (colorSpace && x && y) {
        QPointF point = colorSpace->whitePoint();
        *x = static_cast<float>(point.x());
        *y = static_cast<float>(point.y());
    }
}

int QColorSpaceBind::transferFunction(QColorSpace* colorSpace) {
    if (colorSpace) {
        return static_cast<int>(colorSpace->transferFunction());
    }
    return 0; // Custom
}

int QColorSpaceBind::transformModel(QColorSpace* colorSpace) {
    if (colorSpace) {
        return static_cast<int>(colorSpace->transformModel());
    }
    return 0; // ThreeComponentMatrix
}

void QColorSpaceBind::setDescription(QColorSpace* colorSpace, const char* description) {
    if (colorSpace && description) {
        colorSpace->setDescription(QString::fromUtf8(description));
    }
}

void QColorSpaceBind::setPrimaries(QColorSpace* colorSpace, int primariesId) {
    if (colorSpace) {
        colorSpace->setPrimaries(static_cast<QColorSpace::Primaries>(primariesId));
    }
}

void QColorSpaceBind::setPrimariesFromPoints(QColorSpace* colorSpace, 
                                           float whitePointX, float whitePointY, 
                                           float redPointX, float redPointY, 
                                           float greenPointX, float greenPointY, 
                                           float bluePointX, float bluePointY) {
    if (colorSpace) {
        colorSpace->setPrimaries(QPointF(whitePointX, whitePointY), 
                                QPointF(redPointX, redPointY), 
                                QPointF(greenPointX, greenPointY), 
                                QPointF(bluePointX, bluePointY));
    }
}

void QColorSpaceBind::setTransferFunction(QColorSpace* colorSpace, int transferFunction, float gamma) {
    if (colorSpace) {
        colorSpace->setTransferFunction(static_cast<QColorSpace::TransferFunction>(transferFunction), gamma);
    }
}

void QColorSpaceBind::setWhitePoint(QColorSpace* colorSpace, float x, float y) {
    if (colorSpace) {
        colorSpace->setWhitePoint(QPointF(x, y));
    }
}

void* QColorSpaceBind::transformationToColorSpace(QColorSpace* source, QColorSpace* target) {
    if (source && target) {
        return new QColorTransform(source->transformationToColorSpace(*target));
    }
    return nullptr;
}
