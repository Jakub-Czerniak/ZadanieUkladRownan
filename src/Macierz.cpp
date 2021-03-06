
#include "Macierz.hh"



using namespace std;


Macierz::Macierz()
{
  for(int i;i<ROZMIAR;i++)
    for(int k; k<ROZMIAR;k++)
      tab[i][k]=0;
}

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
{
  tab[0]=A;
  tab[1]=B;
  tab[2]=C;
}

const Wektor & Macierz::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR)
    {
       cerr << "Index poza zakresem" << endl;
       exit(1);
    }
  return tab[index];  
}

Wektor & Macierz::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "Index poza zakresem" << endl;
      exit(1);
    }
  return tab[index];
}

const double & Macierz::operator() (int index1, int index2) const
{
  if (index1 < 0 || index1 >= ROZMIAR || index2 < 0 || index2 >= ROZMIAR)
    {
      cerr << "Index poza zakresem" << endl;
      exit(1);
    }
  return tab[index1][index2];
}

double & Macierz::operator() (int index1, int index2)
{
  if (index1 < 0 || index1 >= ROZMIAR || index2 < 0 || index2 >= ROZMIAR)
    {
      cerr << "Indeks poza zakresem" << endl;
      exit(1);
    }
  return tab[index1][index2];
}

Macierz Macierz::operator +(const Macierz & M)
{
  Macierz wynik;
  for(int index=0;index<ROZMIAR;index++)
    {
      wynik[index]=tab[index]+M[index];
    }
  return wynik; 
}

Macierz Macierz::operator -(const Macierz & M)
{
  Macierz wynik;
  for(int index=0;index<ROZMIAR;index++)
    {
      wynik[index]=tab[index]-M[index];
    }
  return wynik; 
}

Macierz Macierz::operator *(const Macierz & M)
  {
    Macierz wynik;
    Macierz MPom=M;

    MPom=MPom.transponuj();
    for(int i=0;i<ROZMIAR;i++)
      for(int k=0; k<ROZMIAR;k++)
	wynik(i,k)=tab[i]*MPom[k];
    
    return wynik;
  }
  
Macierz Macierz::operator *(double mnoznik)
  {
    Macierz wynik;
  for(int index=0;index<ROZMIAR;index++)
    wynik[index]=tab[index]*mnoznik;

  return wynik;
  }

Macierz Macierz::transponuj() const
{
  Macierz wynik;
  
  for(int i=0;i<ROZMIAR;i++)
    for(int k=0; k<ROZMIAR;k++)
      wynik(i,k)=tab[k][i];
    
  return wynik;
}


double Macierz::wyznacznikSarrus() const
{
  double wynik;
  
  wynik= tab[0][0]*tab[1][1]*tab[2][2]+tab[0][1]*tab[1][2]*tab[2][0]+
    tab[0][2]*tab[1][0]*tab[2][1]-tab[2][0]*tab[1][1]*tab[0][2]-
    tab[2][1]*tab[1][2]*tab[0][0]-tab[2][2]*tab[1][0]*tab[0][1];

  return wynik;
}



bool Macierz::operator== (const Macierz & M) const
  {
  for(int index=0;index<ROZMIAR;index++)
    {
      if(tab[index]!=M[index])
	return false;
    }
  return true;
  }
  
bool Macierz::operator!= (const Macierz & M) const
  {
 return !(*this == M);
  }



std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
  for(int index=0;index<ROZMIAR;index++)
    {
      Strm >> Mac[index];
    }
  return Strm;
}

  std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
  for(int index=0;index<ROZMIAR;index++)
    {
      Strm << Mac[index];
    }
  return Strm;
}
