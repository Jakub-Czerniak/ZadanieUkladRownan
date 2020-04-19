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

Macierz UklRowL::get_A() const
{
  Macierz Mac;
  Mac=A;
  
  return Mac;
}

Wektor UklRowL::get_B() const
{
  Wektor Wek;
  Wek=B;
  
  return Wek;
}

void UklRowL::set_A(const Macierz AA)
{
  A=AA;
}

void UklRowL::set_B(const Wektor BB)
{
  B=BB;
}



Wektor UklRowL::Oblicz() const //metoda Cramera
{
  double Wyz, WyzX, WyzY, WyzZ;
  double X, Y, Z;
  Macierz MacX, MacY, MacZ;
  
  MacX=A.transponuj();
  MacX[0]=B;
  MacX=MacX.transponuj();

  MacY=A.transponuj();
  MacY[1]=B;
  MacY=MacY.transponuj();

  MacZ=A.transponuj();
  MacZ[2]=B;
  MacZ=MacZ.transponuj();


  Wyz=A.wyznacznikSarrus();
  WyzX=MacX.wyznacznikSarrus();
  WyzY=MacY.wyznacznikSarrus();
  WyzZ=MacZ.wyznacznikSarrus();
  
  X=WyzX/Wyz;
  Y=WyzY/Wyz;
  Z=WyzZ/Wyz;

  Wektor wynik(X,Y,Z);
  
  return wynik;
}


Wektor WBledu(Macierz A, Wektor B, Wektor X)
{
  Wektor wynik;

  for(int w=0;w<ROZMIAR;w++)
    for(int k=0;k<ROZMIAR;k++)
      wynik[w]=wynik[w]+A(w,k)*X[k];

  for(int w=0;w<ROZMIAR;w++)
    wynik[w]=wynik[w]-B[w];
  
  return wynik;
}


std::istream &operator >> (std::istream &strm, UklRowL &U)
{
  Macierz pomA;
  Wektor pomB;

  strm >> pomA >> pomB;
  U.set_A(pomA);
  U.set_B(pomB);

  return strm;
}

std::ostream& operator << (std::ostream &strm, const UklRowL &U)
{
  strm << U.get_A() << U.get_B();

  return strm;
}

  
