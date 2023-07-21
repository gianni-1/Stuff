#include "Amoeba.h"
#include "raylib.h"

void GenericAmoeba::draw() {
  DrawCircle(pos.x, pos.y, radius, color);
}

bool GenericAmoeba::collisionCheck(GenericAmoeba &other) {
  float radius_sum = this->radius + other.radius;
  Point dist = this->pos-other.pos;
  float len = dist.dist();
  if (len <= radius_sum) {
    return true;
  }
  return false;
}

void GenericAmoeba::handleBounds() {
  if (pos.x - radius < 0) {
    pos.x = radius;
    speed.x *= -1;
  } else if (pos.x + radius > GetScreenWidth()) {
    pos.x = GetScreenWidth() - radius;
    speed.x *= -1;
  }
  if (pos.y - radius < 0) {
    pos.y = radius;
    speed.y *= -1;
  } else if (pos.y + radius > GetScreenHeight()) {
    pos.y = GetScreenHeight() - radius;
    speed.y *= -1;
  }
}

void GenericAmoeba::update(float delta_t) {
  pos += speed * delta_t;
}

void GenericAmoeba::onCollision(GenericAmoeba &other) {
  Point diff = this->pos-other.getPos();
  speed = (speed.scaleToLen(1.) + diff.scaleToLen(1)*2).scaleToLen(base_speed);
}


void ControllableAmoeba::onPoke(int button) {
  if(button == MOUSE_BUTTON_LEFT)
    base_speed *= 1.5;
  else if (button == MOUSE_BUTTON_RIGHT)
    base_speed *= 2./3.;

  speed = speed.scaleToLen(base_speed);
}

void RandomAmoeba::update(float delta_t) {
  pos += speed * delta_t;
  speed.x += GetRandomValue(-10, 10);
  speed.y += GetRandomValue(-10, 10);

  speed = speed.scaleToLen(base_speed);
}

void Customamoeba1::onCollision(GenericAmoeba &other){
  Point diff = this->pos-other.getPos();
  speed=(speed.scaleToLen(1.)+diff.scaleToLen(1)*10).scaleToLen(base_speed*10);
}

void Customamoeba2::onPoke(int button) {                   //sollte eigentlich für eine Sekunde Amoeba verlangsamen ... 
  auto start = std::chrono::system_clock::now();           // führt aber zu einem 1s langem Lag was aber eigentlich auch ein Zeitverhalten ist i guess
  auto end = std::chrono::system_clock::now();
  if(button == MOUSE_BUTTON_LEFT){
    while((std::chrono::duration_cast<std::chrono::seconds>(end - start).count() != 1)){
      base_speed*=2./3.;
      end = std::chrono::system_clock::now();
      base_speed*=1.5;
    }
  }
  speed = speed.scaleToLen(base_speed);
}

void Customamoeba4::onPoke(int button) {
  if(button == MOUSE_BUTTON_LEFT)
    base_speed *= -1.2;
  else if (button == MOUSE_BUTTON_RIGHT)
    base_speed *= -2./3.;

  speed = speed.scaleToLen(base_speed);
}
