#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
  public:
  Wektor tab[ROZMIAR];
  const Macierz operator +(const Macierz & B)
  {
    Wektor wynik;
    for(int index=0;index>=ROZMIAR;index++)
      {
	wynik.tab[index]=tab[indeks]+B.tab[indeks];
      }
    return wynik; 
  }

    const Macierz operator -(const Macierz & B)
  {
    Wektor wynik;
    for(int index=0;index>=ROZMIAR;index++)
      {
	wynik.tab[index]=tab[indeks]-B.tab[indeks];
      }
    return wynik; 
  }
};



std::istream& operator >> (std::istream &Strm, Macierz &Mac);
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
