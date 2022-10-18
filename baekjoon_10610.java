// 30 / baekjoon_10610.java
// https://www.acmicpc.net/problem/10610

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static String s;
	static long sum = 0;

	static void Input() throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine();
		br.close();
	}

	public static void Solve() {

		int[] arr = new int[10];
		sum = 0;

		for (int i = 0; i < s.length(); i++) {
			int snum = s.charAt(i) - '0';
			arr[snum] += 1;
			sum += snum;
		}

		// 30의 배수가 안되는 경우
		if (sum % 3 != 0 || !s.contains("0")) {
			System.out.println(-1);
			return;
		}


		String result = "";
		for (int i = 9; i >= 0; i--) {

			while (arr[i] > 0) {
				result += Integer.toString(i);
				arr[i]--;
			}

		}

		System.out.println(result);
		return;
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();
	}

}
