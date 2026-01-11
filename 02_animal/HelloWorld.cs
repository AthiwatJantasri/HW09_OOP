using System;

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

    public abstract void Sound();
    public abstract void Eat();
    // ตัด abstract info ออกตาม Java
}

abstract class Mammalia : Animal {
    protected int numberBabies;

    public Mammalia(Color color, Size size, int numberBabies) : base(color, size) {
        this.numberBabies = numberBabies;
    }

    public void Run() {
        Console.WriteLine("Moving: Running on the ground");
    }
}

abstract class Aves : Animal {
    public Aves(Color color, Size size) : base(color, size) { }

    public void Fly() {
        Console.WriteLine("Moving: Flying in the sky");
    }
}

abstract class Osteichthyes : Animal {
    public Osteichthyes(Color color, Size size) : base(color, size) { }

    public void Swim() {
        Console.WriteLine("Moving: Swimming in the sea");
    }
}

class Dog : Mammalia {
    protected bool fierce;

    public Dog(Color color, Size size, int numberBabies, bool fierce) 
        : base(color, size, numberBabies) {
        this.fierce = fierce;
    }

    // เขียนใหม่เอง ไม่ต้อง override ใคร
    public virtual void Info() {
        Console.WriteLine("__Dog__");
        Console.WriteLine($"Color: {color} | Size: {size}");
        Console.WriteLine($"Babies: {numberBabies}");
        Console.WriteLine($"Fierce: {(fierce ? "Yes" : "No")}");
    }

    public override void Sound() {
        Console.WriteLine("Sound: Wolf wolf");
    }

    public override void Eat() {
        Console.WriteLine("Food: Bones");
    }

    public void Bark() {
        Console.WriteLine("Action: Barking loud!");
    }

    public void Bite() {
        Console.WriteLine($"Fierce Status: {fierce}");
        Console.WriteLine("It gonna bite you");
    }
}

class Bird : Aves {
    protected string egg;

    public Bird(Color color, Size size, string egg) : base(color, size) {
        this.egg = egg;
    }

    public void Info() {
        Console.WriteLine("__Bird__");
        Console.WriteLine($"Color: {color} | Size: {size}");
        Console.WriteLine($"Egg Type: {egg}");
    }

    public override void Sound() {
        Console.WriteLine("Sound: Chip chip");
    }

    public override void Eat() {
        Console.WriteLine("Food: Worms");
    }
}

class Fish : Osteichthyes {
    protected string waterGroup;

    public Fish(Color color, Size size, string waterGroup) : base(color, size) {
        this.waterGroup = waterGroup;
    }

    public void Info() {
        Console.WriteLine("__Fish__");
        Console.WriteLine($"Color: {color} | Size: {size}");
        Console.WriteLine($"Water: {waterGroup}");
    }

    public override void Sound() {
        Console.WriteLine("Sound: Pop pop");
    }

    public override void Eat() {
        Console.WriteLine("Food: Small Fish");
    }
}

class ThaiRidgeBack : Dog {
    private string origin;

    public ThaiRidgeBack(Color color, Size size, int numberBabies, bool fierce, string origin) 
        : base(color, size, numberBabies, fierce) {
        this.origin = origin;
    }

    // Override Info ของ Dog เพื่อเปลี่ยนชื่อและเพิ่มข้อมูล
    public override void Info() {
        Console.WriteLine("__ThaiRidgeBack__");
        Console.WriteLine($"Color: {color} | Size: {size}");
        Console.WriteLine($"Babies: {numberBabies}");
        Console.WriteLine($"Fierce: {(fierce ? "Yes" : "No")}");
        Console.WriteLine($"Origin: {origin}");
    }

    public void ShowOrigin() {
        Console.WriteLine($"Origin: {origin}");
    }
}

class HummingBird : Bird {
    public HummingBird(Color color, Size size, string egg) : base(color, size, egg) { }
}

class AngleFish : Fish {
    private string location;

    public AngleFish(Color color, Size size, string waterGroup, string location) 
        : base(color, size, waterGroup) {
        this.location = location;
    }

    public void ShowLocation() {
        Console.WriteLine($"Location: {location}");
    }
}

class Program {
    static void Main(string[] args) {
        ThaiRidgeBack dog = new ThaiRidgeBack(
            Color.BROWN, Size.MEDIUM, 5, true, "Thailand"
        );

        dog.Info();
        dog.Sound();
        dog.Eat();
        dog.Run();
        dog.Bark();

        Console.WriteLine("----------------");

        HummingBird bird = new HummingBird(Color.WHITE, Size.SMALL, "Small egg");
        bird.Info();
        bird.Fly();
        bird.Sound();

        Console.WriteLine("----------------");

        AngleFish fish = new AngleFish(Color.GREY, Size.SMALL, "Salt Water", "Pacific Ocean");
        fish.Info();
        fish.Swim();
        fish.ShowLocation();
    }
}
