import java.awt.Graphics;
import java.awt.Rectangle;

public class Bricks {
	private static final int WIDTH = 50, HEIGHT = 10;
	public int arr[][]={{1,50,100},{1,110,100},{1,170,100},{1,230,100},{1,290,100},{1,50,120},{1,110,120},{1,170,120},{1,230,120},{1,290,120},{1,50,160},{1,110,160},{1,170,160},{1,230,160},{1,290,160},{1,50,140},{1,110,140},{1,170,140},{1,230,140},{1,290,140},{1,50,180},{1,110,180},{1,170,180},{1,230,180},{1,290,180},{1,50,200},{1,110,200},{1,170,200},{1,230,200},{1,290,200},{1,50,220},{1,110,220},{1,170,220},{1,230,220},{1,290,220},{1,50,240},{1,110,240},{1,170,240},{1,230,240},{1,290,240}};
	private Rectangle a;

	Bricks(BrickBreaker game){
	}

	public void paint(Graphics g) {
		for(int i = 0; i < 40; i++){
			if(arr[i][0] == 1){
				g.fillRect(arr[i][1], arr[i][2], WIDTH, HEIGHT);
			}
		}
	}

	public Rectangle getBounds(int i) {
		if(arr[i][0] == 1){
			a = new Rectangle(arr[i][1], arr[i][2], WIDTH, HEIGHT);
		}
		else if(arr[i][0] == 0){
			a = new Rectangle(0, 0, 0, 0);
		}
		return a;
	}
}
