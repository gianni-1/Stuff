#include "point.hh"
#include "polygon.hh"
#include <iostream>
#include <cmath>
#include <array>

// auxiliary functions
Point calc_point(unsigned int j, unsigned int n) {
    auto p = Point(std::cos(j * 2 * M_PI / n), std::sin(j * 2 * M_PI / n));
    return p;
}

void run_test() {
    // test-values
    const double x_vec_0 = 2.12;
    const double x_vec_1 = 4;
    const double x_vec_2 = 35;
    const double x_vec_3 = 5;
    const double x_vec_4 = 0;

    const double y_vec_0 = 22;
    const double y_vec_1 = 3.34;
    const double y_vec_2 = 4.22;
    const double y_vec_3 = 6;
    const double y_vec_4 = 1;

    // points
    auto p0 = Point();
    auto p1 = Point(1, 1);
    auto p2 = Point(1, 0);
    auto p3 = Point(0, 1);

    // point vectors
    std::vector<Point> p_vec = {{p0, p1, p2, p3}};

    std::vector<double> x_vec_small = {{x_vec_0, x_vec_1}};
    std::vector<double> y_vec_small = {{y_vec_0, y_vec_1}};

    std::vector<double> x_vec_large = {{x_vec_0, x_vec_1, x_vec_2, x_vec_3, x_vec_4}};
    std::vector<double> y_vec_large = {{y_vec_0, y_vec_1, y_vec_2, y_vec_3, y_vec_4}};

    // test polygon construcrots
    auto poly4 = Polygon(p_vec);                    // poly-number is = corners
    auto poly2 = Polygon(x_vec_small, y_vec_small);
    auto poly5 = Polygon(x_vec_large, y_vec_large);
    
    // does it work with vectors of unequal size
    auto poly2_small = Polygon(p_vec);
    auto poly2_large = Polygon(p_vec);
    try {
        poly2_small = Polygon(x_vec_small, y_vec_large);    // shoud only have 2 corners
        poly2_large = Polygon(x_vec_large, y_vec_small);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "Polygone constructor does not work for vectors of unequal size" << std::endl;
    }
    
    // test polygon methods
    // .corners
    if (poly4.corners() != 4)
        std::cerr << "poly4: Number of courners is wrong. Shoud be 4 instead of " << poly4.corners() << std::endl;
    if (poly2.corners() != 2)
        std::cerr << "poly2: Number of courners is wrong. Shoud be 2 instead of " << poly4.corners() << std::endl;
    if (poly5.corners() != 5)
        std::cerr << "poly5: Number of courners is wrong. Shoud be 5 instead of " << poly4.corners() << std::endl;
    if (poly2_small.corners() != 2)
        std::cerr << "poly2_small: Number of courners is wrong. Shoud be 2 instead of " << poly4.corners() << std::endl;
    if (poly2_large.corners() != 2)
        std::cerr << "poly2_large: Number of courners is wrong. Shoud be 2 instead of " << poly4.corners() << std::endl;
    
    // .corner (you can start counting at 0 or 1 )
    if ((poly4.corner(2).x() != p2.x() || (poly4.corner(2).y() != p2.y())) &&
        (poly4.corner(2).x() != p1.x() || (poly4.corner(2).y() != p1.y())))
            std::cerr << "poly4: Returns wrong corner" << std::endl;
    
    if ((poly2.corner(1).x() != x_vec_1 || (poly2.corner(1).y() != y_vec_1)) &&
        (poly2.corner(1).x() != x_vec_0 || (poly2.corner(1).y() != y_vec_0)))
            std::cerr << "poly2: Retruns wrong corner" << std::endl;
 
    if ((poly5.corner(4).x() != x_vec_4 || (poly5.corner(4).y() != y_vec_4)) &&
        (poly5.corner(4).x() != x_vec_3 || (poly5.corner(4).y() != y_vec_3)))
            std::cerr << "poly5: Retruns wrong corner" << std::endl;

    if ((poly2_small.corner(1).x() != x_vec_1 || (poly2_small.corner(1).y() != y_vec_1)) &&
        (poly2_small.corner(1).x() != x_vec_0 || (poly2_small.corner(1).y() != y_vec_0)))
            std::cerr << "poly2_small: Retruns wrong corner" << std::endl;

    if ((poly2_large.corner(1).x() != x_vec_1 || (poly2_large.corner(1).y() != y_vec_1)) &&
        (poly2_large.corner(1).x() != x_vec_0 || (poly2_large.corner(1).y() != y_vec_0)))
            std::cerr << "poly2_large: Retruns wrong corner" << std::endl;
        
    // can you get not exitsting corners
    try {
        // you coud say i-th corner is the i-th mod .corners corner
        if (poly4.corner(5).x() != poly4.corner(5 - 4).x() || !std::isnan(poly4.corner(-1).x()))
            std::cerr << "You can get negative corners or corners that are outside the polygon" << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n' << "This error occours by trying to get a non-existing corner" << std::endl;
    }
    

    // .volume
    for (int i = 0; i <= 8; i += 2) {
        // create polygon
        std::vector<Point> point_vector(i);
        for (int j = 0; j < i; j++)
            point_vector.at(j) = calc_point(j+1, i);
        auto polygon = Polygon(point_vector);

        // array with solution
        std::array<double, 9> solution_volumes = {0, 0, 2, 2.59807621135, 2.82842712475};
        
        // test
        if (std::abs(polygon.volume() - solution_volumes[i / 2]) > 0.001)
            std::cerr << "Wrong volume for " << i << " corners: " << polygon.volume() << " != " << solution_volumes[i/2] << std::endl;
    }   
}

int main() {
    // test nr 1
    try {
        run_test();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
} 