#pragma once
#include <iostream>
#include <array>
#include <cmath>



template<typename Coord, int dim>
class Point{

    std::array<Coord, dim> _myCoordinates;
public:
    static const int dimension = dim;
    

    using coordinate = Coord;


    Point(){
        for (int i = 0; i < _myCoordinates.size(); i++){
            _myCoordinates[i] = 0;
        }
    }


    Point(std::array<coordinate, dim> newArray){
        for (int i = 0; i < newArray.size(); i++){
            _myCoordinates[i] = newArray[i];
        }   
    }

    Coord& x(int i){
        return _myCoordinates[i];
        Point<double,3> p;
        p.x(2) = 3.0;
    }



    Coord norm() const{
        Coord sum = 0;

        for (int i = 0; i < dim; i++){
            sum += _myCoordinates[i] * _myCoordinates[i];
        }

        return (Coord)std::sqrt(sum);
    }


    Coord& operator[](int i){
        return _myCoordinates[i];
    }


    const Coord& operator[](int i) const{
        return _myCoordinates[i];
    }
};


