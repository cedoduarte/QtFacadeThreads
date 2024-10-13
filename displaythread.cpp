#include "displaythread.h"

DisplayThread::DisplayThread(QObject *parent) : QThread(parent) {}

void DisplayThread::setMilliseconds(int milliseconds)
{
    m_milliseconds = milliseconds;
}

int DisplayThread::milliseconds() const
{
    return m_milliseconds;
}

void DisplayThread::run()
{
    while (true)
    {
        emit displayNow();
        msleep(m_milliseconds);
    }
}
