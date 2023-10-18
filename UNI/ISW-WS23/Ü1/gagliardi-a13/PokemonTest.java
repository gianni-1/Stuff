public class PokemonTest {
    public static void main(String[] args) {
        // erster Test : Objekterstellung
        System.out.println("Test 1: Objekterstellung");
        Pokemon dangerousPokemon = new Pokemon("Gyarados", Type.WATER);
        Pokemon harmlessPokemon = new Pokemon("Shiggy", Type.WATER);
        System.out.println(dangerousPokemon.toString());
        System.out.println(harmlessPokemon.toString());

        // zweiter Test : Ändern der Namen und Typen der Pokemon-Objekte
        System.out.println("\nTest 2: Ändern der Namen und Typen der Pokemon-Objekte");
        dangerousPokemon.setName("Gyros");
        harmlessPokemon.setType(Type.POISON);
        System.out.println(dangerousPokemon.toString());
        System.out.println(harmlessPokemon.toString());

        // dritter Test : Abfragen der aktualisierten Attribute der Pokemon-Objekte
        System.out.println("\nTest 3: Abfragen der aktualisierten Attribute der Pokemon-Objekte");
        System.out.println("Pokemon 1: Number = " + dangerousPokemon.getNumber() + ", Name = "
                + dangerousPokemon.getName() + ", Type = " + dangerousPokemon.getType());
        System.out.println("Pokemon 2: Number = " + harmlessPokemon.getNumber() + ", Name = "
                + harmlessPokemon.getName() + ", Type = " + harmlessPokemon.getType());

    }
}