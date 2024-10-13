#ifndef DISPLAYTHREAD_H
#define DISPLAYTHREAD_H

#include <QThread>

class DisplayThread : public QThread
{
    Q_OBJECT
public:
    DisplayThread(QObject *parent = nullptr);
    void setMilliseconds(int milliseconds);
    int milliseconds() const;
signals:
    void displayNow();
protected:
    void run() override;
private:
    int m_milliseconds;
};

#endif // DISPLAYTHREAD_H
