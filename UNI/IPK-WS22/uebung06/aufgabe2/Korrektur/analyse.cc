#include "point.hh"
#include <array>
#include <iostream>


int main() {
    // default constructor
    Point<float, 5> default_point_5;
    Point<int, 0> default_point_0;

    // array constructor
    std::array<long, 5> long_array = {1, 4, 5, 5, 3};
    std::array<double, 1> double_array = {1.123};

    Point<short, 4> short_point_4{{3, 4, -2, 4}};
    Point<long, 5> long_point_5(long_array);
    Point<double, 1> double_point_1(double_array);

    // unequal lenght of point and array
    //Point<short, 4> short_point_4{{3}};

    // point with negative dimension -> eigentlich hätte in der Aufgabe stehen müssen: static unsigned int dim;
    //Point<int, -1> negative_point;


    // get coordinate
    for (int i = 0; i < 5; i++) {
        if (default_point_5.x(i) != 0)
            std::cerr << "Default Point has values != 0\n";
    }

    for (int i = 0; i < 5; i++) {
        if (long_point_5.x(i) != long_array[i])
            std::cerr << "long_point_5 has wrong values\n";
    }


    // set coordinate
    default_point_5.x(1) = 4;
    if (default_point_5.x(1) != 4)
        std::cerr << "Cant set a new value to a Point\n";


    /* error handling */
    // get coordinate outside dimenstion
    try {
        float dummy = default_point_5.x(100);
        dummy = default_point_5.x(-23);
        std::cerr << "You can access indexes outside the dimension of the point" << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cerr << "=> Error occurred when accessing an index outside the dimension of the point" << std::endl;
    }

    // set coordinate outside dimenstion
    try {
        default_point_5.x(100) = 12.324;
        default_point_5.x(-23) = 12.324;
        std::cerr << "You can write to an index outside of the dimension of the point" << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cerr << "=> Error occurred when accessing an index outside the dimension of the point" << std::endl;
    }

    // norm
    if (short_point_4.norm() - 6.7082 > 0.001)
        std::cerr << "Wrong norm: " << short_point_4.norm() << " != 6" << std::endl;
    if (default_point_0.norm() != 0)
        std::cerr << "Wrong norm: " << default_point_0.norm() << " != 0" << std::endl;
    if (double_point_1.norm() - double_array[0] > 0.01)
        std::cerr << "Wrong norm: " << double_point_1.norm() << " != " << double_array[0] << std::endl;


    /* index operator */
    // get coordinate
    for (int i = 0; i < 5 && i != 1; i++) {
        if (default_point_5[i] != 0)
            std::cerr << "Default Point has values unequal 0. Index: " << i << " Value: " << default_point_5[i] << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        if (long_point_5[i] != long_array[i])
            std::cerr << "long_point_5 has wrong values"  << std::endl;
    }


    // set coordinate
    default_point_5[0] = 4;
    if (default_point_5[0] != 4)
        std::cerr << "Can't set a new value to a Point";


    return 0;
}
