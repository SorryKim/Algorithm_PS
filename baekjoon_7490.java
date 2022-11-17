// 0 만들기 / baekjoon_7490.java
// https://www.acmicpc.net/problem/7490

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {


	static int N;
	static int result = 0;
	static String[] arr;
	// 입력 받기
	static void Input() throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		br.close();

	}

	static int calc(String str) {

		str = str.replaceAll(" ", " ");

		String[] num = str.split("+|-");
		String[] operator = str.split("");
		return 1;
	}

	static void DFS(int depth) {

		String[] cmd = { "+", "-", " " };

		if(depth == N - 1) {
			String str = "1";
			for(int i = 0; i < N; i++) {
				str += arr[i] + Integer.toString( + 2);
			}

			return;
		}

		for(int i = 0; i < 3; i++) {
			arr[depth] = cmd[i];
			DFS(depth + 1);
		}
	}

	static void Solve() {

		arr = new String[N - 1];


	}


	public static void main(String[] args) throws Exception {

		/*
		int t;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine());

		for(int i = 0; i < t; i++) {
			N = Integer.parseInt(br.readLine());
			result = 0;
			Solve();
		}

		br.close();
		*/

		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str = "121+232-1+2 2-3";
		str.replaceAll("\\p{Z}", "");
		System.out.println(str);
		String[] num = str.split("\\+|-");
		String[] operator = str.split("[1-9]+");


		System.out.println(Arrays.toString(num));
		System.out.println(Arrays.toString(operator));
	}

}
