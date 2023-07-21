#include <iostream>
#include <unistd.h> // needed for usleep
#include <string>
#include <fstream>


// TODO Implementierung des 2D Bool Array
//      Entweder basierend auf der Leinwandimplementierung der Mandelbrot-Aufgabe
//      oder Ihre eigene
class TwoDBoolArray 
{
public:
  TwoDBoolArray(double gcenter_x,double gcenter_y,double gwidth,double gheight,
    int ghorPixels,int gvertPixels) 
    :
    _gcenter_x(gcenter_x),_gcenter_y(gcenter_y),_gwidth(gwidth),
    _gheight(gheight),_ghorPixels(ghorPixels),_gvertPixels(gvertPixels)
    { 
      _gpixels=new bool*[ghorPixels];

      for(int i=0;i<ghorPixels;i++)
      _gpixels[i]=new bool[gvertPixels];

    }

    TwoDBoolArray(const TwoDBoolArray& other){
    _gcenter_x = other._gcenter_x;
    _gcenter_y = other._gcenter_y;
    _gwidth = other._gwidth;
    _gheight = other._gheight;
    _ghorPixels = other._ghorPixels;
    _gvertPixels = other._gvertPixels;

    _gpixels = new bool*[_ghorPixels];
    for(int i=0; i<_ghorPixels;i++){
      _gpixels[i]= new bool[_gvertPixels];
      for (int j=0;j<_gvertPixels;j++){
        _gpixels[i][j]=other._gpixels[i][j];
      }
    }

    }

  ~TwoDBoolArray(){

    for(int i=0;i<_gheight;i++){
      delete[] _gpixels[i];
    }

    delete[] _gpixels;

    _gpixels=nullptr;
  }

  friend std::ostream& operator<< (std::ostream& os,TwoDBoolArray& t){
    for (int i=0;i<t._ghorPixels;i++){
      for(int j=0;j<t._gvertPixels;j++){
        os << t._gpixels[i][j]<<" ";
      }
      os<<std::endl;
    }
    return os;
  }
  double width(){
    return _gwidth;
  }

  double height(){
    return _gheight;
  }

  int horPixels(){
    return _ghorPixels;
  }

  int vertPixels(){
    return _gvertPixels;
  }

  std::istream& operator>> (std::istream& is) {
    for(int i=0;i<_ghorPixels;i++){
      for(int j=0;j<_gvertPixels;j++){
        is>>_gpixels[i][j];
      }
    }
    return is;
  }

  virtual int operator()(int i, int j){
    return _gpixels[i][j];
  }

  virtual int operator()(int i, int j,bool tf){
    _gpixels[i][j]=tf;
    return _gpixels[i][j];
  }


  TwoDBoolArray& operator=(const TwoDBoolArray& other){
    if(this == &other){
      return *this;                                                               
    }

    for(int i=0; i<_gheight;i++){
      delete[] _gpixels[i];
    }

    delete[] _gpixels;

    _gcenter_x = other._gcenter_x;
    _gcenter_y = other._gcenter_y;
    _gwidth = other._gwidth;
    _gheight = other._gheight;
    _ghorPixels = other._ghorPixels;
    _gvertPixels = other._gvertPixels;

    _gpixels = new bool*[_ghorPixels];
    for(int i=0; i<_ghorPixels;i++){
      _gpixels[i]= new bool[_gvertPixels];
      for (int j=0;j<_gvertPixels;j++){
        _gpixels[i][j]=other._gpixels[i][j];
      }
    }

    return *this;

  } 

  
private:
  double _gcenter_x;
  double _gcenter_y;
  double _gwidth;
  double _gheight;
  int _ghorPixels;
  int _gvertPixels;
  bool** _gpixels;
};
//      Ueberladen Sie ggf. die Operatoren operator<< oder operator>> fuer diese Datenstruktur

// Basisklassen
struct Regel
{
  typedef TwoDBoolArray Daten;
  virtual void anwenden(Daten& daten) = 0;
};

struct BoundaryCondition
{
  typedef TwoDBoolArray Daten;
  virtual bool boundary(Daten& daten, int i, int j) = 0;
};

// abgeleitete Klassen durch Vererbung
// Sie koennen auch eine Randbedingung und Game of Life Regel ohne Vererbung implementieren
// Allerdings muss in der Klasse Automat ggf. der Datentyp anpasst werden
class TorusCondition : public BoundaryCondition
{
  // Implementieren Sie hier die Funktion boundary()
  // sodass das Gebiet als doppelt periodisch angenommen wird
  bool boundary(Daten& daten, int i, int j){
    if(i>=daten.vertPixels()|| i<0){
      i=(i+daten.vertPixels()) % daten.vertPixels();
    }
    else if(j>=daten.horPixels() || j<0){
      j=(j+daten.horPixels()) % daten.vertPixels();
    }
    return daten(i,j);
  }
};

class AliveCondition : public BoundaryCondition
{
  // Implementieren Sie hier die Funktion boundary()
  // Randbedingung durch rund um das Rechengebiet lebende Zellen
  bool boundary(Daten& daten, int i ,int j){
    if(i>=daten.vertPixels() || i<0 || j>=daten.horPixels() || j<0){
      return true;
    }
    return daten(i,j);
  }
};

class DeadCondition : public BoundaryCondition
{
  // Implementieren Sie hier die Funktion boundary()
  // Randbedingung durch rund um das Rechengebiet tote Zellen
  bool boundary(Daten& daten, int i ,int j){
    if(i>=daten.vertPixels() || i<0 || j>=daten.horPixels() || j<0){
      return false;
    }
    return daten(i,j);
  }
};

class GameOfLifeRules : public Regel
{
public :
  // der Datentyp fuer das 2D Bool Array
  typedef TwoDBoolArray Daten;

  GameOfLifeRules(BoundaryCondition& bc)
    : _bc(bc)
  {}

  void anwenden(Daten& daten){
    Daten neuedaten(daten);

    for(int i=0; i<daten.horPixels();i++){
      for(int j=0; j<daten.vertPixels();j++){
        int lebendigenach= zählelebendigenachbarn(daten,i,j);
        bool amleben=daten(i,j);

        if(!amleben && lebendigenach==3){
          neuedaten(i,j,true);
        }

        else if(amleben && lebendigenach < 2){
          neuedaten(i,j,false);
        }

        else if(amleben && lebendigenach > 3){
          neuedaten(i,j,false);
        }
      }
    }
    daten=neuedaten;
  }



  int zählelebendigenachbarn(Daten& daten,int i, int j){
    int count=0;
    for (int k=-1; k<=1;k++){
      for(int l=-1; l<=1;l++){
        if(k==0 && l==0)                       //da befinden wir uns auf dem zu betrachteten Feld, von dem wir die lebendigen Nachbarn ermitteln
          continue;

        bool lebendigernachbar= _bc.boundary(daten,i+k,j+l);
        if(lebendigernachbar)
          count++;
      }
    }
    return count;
  }

private :
  BoundaryCondition& _bc;
}; // end class GameOfLifeRules

// Ein zellulaerer Automat, der Regeln und Datenstrukturen von aussen bekommt
class Automat
{
public :
  // der Datentyp fuer das 2D Bool Array
  typedef TwoDBoolArray Daten;

  Automat(Daten& daten, Regel& regel)
    : _daten(daten)
    , _regel(regel)
  {}

  // mache n Schritte
  void doSteps(int n=500)
  {
    for (int i=0; i<n; ++i)
    {
      // Linux-spezifische Art und Weise den Inhalt der Konsole zu loeschen
      // und den Cursor nach oben links zu setzen.
      std::cout << "\x1B[2J\x1B[H" << "Step " << i << std::endl << _daten;
      // Das Wiedergeben der Loesung soll immer 10 Sekunden (=1e7 Mikrosekunden)
      // dauern. Sie koennen diesen Wert auch aendern.
      usleep(1.e7/n*3);
      _regel.anwenden(_daten);
    }
  }

private :
  Daten& _daten;
  Regel& _regel;
};

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: ./<progname> <txt-file>" << std::endl;
    return 1;
  }

  //Datei öffnen
  std::ifstream file(argv[1]);
  if(!file.is_open()){
    std::cout<<"./<progname> <txt-file> "<<std::endl;
    return 1;
  }



  double center_x = -1;
  double center_y = 0;
  double width ;
  double height ;
  int horpixels ;
  int vertpixels ;


  file>>height>>width;
  vertpixels=width;
  horpixels=height;

  TwoDBoolArray board(center_x,center_y,width,height,horpixels,vertpixels);

  for(int i=0; i<horpixels;i++){
    for(int j=0;j<vertpixels;j++){
      char value;
      file>>value;
      board(i,j,value=='1');
    }
  }

  TorusCondition torus;
  GameOfLifeRules rules(torus);
  Automat automat(board,rules);

  //int generations= 50;

  automat.doSteps();






  // Initialisiere Datenstruktur des 2D Bool Array
  // TODO
  // Ueberlegen Sie sich wie Sie einen Startzustand in das 2D Bool Array bekommen
  // Lesen Sie ggf.
  // (1) eine solche Textdatei mittels Filestream ein
  // (2) ueberladen Sie Operatoren operator<< oder operator>>

  // TODO
  // - legen Sie eine Instanz der Randbedingung an
  // - legen Sie eine Instanz des Regelsystems an
  // - Initialisieren Sie den zellulaeren Automaten

  // Experimentieren Sie hier mit Ihrem Automaten

  return 0;
}
