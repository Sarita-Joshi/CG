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

int sideLen(int r){
    return (pow(3,0.5)*r/2);
   }

int sign(int a){
    if(a<0)
        return -1;
    else if(a>0)
        return 1;
    else return 0;

}

void linedraw(int x1, int y1,int x2,int y2, QImage &image){

    int i=1;
    float xi,yi;
 QRgb value = qRgb(255,0,0);


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

void drawCircle(int c1, int c2, int r,QImage &image){


    float x1,x2,y2,y1,x,y;

    float e=1/pow(2,7);

    x1=x=r;
    y1=y=0;

    do{
        x2 = x1 + e*y1;
        y2 = y1- x2*e ;
        image.setPixel(x2+c1, c2-y2, qRgb(0,255,0));
        x1=x2;
        y1=y2;
    }while((y1-y)<e || (x-x1)>e);
}

void draw(int xc, int yc, int x, int y,QImage& image)
{
    QRgb value;
    value=qRgb(0,255,0);
    image.setPixel(xc+x, yc+y, value);
    image.setPixel(xc-x, yc+y, value);
    image.setPixel(xc+x, yc-y, value);
    image.setPixel(xc-x, yc-y, value);
    image.setPixel(xc+y, yc+x, value);
    image.setPixel(xc-y, yc+x, value);
    image.setPixel(xc+y, yc-x, value);
    image.setPixel(xc-y, yc-x, value);
}
void circleBresenham(int xc, int yc, int r,QImage& image)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    draw(xc, yc, x, y,image);
    while (y >= x){
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        draw(xc, yc, x, y,image);

    }

}



void MainWindow::on_pushButton_clicked()
{
    QImage image(400,400,QImage::Format_RGB888);

    image.fill(qRgb(0,0,0));

    int r = ui->lineEdit_3->text().toInt();
    int c1=ui->lineEdit_2->text().toInt();
    int c2=ui->lineEdit->text().toInt();

    drawCircle(c1,c2,r,image);
    circleBresenham(c1,c2,r/2, image);

    linedraw(c1,c2+(r/2),c1+sideLen(r),c2+(r/2),image);
    linedraw(c1,c2+(r/2),c1-sideLen(r),c2+(r/2),image);
    linedraw(c1+sideLen(r),c2+(r/2), c1, c2-r,image);
    linedraw(c1-sideLen(r),c2+(r/2), c1, c2-r,image);


    ui->label->setPixmap(QPixmap::fromImage(image));

}


void MainWindow::on_label_customContextMenuRequested(const QPoint &pos)
{

}
