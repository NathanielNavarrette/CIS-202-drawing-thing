#include "imageview.h"
#include <QDebug>

ImageView::ImageView(QWidget *parent) :
        QGraphicsView(parent)
    {
        scene = new QGraphicsScene();
        this->setSceneRect(50, 50, 350, 350);
        this->setScene(scene);
    }

/*
void ImageView::mousePressEvent(QMouseEvent * e)
{
}
*/
