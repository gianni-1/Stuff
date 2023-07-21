#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

//aufgabe a)
double median_naive(const std::vector<double>& v){
    std::vector<double> sortedVector = v;
    std::sort(sortedVector.begin(), sortedVector.end());
    
    if (sortedVector.size()%2 == 0)
    {
        double arithMittel = (sortedVector[sortedVector.size()/2]+sortedVector[(sortedVector.size()/2)-1])/2;
        return arithMittel;
    } else {
        return sortedVector[(sortedVector.size()-1)/2];
    }
    
    return 0;
    
}


//Anmerkung zu c: wüsste nicht wo man std::max_element benötigt??
//aufgabe c)
double median(const std::vector<double>& v){
    std::vector<double> sortedV = v;
    std::nth_element(sortedV.begin(), sortedV.begin() + sortedV.size()/2, sortedV.end());
    if (sortedV.size()%2 == 0)
    {
        double arithMittel = (sortedV[sortedV.size()/2]+sortedV[(sortedV.size()/2)-1])/2;
        /* -0.5 P
         * Leider falsch, da std::nth_element nur das Element an der Stelle sortedV.size()/2 richtig einsortiert hat.
         * Um das andere Element zu finden, muss man std::max_element auf den linken unsortierten Teil anwenden.
         */
        return arithMittel;
    } else {
        return sortedV[(sortedV.size()-1)/2];
    }

    /*
     * return 0 wird nie ausgeführt
     */
    return 0;
}

int main(){
    //Aufgabe b)
    std::vector<double> v{};
    int n;
    std::cout<<"Geben Sie einen Parameter an welche die Größe des Vektors bestimmt: "<<std::endl;
    std::cin>> n;
    v.resize(n);
    std::iota(v.begin(),v.end(),1);

    //da explizit nach std::shuffle gefragt wurde: mit #include random, die unteren beiden Befehle erzeugen eine random Zahl
    //mit random_shuffle wäre es einfacher, da bereits in #include algorithm drin.
    std::random_device rd;
    std::mt19937 rdm(rd());
    std::shuffle(v.begin(),v.end(),rdm);

    std::cout<<"Der Median_naive des oben angelegten Vektors beträgt: "<<median_naive(v)<<std::endl;
    std::cout<<"Der Median des oben angelegten Vektors beträgt: "<<median(v)<<std::endl;

    //Wenn n ungerade, dann jetzt gerade sonst andersrum:
    v.resize(n+1);
    std::iota(v.begin(),v.end(),1);
    std::shuffle(v.begin(),v.end(),rdm);
    std::cout<<"Der Median_naive des oben angelegten Vektors beträgt: "<<median_naive(v)<<std::endl;
    std::cout<<"Der Median des oben angelegten Vektors beträgt: "<<median(v)<<std::endl;
    return 0;
}