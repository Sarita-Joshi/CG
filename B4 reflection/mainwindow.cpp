#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include<math.h>
static QImage img(600,600,QImage::Format_RGB888);
static int a[10], b[10], ver=0,sx,sy,p[2];
static bool start;

void axes(){
    for(int i=0;i<600;i++){
        img.setPixel(i,300,qRgb(205,205,205));
        img.setPixel(300,i,qRgb(205,205,205));
    }
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    axes();
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

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->pos().x()>400 || ev->pos().y()>400)
        return;

    if(start==true)
    {
    int p1=ev->pos().x();
    int p2=ev->pos().y();

    if(ver==0){
        sx=p1; sy=p2;
    }

     if(ev->button()==Qt::RightButton)
     {
         a[ver]=p1;
         b[ver]=p2;
         dda(sx,sy,a[ver],b[ver]);
         dda(a[ver-1],b[ver-1],a[ver],b[ver]);
         start=false;
     }
     else {
         a[ver]=p1;
         b[ver]=p2;
         if(ver>0)
         {
             dda(a[ver],b[ver],a[ver-1],b[ver-1]);
         }else{
             sx=p1;
             sy=p2;

             dda(sx,sy,sx,sy);
         }
     }
     ver++;
    }
  }
void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev){
     p[0]=ev->pos().x();
     p[1]=ev->pos().y();
     dda(p[0],p[1],p[0],p[1]);
     p[0]=p[0]-300;
     p[1]=300-p[1];
}

void MainWindow::dda(int x1,int y1,int x2,int y2)
{

    float x,y,dx,dy,l,i=1;
    QRgb value;
    value=qRgb(0,255,0);

    l=std::abs(x2-x1)>std::abs(y2-y1)?std::abs(x2-x1):std::abs(y2-y1);
    dx=(x2-x1)/l;
    dy=(y2-y1)/l;

    x=x1+0.5f;
    y=y1+0.5f;
    do
    {
       img.setPixel(static_cast<int>(x),static_cast<int>(y),value);
       x = x + dx;
       y = y + dy;
       i++;
      }while(i <= l);


ui->label->setPixmap(QPixmap::fromImage(img));

}

void clear(){
    img.fill(qRgb(0,0,0));
}


void MainWindow::on_horizontal_clicked()
{
    clear();
    axes();
    if(start == true)
        return;
    for(int i=0;i<ver;i++){
          b[i]  = 600-b[i];
    }
    for(int i=0;i<ver-1;i++){
       dda(a[i],b[i],a[i+1],b[i+1]);
    }
    dda(a[0],b[0],a[ver-1],b[ver-1]);
}

void MainWindow::on_vertical_clicked()
{
    clear();
    axes();
    if(start == true)
        return;
    for(int i=0;i<ver;i++){
       a[i]  = -a[i]+600;
    }
    for(int i=0;i<ver-1;i++){
       dda(a[i],b[i],a[i+1],b[i+1]);
    }
    dda(a[0],b[0],a[ver-1],b[ver-1]);
}

void MainWindow::on_slant_clicked()
{
    clear();
    axes();
    if(start == true)
        return;
    for(int i=0;i<ver;i++){
          a[i]  = 600-a[i];
          b[i]  = 600-b[i];
    }
    for(int i=0;i<ver-1;i++){
       dda(a[i],b[i],a[i+1],b[i+1]);
    }
    dda(a[0],b[0],a[ver-1],b[ver-1]);
}

void MainWindow::on_pushButton_clicked()
{
    img.fill(qRgb(0,0,0));
    axes();
    start=true;
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_rotate_clicked()
{
    clear();
    axes();
    int t1[ver],t2[ver];
    if(start == true)
        return;
    float theta = ui->lineEdit->text().toFloat();
    theta = theta * 3.14 / 180;

    for(int i=0;i<ver;i++){
       int x=a[i] - 300;
       int y=300 - b[i];
          t1[i]  = x*cos(theta) -y*sin(theta) - p[0]*cos(theta) + p[1]*sin(theta)+p[0];
          t2[i]  = x*sin(theta) +y*cos(theta) - p[0]*sin(theta) - p[1]*cos(theta)+p[1];
    }
     for(int i=0;i<ver-1;i++){

       dda(t1[i]+300,300-t2[i],t1[i+1]+300,300-t2[i+1]);

    }
    dda(t1[0]+300,300-t2[0],t1[ver-1]+300,300-t2[ver-1]);



}
