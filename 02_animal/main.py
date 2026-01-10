from abc import ABC, abstractmethod
from enum import Enum

# --- 1. Enums ---
class Color(Enum):
    BLACK = 1
    WHITE = 2
    GREY = 3
    BROWN = 4
    DARK_BROWN = 5
    BLACK_STRIPES = 6
    WHITE_STRIPES = 7

class Size(Enum):
    SMALL = 1
    MEDIUM = 2
    LARGE = 3
    HUGE = 4

# --- 2. Abstract Class: Animal ---
class Animal(ABC):
    def __init__(self, color, size):
        self.color = color
        self.size = size

    @abstractmethod
    def sound(self):
        pass

    @abstractmethod
    def eat(self):
        pass

    def printInfo(self):
        print(f"--- {self.__class__.__name__} ---")
        # .name เพื่อดึงชื่อ Enum เช่น BROWN (ตัด Color. ออก)
        print(f"Color: {self.color.name}, Size: {self.size.name}")

# --- 3. Intermediate Classes ---
class Mammalia(Animal):
    def __init__(self, color, size, numberBabies):
        super().__init__(color, size)
        self.numberBabies = numberBabies

    def run(self):
        print("Moving: Running on the ground.")

class Aves(Animal):
    def __init__(self, color, size):
        super().__init__(color, size)

    def fly(self):
        print("Moving: Flying in the sky.")

class Osteichthyes(Animal):
    def __init__(self, color, size):
        super().__init__(color, size)

    def swimming(self):
        print("Moving: Swimming in the water.")

# --- 4. Concrete Classes ---
class Dog(Mammalia):
    def __init__(self, color, size, numberBabies, fierce):
        super().__init__(color, size, numberBabies)
        self.fierce = fierce

    def sound(self):
        print("Sound: Woof Woof!")

    def eat(self):
        print("Eat: Dog food and bones.")

    def bark(self):
        print("Action: Barking loudly!")

    def bite(self):
        # ทำตาม Java ล่าสุด: ปริ้น status แล้วกัดเลย ไม่ใช้ if
        print(f"Fierce Status: {self.fierce}")
        print("Action: Warning! It bites!")

class Bird(Aves):
    def __init__(self, color, size, eggDesc):
        super().__init__(color, size)
        self.eggDesc = eggDesc

    def sound(self):
        print("Sound: Chirp Chirp!")

    def eat(self):
        print("Eat: Worms and seeds.")

class Fish(Osteichthyes):
    def __init__(self, color, size, waterGroup):
        super().__init__(color, size)
        self.waterGroup = waterGroup

    def sound(self):
        print("Sound: ... (Glub Glub)")

    def eat(self):
        print("Eat: Plankton and small fish.")

# --- 5. Specific Species ---
class ThaiRidgeBack(Dog):
    def __init__(self, color, size, numberBabies, fierce, origin):
        super().__init__(color, size, numberBabies, fierce)
        self.origin = origin

    def showOrigin(self):
        print(f"Origin: {self.origin}")

class HummingBird(Bird):
    def __init__(self, color, size, eggDesc, location):
        super().__init__(color, size, eggDesc)
        self.location = location

    def showLocation(self):
        print(f"Location: {self.location}")

class AngelFish(Fish):
    def __init__(self, color, size, waterGroup):
        super().__init__(color, size, waterGroup)

# --- 6. Main Execution ---

trb = ThaiRidgeBack(Color.BROWN, Size.MEDIUM, 4, True, "Thailand")
trb.printInfo()
trb.eat()
trb.run()
trb.sound()
trb.bark()
trb.bite()
trb.showOrigin()

print("-" * 31)

hmb = HummingBird(Color.GREY, Size.SMALL, "Tiny White Egg", "Tropical Forest")
hmb.printInfo()
hmb.fly()
hmb.eat()
hmb.showLocation()

print("-" * 31)

af = AngelFish(Color.WHITE_STRIPES, Size.SMALL, "Saltwater")
af.printInfo()
af.swimming()
af.eat()
