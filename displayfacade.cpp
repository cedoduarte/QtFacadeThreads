#include "displayfacade.h"
#include "filebrowserthread.h"
#include "displaythread.h"

#include <QListWidget>

DisplayFacade::DisplayFacade(QObject *parent)
    : QObject(parent)
{
    init();
    connectSlots();
}

void DisplayFacade::setListWidget(QListWidget *listWidget)
{
    m_listWidget = listWidget;
}

QListWidget *DisplayFacade::listWidget() const
{
    return m_listWidget;
}

void DisplayFacade::terminate()
{
    m_fileBrowserThread->terminate();
    m_displayThread->terminate();
}

void DisplayFacade::start()
{
    m_fileBrowserThread->start(QThread::HighestPriority);
    m_displayThread->start(QThread::HighPriority);
}

void DisplayFacade::fileFound(const QString &filePath)
{
    m_fileList.push_back(filePath);
}

void DisplayFacade::displayNow()
{
    int index;
    int count = m_lastIndex + m_pageSize;
    if (count > m_fileList.size())
    {
        count = m_fileList.size();
    }
    for (index = m_lastIndex; index < count; index++)
    {
        m_listWidget->addItem(m_fileList[index]);
    }
    m_lastIndex = index;
}

void DisplayFacade::init()
{
    m_fileBrowserThread = new FileBrowserThread(this);
    m_displayThread = new DisplayThread(this);
    m_listWidget = nullptr;
    m_lastIndex = 0;
    m_pageSize = 50;
    m_displayThread->setMilliseconds(2000);
}

void DisplayFacade::connectSlots()
{
    connect(m_fileBrowserThread, &FileBrowserThread::fileFound, this, &DisplayFacade::fileFound);
    connect(m_displayThread, &DisplayThread::displayNow, this, &DisplayFacade::displayNow);
}
