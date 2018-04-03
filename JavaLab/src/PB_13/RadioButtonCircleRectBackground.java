package PB_13;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class FrameEx extends JFrame implements ActionListener {
    JRadioButton d1, d2, d3, c1, c2, c3;
    JButton b1;
    int d;
    JFrame j;

    FrameEx() {
//j= new JFrame("rr");
        setLayout(new FlowLayout());
        setSize(300, 300);
//setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        d1 = new JRadioButton("circle");
        d2 = new JRadioButton("rec");
        d3 = new JRadioButton("line");
        d1.addActionListener(this);
        d2.addActionListener(this);
        d3.addActionListener(this);
        ButtonGroup b1 = new ButtonGroup();
        ButtonGroup b2 = new ButtonGroup();
        b1.add(d1);
        b1.add(d2);
        b1.add(d3);
        c1 = new JRadioButton("red");
        c2 = new JRadioButton("green");
        c3 = new JRadioButton("blue");
        c1.addActionListener(this);
        c2.addActionListener(this);
        c3.addActionListener(this);
        b2.add(c1);
        b2.add(c2);
        b2.add(c3);
        add(d1);
        add(d2);
        add(d3);
        add(c1);
        add(c2);
        add(c3);
        setVisible(true);
        repaint();
    }

    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();
        if (cmd.equals("circle")) {
            d = 1;
        } else if (cmd.equals("rec")) {
            d = 2;
        } else if (cmd.equals("line")) {
            d = 3;
        }
        repaint();
        if (cmd.equals("red")) {
            getContentPane().setBackground(Color.RED);
        } else if (cmd.equals("green")) {
            getContentPane().setBackground(Color.green);
        } else if (cmd.equals("blue")) {
            getContentPane().setBackground(Color.blue);
        }
    }

    public void paint(Graphics g) {
        super.paint(g);
        if (d == 1)
            g.drawOval(100, 100, 50, 50);
        if (d == 2)
            g.drawRect(100, 100, 50, 50);
        if (d == 3)
            g.drawLine(100, 100, 300, 300);
    }
}

public class RadioButtonCircleRectBackground {
    public static void main(String[] args) {
        FrameEx obj1 = new FrameEx();
    }
}
