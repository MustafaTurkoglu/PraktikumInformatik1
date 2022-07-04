#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsTextItem>


class City
{
protected:
        QString name;
        int X;
        int Y;
        const QColor COLOR = QColor(255, 0, 0);
public:
    City(QString name, int X, int Y);
    ~City();
    void draw(QGraphicsScene &scene) ;
    QString getName() const;
    int getX() const;
    int getY() const;
};

#endif // CITY_H
