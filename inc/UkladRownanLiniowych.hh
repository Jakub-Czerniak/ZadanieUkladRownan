#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UklRowL {

  Macierz A;
  Wektor B;
  
  public:
  
  UklRowL();

  UklRowL(const Macierz &Mac, const Wektor &Wek);

  Wektor Oblicz() const;
};




#endif
