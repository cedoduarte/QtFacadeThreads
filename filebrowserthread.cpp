#include "filebrowserthread.h"

#include <QDir>
#include <QFileInfo>

FileBrowserThread::FileBrowserThread(QObject *parent) : QThread(parent) {}

void FileBrowserThread::run()
{
    performsDirectoryTraversal("/");
}

void FileBrowserThread::performsDirectoryTraversal(const QString &dirPath)
{
    QDir dir(dirPath);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    for (int i = 0; i < dir.count(); i++)
    {
        QString filePath = dir.filePath(dir[i]);
        if (QFileInfo(filePath).isDir())
        {
            performsDirectoryTraversal(filePath);
        }
        else
        {
            emit fileFound(filePath);
        }
    }
}
