#include "polygon.hh"

Polygon::Polygon(const std::vector<Point>& corners)
: _intList(corners)
{


}
Polygon::Polygon(const std::vector<double>& x, const std::vector<double>& y)
{

    /* -0.5 P
    Ihr habt den Fall nicht abgefangen, dass man Vektoren unterschiedlicher Größe erhält.
    Möglichkeiten wären, nur die Punkte zu akzeptieren, bei denen es sowohl einen y- wie
    auch x-Wert gibt oder mann füllt die Fehlenden Werte mit nullen auf.
    */

    for(int i=0;i<x.size();i++)
    {
        Point p(x[i],y[i]);
        _intList.push_back(p);
    }

}
std::size_t Polygon::corners() const
{
    return _intList.size();
}
const Point& Polygon::corner(std::size_t i) const
{
    /* -0.5 P
    Ihr lasst es zu, dass man auf negative Ecken und auf Ecken zugreifen kann, die
    außerhalb eures Polynoms liegen. Kann zu einem Segmentationfault führen -> Programmabsturz.
    */

    return _intList[i];
}

//Aufgabe 2

double Polygon::volume() const
{
    if(_intList.size()<3)
        return 0;
    double sum=0;
    for(int i=0;i<_intList.size()-1;i++)
    {
        sum+=_intList[i].x()*_intList[i+1].y()-_intList[i+1].x()*_intList[i].y();
    }
    sum += _intList[_intList.size()-1].x()*_intList[0].y() - _intList[0].x()*_intList[_intList.size()-1].y();
    sum /= 2;
    return sum;
}