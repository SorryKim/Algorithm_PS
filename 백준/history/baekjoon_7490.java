// 0 만들기 / baekjoon_7490.java
// https://www.acmicpc.net/problem/7490

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

	static int N;
	static char[] arr;
	static ArrayList<String> result;

	// 연산자 배열을 int값으로 반환하는 메소드
	static int calc(char[] arr) {

		int sum = 0;

		for (int i = N; i > 1; i--) {

			int num = i;
			// +인 경우
			if (arr[i - 1] == '+')
				sum += num;
			// -인 경우
			else if (arr[i - 1] == '-')
				sum -= num;
			// 공백인 경우
			else {
				
				int result = i;
				int cnt = 1;
				while (arr[i - 1] == ' ') {
					i--;
					result += i * (int) Math.pow(10, cnt++);
				}
				if (i - 1 >= 1 && arr[i - 1] == '-') {
					sum -= result;
				} 
				else {
					sum += result;
				}
			}
		}
		
		if (arr[1] != ' ') {
			sum += 1;
		}

		return sum;
	}

	static void DFS(int depth) {

		if (depth == N) {
			if (calc(arr) == 0) {
				String str = "1";
				for(int i = 1; i < N; i++) {
					str += arr[i];
					str += Integer.toString(i + 1);
				}
				result.add(str);
			}
			return;
		}
		
		char[] op = { ' ', '+', '-' };
		for (int i = 0; i < 3; i++) {
			arr[depth] = op[i];
			DFS(depth + 1);
		}
	}

	static void Solve() {

		arr = new char[N];
		result = new ArrayList<>();
		DFS(1);
		for (int i = 0; i < result.size(); i++) {
			System.out.println(result.get(i));
		}
	}

	public static void main(String[] args) throws Exception {
		int t;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine());

		for (int i = 0; i < t; i++) {
			N = Integer.parseInt(br.readLine());
			Solve();
			System.out.println();
		}
		br.close();
	}
}