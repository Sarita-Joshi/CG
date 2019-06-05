#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void dda(int x1,int y1,int x2,int y2);
    void seedfill(int x,int y,QRgb old,QRgb col);
    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *ev);

private slots:
    void on_choose_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
