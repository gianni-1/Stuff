#include "canvas.hh"

// X und Y Koordinaten sind vertauscht

//Aufgabe 1b)
Canvas::Canvas(const Point& center,double width, double height, int horPixels, int vertPixels)
    : _center(center),
      _width(width),
      _height(height),
      _horPixels(horPixels),
      _vertPixels(vertPixels),
      _pixels(horPixels,std::vector<int>(vertPixels,0))
      {}

//Aufgabe 1c)
int Canvas::brightness(int i, int j) const{
    return _pixels[i][j];
}

//Aufgabe 1d)
void Canvas::setBrightness(int i ,int j,int brightness){
    _pixels[i][j]=brightness;
}

//Aufgabe 1e)
Point Canvas::coord(int i, int j) const{
    double x = _center.x();
    double x2 = _width/_vertPixels;
    i-= _vertPixels /2 ;
    x+= i*x2;

    double y = _center.y();
    double y2 = _height /_horPixels;
    j-= _horPixels /2;
    y+= j*y2;
    return {x,y};


}

//Aufgabe 1f)
void Canvas::write(const std::string& filename) const{
    write_pgm(_pixels, filename);
}
