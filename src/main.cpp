#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"




using namespace std;


int main()
{
  Wektor Raz=Wektor(1,1,1);
  Wektor Dwa=Wektor(2,-1,2);
  Wektor Trzy=Wektor(3,12,-5);
  Macierz MTrzy=Macierz(Raz,Dwa,Wektor(3,2,-1));
  UklRowL Rozw=UklRowL(MTrzy, Trzy);

  Trzy=Rozw.Oblicz();
  cout << Trzy;
  cout << endl << " Start programu " << endl << endl;
}
