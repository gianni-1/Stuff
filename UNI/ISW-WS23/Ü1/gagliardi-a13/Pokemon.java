
public class Pokemon
{


    //Deklaration der privaten Member
    private String name;
    private Type type;
    private int number;     // Attribut zur Speicherung der ID des aktuellen Pokemon-Objekts
    private static int nextNumber = 1; //// Statisches Attribut zur Speicherung der nächsten zu vergebenden ID



    //Konstruktor
    public Pokemon(String name, Type type)
    {
        this.name = name;
        this.type = type;
        this.number = nextNumber;   // Zuweisung der aktuellen nextNumber zur number des aktuellen Pokemon-Objekts
        nextNumber++;           // Inkrementierung der nextNumber für das nächste Pokemon-Objekt
    }

    //Getter- und SetterMethoden für die Attribute name und type und number
    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public int getNumber()
    {
        return number;
    }


    public Type getType()
    {
        return type;
    }

    public void setType(Type type)
    {
        this.type = type;
    }
    
    /* In dieser Methode ist der Parameter, der an die Methode
     * übergeben wird, ebenfalls ’name’ gennant. Um eindeutig 
     * anzugeben, dass die Klassenvariable und nicht der 
     * Parameter gemeint ist , wird die ’this’ Referenz
     * verwendet. Die ’this’ Referenz ist eine Referenz 
     * auf das aktuelle Objekt.
     * */

    public String toString()
    {
        return "Pokemon [Number: " + number + ", Name: " + name + ", Type: " + type + "]";
    }

    //Main zum Ausführen des Programms 
    public static void main(String[] args)
    {
        //Deklaration des Objekts
        Pokemon dangerousPokemon;
        Pokemon harmlessPokemon;

        //Erstellung des Objekts 
        dangerousPokemon = new Pokemon("Gyarados",Type.WATER);
        harmlessPokemon = new Pokemon("Shiggy", Type.WATER);


    }


}
