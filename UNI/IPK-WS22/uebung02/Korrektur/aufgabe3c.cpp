#include <iostream>

/* 0 Punkte insgesamt
Liefert keine richtigen Ergebnisse
*/

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


int main(int argc,char** argv){
    int q,n,z;
    std::cout<<"Gib ein q und ein positves n ein für das q^n berechnet wird"<<std::endl;
    std::cout<<"Gib ein q ein: "<< std::endl;
    std::cout<<"Gib ein n ein: "<<std::endl;

    std::cin>>q;
    std::cin>>n;

    for(int i=2;i<=n;i++){
        /*
        Muss nicht extra geklammert werden
        */
        if((n%i==0)&&(i!=n)){     //Wir schauen hiermit ob i Teiler von n ist ohne dass i=n ist 
            z=iterative(q,n/i);  //Hier sorgen wir dafür , dass n durch i unser neues "n" ist, solange die mod funktion 0 ist und i<=n.
        }
        else{
            z=iterative(z,i);  
        }
    }
    std::cout<<z<<std::endl;
    
    return 0;

}