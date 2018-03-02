package lab5.Swings;
import java.awt.*;
import java.awt.event.*;
import java.awt.FlowLayout.*;
import javax.swing.*;

public class CheckBox extends JApplet implements ItemListener
{
	JLabel lab1,lab2,lab3,lab4;
	JCheckBox cb1,cb2,cb3;
	public void init()
	{
		makeGUI();
	}
	public void makeGUI()
	{
		setLayout(new FlowLayout());
		lab1=new JLabel("Select a Programming language");
		lab2=new JLabel("");
		lab3=new JLabel("");
		lab4=new JLabel("");
		cb1=new JCheckBox("java");
		cb1.addItemListener(this);
		cb2=new JCheckBox("Python");
		cb2.addItemListener(this);
		cb3=new JCheckBox("C++");
		cb3.addItemListener(this);
		add(cb1);
		add(cb2);
		add(cb3);
		add(lab1);
		add(lab2);
		add(lab3);
		add(lab4);
	}
	public void itemStateChanged(ItemEvent ie)
	{
		if(cb1.isSelected())
			lab1.setText("java");
		else
			lab1.setText("");
		if(cb2.isSelected())
			lab2.setText("Python");
		else
			lab2.setText("");
		if(cb3.isSelected())
			lab3.setText("C++");
		else
			lab3.setText("");
		if(!(cb1.isSelected()||cb2.isSelected()||cb3.isSelected()))
			lab4.setText("Select a programming language");
		else
			lab4.setText("is selected");
		
	}
}