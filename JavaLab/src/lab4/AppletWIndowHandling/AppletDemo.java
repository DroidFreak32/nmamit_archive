package lab4.AppletWIndowHandling;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

/*
<applet code="AppletDemo" width=600 height=600>
</applet>
*/


/*
    To Run this file from the console, Perform the following steps:
        1) Remove all the "package" lines on top.
        2) Compile using javac <filename.java>
        3) Run "appletviewer <filename.java>


    To Run this file in intellij, Perform the following steps:
        1) Run > Edit Configurations.
        2) Press the green "+" sign and select "Applet"
        3) In the "Applet Class" field, type the name of the Java class (AppletDemo in this case). It should automatically fill up the package path n stuff.
        4) Apply, OK.
        5) Now run the program from the Project toolbar
*/

public class AppletDemo extends Applet implements KeyListener,MouseListener,MouseMotionListener {

    // Applets don't need main() method. These windows can be shown on browsers. Browsers interpret the above HTML tags.

    String msg = "Keyboard entry: ";

    // Mouse's initial Coordinates
    int mouseX = 100, mouseY = 100;



    public void paint(Graphics g){
        g.drawString(msg,mouseX,mouseY); // Dislay the message at that position
    }
    public void init() {
        addKeyListener(this);
        addMouseListener(this);
        addMouseMotionListener(this);
    }

    @Override
    public void keyTyped(KeyEvent keyEvent) {
        msg += keyEvent.getKeyChar();
        repaint();
        showStatus("Key typed " + keyEvent.getKeyCode());
    }

    @Override
    public void keyPressed(KeyEvent keyEvent) {
        showStatus("Key Pressed");
    }

    @Override
    public void keyReleased(KeyEvent keyEvent) {
        showStatus("Key Released");
    }

    // MouseListener methods
    @Override
    public void mouseClicked(MouseEvent mouseEvent) {
        showStatus("Mouse Clicked");

    }

    @Override
    public void mousePressed(MouseEvent mouseEvent) {
        showStatus("Mouse Pressed");
    }

    @Override
    public void mouseReleased(MouseEvent mouseEvent) {
        showStatus("Mouse Released");
    }

    @Override
    public void mouseEntered(MouseEvent mouseEvent) {
        showStatus("Mouse Entered");
    }

    @Override
    public void mouseExited(MouseEvent mouseEvent) {
        showStatus("Mouse Exited");
    }

    // MouseMotionListener methods

    @Override
    public void mouseDragged(MouseEvent mouseEvent) {

        // Move the text to the mouse's position when it's dragged.
        mouseX = mouseEvent.getX();
        mouseY = mouseEvent.getY();
        repaint();

        showStatus("Mouse Dragged, position: " + mouseX + ", " + mouseY);
    }

    @Override
    public void mouseMoved(MouseEvent mouseEvent) {
        showStatus("Mouse Moved");
    }
}
