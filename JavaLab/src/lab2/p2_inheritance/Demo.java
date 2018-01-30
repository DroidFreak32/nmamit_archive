package p2_inheritance;

public class Demo {
	public static void main(String[] args){
		A a = new A();
		a.callMe();
		a = new B();
		a.callMe(); // Dynamic method dispatch
		B b = new B();
		b.callMeToo(); // Overriding
	}
}
