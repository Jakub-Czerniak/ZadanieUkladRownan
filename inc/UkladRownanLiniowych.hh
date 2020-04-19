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

  Macierz get_A() const;
  
  Wektor get_B() const;

  void set_A(const Macierz AA);

  void set_B(const Wektor BB);

  Wektor Oblicz() const;
};

Wektor WBledu(Macierz A, Wektor B, Wektor X);

std::istream &operator >> (std::istream &strm, UklRowL &U);

std::ostream& operator << (std::ostream &strm, const UklRowL &U);

#endif
