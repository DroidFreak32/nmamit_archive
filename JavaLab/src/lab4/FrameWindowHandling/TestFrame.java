package lab4.FrameWindowHandling;

import java.awt.*;

public class TestFrame extends Frame {
    public static void main(String[] args) {
        TestFrame obj = new TestFrame();
        obj.setTitle("Window Test");
        obj.setSize(300,600);
        obj.setVisible(true);
    }

    public void paint(Graphics g){
        String msg = "Java frame test";
        g.drawString(msg,150,150);
    }
}
