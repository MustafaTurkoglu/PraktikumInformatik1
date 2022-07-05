//
//  DVD.h
//  Versuch08
//
//  Created by Mustafa Türkoğlu on 03.07.22.
//

#ifndef DVD_h
#define DVD_h

#include "Medium.h"

class DVD : public Medium
{
public:
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
    virtual ~DVD();
    virtual void ausgabe() const;
    bool ausleihen(Person person, Datum ausleihdatum);

protected:
    int altersFreigabe;
    std::string genre;
};

#endif /* DVD_h */
