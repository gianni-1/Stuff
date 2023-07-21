#include <iostream>
#include <vector>

void collatz(int number){
    bool läuft=true;

    std::cout<<"Start: "<< number <<std::endl;
    std::vector<long int> folge;
    folge.push_back(number);

    /*
    Man kann die Ausdürcke aus der if Abfrage so wie sie ist, auch einfach in die while-Schleife schreiben
    */
    while(läuft){
        if(number!=0 && number!=1 && number!=-1 && number!=-5 && number!= -17){

            if (number%2 == 0){                          //Wenn number gerade dann geteilt durch 2 und fügt es dem vector folge hinzu
                number =number / 2;
                folge.push_back(number);
                
            }
            else{
                number = 3*number + 1;                 //Wenn number ungerade dann nimmt es number mal 3 plus 1 und fügt es dem vector folge hinzu
                folge.push_back(number);
                
            }
        }
        else{
            läuft=false;                           //Wenn number 0,1,-1,-5,-17 ist dann wird hiermit die while-Schleife abgebrochen 
        }
    }

    for(unsigned long int i=0;i <= folge.size()-1;i=i+1){       //folge.size()-1 weil die Funktion einfach die Länge des vectors angibt wir brauche aber die Länge-1, da der Index mit 0 beginnt
        std::cout<< folge[i]<<","<< std::flush;         //gibt für jedes i, kleiner gleich der Länge vom vector folge,genau die Zahl aus, die an der Stelle vom vector Index i ist
    }
    std::cout<<"Ende"<<std::endl;

}

int main(int argc, char** argv){
    int start;
    std::cout<<"Gib die Zahl ein, von der du eine Collatz-Folge erstellt haben willst: "<< std::endl;
    std::cin>> start;

    collatz(start);

    return 0;

}