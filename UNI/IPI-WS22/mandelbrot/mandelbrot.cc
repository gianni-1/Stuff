#include <iostream>
#include <cmath>
#include <string>

// Datentyp Complex in der Datei canvas.hh
#include "canvas.hh"

// Summiert zwei komplexe Zahlen z und c und schreibt das Ergebnis in z
void add_complex( Complex& c,Complex& b/* TODO Typ z, Typ c */ )
{
  c.real=c.real+ b.real;
  c.imag =c.imag+ b.imag ;
  // TODO
}

// Multipliziert zwei komplexe Zahlen z und c und schreibt das Ergebnis in z
void multiply_complex( Complex& c,Complex& b/* TODO Typ z, Typ c */)
{
  double tempcreal=c.real;
  double tempcimag=c.imag;

  double tempbreal=b.real;
  double tempbimag=b.imag;

  c.real= tempcreal*tempbreal-tempcimag*tempbimag;
  c.imag=tempcreal*tempbimag+tempcimag*tempcreal;
  // TODO
}

// Betrag einer komplexen Zahl
double betrag(Complex z)
{
  double wert;
  wert=std::sqrt(z.real*z.real+z.imag*z.imag);
  return wert;
  // TODO Nutzen Sie std::sqrt zur Wsurzelberechnung
}

// TODO Funktion mandelbrot()
void mandelbrot(Canvas& canvas, double threshold, int maxIt, std::string filename){
  int width = canvas.horPixels();
  int height= canvas.vertPixels();

  for(int i=0; i<height;i++){
    for(int j=0; j<width;j++){
      Complex c = canvas.coord(i,j);                           //das ist das c aus der allgemeinen mandelbrot formel
      Complex z;                                                 //unser z0=0
      z.real=0;
      z.imag=0;
      int iter= 0;

      while(betrag(z)<threshold && iter<maxIt){
        multiply_complex(z,z);
        add_complex(z,c);
        iter++;
      }

      if(betrag(z)<threshold){
        canvas.writePixel(i,j,0);
      }

      else{
        double logIter= std::log(iter);
        int grey = static_cast<int>(std::max(logIter-1, 0.0)*100);
        canvas.writePixel(i,j,grey);
      }
    }
  }
  canvas.write(filename);
}

int main()
{
  double threshold = 1000;
  int maxIt = 1000;
  double center_x = -1;
  double center_y = 0;
  double width = 6;
  double height = 5;
  int horpixels = 4000;
  int vertpixels = 3000;
  std::string filename="mandelbrot.pgm";

  Canvas cc(center_x,center_y,width,height,horpixels,vertpixels);

  mandelbrot(cc,threshold,maxIt,filename);
  // unsigned int width = 400;
  // unsigned int height = 300;

  // int* pixels= new int[width*height];

  // for(int i= 0; i<width;i++){
  //   for(int j=0;j<height;j++){
  //     double i2= static_cast<double>(i)/(width-1);
  //     double j2= static_cast<double>(j)/(height-1);

  //     double len = std::sqrt(i2*i2 + j2*j2);

  //   }
  // }

  return 0;
}
