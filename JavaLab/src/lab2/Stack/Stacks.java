package lab2;

import java.io.*;
import java.util.*;

public class Stacks {
	
	private int stk[] = new int[10];
	private int top;
	public Stacks(){
		top = -1;
	}
	public void pushS(int i){
		if(top == stk.length){
			System.out.println("Stack full");
			return;
		}
		top++;
		stk[top] = i;
		System.out.println("Pushed "+i);
	}
	public void popS(){
		if(top == -1){
			System.out.println("Stack Empty");
			return;
		}
		int i = stk[top];
		top--;
		System.out.println("Popped "+i);
		return;
	}
	public void dispStack(){
		for (int i = top; i > -1; i--)
			System.out.println(stk[i]);
	}
	public static void main(String[] args){
		Stacks s = new Stacks();
		int c;
		Scanner reader = new Scanner(System.in);
		while(true){
			System.out.println("Enter option: \n1 - Push\n2 - Pop"
					+ "\n3 - Display\n4 - Exit");
			c = reader.nextInt();
			switch(c){
			case 1:
				System.out.println("Enter the number to push. ");
				s.pushS(reader.nextInt());
				break;
			case 2:
				s.popS();
				break;
			case 3:
				System.out.println("Contents of stack: ");
				s.dispStack();
				break;
			default:
				return;
			}
		}
	}
}



//stack, dynamic method dispatch, method overriding