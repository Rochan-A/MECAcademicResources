import java.awt.Graphics;
import java.awt.Rectangle;

public class Racket {
	private static final int WIDTH = 60, HEIGHT = 10;
	private BrickBreaker game;
	private int right, left;
	private int y;
	private int x, xa;

	public Racket(BrickBreaker game, int right, int left) {
		this.game = game;
		this.x = game.getWidth()/2;
		y = game.getHeight() - 50;
		this.right = right;
		this.left = left;
	}

	public void update() {
		if (x > 0 && x < game.getWidth() - WIDTH)
			x += xa;
		else if (x == 0)
			x++;
		else if (x == game.getWidth() - WIDTH)
			x--;
	}

	public void pressed(int keyCode) {
		if (keyCode == right)
			xa = 1;
		else if (keyCode == left)
			xa = -1;
	}

	public void released(int keyCode) {
		if (keyCode == right || keyCode == left)
			xa = 0;
	}

	public Rectangle getBounds() {
		return new Rectangle(x, y, WIDTH, HEIGHT);
	}

	public void paint(Graphics g) {
		g.fillRect(x, y, WIDTH, HEIGHT);
	}
}