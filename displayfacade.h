#ifndef DISPLAYFACADE_H
#define DISPLAYFACADE_H

#include <QObject>
#include <vector>

class DisplayThread;
class FileBrowserThread;
class QListWidget;

class DisplayFacade : public QObject
{
    Q_OBJECT
public:
    DisplayFacade(QObject *parent = nullptr);
    void setListWidget(QListWidget *listWidget);
    QListWidget* listWidget() const;
    void terminate();
    void start();
private slots:
    void fileFound(const QString &filePath);
    void displayNow();
private:
    void init();
    void connectSlots();

    DisplayThread *m_displayThread;
    FileBrowserThread *m_fileBrowserThread;
    QListWidget *m_listWidget;
    std::vector<QString> m_fileList;
    int m_lastIndex = 0;
    int m_pageSize = 50;
};

#endif // DISPLAYFACADE_H
