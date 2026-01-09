from abc import ABC, abstractmethod
import math
class Shape(ABC):
  def __init__(self,name):
    self._name = name #โพเทกเต็ดแอทริบิ้ว
    
  @abstractmethod
  def area(self):
    pass
  
  def info(self):
    print(f"ShapeName :{self._name}")
    
#class Circle
class Circle(Shape):
  def __init__(self,name,radius):
    super().__init__(name)
    self._radius = radius
    
  def area(self):
    return math.pi * (self._radius **2)
    
#class Cylinder
class Cylinder(Circle):
  def __init__(self,name,radius,length):
    super().__init__(name,radius)
    self._length = length
    
  def volume(self):
    return self.area() * self._length
    
#class Rectangle
class Rectangle(Shape):
  def __init__(self,name,width,height):
    super().__init__(name)
    self._width = width
    self._height = height
    
  def area(self):
    return self._width * self._height
    
#class Polygon
class Polygon(Rectangle):
  def __init__(self,name,width,height,n):
    super().__init__(name,width,height)
    self._n = n
    
  def area(self):
    return 0.5 * self._width * self._height * self._n
    
  def volume(self):
    return self.area() * self._height

#เรียกใช้งาน    
c = Circle("MyCircle", 5.0)
c.info()
print(f"Circle Area: {c.area():.2f}")
print("____________________________________")
    
cy1 = Cylinder("MyCylinder",5.0,10.0)
cy1.info()
print(f"CylinderVolume:{cy1.volume():.2f}")
print("____________________________________")
rec1 = Rectangle("MyRectangle",5.0,7.0)
rec1.info()
print(f"RectangleArea:{rec1.area():.2f}")
print("____________________________________")
poly = Polygon("MyPolygon", 4.0, 10.0, 6)
poly.info()
# คำนวณ Area: 0.5 * 4 * 10 * 6 = 120.0
print(f"Polygon Area: {poly.area():.2f}")
# คำนวณ Volume: Area(120) * Height(10) = 1200.0
print(f"Polygon Volume: {poly.volume():.2f}")
