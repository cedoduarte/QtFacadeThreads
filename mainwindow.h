#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class DisplayFacade;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_buttonStart_clicked();
private:
    Ui::MainWindow *ui;
    DisplayFacade *m_displayFacade;
};

#endif // MAINWINDOW_H
