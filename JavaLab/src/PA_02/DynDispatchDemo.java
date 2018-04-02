package PA_02;

class Figure {
    double dim1;
    double dim2;

    Figure(double a, double b) {
        dim1 = a;
        dim2 = b;
    }

    double area() {
        System.out.println("Area for Figure is undefined.");
        return 0;
    }
}

class Rectangle extends Figure {
    Rectangle(double a, double b) {
        super(a, b);
    }

    // override area for rectangle
    double area() {
        System.out.println("Area of Rectangle: ");
        return dim1 * dim2;
    }
}

class Triangle extends Figure {
    Triangle(double a, double b) {
        super(a, b);
    }

    // override area for right triangle
    double area() {
        System.out.println("Area of Triangle: ");
        return dim1 * dim2 / 2;
    }
}

public class DynDispatchDemo {
    public static void main(String[] args) {
        double res;
        Figure f = new Figure(10, 10);
        Rectangle r = new Rectangle(9, 5);
        Triangle t = new Triangle(10, 8);
        Figure figref;  // Parent
        figref = r;     // Parent object is now the instance of the child Rectangle
        res = figref.area();  // Dynamic Method Dispatch
        System.out.println(res);

        figref = t;
        res = figref.area();
        System.out.println(res);

        figref = f;
        res = figref.area();
        System.out.println(res);

    }
}
