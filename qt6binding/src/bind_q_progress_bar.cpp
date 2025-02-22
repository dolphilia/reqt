#include "bind_q_progress_bar.h"

BindQProgressBar::BindQProgressBar(QWidget *parent)
    : QProgressBar(parent)
    , m_handler(nullptr)
{
}

BindQProgressBar::~BindQProgressBar()
{
    delete m_handler;
}

void BindQProgressBar::setProgressBarHandler(ProgressBarHandler *handler)
{
    if (m_handler) {
        disconnect(this, &QProgressBar::valueChanged, m_handler, &ProgressBarHandler::onValueChanged);
        delete m_handler;
    }

    m_handler = handler;

    if (m_handler) {
        connect(this, &QProgressBar::valueChanged, m_handler, &ProgressBarHandler::onValueChanged);
    }
}

ProgressBarHandler *BindQProgressBar::handler() const
{
    return m_handler;
}
