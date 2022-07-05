//
//  Magazin.h
//  Versuch08
//
//  Created by Mustafa Türkoğlu on 03.07.22.
//

#ifndef Magazin_h
#define Magazin_h
#include "Medium.h"
#include "Datum.h"

class Magazin : public Medium
{
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe,std::string initSparte);
    virtual ~Magazin();
    virtual void ausgabe() const;
    bool ausleihen(Person person, Datum ausleihdatum);

protected:
    Datum ausgabeDatum;
    std::string sparte;
};


#endif /* Magazin_h */
