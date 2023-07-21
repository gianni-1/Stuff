#include <iostream>
#include <map>


namespace frequencies {
void print_frequencies(const std::map<char,int>& letters){
    
    int count = 0;
    for(auto&  C : letters ){
    count += C.second;
    }

    for (std::pair<const char, int> C : letters){
        std::cout << C.first << " - " << static_cast<double>(C.second) / count * 100 << "%" << std::endl;
    }

    std::cout  << "Gesamte Anzahl von Buchstaben: " << count << std::endl;

    
}

std::map<char,int> get_frequencies(){
   std::cout  << "Zu verwendende Zeichenfolge schreiben: ";
   std::map<char,int> letters;
    while(true){
        unsigned char C; 
        std::cin >> C; 

        if(not std::cin){
            break;
        }

        if(std::isalpha(C)){
            C = std::toupper(C);
            letters[C] = letters[C]+ 1;

        }
    }
    return letters;
}


void letter_freq(){
    std::map<char, int> letters = get_frequencies();
    print_frequencies(letters);
}
}
