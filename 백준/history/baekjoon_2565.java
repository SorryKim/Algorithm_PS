// 전깃줄 / baekjoon_2565.java
// https://www.acmicpc.net/problem/2565

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;


public class Main {

	static int[][] arr;
	static int[] dp;
	static int N;
	static int result;

	static void input() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N][2];

		for(int i = 0;  i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			arr[i][0] = start;
			arr[i][1] = end;
		}

		// 첫번째 인수 오름차순
		Arrays.sort(arr, new Comparator<int[]>() {
			@Override
			public int compare(int[] n1, int[] n2) {
				return n1[0] - n2[0];
			}
		});

		br.close();
	}
	
	// n번째에서 설치할 수 있는 전선의 개수를 구하는 메소드
	static int func(int n) {
		
		if(dp[n] == 0) {
			dp[n] = 1;
			for(int i = n + 1; i < N; i++) {
				// 전선을 설치할 수 있는 경우
				if(arr[n][1] < arr[i][1]) 
					dp[n] = Math.max(dp[n], func(i) + 1);
			}
		}
		
		return dp[n];
	}

	static void solve() {

		result = 0;
		dp = new int[N];
		for(int i = 0; i < N; i++)
			dp[i] = 0;

		for(int i = 0; i < N; i++) 
			result = Math.max(func(i), result);
		

		System.out.println(N - result);
	}

	public static void main(String[] args) throws Exception {
		input();
		solve();
	}

}
