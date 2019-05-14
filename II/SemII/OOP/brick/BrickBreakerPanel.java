import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JPanel;
import javax.swing.Timer;

public class BrickBreakerPanel extends JPanel implements ActionListener, KeyListener {
	private BrickBreaker game;
	private Ball ball;
	private Racket player;
	private Bricks bricks;
	private int score;

	public BrickBreakerPanel(BrickBreaker game) {
		setBackground(Color.WHITE);
		this.game = game;
		ball = new Ball(game);
		player = new Racket(game, KeyEvent.VK_RIGHT, KeyEvent.VK_LEFT);
		bricks = new Bricks(game);
		Timer timer = new Timer(5, this);
		timer.start();
		addKeyListener(this);
		setFocusable(true);
	}

	public Racket getPlayer() {
		return player;
	}

	public Bricks getBrick() {
		return bricks;
	}

	public void increaseScore() {
		score++;
	}

	public int getScore() {
		return score;
	}

	private void update() {
		ball.update();
		player.update();
	}

	public void actionPerformed(ActionEvent e) {
		update();
		repaint();
	}

	public void keyPressed(KeyEvent e) {
		player.pressed(e.getKeyCode());
	}

	public void keyReleased(KeyEvent e) {
		player.released(e.getKeyCode());
	}

	public void keyTyped(KeyEvent e) {
		;
	}

	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.drawString(":" + game.getPanel().getScore() + ":", game.getWidth() / 2, 10);
		ball.paint(g);
		player.paint(g);
		bricks.paint(g);
	}
}