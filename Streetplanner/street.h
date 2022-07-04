#ifndef STREET_H
#define STREET_H

#include <city.h>

class Street
{
public:
    Street(City*,City*);
    ~Street();
    void draw(QGraphicsScene &scene);
    City* getStadt1() const;
    City* getStadt2() const;
    void street_id();
    void drawRed(QGraphicsScene &scene);
    void drawBlack(QGraphicsScene &scene);

private:
    City* stadt1;
    City* stadt2;

};

#endif // STREET_H
