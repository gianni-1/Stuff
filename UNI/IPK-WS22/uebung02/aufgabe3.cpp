#include <iostream>

int iterative(int q, int n){
    int first=q;
    if(n==0){
        return 1;
    }
    else if(n<0){
        std::cerr<<"Fehler!"<<std::endl;
        return 1;
    }
    else{
        for(int i=2;i<=n;i++){
            q=q*first;
        }
        return q;
    }
}

int recursive(int q, int n){
    if(n==0){
        return 1;
    }
    else if(n<0){
        std::cerr<<"Fehler!"<<std::endl;
        return 1;
    }
    else{
        return q*recursive(q,n-1);
    }
}

int main(int argc,char** argv){
    int q,n;
    std::cout<<"Gib ein q und ein positves n ein für das q^n berechnet wird"<<std::endl;
    std::cout<<"Gib ein q ein: "<< std::endl;
    std::cout<<"Gib ein n ein: "<<std::endl;

    std::cin>>q;
    std::cin>>n;
    std::cout<<recursive(q,n)<<std::endl;
    
    return 0;

}