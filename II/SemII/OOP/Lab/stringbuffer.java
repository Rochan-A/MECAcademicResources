import java.util.StringTokenizer;

class string{

	public static void main(String args[]){

		StringBuffer sb = new StringBuffer("Hello");
		System.out.println(sb);

		StringTokenizer st = new StringTokenizer("Hello, My name is Rochan", " ");
		System.out.println(st.countTokens());

	}
}