// Save as Main.java

// --- 1. Enum ---
enum Color {
    BLACK, WHITE, GREY, BROWN, DARK_BROWN, BLACK_STRIPES, WHITE_STRIPES
}

enum Size {
    SMALL, MEDIUM, LARGE, HUGE
}

// --- 2. Abstract Class: Animal ---
abstract class Animal {
    protected Color color;
    protected Size size;

    // Constructor
    public Animal(Color color, Size size) {
        this.color = color;
        this.size = size;
    }

    public abstract void sound();
    public abstract void eat();

    public void printInfo() {
        System.out.println("--- " + this.getClass().getSimpleName() + " ---");
        System.out.println("Color: " + color + ", Size: " + size);
    }
}

// --- 3. Intermediate Classes ---
abstract class Mammalia extends Animal {
    protected int numberBabies;

    public Mammalia(Color color, Size size, int numberBabies) {
        super(color, size);
        this.numberBabies = numberBabies;
    }

    public void run() {
        System.out.println("Moving: Running on the ground.");
    }
}

abstract class Aves extends Animal {
    public Aves(Color color, Size size) {
        super(color, size);
    }

    public void fly() {
        System.out.println("Moving: Flying in the sky.");
    }
}

abstract class Osteichthyes extends Animal {
    public Osteichthyes(Color color, Size size) {
        super(color, size);
    }

    public void swimming() {
        System.out.println("Moving: Swimming in the water.");
    }
}

// --- 4. Concrete Classes ---
class Dog extends Mammalia {
    protected boolean fierce;

    public Dog(Color color, Size size, int numberBabies, boolean fierce) {
        super(color, size, numberBabies);
        this.fierce = fierce;
    }

    @Override
    public void sound() {
        System.out.println("Sound: Woof Woof!");
    }

    @Override
    public void eat() {
        System.out.println("Eat: Dog food and bones.");
    }

    public void bark() {
        System.out.println("Action: Barking loudly!");
    }

    public void bite() {
    System.out.println("Fierce Status: " + fierce); 
    System.out.println("Action: Warning! It bites!");
  }
}

class Bird extends Aves {
    protected String eggDesc;

    public Bird(Color color, Size size, String eggDesc) {
        super(color, size);
        this.eggDesc = eggDesc;
    }

    @Override
    public void sound() {
        System.out.println("Sound: Chirp Chirp!");
    }

    @Override
    public void eat() {
        System.out.println("Eat: Worms and seeds.");
    }
}

class Fish extends Osteichthyes {
    protected String waterGroup;

    public Fish(Color color, Size size, String waterGroup) {
        super(color, size);
        this.waterGroup = waterGroup;
    }

    @Override
    public void sound() {
        System.out.println("Sound: ... (Glub Glub)");
    }

    @Override
    public void eat() {
        System.out.println("Eat: Plankton and small fish.");
    }
}

// --- 5. Specific Species ---
class ThaiRidgeBack extends Dog {
    private String origin;

    public ThaiRidgeBack(Color color, Size size, int numberBabies, boolean fierce, String origin) {
        super(color, size, numberBabies, fierce);
        this.origin = origin;
    }

    public void showOrigin() {
        System.out.println("Origin: " + origin);
    }
}

class HummingBird extends Bird {
    private String location;

    public HummingBird(Color color, Size size, String eggDesc, String location) {
        super(color, size, eggDesc);
        this.location = location;
    }

    public void showLocation() {
        System.out.println("Location: " + location);
    }
}

class AngelFish extends Fish {
    public AngelFish(Color color, Size size, String waterGroup) {
        super(color, size, waterGroup);
    }
}

// --- 6. Main Execution ---
public class Main {
    public static void main(String[] args) {
        ThaiRidgeBack trb = new ThaiRidgeBack(Color.BROWN, Size.MEDIUM, 4, true, "Thailand");
        trb.printInfo();
        trb.eat();
        trb.run();
        trb.sound();
        trb.bark();
        trb.bite();
        trb.showOrigin();
        
        System.out.println("-------------------------------");

        HummingBird hmb = new HummingBird(Color.GREY, Size.SMALL, "Tiny White Egg", "Tropical Forest");
        hmb.printInfo();
        hmb.fly();
        hmb.eat();
        hmb.showLocation();

        System.out.println("-------------------------------");

        AngelFish af = new AngelFish(Color.WHITE_STRIPES, Size.SMALL, "Saltwater");
        af.printInfo();
        af.swimming();
        af.eat();
    }
}
