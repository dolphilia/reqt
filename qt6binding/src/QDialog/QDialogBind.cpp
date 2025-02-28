#include "QDialogBind.h"
#include "QDialogHandler.h"
#include <QVariant>

QDialog* QDialogBind::create(QWidget* parent, Qt::WindowFlags f) {
    return new QDialog(parent, f);
}

void QDialogBind::destroy(QDialog* dialog) {
    if (dialog) {
        QDialogHandler* handler = getHandler(dialog);
        if (handler) {
            delete handler;
        }
        delete dialog;
    }
}

bool QDialogBind::isSizeGripEnabled(QDialog* dialog) {
    if (dialog) {
        return dialog->isSizeGripEnabled();
    }
    return false;
}

int QDialogBind::result(QDialog* dialog) {
    if (dialog) {
        return dialog->result();
    }
    return 0;
}

QSize* QDialogBind::minimumSizeHint(QDialog* dialog) {
    if (dialog) {
        return new QSize(dialog->minimumSizeHint());
    }
    return nullptr;
}

QSize* QDialogBind::sizeHint(QDialog* dialog) {
    if (dialog) {
        return new QSize(dialog->sizeHint());
    }
    return nullptr;
}

void QDialogBind::setModal(QDialog* dialog, bool modal) {
    if (dialog) {
        dialog->setModal(modal);
    }
}

void QDialogBind::setResult(QDialog* dialog, int result) {
    if (dialog) {
        dialog->setResult(result);
    }
}

void QDialogBind::setSizeGripEnabled(QDialog* dialog, bool enabled) {
    if (dialog) {
        dialog->setSizeGripEnabled(enabled);
    }
}

void QDialogBind::setVisible(QDialog* dialog, bool visible) {
    if (dialog) {
        dialog->setVisible(visible);
    }
}

void QDialogBind::accept(QDialog* dialog) {
    if (dialog) {
        dialog->accept();
    }
}

void QDialogBind::done(QDialog* dialog, int result) {
    if (dialog) {
        dialog->done(result);
    }
}

int QDialogBind::exec(QDialog* dialog) {
    if (dialog) {
        return dialog->exec();
    }
    return 0;
}

void QDialogBind::open(QDialog* dialog) {
    if (dialog) {
        dialog->open();
    }
}

void QDialogBind::reject(QDialog* dialog) {
    if (dialog) {
        dialog->reject();
    }
}

void QDialogBind::setAcceptedCallback(QDialog* dialog, void (*callback)(void*), void* data) {
    if (dialog) {
        QDialogHandler* handler = getHandler(dialog);
        if (!handler) {
            handler = new QDialogHandler(dialog, dialog);
            setHandler(dialog, handler);
        }
        handler->acceptedCallback = callback;
        handler->acceptedData = data;
    }
}

void QDialogBind::setFinishedCallback(QDialog* dialog, void (*callback)(void*, int), void* data) {
    if (dialog) {
        QDialogHandler* handler = getHandler(dialog);
        if (!handler) {
            handler = new QDialogHandler(dialog, dialog);
            setHandler(dialog, handler);
        }
        handler->finishedCallback = callback;
        handler->finishedData = data;
    }
}

void QDialogBind::setRejectedCallback(QDialog* dialog, void (*callback)(void*), void* data) {
    if (dialog) {
        QDialogHandler* handler = getHandler(dialog);
        if (!handler) {
            handler = new QDialogHandler(dialog, dialog);
            setHandler(dialog, handler);
        }
        handler->rejectedCallback = callback;
        handler->rejectedData = data;
    }
}

QDialogHandler* QDialogBind::getHandler(QDialog* dialog) {
    if (dialog) {
        QVariant variant = dialog->property("handler");
        if (variant.isValid()) {
            return variant.value<QDialogHandler*>();
        }
    }
    return nullptr;
}

void QDialogBind::setHandler(QDialog* dialog, QDialogHandler* handler) {
    if (dialog) {
        dialog->setProperty("handler", QVariant::fromValue(handler));
    }
}
