import java.util.*;

abstract class Shape {
    protected String name;

    public Shape(String name) {
        this.name = name;
    }

    public abstract double area();

    public void info() {
        System.out.println("ShapeName: " + this.name);
    }
}

class Circle extends Shape {
    protected double radius;

    public Circle(String name, double radius) {
        super(name);
        this.radius = radius;
    }

    @Override
    public double area() {
        return Math.PI * Math.pow(radius, 2);
    }
}

class Cylinder extends Circle {
    private double length;

    public Cylinder(String name, double radius, double length) {
        super(name, radius);
        this.length = length;
    }

    public double volume() {
        return this.area() * length;
    }
}

class Rectangle extends Shape {
    protected double width, height;

    public Rectangle(String name, double width, double height) {
        super(name);
        this.width = width;
        this.height = height;
    }

    @Override
    public double area() {
        return width * height;
    }
}

class Polygon extends Rectangle {
    private double n;

    public Polygon(String name, double width, double height, double n) {
        super(name, width, height);
        this.n = n;
    }

    @Override
    public double area() {
        return 0.5 * width * height * n;
    }

    public double volume() {
        return this.area() * height;
    }
}

public class Main {
    public static void main(String[] args) {
        Circle cir1 = new Circle("MyCircle", 5.0);
        cir1.info();
        System.out.printf("CircleArea: %.2f\n", cir1.area());
        System.out.println("_______________________________");

        Cylinder cy1 = new Cylinder("MyCylinder", 4.0, 10.0);
        cy1.info();
        System.out.printf("CylinderVolume: %.2f\n", cy1.volume());
        System.out.println("_______________________________");

        Rectangle rec1 = new Rectangle("MyRectangle", 2.0, 6.0);
        rec1.info();
        System.out.printf("RectangleArea: %.2f\n", rec1.area());
        System.out.println("_______________________________");

        Polygon pol1 = new Polygon("MyPolygon", 4.0, 10.0, 6.0);
        pol1.info();
        System.out.printf("PolygonArea: %.2f\n", pol1.area());
        System.out.printf("PolygonVolume: %.2f\n", pol1.volume());
    }
}