#include "imageview.h"
#include <QDebug>

ImageView::ImageView(QWidget *parent) :
       QGraphicsView(parent)
{
       scene = new QGraphicsScene();
       //this->setSceneRect(50, 50, 350, 350);
       //this->setSceneRect(-200, -200, 400, 400);
       scene->setSceneRect(QRectF(-200,-200,400,400));
       this->setScene(scene);
       last_position.setX(0);
       last_position.setY(0);
}

void ImageView::mousePressEvent(QMouseEvent * e)
{
   auto pos = mapToScene(e->pos());

   scene->addEllipse((pos.x()-5),(pos.y()-5),//x,y
                     10,10,// size
                     //QPen(Qt::black)
                     getColorPen(),
                     getColorBrush());
                     //QBrush(Qt::black)); // pen,brush
   if(last_position.x() != 0 && last_position.y() != 0)
   {
       scene->addLine(last_position.x(),
                      last_position.y(),
                       pos.x(),
                       pos.y(),
                       getColorPen()
                       //QPen(Qt::black)
                      );
   }
   last_position = pos;

   this->count++;
   //qDebug() << e->pos();
}

QPen ImageView::getColorPen()
{
    int inc = this->count % 5;

    if(inc == 0)
        return QPen(Qt::black);
    else if(inc == 1)
        return QPen(Qt::blue);
    else if(inc == 2)
        return QPen(Qt::red);
    else if(inc == 3)
        return QPen(Qt::green);
    else if(inc == 4)
        return QPen(Qt::yellow);
    else
        return QPen(Qt::black);
}


QBrush ImageView::getColorBrush()
{
    int inc = this->count % 5;

    if(inc == 0)
        return QBrush(Qt::black);
    else if(inc == 1)
        return QBrush(Qt::blue);
    else if(inc == 2)
        return QBrush(Qt::red);
    else if(inc == 3)
        return QBrush(Qt::green);
    else if(inc == 4)
        return QBrush(Qt::yellow);
    else
        return QBrush(Qt::black);
}
