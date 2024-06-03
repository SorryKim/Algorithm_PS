// 가장 큰 정사각형 / baekjoon_1915.java
// https://www.acmicpc.net/problem/1915

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[][] arr, DP;

	public static void main(String[] args) throws Exception {

		Input();
		Solve();

	}

	static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		arr = new int[N][M];
		DP = new int[N][M];

		for(int i = 0; i < N; i++) {
			String s = br.readLine();
			for(int j = 0; j < M; j++) {
				arr[i][j] = s.charAt(j) - '0';
				DP[i][j] = arr[i][j];
			}
		}
	}

	static void Solve() throws IOException{

		int result = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {

				if(i >= 1 && j >= 1) {
					int a = DP[i - 1][j - 1];
					int b = DP[i][j - 1];
					int c = DP[i - 1][j];
					int d = DP[i][j];
					
					if(d == 1) {
						DP[i][j] = Math.min(a, Math.min(b, c)) + 1;
					}
				}

				result = Math.max(result, DP[i][j]);
			}
		}

		System.out.println(result * result);
	}

}
