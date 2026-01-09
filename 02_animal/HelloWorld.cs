using System;

// --- 1. Enums ---
public enum Color { Black, White, Grey, Brown, DarkBrown, BlackStripes, WhiteStripes }
public enum Size { Small, Medium, Large, Huge }

// --- 2. Abstract Class: Animal ---
public abstract class Animal {
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
        // C# prints Enum names nicely by default
        Console.WriteLine($"Color: {color}, Size: {size}");
    }
}

// --- 3. Intermediate Classes ---
public abstract class Mammalia : Animal {
    protected int numberBabies;

    public Mammalia(Color color, Size size, int numberBabies) : base(color, size) {
        this.numberBabies = numberBabies;
    }

    public void Run() {
        Console.WriteLine("Moving: Running on the ground.");
    }
}

public abstract class Aves : Animal {
    public Aves(Color color, Size size) : base(color, size) { }

    public void Fly() {
        Console.WriteLine("Moving: Flying in the sky.");
    }
}

public abstract class Osteichthyes : Animal {
    public Osteichthyes(Color color, Size size) : base(color, size) { }

    public void Swimming() {
        Console.WriteLine("Moving: Swimming in the water.");
    }
}

// --- 4. Concrete Classes ---
public class Dog : Mammalia {
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
        if (fierce) {
            Console.WriteLine("Action: Warning! It bites!");
        } else {
            Console.WriteLine("Action: It plays gently (not biting).");
        }
    }
}

public class Bird : Aves {
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

public class Fish : Osteichthyes {
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
public class ThaiRidgeBack : Dog {
    private string origin;

    public ThaiRidgeBack(Color color, Size size, int numberBabies, bool fierce, string origin) 
        : base(color, size, numberBabies, fierce) {
        this.origin = origin;
    }

    public void ShowOrigin() {
        Console.WriteLine($"Origin: {origin}");
    }
}

public class HummingBird : Bird {
    private string location;

    public HummingBird(Color color, Size size, string eggDesc, string location) 
        : base(color, size, eggDesc) {
        this.location = location;
    }

    public void ShowLocation() {
        Console.WriteLine($"Location: {location}");
    }
}

public class AngelFish : Fish {
    public AngelFish(Color color, Size size, string waterGroup) : base(color, size, waterGroup) { }
}

// --- 6. Main Execution ---
class Program {
    static void Main(string[] args) {
        // Test ThaiRidgeBack
        ThaiRidgeBack trb = new ThaiRidgeBack(Color.Brown, Size.Medium, 4, true, "Thailand");
        trb.PrintInfo();
        trb.Eat();
        trb.Run();
        trb.Sound();
        trb.Bark();
        trb.Bite();
        trb.ShowOrigin();
        Console.WriteLine("-------------------------------");

        // Test HummingBird
        HummingBird hmb = new HummingBird(Color.Grey, Size.Small, "Tiny White Egg", "Tropical Forest");
        hmb.PrintInfo();
        hmb.Fly();
        hmb.Eat();
        hmb.ShowLocation();
        Console.WriteLine("-------------------------------");

        // Test AngelFish
        AngelFish af = new AngelFish(Color.WhiteStripes, Size.Small, "Saltwater");
        af.PrintInfo();
        af.Swimming();
        af.Eat();
    }
}