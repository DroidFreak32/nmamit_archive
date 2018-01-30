package lab4.FrameWindowHandling;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class TestFrameEventHandling extends Frame implements MouseListener {

    String msg;
    String key;

    boolean lower;

    public TestFrameEventHandling(){
        addMouseListener(this);         // The frame class itself listens to mouse events.
        msg = "Java frame test";
        key = "";
        lower = true;
    }

    public static void main(String[] args) {
        TestFrameEventHandling obj = new TestFrameEventHandling();
        obj.setTitle("Window Test");
        obj.setSize(300,600);
        obj.setVisible(true);
    }

    public void paint(Graphics g){
        g.drawString(msg,150,150);
    }

    @Override
    public void mouseClicked(MouseEvent mouseEvent) {
        if(lower){
            msg = msg.toUpperCase();
            lower = false;
        }
        else{
            msg = msg.toLowerCase();
            lower = true;
        }
        repaint();

    }

    @Override
    public void mousePressed(MouseEvent mouseEvent) {

    }

    @Override
    public void mouseReleased(MouseEvent mouseEvent) {

    }

    @Override
    public void mouseEntered(MouseEvent mouseEvent) {

    }

    @Override
    public void mouseExited(MouseEvent mouseEvent) {

    }
}
