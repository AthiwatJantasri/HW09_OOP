#include <iostream>
#include <string>
using namespace std;

// --- 1. Enums ---
enum class Color { BLACK, WHITE, GREY, BROWN, DARK_BROWN, BLACK_STRIPES, WHITE_STRIPES };
enum class Size { SMALL, MEDIUM, LARGE, HUGE };

// Helper functions to get string from Enum
string getColorName(Color c) {
    switch(c) {
        case Color::BLACK: return "Black";
        case Color::WHITE: return "White";
        case Color::GREY: return "Grey";
        case Color::BROWN: return "Brown";
        case Color::DARK_BROWN: return "Dark Brown";
        case Color::BLACK_STRIPES: return "Black Stripes";
        case Color::WHITE_STRIPES: return "White Stripes";
        default: return "Unknown";
    }
}

string getSizeName(Size s) {
    switch(s) {
        case Size::SMALL: return "Small";
        case Size::MEDIUM: return "Medium";
        case Size::LARGE: return "Large";
        case Size::HUGE: return "Huge";
        default: return "Unknown";
    }
}

// --- 2. Abstract Class: Animal ---
class Animal {
protected:
    Color color;
    Size size;
    string className; // เก็บชื่อ Class เพื่อ printInfo

public:
    Animal(Color c, Size s, string name) : color(c), size(s), className(name) {}

    virtual void sound() = 0; // Pure Virtual Function
    virtual void eat() = 0;   // Pure Virtual Function

    void printInfo() {
        cout << "--- " << className << " ---" << endl;
        cout << "Color: " << getColorName(color) << ", Size: " << getSizeName(size) << endl;
    }
    
    // Virtual Destructor
    virtual ~Animal() {}
};

// --- 3. Intermediate Classes ---
class Mammalia : public Animal {
protected:
    int numberBabies;
public:
    Mammalia(Color c, Size s, string name, int babies) : Animal(c, s, name), numberBabies(babies) {}

    void run() {
        cout << "Moving: Running on the ground." << endl;
    }
};

class Aves : public Animal {
public:
    Aves(Color c, Size s, string name) : Animal(c, s, name) {}

    void fly() {
        cout << "Moving: Flying in the sky." << endl;
    }
};

class Osteichthyes : public Animal {
public:
    Osteichthyes(Color c, Size s, string name) : Animal(c, s, name) {}

    void swimming() {
        cout << "Moving: Swimming in the water." << endl;
    }
};

// --- 4. Concrete Classes ---
class Dog : public Mammalia {
protected:
    bool fierce;
public:
    Dog(Color c, Size s, string name, int babies, bool f) : Mammalia(c, s, name, babies), fierce(f) {}

    void sound() override {
        cout << "Sound: Woof Woof!" << endl;
    }

    void eat() override {
        cout << "Eat: Dog food and bones." << endl;
    }

    void bark() {
        cout << "Action: Barking loudly!" << endl;
    }

    void bite() {
        if (fierce)
            cout << "Action: Warning! It bites!" << endl;
        else
            cout << "Action: It plays gently (not biting)." << endl;
    }
};

class Bird : public Aves {
protected:
    string eggDesc;
public:
    Bird(Color c, Size s, string name, string egg) : Aves(c, s, name), eggDesc(egg) {}

    void sound() override {
        cout << "Sound: Chirp Chirp!" << endl;
    }

    void eat() override {
        cout << "Eat: Worms and seeds." << endl;
    }
};

class Fish : public Osteichthyes {
protected:
    string waterGroup;
public:
    Fish(Color c, Size s, string name, string water) : Osteichthyes(c, s, name), waterGroup(water) {}

    void sound() override {
        cout << "Sound: ... (Glub Glub)" << endl;
    }

    void eat() override {
        cout << "Eat: Plankton and small fish." << endl;
    }
};

// --- 5. Specific Species ---
class ThaiRidgeBack : public Dog {
private:
    string origin;
public:
    ThaiRidgeBack(Color c, Size s, int babies, bool f, string o) 
        : Dog(c, s, "ThaiRidgeBack", babies, f), origin(o) {}

    void showOrigin() {
        cout << "Origin: " << origin << endl;
    }
};

class HummingBird : public Bird {
private:
    string location;
public:
    HummingBird(Color c, Size s, string egg, string loc) 
        : Bird(c, s, "HummingBird", egg), location(loc) {}

    void showLocation() {
        cout << "Location: " << location << endl;
    }
};

class AngelFish : public Fish {
public:
    AngelFish(Color c, Size s, string water) 
        : Fish(c, s, "AngelFish", water) {}
};

// --- 6. Main Execution ---
int main() {
    // Test ThaiRidgeBack
    ThaiRidgeBack trb(Color::BROWN, Size::MEDIUM, 4, true, "Thailand");
    trb.printInfo();
    trb.eat();
    trb.run();
    trb.sound();
    trb.bark();
    trb.bite();
    trb.showOrigin();
    cout << "-------------------------------" << endl;

    // Test HummingBird
    HummingBird hmb(Color::GREY, Size::SMALL, "Tiny White Egg", "Tropical Forest");
    hmb.printInfo();
    hmb.fly();
    hmb.eat();
    hmb.showLocation();
    cout << "-------------------------------" << endl;

    // Test AngelFish
    AngelFish af(Color::WHITE_STRIPES, Size::SMALL, "Saltwater");
    af.printInfo();
    af.swimming();
    af.eat();

    return 0;
}