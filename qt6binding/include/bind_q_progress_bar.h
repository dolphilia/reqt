#ifndef BIND_Q_PROGRESS_BAR_H
#define BIND_Q_PROGRESS_BAR_H

#include <QProgressBar>
#include "handler_progress_bar.h"

class BindQProgressBar : public QProgressBar {
    Q_OBJECT
public:
    explicit BindQProgressBar(QWidget *parent = nullptr);
    ~BindQProgressBar();

    void setProgressBarHandler(ProgressBarHandler *handler);
    ProgressBarHandler *handler() const;

private:
    ProgressBarHandler *m_handler;
};

#endif // BIND_Q_PROGRESS_BAR_H
