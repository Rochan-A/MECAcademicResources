//package ss;

class Student{

	int rollno, grade;
	String Name;
	static int dob = 14051999;
	//int dob = 100;

	Student(int r, int g, String N){
		rollno = r;
		grade = g;
		Name = N;
	}

	void print(){
		System.out.printf("Roll no: %d, Grade: %d, DOB: %d and Name: %s\n", rollno, grade, dob, Name);
	}

	void change_dob(){
		dob = 13051999;
	}

	public void Change_rollno(){
		rollno = rollno + 10;
	}

	protected void Change_grades(){
		grade = grade + 10;
	}

	private void Change_names(){
		Name = "Something Else";
	}

	public static void main(String[] args) {

		Student stu = new Student(10, 98, "Aditya");
		stu.print();
		stu.Change_grades();
		System.out.printf("Roll no: %d, Grade: %d, DOB: %d and Name: %s\n", stu.rollno, stu.grade, stu.dob, stu.Name);
	}

}