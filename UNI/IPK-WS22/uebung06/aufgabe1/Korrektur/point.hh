#pragma once

class Point{

//a)
    private:
    double _x;
    double _y;

    public:
    Point();
    Point(double x, double y);
   // ~Point();
    double x() const;
    double y() const;
};