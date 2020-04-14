#include "UkladRownanLiniowych.hh"
using namespace std;

UklRowL::UklRowL()
{
  A=Macierz();
  B=Wektor();
}

UklRowL::UklRowL(const Macierz &Mac, const Wektor &Wek)
{
  A=Mac;
  B=Wek;
}


Wektor UklRowL::Oblicz() const
{
  double Wyz, WyzX, WyzY, WyzZ;
  double X, Y, Z;
  Macierz MacX, MacY, MacZ;
  
  MacX=A.transponuj();
  MacX[0]=B;
  MacX=MacX.transponuj();
  cout << MacX;

  MacY=A.transponuj();
  MacY[1]=B;
  MacY=MacY.transponuj();
  cout << MacY;

  MacZ=A.transponuj();
  MacZ[2]=B;
  MacZ=MacZ.transponuj();
  cout << MacZ;


  Wyz=A.wyznacznikSarrus();
  cout << Wyz << endl;
  WyzX=MacX.wyznacznikSarrus();
  cout << WyzX << endl;
  WyzY=MacY.wyznacznikSarrus();
  cout << WyzY << endl;
  WyzZ=MacZ.wyznacznikSarrus();
  cout << WyzZ << endl;
  
  X=WyzX/Wyz;
  Y=WyzY/Wyz;
  Z=WyzZ/Wyz;

  Wektor wynik(X,Y,Z);
  
  return wynik;
}
