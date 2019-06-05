#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
#include<string>
 QImage image(300,300,QImage::Format_RGB888);
 int t;

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

int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a<b?a:b;
}


void linedraw(int x1, int y1,int x2,int y2, QImage &image,int s){

    int i=1;
    float xi,yi;
 QRgb value = qRgb(0,255,0);


    float length = abs(x2-x1) > abs(y2-y1) ? abs(x2-x1) : abs(y2-y1);
    xi = (x2-x1)/length;
    yi = (y2-y1)/length;


    float x= x1 + 0.5*sign(xi);
    float y= y1 + 0.5*sign(yi);

    switch(s){

    case 1://solid
    while(i<=length)  {

        image.setPixel(floor(x),floor(y),value);
        x = x + xi;
        y = y + yi;

        i++;
    }
    break;

    case 2://dash
    while(i<=length)  {
        if(i%13 <10)
        image.setPixel(floor(x),floor(y),value);
        x = x + xi;
        y = y + yi;

        i++;
    }
    break;
    case 3://dash dot
    while(i<=length)  {
        if((i%15 < 10) || (i%15 == 12))
        image.setPixel(floor(x),floor(y),value);
        x = x + xi;
        y = y + yi;

        i++;
    }
    break;
    case 4://dot
    while(i<=length)  {
        if(i%2 == 0)
        image.setPixel(floor(x),floor(y),value);
        x = x + xi;
        y = y + yi;

        i++;
    }
    break;
    case 5://thick line
        while(i<=length)  {

            image.setPixel(floor(x),floor(y),value);

            for(int j=1;j<t/2;j++){

            if(x+j<=max(x1,x2) && y+j<=max(y1,y2) && x+j>=min(x1,x2) && y+j>=min(x1,x2) ){
                image.setPixel(floor(x),floor(y+j),value);
                image.setPixel(floor(x+j),floor(y),value);
            }
            }
            x = x + xi;
            y = y + yi;

            i++;
        }

    }

}


void MainWindow::on_pushButton_clicked()
{

    int x1 = ui->x1->text().toInt();
    int x2 = ui->x2->text().toInt();
    int y1 = ui->y1->text().toInt();
    int y2 = ui->y2->text().toInt();


    int s = ui->style->currentText().toInt();
    t =ui->thickness->text().toInt();


    linedraw(x1,y1,x2,y2,image,s);

    ui->l->setPixmap(QPixmap::fromImage(image));

}

void MainWindow::on_pushButton_2_clicked()
{
     image.fill(qRgb(0,0,0));
     ui->l->setPixmap(QPixmap::fromImage(image));

}
