//
// Created by Lorenz Braun on 12.01.22.
//
#include <cmath>

#include "Point.h"

Point::Point(float x, float y) : x(x), y(y) {}

Point Point::operator-(Point other) {
  return Point(this->x - other.x, this->y - other.y);
}

float Point::dist() const{
  return std::sqrt(x*x + y*y);
}

Point Point::operator*(float factor) {
    return Point(x*factor,y*factor);
}

Point &Point::operator+=(Point other) {
  x+=other.x;
  y+=other.y;
  return *this;
}

Point Point::scaleToLen(float len) {
  float scaleFactor = len/this->dist();
  return (*this)*scaleFactor;
}
Point Point::operator+(Point other) {
  return Point(this->x + other.x, this->y + other.y);
}
