package lab5.Swings;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Radio extends JApplet implements ActionListener
{
	JRadioButton b1,b2,b3,b4;
	JTextField tb1,tb2,tb3;
	public void init() 
	{
		makeGUI();
	}
	private void makeGUI() 
	{
		setLayout(new FlowLayout());
		b1 = new JRadioButton("ADD");
		b1.addActionListener(this);
		add(b1);
		b2 = new JRadioButton("SUB");
		b2.addActionListener(this);
		add(b2);
		b3 = new JRadioButton("MUL");
		b3.addActionListener(this);
		add(b3);
		b4 = new JRadioButton("DIV");
		b4.addActionListener(this);
		add(b4);
		ButtonGroup bg = new ButtonGroup();
		bg.add(b1);
		bg.add(b2);
		bg.add(b3);
		bg.add(b4);
		tb1=new JTextField(20);
		tb1.addActionListener(this);
		tb2=new JTextField(20);
		tb2.addActionListener(this);
		tb3=new JTextField(20);
		tb3.addActionListener(this);
		tb3.disable();
		add(tb1);
		add(tb2);
		add(tb3);
	}
	public void actionPerformed(ActionEvent ae)
	{
		String s1,s2,s3;
		try
		{
			s1=tb1.getText();
			s2=tb2.getText();
			int num1 = Integer.parseInt(s1);
			int num2 = Integer.parseInt(s2);
			int num3=0;
			if(ae.getActionCommand().equals("ADD"))
			{
				num3=num1+num2;
			}
			else if(ae.getActionCommand().equals("SUB"))
			{
				num3=num1-num2;
			}
			else if(ae.getActionCommand().equals("MUL"))
			{
				num3=num1*num2;
			}
			else if(ae.getActionCommand().equals("DIV"))
			{
				try
				{
					num3=num1/num2;
				}
				catch(Exception ex)
				{
					System.out.println(ex);
				}
			}
			Integer intval = new Integer(num3);
			s3 =  intval.toString();
			tb3.setText(s3);
		}
		catch(Exception ex)
		{
			System.out.println(ex);
		}
	}
}