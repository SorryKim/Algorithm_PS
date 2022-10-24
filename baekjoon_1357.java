// 뒤집힌 덧셈 / baekjoon_1357.java
// https://www.acmicpc.net/problem/1357

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {


	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		String s1 = st.nextToken();
		String s2 = st.nextToken();

		System.out.println(Integer.parseInt(func(s1,s2)));
	}

	public static String func(String s1, String s2) {
		StringBuffer sb1 = new StringBuffer(s1);
		StringBuffer sb2 = new StringBuffer(s2);
		sb1.reverse();
		sb2.reverse();

		int i1 = Integer.parseInt(sb1.toString());
		int i2 = Integer.parseInt(sb2.toString());

		String result = Integer.toString(i1+i2);
		sb1 = new StringBuffer(result);

		return sb1.reverse().toString();

	}

}
