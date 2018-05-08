#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
//include <

class ImageView : public QGraphicsView
{
       Q_OBJECT
   public:
       // http://en.cppreference.com/w/cpp/language/explicit
       explicit ImageView(QWidget *parent = 0);

   signals:

   public slots:
       void mousePressEvent(QMouseEvent * e);
       // void mouseReleaseEvent(QMouseEvent * e);
       // void mouseDoubleClickEvent(QMouseEvent * e);
       // void mouseMoveEvent(QMouseEvent * e);
   private:
       QGraphicsScene * scene;
       QPointF last_position;
       QPen getColorPen();
       QBrush getColorBrush();
       int count = 0;
};
#endif // IMAGEVIEW_H
