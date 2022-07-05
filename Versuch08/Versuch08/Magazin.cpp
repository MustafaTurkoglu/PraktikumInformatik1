//
//  Magazin.cpp
//  Versuch08
//
//  Created by Mustafa Türkoğlu on 03.07.22.
//

#include <stdio.h>
#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) :Medium(initTitel),ausgabeDatum(initDatumAusgabe),sparte(initSparte)
{
    
}

Magazin::~Magazin()
{
}

void Magazin::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Datum der Ausgabe: " << ausgabeDatum
              << " Sparte: " << sparte << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    if(ausleihdatum-ausgabeDatum==0)
    {
    std::cout<<"Das Magazin darf nicht ausgeliehen werden, es die neueste Ausgabe ist "<<std::endl;
        
        return false;
    }
    
    else
    {
    Medium::ausleihen(person,ausleihdatum);
    
        return true
    ;
    }
}
