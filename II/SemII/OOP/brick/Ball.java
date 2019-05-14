import java.awt.Graphics;
import java.awt.Rectangle;

import javax.swing.JOptionPane;

public class Ball {
	private static final int WIDTH = 10, HEIGHT = 10;
	private Bricks bricks;
	private BrickBreaker game;
	private int x, y, xa = 1, ya = 1;

	public Ball(BrickBreaker game) {
		this.game = game;
		x = game.getWidth() / 2;
		y = game.getHeight() / 2;
	}

	public void update() {
		x += xa;
		y += ya;
		if (y > 0 && y < game.getHeight() - HEIGHT){
			if ((x < 0 )){
				xa = -xa;
				x = 4;
			}
			else if((x > game.getWidth() - WIDTH)){
				xa = -xa;
				x = game.getWidth() - WIDTH - 5;
			}
		}
		else if(x > 0 && x < game.getWidth() - WIDTH){
			if ((y < 0 )){
				ya = 2;
				y = 5;
			}
			else if((y > game.getHeight() - HEIGHT)){
				JOptionPane.showMessageDialog(null, "You Died", "BrickBreaker", JOptionPane.PLAIN_MESSAGE);
			}
		}
		if (game.getPanel().getScore() == 40)
			JOptionPane.showMessageDialog(null, "Player wins", "BrickBreaker", JOptionPane.PLAIN_MESSAGE);
		checkCollision();
		//System.out.println(Integer.toString(x) + " " + Integer.toString(y) + " " + Integer.toString(xa) + " " + Integer.toString(ya));
	}

	public void checkCollision() {
		if (game.getPanel().getPlayer().getBounds().intersects(getBounds()))
			ya = -ya;
		bricks = game.getPanel().getBrick();
		for(int i = 0; i < 40; i++){
			if (bricks.getBounds(i).intersects(getBounds())){
				bricks.arr[i][0] = 0;
				game.getPanel().increaseScore();
			}
		}
	}

	public Rectangle getBounds() {
		return new Rectangle(x, y, WIDTH, HEIGHT);
	}

	public void paint(Graphics g) {
		g.fillRect(x, y, WIDTH, HEIGHT);
	}
}