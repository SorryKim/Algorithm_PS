// A와 B / baekjoon_12904.java
//https://www.acmicpc.net/problem/12904

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static String S,T;

	static void Input() throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		S = br.readLine();
		T = br.readLine();
		br.close();

	}

	static boolean func(String s1, String s2) {

		StringBuffer s = new StringBuffer(s1);
		StringBuffer t = new StringBuffer(s2);

		while(s.length() < t.length()) {

			if(t.charAt(t.length() - 1) == 'A'){
				t.deleteCharAt(t.length() - 1);
			}

			else if(t.charAt(t.length() - 1) == 'B') {
				t.deleteCharAt(t.length() - 1);
				t.reverse();
			}
		}

		String result1 = s.toString();
		String result2 = t.toString();
		if(result1.equals(result2))
			return true;
		else
			return false;
	}
	static void Solve() {

		if(func(S,T))
			System.out.println(1);
		else
			System.out.println(0);

	}


	public static void main(String[] args) throws Exception{

		Input();
		Solve();

	}


}
