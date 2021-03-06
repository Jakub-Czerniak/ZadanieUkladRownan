#include "Wektor.hh"

using namespace std; 



Wektor::Wektor()
{
  tab[0]= 0;
  tab[1]= 0;
  tab[2]= 0;
}

Wektor::Wektor(double xx,double yy,double zz)
{
  tab[0]= xx;
  tab[1]= yy;
  tab[2]= zz;
}

const double & Wektor::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Index poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

double & Wektor::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Index poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

Wektor Wektor::operator+ (const Wektor &W2) const
{
  Wektor wynik;
  for (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik[index]=tab[index]+W2[index];
    }
  return wynik;
}

Wektor Wektor::operator- (const Wektor & W2) const
{
  Wektor wynik;
  for (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik[index]=tab[index]-W2[index];
    }
  return wynik;
}

double Wektor::operator* (const Wektor & W2) const
{
  double wynik=0;
  for  (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik+=tab[index]*W2[index];
    }
  return wynik;
}

Wektor Wektor::operator* (double l2) const
{
  Wektor wynik;
  for (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik[index]=tab[index]*l2;
    }
  return wynik;
}

Wektor  Wektor::operator/ (double l2) const
{
  Wektor wynik;
  if(abs(l2)<0.00001)
    {
      cerr << "Dzielenie przez 0" << endl;
      exit(1);
    }
  for (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik[index]=tab[index]/l2;
    }
  return wynik;
}

double Wektor::dlugosc() const
{
  double wynik;
  wynik=sqrt(tab[0]*tab[0]+tab[1]*tab[1]+tab[2]*tab[2]);
  return wynik;
}

bool Wektor::operator==(const Wektor & W2) const
{
  if(abs(tab[2]-W2[2])<0.00001 && abs(tab[1]-W2[1])<0.00001 && abs(tab[0]-W2[0])<0.00001) 
    return true;
  return false;
}

bool Wektor::operator!=(const Wektor & W2) const
{
  return !(*this == W2);
}


std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
  Strm >> Wek[0] >> Wek[1] >> Wek[2];
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
  Strm << Wek[0]<< ' ' << Wek[1] << ' ' << Wek[2] << endl;
  return Strm;
}

Wektor operator*(double l1, const Wektor & W2)
{
 Wektor wynik;
    for (int index = 0 ; index<ROZMIAR ;index++)
      {
	wynik[index]=l1*W2[index];
      }
    return wynik;
}
