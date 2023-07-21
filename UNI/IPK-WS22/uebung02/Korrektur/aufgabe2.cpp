#include <iostream>

unsigned long long fibonacci(int number){
    unsigned long long start=0;
    unsigned long long next=1;

    for(int i=0;i<=number;i++){
        std::cout<<"N = "<<i <<":"<<start<<std::endl;
        next=start+next;
        start=next-start;
    }   
    return start;
   /* if (number==0){
        return 0;
    }
    else if (number ==1){
        return 1;
    }
    else{
        return fibonacci(number-1)+fibonacci(number-2);
    }
    */
}

int main(int argc, char** argv){

    int number;

    std::cout<<"Geben sie eine Zahl N ein,die als obere Grenze einer Zahlenreihe definiert wird , die mit 0 und 1 beginnt."<<std::endl;
    std::cout<<"Jede weitere Zahl entspricht dabei der Summe der beiden vorangegangenen Zahlen bis hoch zur oberen Grenze N: "<<std::flush;
    std::cin>>number;
    fibonacci(number);
    
    return 0;
}