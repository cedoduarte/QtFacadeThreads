#ifndef FILEBROWSERTHREAD_H
#define FILEBROWSERTHREAD_H

#include <QThread>

class FileBrowserThread : public QThread
{
    Q_OBJECT
public:
    FileBrowserThread(QObject *parent = nullptr);
signals:
    void fileFound(const QString &filePath);
protected:
    void run() override;
private:
    void performsDirectoryTraversal(const QString &dirPath);
};

#endif // FILEBROWSERTHREAD_H
