#include <iostream>
#include <string>

enum class Color {
    BLACK, WHITE, GREY, BROWN, DARK_BROWN, BLACK_STRIPES, WHITE_STRIPES
};

enum class Size {
    SMALL, MEDIUM, LARGE, HUGE
};

// Helper function เพื่อแปลง Enum เป็น String ให้เหมือน Java
std::string colorToString(Color c) {
    switch (c) {
        case Color::BLACK: return "BLACK";
        case Color::WHITE: return "WHITE";
        case Color::GREY: return "GREY";
        case Color::BROWN: return "BROWN";
        case Color::DARK_BROWN: return "DARK_BROWN";
        case Color::BLACK_STRIPES: return "BLACK_STRIPES";
        case Color::WHITE_STRIPES: return "WHITE_STRIPES";
        default: return "UNKNOWN";
    }
}

std::string sizeToString(Size s) {
    switch (s) {
        case Size::SMALL: return "SMALL";
        case Size::MEDIUM: return "MEDIUM";
        case Size::LARGE: return "LARGE";
        case Size::HUGE: return "HUGE";
        default: return "UNKNOWN";
    }
}

class Animal {
protected:
    Color color;
    Size size;
public:
    Animal(Color c, Size s) : color(c), size(s) {}
    virtual ~Animal() {} // Destructor for cleanup

    virtual void sound() = 0; // Pure virtual function
    virtual void eat() = 0;
};

class Mammalia : public Animal {
protected:
    int numberBabies;
public:
    Mammalia(Color c, Size s, int babies) : Animal(c, s), numberBabies(babies) {}

    void run() {
        std::cout << "Moving: Running on the ground" << std::endl;
    }
};

class Aves : public Animal {
public:
    Aves(Color c, Size s) : Animal(c, s) {}

    void fly() {
        std::cout << "Moving: Flying in the sky" << std::endl;
    }
};

class Osteichthyes : public Animal {
public:
    Osteichthyes(Color c, Size s) : Animal(c, s) {}

    void swim() {
        std::cout << "Moving: Swimming in the sea" << std::endl;
    }
};

class Dog : public Mammalia {
protected:
    bool fierce;
public:
    Dog(Color c, Size s, int babies, bool f) : Mammalia(c, s, babies), fierce(f) {}

    // virtual เพื่อให้ ThaiRidgeBack override ได้
    virtual void info() {
        std::cout << "__Dog__" << std::endl;
        std::cout << "Color: " << colorToString(color) << " | Size: " << sizeToString(size) << std::endl;
        std::cout << "Babies: " << numberBabies << std::endl;
        std::cout << "Fierce: " << (fierce ? "Yes" : "No") << std::endl;
    }

    void sound() override {
        std::cout << "Sound: Wolf wolf" << std::endl;
    }

    void eat() override {
        std::cout << "Food: Bones" << std::endl;
    }

    void bark() {
        std::cout << "Action: Barking loud!" << std::endl;
    }

    void bite() {
        std::cout << "Fierce Status: " << fierce << std::endl;
        std::cout << "It gonna bite you" << std::endl;
    }
};

class Bird : public Aves {
protected:
    std::string egg;
public:
    Bird(Color c, Size s, std::string e) : Aves(c, s), egg(e) {}

    void info() {
        std::cout << "__Bird__" << std::endl;
        std::cout << "Color: " << colorToString(color) << " | Size: " << sizeToString(size) << std::endl;
        std::cout << "Egg Type: " << egg << std::endl;
    }

    void sound() override {
        std::cout << "Sound: Chip chip" << std::endl;
    }

    void eat() override {
        std::cout << "Food: Worms" << std::endl;
    }
};

class Fish : public Osteichthyes {
protected:
    std::string waterGroup;
public:
    Fish(Color c, Size s, std::string wg) : Osteichthyes(c, s), waterGroup(wg) {}

    void info() {
        std::cout << "__Fish__" << std::endl;
        std::cout << "Color: " << colorToString(color) << " | Size: " << sizeToString(size) << std::endl;
        std::cout << "Water: " << waterGroup << std::endl;
    }

    void sound() override {
        std::cout << "Sound: Pop pop" << std::endl;
    }

    void eat() override {
        std::cout << "Food: Small Fish" << std::endl;
    }
};

class ThaiRidgeBack : public Dog {
private:
    std::string origin;
public:
    ThaiRidgeBack(Color c, Size s, int babies, bool f, std::string o) 
        : Dog(c, s, babies, f), origin(o) {}

    void info() override {
        std::cout << "__ThaiRidgeBack__" << std::endl;
        std::cout << "Color: " << colorToString(color) << " | Size: " << sizeToString(size) << std::endl;
        std::cout << "Babies: " << numberBabies << std::endl;
        std::cout << "Fierce: " << (fierce ? "Yes" : "No") << std::endl;
        std::cout << "Origin: " << origin << std::endl;
    }

    void showOrigin() {
        std::cout << "Origin: " << origin << std::endl;
    }
};

class HummingBird : public Bird {
public:
    HummingBird(Color c, Size s, std::string e) : Bird(c, s, e) {}
};

class AngleFish : public Fish {
private:
    std::string location;
public:
    AngleFish(Color c, Size s, std::string wg, std::string loc) 
        : Fish(c, s, wg), location(loc) {}

    void showLocation() {
        std::cout << "Location: " << location << std::endl;
    }
};

int main() {
    ThaiRidgeBack dog(Color::BROWN, Size::MEDIUM, 5, true, "Thailand");
    dog.info();
    dog.sound();
    dog.eat();
    dog.run();
    dog.bark();
    
    std::cout << "----------------" << std::endl;

    HummingBird bird(Color::WHITE, Size::SMALL, "Small egg");
    bird.info();
    bird.fly();
    bird.sound();

    std::cout << "----------------" << std::endl;

    AngleFish fish(Color::GREY, Size::SMALL, "Salt Water", "Pacific Ocean");
    fish.info();
    fish.swim();
    fish.showLocation();

    return 0;
}
