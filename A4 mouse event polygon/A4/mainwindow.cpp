#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <math.h>
#include<QDebug>
static QImage img(400,400,QImage::Format_RGB888);
static int a[10],b[10], ver=0,sx,sy,r=0,g=0,bl=0;
static bool start;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dda(int x1,int y1,int x2,int y2)
{

    float x,y,dx,dy,l,i=1;
    QRgb value;
    value=qRgb(r,g,bl);

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
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->pos().x()>400 || ev->pos().y()>400)
        return;

    if(start==true)
    {
    int p=ev->pos().x();
    int q=ev->pos().y();
               qDebug()<<p<<'\t'<<q;
    if(ver==0){
      sx=p;sy=q;
    }

     if(ev->button()==Qt::RightButton)
     {
         a[ver]=p;
         b[ver]=q;
         dda(sx,sy,a[ver],b[ver]);
         dda(a[ver-1],b[ver-1],a[ver],b[ver]);
         start=false;
         qDebug()<<a[0]<<'\t'<<b[0];
     }
     else {
         a[ver]=p;
         b[ver]=q;
         if(ver>0)
         {
             dda(a[ver],b[ver],a[ver-1],b[ver-1]);
         }else{
             sx=p;
             sy=q;
             dda(sx,sy,sx,sy);

         }

     }
     ver++;
    }
    img.setPixel(a[0],b[0],qRgb(r,g,bl));
    img.setPixel(a[ver],b[ver],qRgb(r,g,bl));
  }



void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int p=ev->pos().x();
     int q=ev->pos().y();            
     QRgb col=qRgb(0,255,0);
     QRgb old=qRgb(0,0,0);
     if(start==false)
         col=qRgb(r,g,bl);
     seedfill(p,q,old,col);
     ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::seedfill(int x,int y,QRgb old,QRgb col)
{
     if(x<=0 || x>=400 || y<=0 || y>=400){
         return;
     }

    QRgb curr=img.pixel(x,y);

    if(curr!=old)
        return;

        img.setPixel(x,y,col);
        seedfill(x,y+1,old,col);
        seedfill(x-1,y,old,col);
        seedfill(x,y-1,old,col);
        seedfill(x+1,y,old,col);

}

void MainWindow::on_choose_clicked()
{
   r= ui->spinBoxR->text().toInt();
   g= ui->spinBoxG->text().toInt();
   bl= ui->spinBoxB->text().toInt();
   QRgb c = qRgb(r,g,bl);
   QImage img1(70,70,QImage::Format_RGB888);
   img1.fill(qRgb(r,g,bl));
   ui->color->setPixmap(QPixmap::fromImage(img1));
}
