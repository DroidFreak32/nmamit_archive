package lab3.Exceptions;

public class ExceptionHandling {
	
	private int i = 0;
	private int a = 50;
	private int res;
	
	public void forceThrow() throws ArithmeticException {
		if (i == 0)
			throw new ArithmeticException("TEST");
	}
	
	
	
	public void noThrow(){
		//ArithmeticException
		int arr[] = new int[5];
		
		try{
			arr[5]=2;
			res = a/i;
		}
		catch (ArithmeticException e){
			System.out.println("Divide by 0 exception: "+e.toString());
		}
		catch (ArrayIndexOutOfBoundsException e){
			System.out.println("ArrayIndexOutOfBoundsException " + e.toString());
		}
		finally{
			System.out.println("Inside Finally block");
		}
		
		try{
			forceThrow();
		}
		catch(Exception e){
			System.out.println("Force throw exception" +e.toString());
		}
	}
	
	public String toString(){
		return ("CLASS DEF");
	}

}

