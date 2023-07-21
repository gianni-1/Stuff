#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Shape {
 public:
  virtual ~Shape() {};                        //Destruktor virtual

  virtual std::string name() const = 0;

  virtual int dimension() const { return 0; }

  virtual double volume() const { return 0.0; }
};

class Point : public Shape {
 public:
  virtual std::string name() const { return "point"; }

  /* -1 P
  Ein Punkt hat nicht die Dimension 2
  */
  virtual int dimension() const { return 2; }

  virtual double volume() const { return 0.0; }

  Point(double x, double y) : _x(x), _y(y) {}

  Point() : _x(0.), _y(0.) {}

  ~Point() {};

  double x() const { return _x; }

  double y() const { return _y; }

 private:
  double _x;
  double _y;
};

class Circle : public Shape {
 public:
  virtual std::string name() const { return "circle"; }

  virtual int dimension() const { return 2; }      // const hat gefehlt

  virtual double volume() const { return M_PI * _radius * _radius; }

  Circle(double radius) : _radius(radius) {}

  ~Circle() {};

 private:
  double _radius;
};

class Sphere : public Shape {
 public:
  virtual std::string name() const { return "sphere"; }

  virtual int dimension() const { return 3; }            //ist dreidimensional

  virtual double volume() const {
    return 4.0 / 3.0 * M_PI * _radius * _radius * _radius;
  }

  Sphere(double radius) : _radius(radius) {}

  ~Sphere() {};

 private:
  double _radius;
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

  ~Polygon() {};

 private:
  std::vector<Point> _corners;
};

int main(int argc, char** argv) {
  std::vector<std::shared_ptr<Shape>> shapes;

  // add some shapes
  shapes.push_back(std::make_shared<Point>(2, 4));
  shapes.push_back(std::make_shared<Circle>(70));
  shapes.push_back(std::make_shared<Sphere>(10));
  std::vector<Point> corners = {{-4., -4.}, {4., -4.}, {4., 4.}, {-4., 4.}};
  shapes.push_back(std::make_shared<Polygon>(corners));
  corners.resize(1);
  shapes.push_back(std::make_shared<Polygon>(corners));

  // find volume of largest 2D shape
  double volume = 0.0;
  for (auto& shape : shapes) {
    std::cout<<shape->name()<<" "<<shape->volume()<<std::endl;
    if (shape->dimension() != 2) continue;

    volume = std::max(volume, shape->volume());
  }

  std::cout << volume << std::endl;
}
