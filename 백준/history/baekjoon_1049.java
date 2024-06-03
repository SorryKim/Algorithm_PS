// 기타줄 / baekjoon_1049.java
// https://www.acmicpc.net/problem/1049

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] pack, single;

	static void Input() throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		pack = new int[M];
		single = new int[M];

		for(int i = 0; i < M; i++) {
			int a,b;
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			pack[i] = a;
			single[i] = b;
		}
		br.close();

	}

	static void Solve() {

		Arrays.sort(pack);
		Arrays.sort(single);

		int sum1 = ((N/6) + 1)*pack[0];
		int sum2 = N * single[0];
		int sum3 = N/6 * pack[0] + N%6 * single[0];

		int result = Math.min(Math.min(sum1, sum2), sum3);

		System.out.println(result);

	}


	public static void main(String[] args) throws Exception{

		Input();
		Solve();

	}


}
