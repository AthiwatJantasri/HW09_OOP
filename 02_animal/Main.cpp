#include <iostream>
#include <string>
using namespace std;

enum class Color { BLACK, WHITE, GREY, BROWN };
enum class Size { SMALL, MEDIUM, LARGE, HUGE };

class Animal {
protected:
    Color color;
    Size size;

public:
    Animal(Color c, Size s) : color(c), size(s) {}
    virtual void sound() = 0;
    virtual void eat() = 0;

    void info() {
        cout << "__Animal__" << endl;
    }
};

// ======================

class Mammalia : public Animal {
protected:
    int numberBabies;

public:
    Mammalia(Color c, Size s, int n) : Animal(c, s), numberBabies(n) {}
    void run() { cout << "Moving: Running on the ground\n"; }
};

class Aves : public Animal {
public:
    Aves(Color c, Size s) : Animal(c, s) {}
    void fly() { cout << "Moving: Flying in the sky\n"; }
};

class Osteichthyes : public Animal {
public:
    Osteichthyes(Color c, Size s) : Animal(c, s) {}
    void swim() { cout << "Moving: Swimming in the sea\n"; }
};

// ======================

class Dog : public Mammalia {
protected:
    bool fierce;

public:
    Dog(Color c, Size s, int n, bool f) : Mammalia(c, s, n), fierce(f) {}

    void sound() override { cout << "Sound: Wolf wolf\n"; }
    void eat() override { cout << "Food: Bones\n"; }
    void bark() { cout << "Action: Barking loud!\n"; }
    void bite() {
        cout << "Fierce Status: " << fierce << endl;
        cout << "It gonna bite you\n";
    }
};

class Bird : public Aves {
protected:
    string egg;

public:
    Bird(Color c, Size s, string e) : Aves(c, s), egg(e) {}
    void sound() override { cout << "Sound: Chip chip\n"; }
    void eat() override { cout << "Food: Worms\n"; }
};

class Fish : public Osteichthyes {
protected:
    string waterGroup;

public:
    Fish(Color c, Size s, string w) : Osteichthyes(c, s), waterGroup(w) {}
    void sound() override { cout << "Sound: Pop pop\n"; }
    void eat() override { cout << "Food: Small Fish\n"; }
};

// ======================

class ThaiRidgeBack : public Dog {
    string origin;

public:
    ThaiRidgeBack(Color c, Size s, int n, bool f, string o)
        : Dog(c, s, n, f), origin(o) {}

    void showOrigin() { cout << "Origin: " << origin << endl; }
};

class HummingBird : public Bird {
public:
    HummingBird(Color c, Size s, string e) : Bird(c, s, e) {}
};

class AngleFish : public Fish {
    string location;

public:
    AngleFish(Color c, Size s, string w, string l)
        : Fish(c, s, w), location(l) {}

    void showLocation() { cout << "Location: " << location << endl; }
};

// ======================

int main() {
    ThaiRidgeBack dog(Color::BROWN, Size::MEDIUM, 5, true, "Thailand");
    dog.sound(); dog.eat(); dog.run(); dog.bark(); dog.bite(); dog.showOrigin();

    cout << "----------------\n";

    HummingBird bird(Color::WHITE, Size::SMALL, "Small egg");
    bird.fly(); bird.sound(); bird.eat();

    cout << "----------------\n";

    AngleFish fish(Color::GREY, Size::SMALL, "Salt Water", "Pacific Ocean");
    fish.swim(); fish.sound(); fish.eat(); fish.showLocation();
}
