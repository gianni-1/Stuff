#pragma once
#include <vector>
#include "point.hh"

class Polygon
{
    private:
    std::vector<Point> _intList;

    public:
    Polygon(const std::vector<Point>& corners);
    Polygon(const std::vector<double>& x, const std::vector<double>& y);
    std::size_t corners() const;
    const Point& corner(std::size_t i) const;
    
    //Aufgabe 2
    double volume() const;
};