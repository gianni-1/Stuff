

public class Pokemon
{
    //Deklaration des Aufzählungstyps type
    enum Type
    {
        FIRE,
        WATER,
        POISON;
    }

    //Deklaration der privaten Member
    private String name;
    private Type type;


    //Konstruktor
    public Pokemon(String name, Type type)
    {
        this.name = name;
        this.type = type;
    }

    //Getter- und SetterMethoden für die Attribute name und type 
    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
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



    //Main zum Ausführen des Programms 
    public static void main(String[] args)
    {
        //Deklaration des Objekts
        Pokemon dangerousPokemon;

        //Erstellung des Objekts 
        dangerousPokemon = new Pokemon("Gyarados",Type.WATER);
    }


}