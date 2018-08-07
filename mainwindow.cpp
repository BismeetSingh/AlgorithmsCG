#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
using namespace std;
int flag=1;
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
void MainWindow::paintEvent(QPaintEvent *)
{
    if(flag==1){
        drawDDa();
    }
    else if(flag==2){
        drawBreshnan();
    }
    else if (flag==3) {
        drawCircle();
    }
    else if (flag==4) {
        drawEllipse();
    }

//    setAutoFillBackground(true);
//    drawDDa();
//    drawBreshnan();
}
void MainWindow::drawDDa(){
        QPainter painter(this);
        QPen horizontalLine(Qt::blue);
        horizontalLine.setWidth(1);
    int x0=450;
    int x1=690;
    int y0=120;
    int y1=120;
    int dx=x1-x0;
    int dy=y1-y0;
    int steps=0;
    float xinc=0;
    float yinc=0;
    float x=0;
    float y=0;
    if(abs(dx)>abs(dy)){
        steps=abs(dx);
    }
    else{
        steps=abs(dy);
    }
    xinc=dx/(float)steps;
    yinc=dy/(float)steps;
    x=x0;
    y=y0;
    cout<<"The number of steps calculated by the algorithm"<<steps;
    cout<<"The value of xinc is"<<xinc<<endl;
    for(int i=0;i<steps;i++){
        painter.drawPoint((int)x,(int)y);
        x+=xinc;
        y+=yinc;
        cout<<"The value of coord is"<<x<<endl;




    }


}
void MainWindow::drawBreshnan()
{
    QPainter painter(this);
    QPen horizontalLine(Qt::blue);
    horizontalLine.setWidth(1);
    int x0=250;
    int x1=390;
    int y0=120;
    int y1=120;
    int dx=x1-x0;
    int dy=y1-y0;
    int doubley=2*dy;
    int doublex=2*dx;
    int p0=doubley-doublex;
    int x=x0;
    int y=y0;
    for (int i=0;i<dx;i++) {
         painter.drawPoint(x,y);
         x=x+1;
         if(p0<0){
             p0=p0+2*dy;
         }
         else {
             p0=p0+2*dy-2*dx;
             y=y+1;
         }



    }



}
void MainWindow::drawCircle(int xcentre,int ycentre,int x,int y)
{
    //Using the symmetry property of the circle to plot the points with respect to the center.
    //Since centre isnt 0,0 we need to adjust points as per the same.
    //Octal rotation.
    QPainter painter(this);
    QPen horizontalLine(Qt::blue);
    horizontalLine.setWidth(1);
    painter.drawPoint(xcentre+x,ycentre+y);
    painter.drawPoint(xcentre+y,ycentre+x);
    painter.drawPoint(xcentre-y,ycentre+x);
    painter.drawPoint(xcentre-x,ycentre+y);
    painter.drawPoint(xcentre-x,ycentre-y);
    painter.drawPoint(xcentre-x,ycentre-y);
    painter.drawPoint(xcentre-y,ycentre-x);
    painter.drawPoint(xcentre+y,ycentre-x);
    painter.drawPoint(xcentre+x,ycentre-y);
}

void MainWindow::drawCircle(){


    int radius=105;
    int xcentre=500;
    int ycentre=200;
    double p0=1-radius;
    int x=0;
    //y is radius distance away from the center.(0,r)
    int y=radius;
    //First point
     drawCircle(xcentre,ycentre,x,y);
    while (x<=y) {

        x++;
        if(p0<0){
            p0=p0+2*x+1;
        }
        else {
            y--;
            p0=p0+(2*x)+1-(2*y);

        }

         drawCircle(xcentre,ycentre,x,y);




    }




}
void MainWindow::drawEllipse(){
    int rx=300;
    int ry=100;
    int centerx=500;
    int centery=300;
    double p1_0=(ry*ry)+(rx*rx)/4-(ry*rx*rx);
    int x=0;
    int y=ry;
    drawEllipse(centerx,centery,x,y);
    while ((2*ry*ry*x)<2*rx*rx*y) {
        x=x+1;
        if(p1_0<0){
            p1_0+=2*(ry*ry)*x+(ry*ry);
        }
        else {
            y--;
            p1_0+=2*(ry*ry)*x+(ry*ry)-(2*rx*rx*y);
        }
         drawEllipse(centerx,centery,x,y);



    }
    p1_0=(ry*ry)*pow((x+0.5),2)+(rx*rx)*pow((y-1),2)-(pow(rx,2)*pow(ry,2));
     drawEllipse(centerx,centery,x,y);
    while (y>0) {
        y--;
        if(p1_0>0){
            p1_0-=2*(2*rx*rx*y)+(rx*rx);
        }
        else {
            x++;
            p1_0+=2*(ry*ry)*x-2*(rx*rx*y)+(rx*rx);
        }
         drawEllipse(centerx,centery,x,y);


    }















}
void MainWindow::drawEllipse(int xcentre,int ycentre,int x,int y){
    QPainter painter(this);
    QPen horizontalLine(Qt::blue);
    horizontalLine.setWidth(1);
    painter.drawPoint(xcentre+x,ycentre+y);
    painter.drawPoint(xcentre+x,ycentre-y);
    painter.drawPoint(xcentre-x,ycentre-y);
    painter.drawPoint(xcentre-x,ycentre+y);



}

void MainWindow::on_radioButton_clicked()
{
    flag=1;
    update();

}

void MainWindow::on_radioButton_2_clicked()
{
    flag=2;
    update();
}

void MainWindow::on_radioButton_3_clicked()
{
    flag=3;
    update();
}

void MainWindow::on_radioButton_4_clicked()
{
    flag=4;
    update();
}
