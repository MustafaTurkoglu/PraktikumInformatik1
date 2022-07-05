//
//  Buch.cpp
//  Versuch08
//
//  Created by Mustafa Türkoğlu on 03.07.22.
//

#include "Buch.h"
#include "Medium.h"

Buch::Buch(std::string initTitel, std::string initAutor) :Medium(initTitel),autor(initAutor)
{
    
}

Buch::~Buch()
{
}
//ausgabe function
void Buch::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Autor: " << autor << std::endl;
}
