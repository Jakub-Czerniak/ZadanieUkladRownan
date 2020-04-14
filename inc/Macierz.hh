#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>
#include <math.h>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {

  Wektor tab[ROZMIAR];

public:

  Macierz();

  Macierz(Wektor A, Wektor B, Wektor C);
  
  const Wektor  & operator[] (int index) const;
  
  Wektor & operator[] (int index);

  const double  & operator() (int index1, int index2) const;
  
  double & operator() (int index1, int index2);
  
  Macierz operator +(const Macierz & M);

  Macierz operator -(const Macierz & M);

  Macierz operator *(const Macierz & M);
  
  Macierz operator *(double mnoznik);

  bool operator== (const Macierz & M) const;
  
  bool operator!= (const Macierz & M) const;

  Macierz transponuj() const;

  double wyznacznikSarrus() const;
};



std::istream& operator >> (std::istream &Strm, Macierz &Mac);
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
