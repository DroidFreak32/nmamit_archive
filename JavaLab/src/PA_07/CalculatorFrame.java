package PA_07;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class Calculate implements ActionListener {
    JLabel l1 = new JLabel("First Number");
    JLabel l2 = new JLabel("Second Number");
    JLabel l3 = new JLabel("Third Number");
    JTextField t1 = new JTextField(10);
    JTextField t2 = new JTextField(10);
    JTextField t3 = new JTextField(10);
    JButton b1 = new JButton("Sum");

    Calculate() {
        JFrame f = new JFrame("Calculate");
        f.setLayout(new FlowLayout());
        f.setSize(500, 500);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(l1);
        f.add(t1);
        f.add(l2);
        f.add(t2);
        f.add(l3);
        f.add(t3);
        f.add(b1);
        b1.addActionListener(this);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        float a = Float.parseFloat(t1.getText());
        float b = Float.parseFloat(t2.getText());
        float c = Float.parseFloat(t3.getText());
        if (ae.getActionCommand().equals("Sum")) {
            float s = a + b + c;
            float t = ((a + b + c) / 3);
            float w = (Math.max(Math.max(a, b), c));
            JOptionPane.showMessageDialog(null, "sum is" + s + "\navg is" + t + "\nmax is" + w);
        }
    }


}

public class CalculatorFrame {
    public static void main(String args[]) {
        Calculate h = new Calculate();
    }
}
