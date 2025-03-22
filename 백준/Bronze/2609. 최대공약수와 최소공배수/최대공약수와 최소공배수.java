import java.io.*;
import java.util.*;

public class Main {

	static int GCD(int a, int b){

		if(b == 0) return a;
		else return GCD(b, a % b);
	}
    public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		if(b > a){
			int temp = a;
			a = b;
			b = temp;
		}

		int gcd = GCD(a,b);
		int lcm = a * b / gcd;

		System.out.println(gcd);
		System.out.println(lcm);
	}
		
}