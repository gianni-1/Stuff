#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void extrem(std::vector<double> x){

    std::sort(x.begin(),x.end());


    /* -0.5 P
    Sorgt für Programmabsturz bei leerem Vektor als Eingabe.
    */
    double klein=x[0];
    

    double groß=x[x.size()-1];

    std::pair<double,double> kleingroß = std::make_pair(klein, groß);
    std::cout<<"kleinste Zahl :"<<kleingroß.first<<" ";
    std::cout <<"größte Zahl :"<<kleingroß.second<<std::endl;
    
    /*
    Das pair sollte auch in der Funktion zurückgegeben werden!
    
    =>
    
    std::pair<double, double> extrem(std::vector<double> x) {
        ...
        return kleingroß;
    }
    */

}

std::vector<double> reversed(const std::vector<double>& v){
    std::vector<double> reverse;
    for (int i=v.size()-1;i>=0;--i){
        reverse.push_back(v[i]);
    }
    return reverse;
}

void runden(std::vector<double>& k) {

    int laenge = k.size();
    for (int i=0; i < laenge; i++)
    {
        std::cout<<"Ungerundet "<<i+1<<": "<<k[i]<<std::endl;
    }
    for (int i = 0; i < laenge; i++)
    {
        k[i] = std::round(k[i]);
    }

    for (int i=0; i < laenge; i++)
    {
        std::cout<<"Gerundet "<<i+1<<": "<<k[i]<<std::endl;
    }
}

void swap(std::vector<double>& v) {
    int laenge = v.size();
    
    std::cout<<"Reihenfolge vor dem Swap: "<<std::endl;
    for (int i=0; i < laenge; i++)
    {
        std::cout<<v[i]<<std::endl;
    }

    for (int i = 0; i < laenge/2; i++) //tauschen der elemente des vektors
    {

    std::swap(v[i], v[laenge-1-i]);
    //Zur Verfolgung der einzelnen Swap Schritte in der Konsole:
    /*std::cout<<"Swap: "<<i+1<<std::endl;
    for (int i=0; i < laenge; i++)
    {

        std::cout<<v[i]<<std::endl;
    }*/
    }

    std::cout<<"Reihenfolge nach dem Swap: "<<std::endl;
    for (int i=0; i < laenge; i++)
    {
        std::cout<<v[i]<<std::endl;
    }
}





int main (int argc, char** argv){
    /*
    Mehr Kommentare in der main!

    Beschreibt, welcher Code-Abschnitt was übernimmt.
    */
    std::vector<double> v1{3.5, 4, 5.5, 6, 7.5, 8};
    std::vector<double> v2{44, 3, 88.5, 9, 33.43, 20};
    std::vector<double> v3{120, 350.1, 2, 5.3, 0.5};
    std::vector<double> v4(10);
    std::vector<double> v5{4.3, 5.5, 7.3, 6.8};
    std::vector<double> v6{6.7, 201.3, 250.4, 99.6, 70.3};
    /* -0.5 P
    Der leere Vektor fehlt (mit v.size() == 0).
    Notiz fehlt, welche Werte die Einträge haben, die man nicht selbst definiert hat.
    */

    std::cout<<"Groesse Vector: "<<v1.size()<<std::endl;
    v1.resize(20);
    std::cout<<""<<std::endl;
    for(double i:v1){
        std::cout<<i<<std::endl;
    }
    std::cout<<""<<std::endl;

    std::cout<<"kleinstes-größtes-Elementpaar v1: ";
    extrem(v1);
    std::cout<<"kleinstes-größtes-Elementpaar v2: ";
    extrem(v2);
    std::cout<<"kleinstes-größtes-Elementpaar v3: ";
    extrem(v3);
    std::cout<<"kleinstes-größtes-Elementpaar v4: ";
    extrem(v4);
    std::cout<<""<<std::endl;

    for (double j :reversed(v1)){
        std::cout<< "Werte von v1 umgedreht: "<<j<<std::endl;
    }
    std::cout<<""<<std::endl;

        for (double j :reversed(v2)){
        std::cout<< "Werte von v2 umgedreht: "<<j<<std::endl;
    }
     std::cout<<""<<std::endl;

        for (double j :reversed(v3)){
        std::cout<< "Werte von v3 umgedreht: "<<j<<std::endl;
    }
    std::cout<<""<<std::endl;

        for (double j :reversed(v4)){
        std::cout<< "Werte von v4 umgedreht: "<<j<<std::endl;
    }
    std::cout<<""<<std::endl;

    runden(v5);
    std::cout<<""<<std::endl;


    runden(v6);
    std::cout<<""<<std::endl;

    swap(v2);
    std::cout<<""<<std::endl;

    swap(v3);
    std::cout<<""<<std::endl;
    
    swap(v4);
    std::cout<<""<<std::endl;
    
    /* Hinweis:
    Euer Output ist etwas unübersichtlich. Vor allem, wenn man bedenkt,
    dass man den Vektor von vorher mit dem Vektor von nachher einfach
    vergleichen können soll.
    */



    return 0;
}