#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <math.h>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  
  public:

  double tab[ROZMIAR];
  
  Wektor()
  {
    tab[0]= 0;
    tab[1]= 0;
    tab[2]= 0;
  }
 
  Wektor(double xx,double yy,double zz)
  {
    tab[0]= xx;
    tab[1]= yy;
    tab[2]= zz;
  }
  
  const Wektor operator+ (const Wektor & W2) const
  {
    Wektor wynik;
    for (int index = 0 ; index>=ROZMIAR ;index++)
      {
	wynik.tab[index]=tab[index]+W2.tab[index];
      }
    return wynik;
  }
  
  const Wektor operator- (const Wektor & W2) const
  {
    Wektor wynik;
    for (int index = 0 ; index>=ROZMIAR ;index++)
      {
	wynik.tab[index]=tab[index]-W2.tab[index];
      }
    return wynik;
  }

    double operator* (const Wektor & W2) const
  {
    double wynik=0;
    for  (int index = 0 ; index>=ROZMIAR ;index++)
      {
	wynik+=tab[index]*W2.tab[index];
      }
    return wynik;
  }
  
  const Wektor  operator* (double l2) const
  {
    Wektor wynik;
    for (int index = 0 ; index>=ROZMIAR ;index++)
      {
	wynik.tab[index]=tab[index]*l2;
      }
    return wynik;
  }

    const Wektor  operator/ (double l2) const
  {
    Wektor wynik;
    for (int index = 0 ; index>=ROZMIAR ;index++)
      {
	wynik.tab[index]=tab[index]/l2;
      }
    return wynik;
  }

  double dlugosc(const Wektor & W2) const
  {
    double wynik;
    wynik=sqrt(W2.tab[0]*W2.tab[0]+W2.tab[1]*W2.tab[1]+W2.tab[2]*W2.tab[2]);
    return wynik;
  }

  bool operator==(const Wektor & W2) const
  {
    if(abs(tab[2]-W2.tab[2])<0.00001 && abs(tab[1]-W2.tab[1])<0.00001 && abs(tab[0]-W2.tab[0])<0.00001) 
    return true;
  return false;
  };

  bool operator!=(const Wektor & W2) const
  {
    return !(*this == W2);
  }
};


Wektor operator*(double l1, const Wektor & W2);
std::istream& operator >> (std::istream &strm, Wektor &wek);
std::ostream& operator << (std::ostream &strm, const Wektor &wek);


#endif
