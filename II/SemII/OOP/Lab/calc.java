import java.awt.*;
import java.awt.event.*;

class Calc implements ActionListener{
	Frame f = new Frame();

	Button num1 = new Button("1");
	Button num2 = new Button("2");
	Button num3 = new Button("3");
	Button num4 = new Button("4");
	Button num5 = new Button("5");
	Button num6 = new Button("6");
	Button num7 = new Button("7");
	Button num8 = new Button("8");
	Button num9 = new Button("9");
	Button num0 = new Button("0");

	Button sym_plus = new Button("+");
	Button sym_minus = new Button("-");
	Button sym_multiply = new Button("*");
	Button sym_divide = new Button("/");
	Button sym_eq = new Button("=");
	Button clear = new Button("clr");

	TextField output = new TextField();

	StringBuilder putText = new StringBuilder();
	int inputNum = 0;
	int tempNumber = 0;

	int actionToDo = 0;

	//Driver
	Calc(){
		num7.setBounds(40, 100, 40, 40);
		num8.setBounds(120, 100, 40, 40);
		num9.setBounds(200, 100, 40, 40);
		sym_plus.setBounds(280, 100, 40, 40);
		sym_multiply.setBounds(360, 100, 40, 40);
		clear.setBounds(440, 100, 40, 40);

		num4.setBounds(40, 180, 40, 40);
		num5.setBounds(120, 180, 40, 40);
		num6.setBounds(200, 180, 40, 40);
		sym_minus.setBounds(280, 180, 40, 40);
		sym_divide.setBounds(360, 180, 40, 40);
		sym_eq.setBounds(440, 180, 40, 40);

		num1.setBounds(40, 260, 40, 40);
		num2.setBounds(120, 260, 40, 40);
		num3.setBounds(200, 260, 40, 40);

		num0.setBounds(40, 340, 40, 40);

		output.setBounds(40, 40, 280, 40);

		f.add(output);

		f.add(num7);
		f.add(num8);
		f.add(num9);
		f.add(sym_plus);

		f.add(num4);
		f.add(num5);
		f.add(num6);
		f.add(sym_minus);
		f.add(clear);

		f.add(num1);
		f.add(num2);
		f.add(num3);
		f.add(sym_multiply);

		f.add(num0);
		f.add(sym_divide);

		f.add(sym_eq);

		num1.addActionListener(this);
		num2.addActionListener(this);
		num3.addActionListener(this);
		num4.addActionListener(this);
		num5.addActionListener(this);
		num6.addActionListener(this);
		num7.addActionListener(this);
		num8.addActionListener(this);
		num9.addActionListener(this);
		num0.addActionListener(this);

		sym_divide.addActionListener(this);
		sym_minus.addActionListener(this);
		sym_multiply.addActionListener(this);
		sym_plus.addActionListener(this);
		sym_eq.addActionListener(this);
		clear.addActionListener(this);

		f.setLayout(null);
		f.setVisible(true);
		f.setSize(360,500);
	}

	public void actionPerformed(ActionEvent ae){
		if (ae.getSource() == num1){
			inputNum = (10*inputNum) + 1;
			putText.append("1");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num2){
			inputNum = (10*inputNum) + 2;
			putText.append("2");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num3){
			inputNum = (10*inputNum) + 3;
			putText.append("3");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num4){
			inputNum = (10*inputNum) + 4;
			putText.append("4");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num5){
			inputNum = (10*inputNum) + 5;
			putText.append("5");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num6){
			inputNum = (10*inputNum) + 6;
			putText.append("6");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num7){
			inputNum = (10*inputNum) + 7;
			putText.append("7");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num8){
			inputNum = (10*inputNum) + 8;
			putText.append("8");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num9){
			inputNum = (10*inputNum) + 9;
			putText.append("9");
			output.setText(putText.toString());
		}

		if (ae.getSource() == num0){
			inputNum = (10*inputNum) + 0;
			putText.append("0");
			output.setText(putText.toString());
		}

		if (ae.getSource() == sym_divide){
			tempNumber = inputNum;
			inputNum = 0;
			actionToDo = 4;
			putText.setLength(0);
			output.setText(putText.toString());
		}

		if (ae.getSource() == sym_minus){
			tempNumber = inputNum;
			inputNum = 0;
			putText.setLength(0);
			actionToDo = 2;
			output.setText(putText.toString());
		}

		if (ae.getSource() == sym_multiply){
			tempNumber = inputNum;
			inputNum = 0;
			putText.setLength(0);
			actionToDo = 3;
			output.setText(putText.toString());
		}

		if (ae.getSource() == sym_plus){
			tempNumber = inputNum;
			inputNum = 0;
			putText.setLength(0);
			actionToDo = 1;
			output.setText(putText.toString());
		}

		if (ae.getSource() == sym_eq){
			if (actionToDo == 1){
				output.setText(String.valueOf(inputNum + tempNumber));
			}
			if (actionToDo == 2){
				output.setText(String.valueOf(tempNumber - inputNum));
			}
			if (actionToDo == 3){
				output.setText(String.valueOf(inputNum * tempNumber));
			}
			if (actionToDo == 4){
				output.setText(String.valueOf(tempNumber/inputNum));
			}
		}

		if (ae.getSource() == clear){
			tempNumber = 0;
			inputNum = 0;
			output.setText("");
		}

	}

  	public static void main(String[] args) {
		new Calc();
	}
}
