from abc import ABC, abstractmethod
from enum import Enum


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

    def info(self):
        print(f"__{self.__class__.__name__}__")
        print(f"Color: {self.color.name} Size: {self.size.name}")


# ======================

class Mammalia(Animal):
    def __init__(self, color, size, number_babies):
        super().__init__(color, size)
        self.number_babies = number_babies

    def run(self):
        print("Moving: Running on the ground")


class Aves(Animal):
    def fly(self):
        print("Moving: Flying in the sky")


class Osteichthyes(Animal):
    def swim(self):
        print("Moving: Swimming in the sea")


# ======================

class Dog(Mammalia):
    def __init__(self, color, size, number_babies, fierce):
        super().__init__(color, size, number_babies)
        self.fierce = fierce

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

    def sound(self):
        print("Sound: Chip chip")

    def eat(self):
        print("Food: Worms")


class Fish(Osteichthyes):
    def __init__(self, color, size, water_group):
        super().__init__(color, size)
        self.water_group = water_group

    def sound(self):
        print("Sound: Pop pop")

    def eat(self):
        print("Food: Small Fish")


# ======================

class ThaiRidgeBack(Dog):
    def __init__(self, color, size, number_babies, fierce, origin):
        super().__init__(color, size, number_babies, fierce)
        self.origin = origin

    def show_origin(self):
        print("Origin:", self.origin)


class HummingBird(Bird):
    pass


class AngleFish(Fish):
    def __init__(self, color, size, water_group, location):
        super().__init__(color, size, water_group)
        self.location = location

    def show_location(self):
        print("Location:", self.location)


# ======================
# main

dog = ThaiRidgeBack(Color.BROWN, Size.MEDIUM, 5, True, "Thailand")
dog.info()
dog.sound()
dog.eat()
dog.run()
dog.bark()
dog.bite()
dog.show_origin()

print("----------------")

bird = HummingBird(Color.WHITE, Size.SMALL, "Small egg")
bird.info()
bird.fly()
bird.sound()
bird.eat()

print("----------------")

fish = AngleFish(Color.GREY, Size.SMALL, "Salt Water", "Pacific Ocean")
fish.info()
fish.swim()
fish.sound()
fish.eat()
fish.show_location()
