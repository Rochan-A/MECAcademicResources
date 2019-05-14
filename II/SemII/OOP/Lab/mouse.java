// Java Program to illustrate MouseMotionListener events
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Mouse extends Frame implements MouseMotionListener {

	static JLabel label1, label2;

	public static void main(String[] args)
	{

		JFrame f = new JFrame("MouseMotionListener");


		f.setSize(600, 400);


		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// create anew panel
		JPanel p = new JPanel();

		// set the layout of the panel
		p.setLayout(new FlowLayout());

		// initialize the labels
		label1 = new JLabel("no event ");

		label2 = new JLabel("no event ");

		// create an object of mouse class
		Mouse m = new Mouse();

		// add mouseListener to the frame
		f.addMouseMotionListener(m);

		// add labels to the panel
		p.add(label1);
		p.add(label2);

		// add panel to the frame
		f.add(p);

		f.show();
	}

	public void mouseDragged(MouseEvent e)
	{
		label1.setText("mouse is dragged through point "
					+ e.getX() + " " + e.getY());
	}

	public void mouseMoved(MouseEvent e)
	{
		label2.setText("mouse is moved to point "
					+ e.getX() + " " + e.getY());
	}
}