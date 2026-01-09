using System;

abstract class Shape {
    protected string name;
    public Shape(string name) => this.name = name;
    public abstract double Area();
    public void Info() => Console.WriteLine($"ShapeName: {name}");
}

class Circle : Shape {
    protected double radius;
    public Circle(string name, double radius) : base(name) => this.radius = radius;
    public override double Area() => Math.PI * Math.Pow(radius, 2);
}

class Cylinder : Circle {
    private double length;
    public Cylinder(string name, double radius, double length) : base(name, radius) 
        => this.length = length;
    public double Volume() => this.Area() * length;
}

class Rectangle : Shape {
    protected double width, height;
    public Rectangle(string name, double width, double height) : base(name) {
        this.width = width;
        this.height = height;
    }
    public override double Area() => width * height;
}

class Polygon : Rectangle {
    private double n;
    public Polygon(string name, double width, double height, double n) 
        : base(name, width, height) => this.n = n;
    public override double Area() => 0.5 * width * height * n;
    public double Volume() => this.Area() * height;
}

class Program {
    static void Main() {
        Circle cir1 = new Circle("MyCircle", 5.0);
        cir1.Info();
        Console.WriteLine($"CircleArea: {cir1.Area():F2}\n_______________________________");

        Cylinder cy1 = new Cylinder("MyCylinder", 4.0, 10.0);
        cy1.Info();
        Console.WriteLine($"CylinderVolume: {cy1.Volume():F2}\n_______________________________");

        Rectangle rec1 = new Rectangle("MyRectangle", 2.0, 6.0);
        rec1.Info();
        Console.WriteLine($"RectangleArea: {rec1.Area():F2}\n_______________________________");

        Polygon pol1 = new Polygon("MyPolygon", 4.0, 10.0, 6.0);
        pol1.Info();
        Console.WriteLine($"PolygonArea: {pol1.Area():F2}");
        Console.WriteLine($"PolygonVolume: {pol1.Volume():F2}");
    }
}