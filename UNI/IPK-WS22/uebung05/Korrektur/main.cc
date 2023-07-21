#include "point.hh"
#include "polygon.hh"
#include <iostream>
#include <cmath>
//c)

/*
Gut gelöst.

Tipp:   Führt gerne mein Analyseprogramm, das ich mir geschrieben habe aus.
        Ich habe es bereits in der CMakeLists.txt hinzugefügt. Fühlt euch
        auch frei den Code in der analyse.cc durchzulese, um herauszufinden,
        was ich sonst so überprüft habe.
*/

int main()
{
    Point p1;
    Point p2(2.0,3.1);

    std::cout << "Punkt 1: " << p1.x() << " " << p1.y() << std::endl << "Punkt 2: " << p2.x() << " " << p2.y() << std::endl;

    Polygon pol1({p1,p2});
    Polygon pol2({2.4, 3.2, 1.2, 0.5, -5.2}, {3.0, 3.1, 4.2, -1.5, 0.2});

    std::cout << "Ecken des ersten Polygons: " << std::endl;
    for(int i=0;i<pol1.corners();i++)
    {
        std::cout << pol1.corner(i).x() << " " << pol1.corner(i).y() << std::endl;
    } 
    std::cout << "Ecken des zweiten Polygons: " << std::endl;
    for(int i=0;i<pol2.corners();i++)
    {
        std::cout << pol2.corner(i).x() << " " << pol2.corner(i).y() << std::endl;
    } 

    //Aufgabe 2 b)

    const double pi = M_PI;

    for(int n=1;n<10;n++)
    {
        std::vector<Point> nEckPunkte;
        for(int i=1;i<=n;i++)
        {
            Point Eck(std::cos(2*pi*i/n), std::sin(2*pi*i/n));
            nEckPunkte.push_back(Eck);
        }
        Polygon nEck(nEckPunkte);
        std::cout << "Volumen vom " << n << " Eck: " << nEck.volume() << std::endl;
    }
    //Aufgabe c)
    Polygon ueberschneidung({2,4,7,1},{1,4,1,3});
    /* -0.5 P
    Beschreibung fehlt.
    */
    std::cout << "Volumen eines überschneidenden Polygons: " << ueberschneidung.volume() << std::endl;
    
   

    return 0;
}