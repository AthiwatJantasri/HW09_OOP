#include <iostream>
#include <string>
using namespace std;

// --- 1. Enums ---
enum Color { BLACK, WHITE, GREY, BROWN, DARK_BROWN, BLACK_STRIPES, WHITE_STRIPES };
enum Size { SMALL, MEDIUM, LARGE, HUGE };

// Helper function to convert Enum to String for printing
string colorToString(Color c) {
    switch(c) {
        case BLACK: return "BLACK";
        case WHITE: return "WHITE";
        case GREY: return "GREY";
        case BROWN: return "BROWN";
        case DARK_BROWN: return "DARK_BROWN";
        case BLACK_STRIPES: return "BLACK_STRIPES";
        case WHITE_STRIPES: return "WHITE_STRIPES";
        default: return "UNKNOWN";
    }
}
string sizeToString(Size s) {
    switch(s) {
        case SMALL: return "SMALL";
        case MEDIUM: return "MEDIUM";
        case LARGE: return "LARGE";
        case HUGE: return "HUGE";
        default: return "UNKNOWN";
    }
}

// --- 2. Abstract Class: Animal ---
class Animal {
protected:
    Color color;
    Size size;
public:
    Animal(Color c, Size s) : color(c), size(s) {}
    virtual void sound() = 0; // Pure virtual function
    virtual void eat() = 0;   // Pure virtual function
    
    void printInfo() {
        // C++ ไม่มี reflection ชื่อคลาสแบบง่ายๆ ขอ Hardcode ชื่อในลูกแทน หรือใช้วิธี typeid แต่มันจะยาว
        // ในที่นี้ขอปริ้นแค่ Attributes
        cout << "Color: " << colorToString(color) << ", Size: " << sizeToString(size) << endl;
    }
};

// --- 3. Intermediate Classes ---
class Mammalia : public Animal {
protected:
    int numberBabies;
public:
    Mammalia(Color c, Size s, int babies) : Animal(c, s), numberBabies(babies) {}
    void run() { cout << "Moving: Running on the ground." << endl; }
};

class Aves : public Animal {
public:
    Aves(Color c, Size s) : Animal(c, s) {}
    void fly() { cout << "Moving: Flying in the sky." << endl; }
};

class Osteichthyes : public Animal {
public:
    Osteichthyes(Color c, Size s) : Animal(c, s) {}
    void swimming() { cout << "Moving: Swimming in the water." << endl; }
};

// --- 4. Concrete Classes ---
class Dog : public Mammalia {
protected:
    bool fierce;
public:
    Dog(Color c, Size s, int babies, bool f) : Mammalia(c, s, babies), fierce(f) {}
    void sound() override { cout << "Sound: Woof Woof!" << endl; }
    void eat() override { cout << "Eat: Dog food and bones." << endl; }
    void bark() { cout << "Action: Barking loudly!" << endl; }
    void bite() {
        cout << "Fierce Status: " << (fierce ? "true" : "false") << endl;
        cout << "Action: Warning! It bites!" << endl;
    }
};

class Bird : public Aves {
protected:
    string eggDesc;
public:
    Bird(Color c, Size s, string egg) : Aves(c, s), eggDesc(egg) {}
    void sound() override { cout << "Sound: Chirp Chirp!" << endl; }
    void eat() override { cout << "Eat: Worms and seeds." << endl; }
};

class Fish : public Osteichthyes {
protected:
    string waterGroup;
public:
    Fish(Color c, Size s, string water) : Osteichthyes(c, s), waterGroup(water) {}
    void sound() override { cout << "Sound: ... (Glub Glub)" << endl; }
    void eat() override { cout << "Eat: Plankton and small fish." << endl; }
};

// --- 5. Specific Species ---
class ThaiRidgeBack : public Dog {
private:
    string origin;
public:
    ThaiRidgeBack(Color c, Size s, int babies, bool f, string o) : Dog(c, s, babies, f), origin(o) {}
    void printHeader() { cout << "--- ThaiRidgeBack ---" << endl; } // Helper for header
    void showOrigin() { cout << "Origin: " << origin << endl; }
};

class HummingBird : public Bird {
private:
    string location;
public:
    HummingBird(Color c, Size s, string egg, string loc) : Bird(c, s, egg), location(loc) {}
    void printHeader() { cout << "--- HummingBird ---" << endl; }
    void showLocation() { cout << "Location: " << location << endl; }
};

class AngelFish : public Fish {
public:
    AngelFish(Color c, Size s, string water) : Fish(c, s, water) {}
    void printHeader() { cout << "--- AngelFish ---" << endl; }
};

// --- 6. Main ---
int main() {
    ThaiRidgeBack trb(BROWN, MEDIUM, 4, true, "Thailand");
    trb.printHeader();
    trb.printInfo();
    trb.eat();
    trb.run();
    trb.sound();
    trb.bark();
    trb.bite();
    trb.showOrigin();
    cout << "-------------------------------" << endl;

    HummingBird hmb(GREY, SMALL, "Tiny White Egg", "Tropical Forest");
    hmb.printHeader();
    hmb.printInfo();
    hmb.fly();
    hmb.eat();
    hmb.showLocation();
    cout << "-------------------------------" << endl;

    AngelFish af(WHITE_STRIPES, SMALL, "Saltwater");
    af.printHeader();
    af.printInfo();
    af.swimming();
    af.eat();

    return 0;
}
