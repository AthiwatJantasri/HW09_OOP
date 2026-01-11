enum Color {
    BLACK, WHITE, GREY, BROWN, DARK_BROWN, BLACK_STRIPES, WHITE_STRIPES
}

enum Size {
    SMALL, MEDIUM, LARGE, HUGE
}

abstract class Animal {
    protected Color color;
    protected Size size;

    public Animal(Color color, Size size) {
        this.color = color;
        this.size = size;
    }
    
    // Abstract Method บังคับให้ลูกไปเขียนเอง
    public abstract void sound();
    public abstract void eat();
}

// ======================

abstract class Mammalia extends Animal {
    protected int numberBabies;

    public Mammalia(Color color, Size size, int numberBabies) {
        super(color, size);
        this.numberBabies = numberBabies;
    }

    public void run() {
        System.out.println("Moving: Running on the ground");
    }
}

abstract class Aves extends Animal {
    public Aves(Color color, Size size) {
        super(color, size);
    }

    public void fly() {
        System.out.println("Moving: Flying in the sky");
    }
}

abstract class Osteichthyes extends Animal {
    public Osteichthyes(Color color, Size size) {
        super(color, size);
    }

    public void swim() {
        System.out.println("Moving: Swimming in the sea");
    }
}

// ======================

class Dog extends Mammalia {
    protected boolean fierce;

    public Dog(Color color, Size size, int numberBabies, boolean fierce) {
        super(color, size, numberBabies);
        this.fierce = fierce;
    }

    @Override
    public void sound() {
        System.out.println("Sound: Wolf wolf");
    }

    @Override
    public void eat() {
        System.out.println("Food: Bones");
    }

    public void bark() {
        System.out.println("Action: Barking loud!");
    }

    public void bite() {
        System.out.println("Fierce Status: " + fierce);
        System.out.println("It gonna bite you");
    }
}

class Bird extends Aves {
    protected String egg;

    public Bird(Color color, Size size, String egg) {
        super(color, size);
        this.egg = egg;
    }

    @Override
    public void sound() {
        System.out.println("Sound: Chip chip");
    }

    @Override
    public void eat() {
        System.out.println("Food: Worms");
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
        System.out.println("Sound: Pop pop");
    }

    @Override
    public void eat() {
        System.out.println("Food: Small Fish");
    }
}

// ======================

class ThaiRidgeBack extends Dog {
    private String origin;

    public ThaiRidgeBack(Color color, Size size, int numberBabies, boolean fierce, String origin) {
        super(color, size, numberBabies, fierce);
        this.origin = origin;
    }
    
    public void info() {
      System.out.println("--Dog--");
      System.out.println("__ThaiRidgeBack__"); // เขียนชื่อตรงๆ
      System.out.println("Color: " + color + " | Size: " + size);
      System.out.println("Babies: " + numberBabies);
      System.out.println("Fierce: " + (fierce ? "Yes" : "No"));
      System.out.println("Origin: " + origin);
    }

    public void showOrigin() {
        System.out.println("Origin: " + origin);
    }
}

class HummingBird extends Bird {
    public HummingBird(Color color, Size size, String egg) {
        super(color, size, egg);
    }
    
    public void info() {
        // แก้แล้ว: เขียนชื่อตรงๆ
        System.out.println("--Bird--");
        System.out.println("__HummingBird");
        System.out.println("Color: " + color + " | Size: " + size);
        System.out.println("Egg Type: " + egg);
    }
}

class AngleFish extends Fish {
    private String location;

    public AngleFish(Color color, Size size, String waterGroup, String location) {
        super(color, size, waterGroup);
        this.location = location;
    }
    
    public void info() {
        // แก้แล้ว: เขียนชื่อตรงๆ
        System.out.println("--Fish--");
        System.out.println("__AngleFish__");
        System.out.println("Color: " + color + " | Size: " + size);
        System.out.println("Water: " + waterGroup);
    }

    public void showLocation() {
        System.out.println("Location: " + location);
    }
}

// ======================

public class App {
    public static void main(String[] args) {

        ThaiRidgeBack dog = new ThaiRidgeBack(
                Color.BROWN, Size.MEDIUM, 5, true, "Thailand"
        );

        dog.info();
        dog.sound();
        dog.eat();
        dog.run();
        dog.bark();

        System.out.println("----------------");

        HummingBird bird = new HummingBird(Color.WHITE, Size.SMALL, "Small egg");
        bird.info();
        bird.fly();
        bird.sound();

        System.out.println("----------------");

        AngleFish fish = new AngleFish(Color.GREY, Size.SMALL, "Salt Water", "Pacific Ocean");
        fish.info();
        fish.swim();
        fish.showLocation();
    }
}
