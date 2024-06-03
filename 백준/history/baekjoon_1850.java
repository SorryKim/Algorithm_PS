// 최대공약수 / baekjoon_1850.java
// https://www.acmicpc.net/problem/1850

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static long a,b;

	public static void main(String[] args) throws Exception {

		Input();
		Solve();

	}

	static void Solve() throws IOException{

		long temp = GCD(Math.max(a, b), Math.min(a, b));
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < temp; i++)
			sb.append("1");
		// Stringbuilder를 사용하지 않으면 시간초과 발생함
		/*
		String s ="";
		for(int i = 1; i <= temp; i++) {
			s += "1";
		}
		System.out.println(s);
		*/
		System.out.println(sb.toString());
	}

	static void Input() throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		a = Long.parseLong(st.nextToken());
		b = Long.parseLong(st.nextToken());
	}

	static long GCD(long a, long b) {

		while(b > 0) {
			long l = a;
			a = b;
			b = l % b;
		}

		return a;
	}



}
