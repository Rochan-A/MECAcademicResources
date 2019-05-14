import java.awt.Color;

import javax.swing.JFrame;

public class BrickBreaker extends JFrame {
	private final static int WIDTH = 400, HEIGHT = 850;
	private BrickBreakerPanel panel;

	public BrickBreaker() {
		setSize(WIDTH, HEIGHT);
		setTitle("Breakout");
		setBackground(Color.WHITE);
		setResizable(false);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		panel = new BrickBreakerPanel(this);
		add(panel);
	}

	public BrickBreakerPanel getPanel() {
		return panel;
	}
	public static void main(String[] args) {
		new BrickBreaker();
	}
}