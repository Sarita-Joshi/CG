#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int sign(int a){
    if(a<0)
        return -1;
    else if(a>0)
        return 1;
    else return 0;

}

void bresenham(int x1, int y1, int x2, int y2, QImage &image){
int i=1,e,s1,s2;
bool ch = false;
int xi,yi,x,y;
QRgb value = qRgb(0,255,0);
x=x1;
y=y1;
xi = abs(x2-x1);
yi = abs(y2-y1);
s1= sign(x2-x1);
s2 = sign(y2-y1);

if(yi>xi){
    int temp=xi;
    xi = yi;
    yi = temp;
    ch = true;
}
e = 2 * yi - xi;
for(;i<=xi;i++){
      image.setPixel(x,y,value);
    while(e>=0){
        if(ch)    x = x + s1;
        else      y = y + s2;
        e = e - 2*xi;
    }
    if(ch)  y=y+s2;
    else    x=x+s1;
    e = e + 2*yi;
}

}

void linedraw(int x1, int y1,int x2,int y2, QImage &image){

    int i=1;
    float xi,yi;
    QRgb value = qRgb(0,255,0);


    float length = abs(x2-x1) > abs(y2-y1) ? abs(x2-x1) : abs(y2-y1);
    xi = (x2-x1)/length;
    yi = (y2-y1)/length;


    float x= x1 + 0.5*sign(xi);
    float y= y1 + 0.5*sign(yi);

    while(i<=length)  {

        image.setPixel(floor(x),floor(y),value);
        x = x + xi;
        y = y + yi;

        i++;
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    QImage image(200,200,QImage::Format_RGB888);


    float len = ui->lineEdit->text().toFloat();
    float bre = ui->lineEdit_2->text().toFloat();

    linedraw(0,0,0,len,image);
    linedraw(0,0,bre,0,image);
    linedraw(bre,0,bre,len,image);
    linedraw(0,len,bre,len,image);

    linedraw(0, len/2, bre/2, 0,image);
    linedraw(bre/2, 0, bre, len/2,image);
    linedraw(bre, len/2, bre/2, len,image);
    linedraw(bre/2 ,len, 0, len/2,image);

    bresenham(bre/4, len/4, 3*bre/4, len/4 ,image);
    bresenham(3*bre/4, len/4, 3*bre/4, 3*len/4,image);
    bresenham(3*bre/4, 3*len/4, bre/4, 3*len/4,image);
    bresenham(bre/4 ,3*len/4, bre/4, len/4,image);


    ui->l->setPixmap(QPixmap::fromImage(image));

}


void MainWindow::on_pushButton_clicked()
{

    QImage image(300,300,QImage::Format_RGB888);

    image.fill(qRgb(0,0,0));

    int x1 = ui->x1->text().toInt();
    int y1 = ui->y1->text().toInt();
    int x2 = ui->x2->text().toInt();
    int y2 = ui->y2->text().toInt();

    bresenham(x1,y1,x2,y2,image);

    ui->l->setPixmap(QPixmap::fromImage(image));

}

void MainWindow::on_hor_clicked()
{


}
