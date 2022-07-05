//
//  DVD.cpp
//  Versuch08
//
//  Created by Mustafa Türkoğlu on 03.07.22.
//

#include <stdio.h>
#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) :
Medium(initTitel), altersFreigabe(initAltersfreigabe), genre(initGenre)
{
}

DVD::~DVD()
{
}

void DVD::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Pegi Rating: " << altersFreigabe
              << "Genre: " << genre << std::endl;
}
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    Datum aktuellesDatum;
    if (altersFreigabe <= abs(person.getGeburtsdatum() - aktuellesDatum) / 12)
    {
        Medium::ausleihen(person, ausleihdatum);
        return true;
    }

    else
    {
        std::cout << "DVD darf nicht ausgeliehen werden! Wegen Pegi Rating !" << std::endl;
        return false;
    }
    }
