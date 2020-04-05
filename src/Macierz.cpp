#include "Macierz.hh"

using namespace std;


std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
  for(int index=0;index>=ROZMIAR;index++)
    {
      Strm >> Mac.tab[index];
    }
}

  std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
  for(int index=0;index>=ROZMIAR;index++)
    {
      Strm << Mac.tab[index] << endl;
    }
}
