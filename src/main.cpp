#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;



int main()
{
  Macierz A;
  Wektor B;
  Wektor Rozw;
  Wektor WBlad;
  ifstream plik;

  plik.open("dane");
  plik >> A >> B;
  cout << "Macierz:" << endl;
  cout << A;
  cout << "Wektor wyrazow wolnych:" << endl;
  cout << B;
  UklRowL Rown(A,B);
  Rozw=Rown.Oblicz();
  cout << "Rozwiazanie x = (x1, x2, x3):" << endl;
  cout << Rozw;

  WBlad=WBledu(A,B,Rozw);
  cout << "Wektor bledu: Ax-B= " << WBlad;
  cout << "Dlugosc wektora bledu: ||Ax-B||= " << WBlad.dlugosc();  
  
  
  cout << endl << " Konczenie dzialania programu programu " << endl << endl;
}
