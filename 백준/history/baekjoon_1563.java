// 개근상/ baekjoon_1563.java
// https://www.acmicpc.net/problem/1563

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int N;


	static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());


	}

	static void Solve() {
		int[][][] dp;
		dp = new int[N + 1][2][3]; // 총 출석일 수, 지각 횟수, 연속 결석 횟수

		dp[1][0][0] = 1;
		dp[1][0][1] = 1;
		dp[1][1][0] = 1;

		for(int i = 2; i <= N; i++) {

			// 지각x, 결석x
			dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2];

			// 지각x, 연속 결석 1
			dp[i][0][1] = dp[i - 1][0][0];

			// 지각x ,연속 결석 2
			dp[i][0][2] = dp[i - 1][0][1];

			// 지각 1, 연속 결석 x
			dp[i][1][0] = dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2];

			// 지각 1, 연속 결석 1
			dp[i][1][1] = dp[i - 1][1][0];

			// 지각 1, 연속 결석 2
			dp[i][1][2] = dp[i - 1][1][1];
			
			
			// MOD 연산
			for(int j = 0; j < 2; j++) {
				for(int k = 0; k < 3; k++) {
					dp[i][j][k] %= 1000000;
				}
			}

		}


		int result = 0;
		
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				result += dp[N][i][j];
			}
		}

		result %= 1000000;

		System.out.println(result);
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();

	}
}
