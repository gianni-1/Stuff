#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

class Shape {
 public:
  virtual std::string name() const = 0;

  virtual int dimension() const { return 0; }

  virtual double volume() const { return 0.0; }
};

class Point : public Shape {
 public:
  virtual std::string name() const { return "point"; }

  virtual int dimension() const { return 2; }

  virtual double volume() const { return 0.0; }

  Point(double x, double y) : _x(x), _y(y) {}

  Point() : _x(0.), _y(0.) {}

  double x() const { return _x; }

  double y() const { return _y; }

 private:
  double _x;
  double _y;
};

class Polygon : public Shape {
 public:
  virtual std::string name() const { return "polygon"; }

  virtual int dimension() const { return 2; }

  virtual double volume() const {
    auto size = _corners.size();
    double result = 0.0;
    for (std::size_t i = 0; i < size; ++i)
      result += _corners[i].x() * _corners[(i + 1) % size].y() -
                _corners[(i + 1) % size].x() * _corners[i].y();

    return 0.5 * result;
  }

  Polygon(const std::vector<Point>& corners) : _corners(corners) {}

 private:
  std::vector<Point> _corners;
};

class PolygonGenerator {
 public:
  PolygonGenerator() : _corner_dist(3, 11), _radius_dist(8, 4) {}

  std::vector<std::shared_ptr<Polygon>> makePolygons(std::size_t count) {                  //überall Polygon* mit shared pointer ersetzt 
    std::vector<std::shared_ptr<Polygon>> result;
    for (std::size_t k = 0; k < count; ++k) {
      std::vector<Point> corners(_corner_dist(_random));
      for (std::size_t i = 1; i <= corners.size(); ++i) {
        auto radius = _radius_dist(_random);
        auto angle = count / i * 2.0 * M_PI;                             //Es wird durch 0 geteilt
        corners[i-1] = {std::cos(angle) * radius, std::sin(angle) * radius};        //Die Formel ist vermutlich falsch 
      }
      auto polygon = std::make_shared<Polygon>(corners);
      result.push_back(polygon);
    }
    return result;
  }

 private:
  // random numnber generator
  std::mt19937_64 _random;
  // distribution for number of corners: [3,11)
  std::uniform_int_distribution<> _corner_dist;
  // distribution for radius from origin of each corner
  std::lognormal_distribution<> _radius_dist;
};

int main(int argc, char** argv) {
  PolygonGenerator gen;

  std::vector<std::shared_ptr<Polygon>> polygons = gen.makePolygons(10);

  for (auto& p : polygons){
    std::cout <<p->volume() << std::endl;

  }
}
 