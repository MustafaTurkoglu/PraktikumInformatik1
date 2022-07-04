#ifndef MAP_H
#define MAP_H

#include "city.h"
#include "street.h"
#include "abstractmap.h"

#include <QVector>

class Map: public AbstractMap
{
public:
    Map();
    ~Map();
    void addCity(City*);
    bool addStreet(Street*);
    City* findCity(const QString cityName) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    void draw(QGraphicsScene& scene);
    QVector<Street*> getStreetList(const City* city) const;
    QVector<City*> getCityList();

private:
    QVector<City*> stadt_Liste;
    QVector <Street*> strassen_Liste;
};

#endif // MAP_H
