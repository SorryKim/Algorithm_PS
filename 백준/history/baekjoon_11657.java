// 타임머신 / baekjoon_11657.java
// https://www.acmicpc.net/problem/11657

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static long[] dist; // underflow 발생 가능하므로 long타입
	static int[][] edge;
	static final long INF = 987654321;

	static void input() throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		dist = new long[N];
		for(int i = 0; i < N; i++)
			dist[i] = INF;

		edge = new int[M][3];

		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken());
			edge[i] = new int[] {a, b, c};
		}

		br.close();
	}


	static void solve() {

		dist[0] = 0;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				int a = edge[j][0];
				int b = edge[j][1];
				int c = edge[j][2]; // cost
				if(dist[a] != INF && dist[b] > (dist[a] + c))
					dist[b] = dist[a] + c;
			}
		}

		// 음의 사이클 확인
		for(int i = 0; i < M; i++) {
			int a = edge[i][0];
			int b = edge[i][1];
			int c = edge[i][2];

			if(dist[a] != INF && dist[b] > dist[a] + c) {
				System.out.println(-1);
				return;
			}
		}

		for(int i = 1; i < N; i++) {
			if(dist[i] == INF)
				System.out.println(-1);
			else
				System.out.println(dist[i]);
		}

	}



	public static void main(String[] args) throws Exception {
		input();
		solve();
	}

}
