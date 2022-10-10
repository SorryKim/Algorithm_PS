// 1학년 / baekjoon_5557.java
// https://www.acmicpc.net/problem/5557

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] arr;
	static long[][] DP;

	static void Input() throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new int[N + 1];

		for(int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		br.close();

	}

	static void Solve() {

		DP = new long[N][21];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j <= 20; j++)
				DP[i][j] = 0;
		}

		DP[0][arr[0]] = 1;

		for(int i = 1; i < N; i++) {
			for(int j = 0; j <= 20; j++) {

				if(DP[i-1][j] != 0) {

					// 더하는 경우
					if(j + arr[i] <= 20 && j + arr[i] >= 0)
						DP[i][j + arr[i]] += DP[i-1][j];
					// 빼는 경우
					if(j - arr[i] <= 20 && j - arr[i] >= 0)
						DP[i][j - arr[i]] += DP[i-1][j];

				}
			}
		}

		// 결과 출력
		System.out.println(DP[N-2][arr[N-1]]);

	}


	public static void main(String[] args) throws Exception{

		Input();
		Solve();

	}


}
