from enum import Enum, auto
from abc import ABC, abstractmethod

# Enums
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

# Abstract Base Class
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
    
    # ไม่มี abstract info() ตามที่คุณต้องการ

# Intermediate Abstract Classes
class Mammalia(Animal):
    def __init__(self, color, size, number_babies):
        super().__init__(color, size)
        self.number_babies = number_babies

    def run(self):
        print("Moving: Running on the ground")

class Aves(Animal):
    def __init__(self, color, size):
        super().__init__(color, size)

    def fly(self):
        print("Moving: Flying in the sky")

class Osteichthyes(Animal):
    def __init__(self, color, size):
        super().__init__(color, size)

    def swim(self):
        print("Moving: Swimming in the sea")

# Concrete Classes
class Dog(Mammalia):
    def __init__(self, color, size, number_babies, fierce):
        super().__init__(color, size, number_babies)
        self.fierce = fierce

    def info(self):
        print("__Dog__")
        # .name เพื่อดึงชื่อ Enum ออกมาเป็น String
        print(f"Color: {self.color.name} | Size: {self.size.name}")
        print(f"Babies: {self.number_babies}")
        print(f"Fierce: {'Yes' if self.fierce else 'No'}")

    def sound(self):
        print("Sound: Wolf wolf")

    def eat(self):
        print("Food: Bones")

    def bark(self):
        print("Action: Barking loud!")

    def bite(self):
        print(f"Fierce Status: {self.fierce}")
        print("It gonna bite you")

class Bird(Aves):
    def __init__(self, color, size, egg):
        super().__init__(color, size)
        self.egg = egg

    def info(self):
        print("__Bird__")
        print(f"Color: {self.color.name} | Size: {self.size.name}")
        print(f"Egg Type: {self.egg}")

    def sound(self):
        print("Sound: Chip chip")

    def eat(self):
        print("Food: Worms")

class Fish(Osteichthyes):
    def __init__(self, color, size, water_group):
        super().__init__(color, size)
        self.water_group = water_group

    def info(self):
        print("__Fish__")
        print(f"Color: {self.color.name} | Size: {self.size.name}")
        print(f"Water: {self.water_group}")

    def sound(self):
        print("Sound: Pop pop")

    def eat(self):
        print("Food: Small Fish")

# Specific Classes
class ThaiRidgeBack(Dog):
    def __init__(self, color, size, number_babies, fierce, origin):
        super().__init__(color, size, number_babies, fierce)
        self.origin = origin

    def info(self):
        print("__ThaiRidgeBack__") # เขียนชื่อตรงๆ
        print(f"Color: {self.color.name} | Size: {self.size.name}")
        print(f"Babies: {self.number_babies}")
        print(f"Fierce: {'Yes' if self.fierce else 'No'}")
        print(f"Origin: {self.origin}")

    def show_origin(self):
        print(f"Origin: {self.origin}")

class HummingBird(Bird):
    def __init__(self, color, size, egg):
        super().__init__(color, size, egg)

class AngleFish(Fish):
    def __init__(self, color, size, water_group, location):
        super().__init__(color, size, water_group)
        self.location = location

    def show_location(self):
        print(f"Location: {self.location}")

# Main Execution
if __name__ == "__main__":
    dog = ThaiRidgeBack(Color.BROWN, Size.MEDIUM, 5, True, "Thailand")
    dog.info()
    dog.sound()
    dog.eat()
    dog.run()
    dog.bark()
    # dog.bite()
    # dog.show_origin()

    print("----------------")

    bird = HummingBird(Color.WHITE, Size.SMALL, "Small egg")
    bird.info()
    bird.fly()
    bird.sound()

    print("----------------")

    fish = AngleFish(Color.GREY, Size.SMALL, "Salt Water", "Pacific Ocean")
    fish.info()
    fish.swim()
    fish.show_location()
