using System;

// --- 1. Enums ---
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

    public Animal(Color color, Size size) {
        this.color = color;
        this.size = size;
    }

    public abstract void Sound();
    public abstract void Eat();

    public void PrintInfo() {
        Console.WriteLine("--- " + this.GetType().Name + " ---");
        Console.WriteLine("Color: " + color + ", Size: " + size);
    }
}

// --- 3. Intermediate Classes ---
abstract class Mammalia : Animal {
    protected int numberBabies;

    public Mammalia(Color color, Size size, int numberBabies) : base(color, size) {
        this.numberBabies = numberBabies;
    }

    public void Run() {
        Console.WriteLine("Moving: Running on the ground.");
    }
}

abstract class Aves : Animal {
    public Aves(Color color, Size size) : base(color, size) {}

    public void Fly() {
        Console.WriteLine("Moving: Flying in the sky.");
    }
}

abstract class Osteichthyes : Animal {
    public Osteichthyes(Color color, Size size) : base(color, size) {}

    public void Swimming() {
        Console.WriteLine("Moving: Swimming in the water.");
    }
}

// --- 4. Concrete Classes ---
class Dog : Mammalia {
    protected bool fierce;

    public Dog(Color color, Size size, int numberBabies, bool fierce) : base(color, size, numberBabies) {
        this.fierce = fierce;
    }

    public override void Sound() {
        Console.WriteLine("Sound: Woof Woof!");
    }

    public override void Eat() {
        Console.WriteLine("Eat: Dog food and bones.");
    }

    public void Bark() {
        Console.WriteLine("Action: Barking loudly!");
    }

    public void Bite() {
        Console.WriteLine("Fierce Status: " + fierce); 
        Console.WriteLine("Action: Warning! It bites!");
    }
}

class Bird : Aves {
    protected string eggDesc;

    public Bird(Color color, Size size, string eggDesc) : base(color, size) {
        this.eggDesc = eggDesc;
    }

    public override void Sound() {
        Console.WriteLine("Sound: Chirp Chirp!");
    }

    public override void Eat() {
        Console.WriteLine("Eat: Worms and seeds.");
    }
}

class Fish : Osteichthyes {
    protected string waterGroup;

    public Fish(Color color, Size size, string waterGroup) : base(color, size) {
        this.waterGroup = waterGroup;
    }

    public override void Sound() {
        Console.WriteLine("Sound: ... (Glub Glub)");
    }

    public override void Eat() {
        Console.WriteLine("Eat: Plankton and small fish.");
    }
}

// --- 5. Specific Species ---
class ThaiRidgeBack : Dog {
    private string origin;

    public ThaiRidgeBack(Color color, Size size, int numberBabies, bool fierce, string origin) 
        : base(color, size, numberBabies, fierce) {
        this.origin = origin;
    }

    public void ShowOrigin() {
        Console.WriteLine("Origin: " + origin);
    }
}

class HummingBird : Bird {
    private string location;

    public HummingBird(Color color, Size size, string eggDesc, string location) 
        : base(color, size, eggDesc) {
        this.location = location;
    }

    public void ShowLocation() {
        Console.WriteLine("Location: " + location);
    }
}

class AngelFish : Fish {
    public AngelFish(Color color, Size size, string waterGroup) : base(color, size, waterGroup) {}
}

// --- 6. Main Execution ---
class Program {
    static void Main(string[] args) {
        ThaiRidgeBack trb = new ThaiRidgeBack(Color.BROWN, Size.MEDIUM, 4, true, "Thailand");
        trb.PrintInfo();
        trb.Eat();
        trb.Run();
        trb.Sound();
        trb.Bark();
        trb.Bite();
        trb.ShowOrigin();

        Console.WriteLine("-------------------------------");

        HummingBird hmb = new HummingBird(Color.GREY, Size.SMALL, "Tiny White Egg", "Tropical Forest");
        hmb.PrintInfo();
        hmb.Fly();
        hmb.Eat();
        hmb.ShowLocation();

        Console.WriteLine("-------------------------------");

        AngelFish af = new AngelFish(Color.WHITE_STRIPES, Size.SMALL, "Saltwater");
        af.PrintInfo();
        af.Swimming();
        af.Eat();
    }
}
