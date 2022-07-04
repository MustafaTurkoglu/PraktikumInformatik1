#include "map.h"

#include <QDebug>
#include <QGraphicsTextItem>

Map::Map()
{

}

Map::~Map()
{

}

void Map::addCity(City* stadt)
{
    stadt_Liste.append(stadt);
    qDebug() << stadt->getName() << " wurde in der Karte hinzugefügt";
}

bool Map::addStreet(Street* street)
{

        City* city1  = street->getStadt1();
        City* city2 = street->getStadt2();

        if (findCity(city1->getName()) != nullptr && findCity(city2->getName()) != nullptr)
        {
            strassen_Liste.append(street);
            return true;
        }
        else
        {
            return false;
        }

}
City* Map::findCity(const QString cityName) const
 {
     for(QVector<City*>::const_iterator it = stadt_Liste.begin(); it != stadt_Liste.end(); it++)
     {
         if ((*it)->getName() == cityName)
         {
             return *it;
         }
     }
         return nullptr;
 }
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if(city == street->getStadt1())
    {
        return street->getStadt2();
    }
    if(city == street->getStadt2())
    {
        return street->getStadt1();
    }
    else
    {
        return nullptr;
    }
}
double Map::getLength(const Street* street) const
{
    double x1 = street->getStadt1()->getX();
    double y1 = street->getStadt1()->getY();
    double x2 = street->getStadt2()->getX();
    double y2 = street->getStadt2()->getY();
    double abs = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    double laenge = sqrt(abs);
    return laenge;
}
void Map::draw(QGraphicsScene& scene)
{

    for(auto city : stadt_Liste)
        {
            city->draw(scene);
        }
        for(auto street : strassen_Liste)
        {
            street->draw(scene);
        }
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector <Street*> cityStreetList;
    for(QVector<Street*>::const_iterator it = strassen_Liste.begin();
        it != strassen_Liste.end();
        it++)
    {
        if(city == (*it)->getStadt1() || city == (*it)->getStadt2())
        {
            cityStreetList.append(*it);
        }
    }
    return cityStreetList;
}

QVector<City*> Map::getCityList()
{
    return stadt_Liste;
}



