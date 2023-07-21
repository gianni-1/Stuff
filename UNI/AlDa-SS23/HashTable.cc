#include <iostream>



// Definieren einer Klasse für die Knoten der verketteten List
template<class T>
class Node{
    int _key;
    T _value;    //Verwenden von T anstelle von int 
    Node* next;
    
    public: 
   Node(int key,T value)
   : // Konstruktor für die Node-Klasse
        _key(key), // Der Schlüssel für den Knoten
        _value(value), // Der Wert für den Knoten
        next(nullptr)// Ein Zeiger auf den nächsten Knoten in der Liste, standardmäßig auf nullptr gesetzt
        {} 
    template<class K>
    friend class LinkedList; // damit LinkedList Zugang auf privates Member 'next' hat 
};


// Definieren einer Klasse für eine verkettete Liste
template<class T>
class LinkedList{
    Node<T>* head;
    LinkedList(): // Konstruktor für die LinkedList-Klasse
        head(nullptr) // Der Kopf der Liste, standardmäßig auf nullptr gesetzt
        {}
    void insert(int key,T value){ // Methode zum Einfügen eines neuen Knotens am Anfang der Liste
        Node<T>* new_node= new Node<T>(key,value); // Erstellen eines neuen Knotens
        new_node->next=head; // Setzen des nächsten Zeigers des neuen Knotens auf den aktuellen Kopf der Liste
        head=new_node; // Setzen des neuen Knotens als neuen Kopf der Liste
    }
    T remove(){ // Methode zum Entfernen des Kopfes der Liste
        if(head!= nullptr){ // Überprüfen, ob die Liste nicht leer ist
            Node<T>* removed_node = head;  // Speichern des Knotens, der entfernt werden soll, in einer temporären Variable
            head=head->next;   // Setzen des Kopfes der Liste auf den nächsten Knoten
            T removed_value=removed_node->_value; 
            delete removed_node;
            return removed_value; // Rückgabe des Wertes des entfernten Knotens
        }
        return 0; // Rückgabe von NIL, wenn die Liste leer ist
    }
    template<class K>
    friend class HashTable;                         //damit innerhalb der HashTable Methode eine neue LinkedList allokiert werden kann
};


// Definieren einer Klasse für eine Hashtabelle
template<class T>
class HashTable{
    int size;
    LinkedList<T>** table;               //2D Array von Linked Lists
    
    public:
        HashTable(int table_size):          // Konstruktor für die HashTable-Klasse
            size(table_size)                // Die Größe der Hashtabelle 
        {
            table= new LinkedList<T>*[size];
            for(int i =0;i<size;++i){
                table[i]=nullptr;            // Initialisieren der Hashtabelle mit None
            }
        }

        ~HashTable(){
            for(int i=0;i<size;++i){
                delete table[i]; //Lösche jede linked List
            }
            delete[] table; //Lösche das Array von linked Lists
        }

    int hash(int key){ // Methode zur Berechnung des Hashwertes eines Schlüssels
        return key % size; // Verwenden des Modulooperators zur Berechnung des Hashwertes, damit Hashwert innerhalb des Bereiches liegt
    }

    void insert(int key,T value){ // Methode zum Einfügen eines neuen Elements in die Hashtabelle
        int index = hash(key); // Berechnen des Indexes für den Schlüssel
        if (table[index]==nullptr){ // Überprüfen, ob der Index in der Tabelle noch nicht besetzt ist
            table[index] = new LinkedList<T>(); // Wenn ja, erstellen einer neuen LinkedList an diesem Index
        }
        table[index]->insert(key, value); // Einfügen des neuen Elements in die LinkedList an diesem Index
    }

    T remove(int key){ // Methode zum Entfernen eines Elements aus der Hashtabelle
        int index = hash(key); // Berechnen des Indexes für den Schlüssel
        if (table[index]!= nullptr){ // Überprüfen, ob es eine LinkedList an diesem Index gibt
            return table[index]->remove(); // Wenn ja, entfernen des Kopfes der LinkedList und Rückgabe seines Wertes
        }
        return 0; // Rückgabe von NIL, wenn es keine LinkedList an diesem Index gibt
    }
};

int main(){
    int x=1;

    return 0;
}