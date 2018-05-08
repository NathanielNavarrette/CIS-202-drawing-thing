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
                     QPen(Qt::black),
                     QBrush(Qt::black)); // pen,brush
   if(last_position.x() != 0 && last_position.y() != 0)
   {
       scene->addLine(last_position.x(),
                      last_position.y(),
                       pos.x(),
                       pos.y(),
                       QPen(Qt::black)
                      );
   }
   last_position = pos;
   //qDebug() << e->pos();
}
