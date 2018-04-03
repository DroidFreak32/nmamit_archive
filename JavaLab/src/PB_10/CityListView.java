package PB_10;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class A implements ActionListener {
    JFrame jfrm = new JFrame("GUI");
    String citi[] = {"karwar", "goa"};
    JList<String> li;
    JTextField t1;
    JRadioButton r1, r2;
    JCheckBox ch1, ch2;
    JLabel l1, l2, l3;
    ButtonGroup bg;
    JButton b;

    A() {
        jfrm.setLayout(new FlowLayout());
        jfrm.setSize(300, 300);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        l1 = new JLabel("Enter city");
        li = new JList<String>(citi);
        l2 = new JLabel("Enter name : ");
        t1 = new JTextField(10);
        l3 = new JLabel("Enter gender");
        r1 = new JRadioButton("male");
        r2 = new JRadioButton("female");
        bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        ch1 = new JCheckBox("prog");
        ch2 = new JCheckBox("simulation");
        b = new JButton("save");
        b.addActionListener(this);
        jfrm.add(l1);
        jfrm.add(li);
        jfrm.add(l2);
        jfrm.add(t1);
        jfrm.add(l3);
        jfrm.add(r1);
        jfrm.add(r2);
        jfrm.add(ch1);
        jfrm.add(ch2);
        jfrm.add(b);
        jfrm.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        int i;
        String s_name = null;
        String gender = null;
        String hob = null;
        String display = null;
        i = li.getSelectedIndex();
        s_name = t1.getText();
        if (r1.isSelected()) {
            gender = "male";
        }
        if (r2.isSelected()) {
            gender = "female";
        }
        if (ch1.isSelected()) {
            hob = "prog";
            if (ch2.isSelected()) {
                hob = hob + "simulation";
            }
        } else {
            if (ch2.isSelected()) {
                hob = "simulation";
            }
        }
        display = "city " + citi[i] + " name is " + s_name + " gender " + gender + " hobbies " + hob;
        JOptionPane.showMessageDialog(null, display);
    }
}

public class CityListView {
    public static void main(String[] args) {
        A obj1 = new A();
    }
}
