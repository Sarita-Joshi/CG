#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
#include<QDebug>
#include<QMouseEvent>

static QImage img(600,600,QImage::Format_RGB888);
static int a[2], b[2], ver=0,code[2][4];
static int xmin=170,ymin=170,xmax=420,ymax=420;
QRgb old=qRgb(255,0,0);
bool flag=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    window();

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
    if(ev->pos().x()>600 || ev->pos().y()>600)
        return;

    int p1=ev->pos().x();
    int p2=ev->pos().y();

    if(ver==0){
       a[0]=p1; b[0]=p2; ver++;
       if(a[0]<xmin) code[0][0]=1; else code[0][0]=0;//left
       if(a[0]>xmax) code[0][1]=1; else code[0][1]=0;//right
       if(b[0]<ymin) code[0][2]=1; else code[0][2]=0;//above
       if(b[0]>ymax) code[0][3]=1; else code[0][3]=0;//below

    }
    else{
         a[ver]=p1;
         b[ver]=p2;
         if(a[1]<xmin) code[1][0]=1; else code[1][0]=0;
         if(a[1]>xmax) code[1][1]=1;else code[1][1]=0;
         if(b[1]<ymin) code[1][2]=1;else code[1][2]=0;
         if(b[1]>ymax) code[1][3]=1;else code[1][3]=0;
         dda(a[0],b[0],a[ver],b[ver]);
         ver=0;
     }


  }

void MainWindow::dda(int x1,int y1,int x2,int y2){

    int i=1;
    float xi,yi;
     QRgb value=NULL;

if(!flag)
  value = qRgb(0,255,0);
if(flag)
    value=qRgb(255,0,0);

    float length = abs(x2-x1) > abs(y2-y1) ? abs(x2-x1) : abs(y2-y1);
    xi = (x2-x1)/length;
    yi = (y2-y1)/length;


    float x= x1 + 0.5*sign(xi);
    float y= y1 + 0.5*sign(yi);

    while(i<=length)  {
        img.setPixel(floor(x),floor(y),value);

        x = x + xi;
        y = y + yi;

        i++;
    }
flag=false;
 ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::window(){
 dda(xmin,ymin,xmin,ymax);
 dda(xmin,ymin,xmax,ymin);
 dda(xmax,ymin,xmax,ymax);
 dda(xmin,ymax,xmax,ymax);

}

bool inside(int i){
   if( code[i][0] || code[i][1] || code[i][2] || code[i][3])
       return false;
   return true;
}

int line(){
    int c[4];
    for(int i=0;i<4;i++){
    c[i] = code[0][i] && code[1][i];
    if(c[i]) return 2;
    }
    return 1;
}

void MainWindow::on_pushButton_clicked()
{
    double x,y;
    int c[2],d[2];
    float slope = (b[1]-b[0])/(a[1]-a[0]);

    if(line()==2){
        return;
    }

    for(int i=0;i<2;i++){
        if(inside(i)){
           x=a[i];
           y=b[i];
            qDebug()<<"inside";
        }
        if(a[i]<xmin){
            y=b[i] + (xmin-a[i]) * (b[1]-b[0]) / (a[1]-a[0]);
            x=xmin;
            qDebug()<<"left";
        }
        if(a[i]>xmax){
            y=b[i] + (xmax-a[i]) * (b[1]-b[0]) / (a[1]-a[0]);
            x=xmax;
            qDebug()<<"right";

        }
        if(b[i]<ymin){
            x=a[i] + (ymin-b[i]) * (a[1]-a[0]) / (b[1]-b[0]);
            y=ymin;
            qDebug()<<"up";
        }
        if(b[i]>ymax){
            x=a[i] + (ymax-b[i]) * (a[1]-a[0]) / (b[1]-b[0]);
            y=ymax;
            qDebug()<<"bottom";

        }
    qDebug()<<a[i]<<b[i];

    c[i]=x; d[i]=y;
    qDebug()<<c[i]<<d[i];

    }

    flag=true;
    dda(c[0],d[0],c[1],d[1]);

}
