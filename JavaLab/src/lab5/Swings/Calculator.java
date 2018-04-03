package lab5.Swings;

import java.awt.*;
import java.awt.event.*;
import java.awt.FlowLayout.*;
import javax.swing.*;


public class Calculator  extends JApplet implements ActionListener
{
	JLabel lab1,lab2,lab3;
	JTextField tbox1,tbox2,tbox3;
	JButton b1,b2;
	public void init()
	{
		makeGUI();
//		b2.addActionListener(this);
	}
	public void makeGUI()
	{
		setLayout(new FlowLayout());
		lab1=new JLabel("Number1");
		lab2=new JLabel("Number2");
		lab3=new JLabel("Number3");
		tbox1 = new JTextField(20);
		tbox1.addActionListener(this);
		tbox2 = new JTextField(20);
		tbox2.addActionListener(this);
		tbox3 = new JTextField(20);
		tbox3.addActionListener(this);
		b1 = new JButton("ADD");
		b1.setActionCommand("ADD");
		b1.addActionListener(this);
		b2 = new JButton("SUB");
		b2.setActionCommand("SUB");
		b2.addActionListener(this);
		
		add(lab1);
		add(tbox1);
		add(lab2);
		add(tbox2);
		add(lab3);
		add(tbox3);
		add(b1);
		add(b2);
		tbox3.disable();
		
	}
	public void actionPerformed(ActionEvent ae)
	{
		String s1,s2,s3;
		try
		{
			s1=tbox1.getText();
			s2=tbox2.getText();
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
			Integer intval = num3;
			s3 =  intval.toString();
			tbox3.setText(s3);
		}
		catch(Exception ex)
		{
			System.out.println(ex);
		}
	}
}