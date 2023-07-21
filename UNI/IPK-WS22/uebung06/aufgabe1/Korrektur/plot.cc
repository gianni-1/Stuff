#include <cmath>
#include <iostream>

#include "canvas.cc"

/* -0.5 P
Das Bild ist für die angegebenen Pixel richtig, hat aber nicht das richtige
Seitenverhältnis von 4000, 3000
*/

int main() {
  Canvas canvas(Point(0, 0), 4.0, 3.0, 4000, 3000);
  
  // generiert Bild nach Auswahl der Helligeit/Brightness
  for (int j = 0; j < 4000; ++j) //horizontal 
    for (int i = 0; i < 3000; ++i) { //vertikal
      auto canvasCoord = canvas.coord(i, j);
      canvas.setBrightness(i, j,std::max(0.0,100 * (std::sin(1 / canvasCoord.x()) * std::sin(1 / canvasCoord.y()) + 1.0)));
    }

  canvas.write("image.pgm");
}

