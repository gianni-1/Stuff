#include <iostream> 
#include <cmath> 


int main(int argc, char** argv){
    double a;
    std::cout << "a = " << std::flush;
    std::cin >> a;

    double b;
    std:: cout << "b = " << std::flush;
    std:: cin >> b;

    double c; 
    std:: cout << "c = " << std:: flush;
    std:: cin >> c;
    std:: cout <<"Es werden nun die Nullstellen der folgenden Funktion berechnet: "<< a<<"*x²+("<<b<<")*x+("<<c<<")"<<std::endl;

    double y,r,x1,x2;
    y=b*b-4*a*c; // y ist die "Diskriminante" 
    if(y<0){
        std::cerr<<"Die Lösung ist komplex!"<<std::endl;
    }
    else if(a==b && a==0){
        std::cerr<<"Die Lösung ist nicht eindeutig!"<<std::endl;
    }
    else {
        r= std::sqrt(y);
        x1=(-b+r)/(2*a);
        x2=(-b-r)/(2*a);
        if(x1 != x2){
            std::cout<<"Die erste Nullstelle lautet: "<<x1<<std::endl<<" Die zweite Nullstelle lautet: "<<x2<<std::endl;
        }
        else if(x1==x2){
            std::cout<<"Es gibt nur eine Nullstelle,die doppelt sein kann: "<<x1<<std::endl;
        }
    }

    return 0;
}