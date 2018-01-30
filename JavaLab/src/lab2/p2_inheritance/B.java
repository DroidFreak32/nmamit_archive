package p2_inheritance;

class B extends A {
	public B (){
		System.out.println("In B default constructor");
	}
	
	public void callMe(){
		System.out.println("Inside B callMe");
	}
	public void callMeToo(){
		System.out.println("Inside B callMeToo");
	}
}
