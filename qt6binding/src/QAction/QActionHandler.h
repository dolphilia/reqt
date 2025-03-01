#ifndef QACTION_HANDLER_H
#define QACTION_HANDLER_H

#include <QObject>
#include "../../include/qt6/qaction.h"

class QActionHandler : public QObject {
    Q_OBJECT

public:
    explicit QActionHandler(QObject* parent = nullptr);

    void setChangedCallback(QActionChangedCallback callback);
    void setCheckableChangedCallback(QActionCheckableChangedCallback callback);
    void setEnabledChangedCallback(QActionEnabledChangedCallback callback);
    void setHoveredCallback(QActionHoveredCallback callback);
    void setToggledCallback(QActionToggledCallback callback);
    void setTriggeredCallback(QActionTriggeredCallback callback);
    void setVisibleChangedCallback(QActionVisibleChangedCallback callback);

public slots:
    void onChanged();
    void onCheckableChanged(bool checkable);
    void onEnabledChanged(bool enabled);
    void onHovered();
    void onToggled(bool checked);
    void onTriggered(bool checked);
    void onVisibleChanged();

private:
    QActionChangedCallback changedCallback;
    QActionCheckableChangedCallback checkableChangedCallback;
    QActionEnabledChangedCallback enabledChangedCallback;
    QActionHoveredCallback hoveredCallback;
    QActionToggledCallback toggledCallback;
    QActionTriggeredCallback triggeredCallback;
    QActionVisibleChangedCallback visibleChangedCallback;
};

#endif // QACTION_HANDLER_H
