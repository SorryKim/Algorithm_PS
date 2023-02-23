// 파이프 옮기기 2 / baekjoon_17069.java
// https://www.acmicpc.net/problem/17069

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] arr;
	static long[][][] dp;

	static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		arr = new int[N + 1][N + 1];
		dp = new long[N + 1][N + 1][3];
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}


	}



	static void Solve() {

		dp[0][1][0] = 1;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
					
				// 진행 불가
				if((i == 0 && j == 0) || arr[i][j] == 1)
					continue;
				
				// 가로
				if(arr[i + 1][j] == 0)
					dp[i + 1][j][1] = dp[i][j][2] + dp[i][j][1];
				
				// 세로
				if(arr[i][j + 1] == 0)
					dp[i][j + 1][0] = dp[i][j][2] + dp[i][j][0];
				
				// 대각 아래
				if(i + 1 < N && j + 1 < N) {
					if(arr[i + 1][j] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j + 1] == 0)
						dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
				}

			}
		}
		
		long result = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];

		System.out.println(result);

	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();

	}
}
