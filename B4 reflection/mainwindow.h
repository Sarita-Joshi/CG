#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *ev);
    void dda(int x1,int y1,int x2,int y2);
private slots:
    void on_horizontal_clicked();

    void on_vertical_clicked();

    void on_slant_clicked();

    void on_pushButton_clicked();

    void on_rotate_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
