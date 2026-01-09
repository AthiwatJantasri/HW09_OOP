from abc import ABC, abstractmethod
from enum import Enum

# --- 1. สร้าง Enum สำหรับ Color และ Size ---
class Color(Enum):
    BLACK = "Black"
    WHITE = "White"
    GREY = "Grey"
    BROWN = "Brown"
    DARK_BROWN = "Dark Brown"
    BLACK_STRIPES = "Black Stripes"
    WHITE_STRIPES = "White Stripes"

class Size(Enum):
    SMALL = "Small"
    MEDIUM = "Medium"
    LARGE = "Large"
    HUGE = "Huge"

# --- 2. Abstract Class: Animal ---
class Animal(ABC):
    def __init__(self, color, size):
        self._color = color  # type: Color
        self._size = size    # type: Size

    @abstractmethod
    def sound(self):
        pass

    @abstractmethod
    def eat(self):
        pass
    
    # Method เสริมเพื่อแสดงข้อมูลพื้นฐาน
    def print_info(self):
        print(f"--- {self.__class__.__name__} ---")
        # .value เพื่อดึง string ออกมาจาก Enum
        print(f"Color: {self._color.value}, Size: {self._size.value}")

# --- 3. Class กลุ่มประเภทสัตว์ (Mammalia, Aves, Osteichthyes) ---

# 3.1 สัตว์เลี้ยงลูกด้วยนม
class Mammalia(Animal):
    def __init__(self, color, size, number_babies):
        super().__init__(color, size)
        self._number_babies = number_babies # int

    def run(self):
        print("Moving: Running on the ground.")

# 3.2 สัตว์ปีก (Aves)
class Aves(Animal):
    def __init__(self, color, size):
        super().__init__(color, size)

    def fly(self):
        print("Moving: Flying in the sky.")

# 3.3 ปลากระดูกแข็ง (Osteichthyes)
class Osteichthyes(Animal):
    def __init__(self, color, size):
        super().__init__(color, size)

    def swimming(self):
        print("Moving: Swimming in the water.")

# --- 4. Class สัตว์เฉพาะ (Dog, Bird, Fish) ---

# 4.1 Dog
class Dog(Mammalia):
    def __init__(self, color, size, number_babies, fierce):
        super().__init__(color, size, number_babies)
        self._fierce = fierce # boolean (ดุร้ายไหม?)

    def sound(self):
        print("Sound: Woof Woof!")

    def eat(self):
        print("Eat: Dog food and bones.")

    def bark(self):
        print("Action: Barking loudly!")

    def bite(self):
        if self._fierce:
            print("Action: Warning! It bites!")
        else:
            print("Action: It plays gently (not biting).")

# 4.2 Bird
class Bird(Aves):
    def __init__(self, color, size, egg_desc):
        super().__init__(color, size)
        self._egg = egg_desc # string ลักษณะไข่

    def sound(self):
        print("Sound: Chirp Chirp!")
        
    def eat(self):
        print("Eat: Worms and seeds.")

# 4.3 Fish
class Fish(Osteichthyes):
    def __init__(self, color, size, water_group):
        super().__init__(color, size)
        self._water_group = water_group # string (Freshwater/Saltwater)

    def sound(self):
        print("Sound: ... (Glub Glub)")
        
    def eat(self):
        print("Eat: Plankton and small fish.")

# --- 5. Class สายพันธุ์ย่อย (ThaiRidgeBack, HummingBird, AngelFish) ---

class ThaiRidgeBack(Dog):
    def __init__(self, color, size, number_babies, fierce, origin):
        super().__init__(color, size, number_babies, fierce)
        self._origin = origin # string ถิ่นกำเนิด

    def show_origin(self):
        print(f"Origin: {self._origin}")

class HummingBird(Bird):
    def __init__(self, color, size, egg_desc, location):
        super().__init__(color, size, egg_desc)
        self._location = location # string สถานที่พบเจอ

    def show_location(self):
        print(f"Location: {self._location}")

class AngelFish(Fish):
    # ใน Diagram ไม่ได้ระบุ Attribute พิเศษเพิ่ม จึงใช้โครงสร้างเดียวกับ Fish
    pass

# --- 6. ส่วนทดสอบ (Main Execution) ---
if __name__ == "__main__":
    # --- Test ThaiRidgeBack ---
    # สีน้ำตาล, ขนาดกลาง, ลูก 4 ตัว, ดุร้าย(True), มาจากไทย
    trb = ThaiRidgeBack(Color.BROWN, Size.MEDIUM, 4, True, "Thailand")
    trb.print_info()
    trb.eat()           
    trb.run()           
    trb.sound()         
    trb.bark()          
    trb.bite()          
    trb.show_origin()   
    print("-------------------------------")

    # --- Test HummingBird ---
    # แก้ไข: ใช้ Color.GREY (หรือสีที่มีใน Enum) แทน GREEN
    hmb = HummingBird(Color.GREY, Size.SMALL, "Tiny White Egg", "Tropical Forest") 
    hmb.print_info()
    hmb.fly()    
    hmb.eat()   
    hmb.show_location()
    print("-------------------------------")

    # --- Test AngelFish ---
    # สีขาวลายทาง, ขนาดเล็ก, น้ำเค็ม
    af = AngelFish(Color.WHITE_STRIPES, Size.SMALL, "Saltwater")
    af.print_info()
    af.swimming()       
    af.eat()
    
    