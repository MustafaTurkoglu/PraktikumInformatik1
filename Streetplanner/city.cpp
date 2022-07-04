#include "city.h"
#include <QGraphicsTextItem>
#define DOT_RADIUS 5

City::City(QString name,int X,int Y): name(name), X(X), Y(Y)
{

}

City::~City(){

}

void City::draw(QGraphicsScene &scene)
{
    int X,Y;
    X=getX();
    Y=getY();
    // Draw the dot
    scene.addEllipse(X - DOT_RADIUS, Y - DOT_RADIUS, 2 * DOT_RADIUS, 2 * DOT_RADIUS, QPen(COLOR), QBrush(COLOR));
    // Draw the name
    QGraphicsTextItem * txtitem = new QGraphicsTextItem();
    txtitem->setPlainText(name);
    txtitem->setPos(X + DOT_RADIUS / 2, Y + DOT_RADIUS / 2);
    scene.addItem(txtitem);
    qDebug() << QString("City %1 being drawn at X %2 | Y %3").arg(name).arg(X).arg(Y);
}
QString City::getName() const
{
    return name;
}

int City::getX() const
{
    return X;
}

int City::getY() const
{
    return Y;
}
