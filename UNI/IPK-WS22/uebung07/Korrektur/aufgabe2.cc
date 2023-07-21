#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/*
 * Top
 */

//Übersichtlicher in der Konsole
void spaces(std::string x){
    std::cout<<std::endl;
    std::cout<<"Aufgabe: "<<x<<")"<<std::endl;
}
int main(){

    spaces("a");
    //aufgabe a)
    std::vector<int> v(100);
    std::iota(v.begin(),v.end(),50);

    //Bedingung zu der gesucht wird:
    auto divisibleBy5 = [](int i){return i%5 == 0;};

    auto result1 = std::find_if(v.begin(),v.end(),divisibleBy5);
    if (result1 != std::end(v)){
        int index = std::distance(v.begin(),result1);
        std::cout<<"first number divisible by 5 in v is index: '"<<index<<"' with value of: "<<*result1<<std::endl;
    }else {
        std::cout<<"v does not contain a number divisible by 5"<<std::endl;
    }

    spaces("b");
    //aufgabe b)
    std::vector<int> copiedV;
    std::copy_if(v.begin(),v.end(),std::back_inserter(copiedV),[](int x){return x>100;});

    //Ausgabe des Vektors aus Aufgabe b) (zur Übersicht in der Konsole)
    std::cout<<"elements of copied vector: "<<std::endl;
    for (int i = 0; i < copiedV.size(); i++)
    {   
        std::cout<<copiedV[i];
        if (i < copiedV.size()-1){
            std::cout<<",";
        }

    }std::cout<<std::endl;

        
    spaces("c");
    //aufgabe c)
    //neuen vektor erstellt da das Produkt der anderen beiden Vektoren aus a,b) zu groß sind!; long ist als Datentyp nicht zwingend nötig.
    std::vector<int>v1{1,2,3,4,5,6,7,8,9,10};
    long product = std::accumulate(v1.begin(), v1.end(), 1, std::multiplies<int>());
    std::cout<<"product of all numbers in vector: '"<<product<<"' "<<std::endl;


    spaces("d");
    //aufgabe d)
    std::vector<int> vD1{50,55,45,40,35,30,85,80},
                     vD2{18,21,14,12,56,43,32,78};

    std::sort(vD1.begin(),vD1.end());
    std::sort(vD2.begin(),vD2.end());

    std::vector<int> vD3(vD1.size()+vD2.size());
    //kopieren von den ersten beiden sortierten vektor in den neuen Vektor
    std::copy(vD1.begin(),vD1.end(),vD3.begin());
    std::copy(vD2.begin(),vD2.end(),vD3.begin()+vD1.size());

    std::inplace_merge(vD3.begin(),vD3.begin()+vD1.size(),vD3.end());
    //Ausgabe des gemergten und sortierten Vektors
    for (int t : vD3)
        std::cout<<t<<",";
    std::cout<<std::endl;

    return 0;
}
