#include "raylib.h"
#include <vector>
#include <memory>

#include "Amoeba.h"

int main() {
  // Initialization
  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "Amoeba Sim");
  SetTargetFPS(60);

  // Setup Scene
  std::vector<std::unique_ptr<GenericAmoeba>> v;
  v.emplace_back(std::make_unique<GenericAmoeba>(GenericAmoeba({100,100}, {50, 50},30, GREEN)));             //wie push_back, nur dass es keińe Kopie anlegt
  v.emplace_back(std::make_unique<RandomAmoeba>(RandomAmoeba({200,100}, {-50, 50},30, RED)));                // sondern inplace anlegt
  v.emplace_back(std::make_unique<ControllableAmoeba>(ControllableAmoeba({400,300}, {100, -100},30, ORANGE)));
  v.emplace_back(std::make_unique<Customamoeba1>(Customamoeba1({300,80},{60,60},25,BLUE)));
  v.emplace_back(std::make_unique<Customamoeba2>(Customamoeba2({10,10},{30,30},35,PURPLE)));
  v.emplace_back(std::make_unique<Customamoeba3>(Customamoeba3({400,25},{15,15},20,YELLOW)));
  v.emplace_back(std::make_unique<Customamoeba4>(Customamoeba4({300,300},{20,-200},58.5,BLACK)));

  /*
  std::vector<GenericAmoeba*> v;    
  GenericAmoeba a({100,100}, {50, 50},30, GREEN);
  RandomAmoeba b({200,100}, {-50, 50},30, RED);
  ControllableAmoeba c({400,300}, {100, -100},30, ORANGE);
  Customamoeba1 y({300,80},{60,60},25,BLUE);
  Customamoeba2 k({10,10},{30,30},35,PURPLE);
  Customamoeba3 j({400,25},{15,15},20,YELLOW);
  Customamoeba4 t({300,300},{20,-200},58.5,BLACK);
  v.push_back(&a);
  v.push_back(&b);
  v.push_back(&c);
  v.push_back(&y);
  v.push_back(&k);
  v.push_back(&j);
  v.push_back(&t);
  */    
  
  
  // Main render loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    // Update
    for(auto& a :v) {                   // ersetzten jedes Genericamoeba* mit auto&
      a->update(GetFrameTime());
      a->handleBounds();
      for(auto& b : v) {
        if (b == a)
          continue;
        if(a->collisionCheck(*b))
          a->onCollision(*b);
      }
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
      Vector2 mousePos = GetMousePosition();
      for(auto& a : v) {
        Point m(mousePos.x, mousePos.y);
        if ((m - a->getPos()).dist() < a->getRadius())
          a->onPoke(MOUSE_BUTTON_LEFT);
      }
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
      Vector2 mousePos = GetMousePosition();
      for(auto& a : v) {
        Point m(mousePos.x, mousePos.y);
        if ((m - a->getPos()).dist() < a->getRadius())
          a->onPoke(MOUSE_BUTTON_RIGHT);
      }
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for(auto& a :v) {
      a->draw();
    }
    EndDrawing();
  }

  // De-Initialization
  CloseWindow();        // Close window and OpenGL context

  return 0;
}
