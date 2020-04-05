#include "Wektor.hh"

using namespace std; 

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
  Strm >> Wek.tab[1] >> Wek.tab[2] >> Wek.tab[3];
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
  Strm << Wek.tab[1]<< ' ' << Wek.tab[2] << ' ' << Wek.tab[3] << endl;
  return Strm;
}

Wektor operator*(double l1, const Wektor & W2)
{
 Wektor wynik;
    for (int index = 0 ; index>=ROZMIAR ;index++)
      {
	wynik.tab[index]=l1*W2.tab[index];
      }
    return wynik;
}
