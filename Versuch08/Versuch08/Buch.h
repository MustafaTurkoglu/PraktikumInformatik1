//
//  Buch.h
//  Versuch08
//
//  Created by Mustafa Türkoğlu on 03.07.22.
//

#ifndef Buch_h
#define Buch_h

#include "Medium.h"

class Buch : public Medium
{
public:
    Buch(std::string initTitel, std::string initAutor);
    virtual ~Buch();
    virtual void ausgabe() const;

protected:
    std::string autor;
};

#endif /* Buch_h */
