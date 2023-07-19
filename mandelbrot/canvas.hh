#include <string>
#include "pgm.hh"

struct Complex
{
  double real;
  double imag;

  Complex operator()(int i, int j){
    Complex k;
    k.real=i;
    k.imag=j;
    return k;
  }
};

class Canvas
{
public :
  // Konstruktor, erzeuge int* _pixels
  Canvas(double center_x, double center_y,
         double width, double height,
         int horPixels, int vertPixels);

  // Desktruktor, raeume int* _pixels auf
  ~Canvas();

  // gibt die Breite des Bildes zurueck
  double width();

  // gibt die Hoehe des Bildes zurueck
  double height();

  // gibt die Anzahl an horizontalen Pixeln
  int horPixels();

  // gibt die Anzahl an vertikalen Pixeln
  int vertPixels();

  // gebe die Koordinaten des Pixels (i,j) als Complex zurueck
  Complex coord(int i, int j);

  // schreibe value an den Pixel (i,j)
  // Ueberlegen Sie wie aus (i,j) den flachen Index bei row-major bekommen
  void writePixel(int i, int j, int value);

  // Zugang zum Pixel (i,j) im 1D Array
  // Ueberlegen Sie wie aus (i,j) den flachen Index bei row-major bekommen
  int operator()(int i, int j);

  // schreibe Bild mit Dateinamen filename
  void write(std::string filename);
private :
  double _center_x;
  double _center_y;
  double _width;
  double _height;
  int _horPixels;
  int _vertPixels;
  int* _pixels;
};

Canvas::Canvas(double center_x, double center_y,
         double width, double height,
         int horPixels, int vertPixels)
         :
          _center_x(center_x),_center_y(center_y),
        _width(width),_height(height),_horPixels(horPixels),
        _vertPixels(vertPixels){_pixels=new int[horPixels * vertPixels];}


Canvas::~Canvas(){
  delete[] _pixels;
}

// diese Methode ist bereits implementiert
void Canvas::write(std::string filename)
{
  write_pgm(_pixels,_horPixels,_vertPixels,filename);
}

double Canvas::width(){
  return _width;
}

double Canvas::height(){
  return _height;
}

int Canvas::horPixels(){
  return _horPixels;
}

int Canvas::vertPixels(){
  return _vertPixels;
}

Complex Canvas::coord(int i, int j){
  double x=  _center_x - 0.5 * _width + (static_cast<double>(i)-0.5)*_width/_horPixels;
  double y=  _center_y - 0.5 * _height + (static_cast<double>(j)-0.5)* _height / _vertPixels;   // j-0.5
  // double x= _center_x+((static_cast<double>(i)/(_horPixels-1)-0.5)*_width);
  // double y= _center_y+(static_cast<double>(j)/(_vertPixels-1)-0.5)*_height;



  Complex neu;
  neu.real = x;
  neu.imag=y;
  return neu;
}

void Canvas::writePixel(int i, int j, int value){
 
  int index = j +_horPixels*(_vertPixels-1-i);    
  _pixels[index]=value;
}

int Canvas::operator()(int i, int j){
  int index = j +_horPixels*(_vertPixels-1-i);    
  return _pixels[index];
}




