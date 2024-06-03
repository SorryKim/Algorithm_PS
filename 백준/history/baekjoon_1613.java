// 역사 / baekjoon_1613.java
// https://www.acmicpc.net/problem/1613

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, k, num;
	static boolean[][] arr;
	static BufferedReader br;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {

		Input();
		Solve();

	}

	static void Input() throws IOException{

		br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new boolean[n + 1][n + 1];

		for(int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			arr[x][y] = true;
		}

		num = Integer.parseInt(br.readLine());



	}

	static void Solve() throws IOException{

		// 플로이드-워샬 알고리즘
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 1; k <= n; k++) {
					if(arr[j][i] && arr[i][k]) {
						arr[j][k] = true;
					}
				}
			}
		}

		for(int i = 0; i < num; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());

			if(x < 1 || x > n || y < 1 || y > n) {
				System.out.println(0);
			}
			else {

				if(arr[y][x]) {
					System.out.println(1);
				}
				else {
					if(arr[x][y])
						System.out.println(-1);
					else
						System.out.println(0);
				}
			}
		}


	}

}
