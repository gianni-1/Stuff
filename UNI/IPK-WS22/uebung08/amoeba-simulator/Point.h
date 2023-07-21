//
// Created by Lorenz Braun on 12.01.22.
//

#ifndef AMOEBA_SIM_POINT_H
#define AMOEBA_SIM_POINT_H

class Point {
public:
  float x = 0;
  float y = 0;

  Point(float x, float y);

  float dist() const;
  Point scaleToLen(float len);

  Point operator+(Point other);
  Point& operator+=(Point other);
  Point operator*(float factor);
  Point operator-(Point other);

};

#endif //AMOEBA_SIM_POINT_H
