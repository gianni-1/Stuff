#include <iostream>
#include <map>

// Aufgabe B
void print_frequencies(const std::map<char,int>& letters){
    
    // Aufgabe F
    int count = 0;
    for(auto&  C : letters ){
    count += C.second;
    }

    // Aufgabe G
    for (std::pair<const char, int> C : letters){
        std::cout << C.first << " - " << static_cast<double>(C.second) / count * 100 << "%" << std::endl;
    }

    std::cout  << "Gesamte Anzahl von Buchstaben: " << count << std::endl;
}

// Aufgabe A 
std::map<char,int> get_frequencies(){
   std::cout << "Drücken Sie CTRL-D, um die Eingabe zu beenden." << std::endl; 
   std::cout  << "Zu verwendende Zeichenfolge schreiben: ";
   std::map<char,int> letters;
    while(true){
        unsigned char C; 
        std::cin >> C; 

        if(not std::cin){
            break;
        }
        // Aufgabe D
        if(std::isalpha(C)){
            // Aufgabe E
            C = std::toupper(C);
            letters[C] = letters[C]+ 1;

        }
    }
    return letters;
}

// Aufgabe C
void letter_freq(){
    std::map<char, int> letters = get_frequencies();
    print_frequencies(letters);
}

int main(int argc, char **argv){
    letter_freq();
}    
