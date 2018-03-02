package lab5.Swings;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
/*
<applet code="TabDemo" width=400 height=100>
</applet>
*/
public class TabDemo extends JApplet
{
	public void init()
	{
		makeGUI();
	}
	public void makeGUI()
	{
		JTabbedPane jtp=new JTabbedPane();
		jtp.addTab("Places",new CitiesPanel());
		jtp.addTab("Colors",new ColorPanel());
		jtp.addTab("Flavors",new FlavorPanel());
		add(jtp);
	}
}
class CitiesPanel extends JPanel implements TreeSelectionListener
{
	public CitiesPanel()
	{
		DefaultMutableTreeNode top = new DefaultMutableTreeNode("India");
		DefaultMutableTreeNode a = new DefaultMutableTreeNode("Karnataka");
		DefaultMutableTreeNode b = new DefaultMutableTreeNode("kerala");
		DefaultMutableTreeNode a1 = new DefaultMutableTreeNode("Banglore");
		DefaultMutableTreeNode a2 = new DefaultMutableTreeNode("Manglore");
		DefaultMutableTreeNode a3 = new DefaultMutableTreeNode("Udupi");
		DefaultMutableTreeNode b1 = new DefaultMutableTreeNode("Thiruvananthapuram");
		DefaultMutableTreeNode b2 = new DefaultMutableTreeNode("Kochi");
		top.add(a);
		top.add(b);;
		a.add(a1);
		a.add(a2);
		a.add(a3);
		b.add(b1);
		b.add(b2);
		JTree tree= new JTree(top);
		JScrollPane jsp = new JScrollPane(tree);
		add(jsp);
		tree.addTreeSelectionListener(this);
	}
	public void valueChanged(TreeSelectionEvent e) 
	{
			System.out.println("Selection is"+e.getPath());
	}	
}
class ColorPanel extends JPanel implements ListSelectionListener
{
	public JList jlst;
	public String Colors[] ={"red","black","white"};
	public ColorPanel()
	{
		jlst = new JList(Colors);  
		jlst.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		jlst.addListSelectionListener(this);
		add(jlst);
	}
	public void valueChanged(ListSelectionEvent le) 
	{
		 int idx = jlst.getSelectedIndex();
		 System.out.println("Current selection: "+Colors[idx]);
	}
}
class FlavorPanel extends JPanel implements ActionListener
{
	JComboBox jcb;
	public FlavorPanel()
	{
		jcb = new JComboBox();
		jcb.addItem("Vanilla");
		jcb.addItem("Chocolate");
		jcb.addItem("Strawberry");
		jcb.addActionListener(this);
		add(jcb);
	}
	public void actionPerformed(ActionEvent ae)
	{
		String s=(String)jcb.getSelectedItem();
		System.out.println("selection is"+s);
	}
}