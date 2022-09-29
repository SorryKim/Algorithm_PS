// 피보나치 수 6 / baekjoon_11444.java
// https://www.acmicpc.net/problem/11444

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static long N;
	final static long MOD = 1000000007;

	// 행렬 곱셈
	static long[][] multiply(long[][] m1, long[][] m2){

		long[][] result = new long[2][2];

		result[0][0] = (m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0]) % MOD;
		result[0][1] = (m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1]) % MOD;
		result[1][0] = (m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0]) % MOD;
		result[1][1] = (m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]) % MOD;

		return result;
	}

	static void Input() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Long.parseLong(br.readLine());

	}

	static void Solve() {

		long[][] matrix = {{1, 1}, {1, 0}};
		// 단위행렬로 시작
		long[][] I = { {1, 0}, {0, 1}};
		N--;

		while(N > 0) {

			if(N%2 == 1)
				I = multiply(I,matrix);

			matrix = multiply(matrix,matrix);
			N /= 2;
		}

		System.out.print(I[0][0]);
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();
	}

}
