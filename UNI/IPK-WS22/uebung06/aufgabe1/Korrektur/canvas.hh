#pragma once 
#include "point.cc"
#include <vector>
#include <iostream>
#include "pgm.cc"


class Canvas{
    //Aufgabe 1a)
    int _horPixels;
    int _vertPixels;
    const Point _center;
    double _height,_width;
    std::vector<std::vector<int>> _pixels; 

    

    public:
    //Aufgabe 1b)
    Canvas(const Point& center,double width, double height, int horPixels, int _vertPixels);
    
    //Aufgabe 1c)
    int brightness(int i, int j) const;

    //Aufgabe 1d)
    void setBrightness(int i, int j, int brightness);

    //Aufgabe 1e)
    Point coord(int i,int j) const;

    //Aufgabe 1f)
    void write(const std::string& filename) const;



};