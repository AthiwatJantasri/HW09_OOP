using System;

enum Color { BLACK, WHITE, GREY, BROWN, DARK_BROWN, BLACK_STRIPES, WHITE_STRIPES }
enum Size { SMALL, MEDIUM, LARGE, HUGE }

abstract class Animal
{
    protected Color color;
    protected Size size;

    public Animal(Color color, Size size)
    {
        this.color = color;
        this.size = size;
    }

    public abstract void Sound();
    public abstract void Eat();

    public void Info()
    {
        Console.WriteLine($"__{GetType().Name}__");
        Console.WriteLine($"Color: {color} Size: {size}");
    }
}

// ======================

abstract class Mammalia : Animal
{
    protected int numberBabies;

    public Mammalia(Color color, Size size, int numberBabies)
        : base(color, size)
    {
        this.numberBabies = numberBabies;
    }

    public void Run()
    {
        Console.WriteLine("Moving: Running on the ground");
    }
}

abstract class Aves : Animal
{
    public Aves(Color color, Size size) : base(color, size) { }

    public void Fly()
    {
        Console.WriteLine("Moving: Flying in the sky");
    }
}

abstract class Osteichthyes : Animal
{
    public Osteichthyes(Color color, Size size) : base(color, size) { }

    public void Swim()
    {
        Console.WriteLine("Moving: Swimming in the sea");
    }
}

// ======================

class Dog : Mammalia
{
    protected bool fierce;

    public Dog(Color color, Size size, int numberBabies, bool fierce)
        : base(color, size, numberBabies)
    {
        this.fierce = fierce;
    }

    public override void Sound() => Console.WriteLine("Sound: Wolf wolf");
    public override void Eat() => Console.WriteLine("Food: Bones");

    public void Bark() => Console.WriteLine("Action: Barking loud!");

    public void Bite()
    {
        Console.WriteLine($"Fierce Status: {fierce}");
        Console.WriteLine("It gonna bite you");
    }
}

class Bird : Aves
{
    protected string egg;

    public Bird(Color color, Size size, string egg) : base(color, size)
    {
        this.egg = egg;
    }

    public override void Sound() => Console.WriteLine("Sound: Chip chip");
    public override void Eat() => Console.WriteLine("Food: Worms");
}

class Fish : Osteichthyes
{
    protected string waterGroup;

    public Fish(Color color, Size size, string waterGroup) : base(color, size)
    {
        this.waterGroup = waterGroup;
    }

    public override void Sound() => Console.WriteLine("Sound: Pop pop");
    public override void Eat() => Console.WriteLine("Food: Small Fish");
}

// ======================

class ThaiRidgeBack : Dog
{
    private string origin;

    public ThaiRidgeBack(Color c, Size s, int n, bool f, string o)
        : base(c, s, n, f)
    {
        origin = o;
    }

    public void ShowOrigin() => Console.WriteLine("Origin: " + origin);
}

class HummingBird : Bird
{
    public HummingBird(Color c, Size s, string e) : base(c, s, e) { }
}

class AngleFish : Fish
{
    private string location;

    public AngleFish(Color c, Size s, string w, string l) : base(c, s, w)
    {
        location = l;
    }

    public void ShowLocation() => Console.WriteLine("Location: " + location);
}

// ======================

class Program
{
    static void Main()
    {
        ThaiRidgeBack dog = new ThaiRidgeBack(Color.BROWN, Size.MEDIUM, 5, true, "Thailand");
        dog.Info(); dog.Sound(); dog.Eat(); dog.Run(); dog.Bark(); dog.Bite(); dog.ShowOrigin();

        Console.WriteLine("----------------");

        HummingBird bird = new HummingBird(Color.WHITE, Size.SMALL, "Small egg");
        bird.Info(); bird.Fly(); bird.Sound(); bird.Eat();

        Console.WriteLine("----------------");

        AngleFish fish = new AngleFish(Color.GREY, Size.SMALL, "Salt Water", "Pacific Ocean");
        fish.Info(); fish.Swim(); fish.Sound(); fish.Eat(); fish.ShowLocation();
    }
}
