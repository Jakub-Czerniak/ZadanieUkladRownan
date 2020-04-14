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

  double tab[ROZMIAR];
  
public:

  Wektor();
 
  Wektor(double xx,double yy,double zz);

  const double &operator[] (int index) const;

  double &operator[] (int index);
  
  Wektor operator+ (const Wektor & W2) const;
  
  Wektor operator- (const Wektor & W2) const;

  double operator* (const Wektor & W2) const;

  Wektor  operator* (double l2) const;

  Wektor  operator/ (double l2) const;

  double dlugosc() const;

  bool operator==(const Wektor & W2) const;

  bool operator!=(const Wektor & W2) const;

};


Wektor operator*(double l1, const Wektor & W2);
std::istream& operator >> (std::istream &strm, Wektor &wek);
std::ostream& operator << (std::ostream &strm, const Wektor &wek);


#endif
