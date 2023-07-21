#ifndef AMOEBA_SIM_AMOEBA_H
#define AMOEBA_SIM_AMOEBA_H

#include <iostream>
#include <chrono>
#include "Point.h"
#include "raylib.h"

class GenericAmoeba {
protected:
  Point pos;
  Point speed;
  float base_speed;
  unsigned radius = 30;
  Color color;

public:
  GenericAmoeba(Point pos, Point speed, unsigned r, Color color)
    : pos(pos)
    , speed(speed)
    , base_speed(speed.dist())
    , radius(r)
    , color(color)
  {}
  void draw();
  bool collisionCheck(GenericAmoeba& other);
  void handleBounds();
  Point getPos() { return pos; }
  unsigned getRadius() { return radius;}
  virtual void update(float delta_t);
  virtual void onCollision(GenericAmoeba& other);
  virtual void onPoke(int button) {};
};

class ControllableAmoeba : public GenericAmoeba{
public:
  ControllableAmoeba(const Point &pos, const Point &speed, unsigned radius, Color color) : GenericAmoeba(pos, speed, radius, color) {}
  void onPoke(int button) override;
};

class RandomAmoeba : public GenericAmoeba {
public:
  RandomAmoeba(const Point &pos, const Point &speed, unsigned radius, Color color) : GenericAmoeba(pos, speed, radius, color) {}
  void update(float delta_t) override;
};

class Customamoeba1 : public GenericAmoeba{
  public:
  Customamoeba1(const Point &pos, const Point &speed, unsigned radius, Color color) : GenericAmoeba(pos, speed, radius, color){}
  void onCollision(GenericAmoeba& other) override;
};

class Customamoeba2 : public GenericAmoeba{
  public:
  Customamoeba2(const Point &pos, const Point &speed, unsigned radius, Color color) : GenericAmoeba(pos, speed, radius, color){}
  void onPoke(int button) override;
};

class Customamoeba3 : public GenericAmoeba{
  public:
  Customamoeba3(const Point &pos, const Point &speed, unsigned radius, Color color) : GenericAmoeba(pos, speed, radius, color){}
};

class Customamoeba4 : public GenericAmoeba{
  public:
  Customamoeba4(const Point &pos, const Point &speed, unsigned radius, Color color) : GenericAmoeba(pos, speed, radius, color){}
   void onPoke(int button) override;
};

#endif //AMOEBA_SIM_AMOEBA_H
