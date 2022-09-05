// 웜홀 / baekjoon_1865.java
// https://www.acmicpc.net/problem/1865

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M, W;
	static int[] dist;
	static final int INF = 987654321;
	static int[][] edge;

	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(br.readLine());

		while(TC != 0) {
			TC--;

			// input part
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());

			dist = new int[N];
			edge = new int[N][N];

			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++)
					edge[i][j] = INF;
			}

			for(int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int S = Integer.parseInt(st.nextToken()) - 1;
				int E = Integer.parseInt(st.nextToken()) - 1;
				int T = Integer.parseInt(st.nextToken());
				edge[S][E] = T;
				edge[E][S] = T;
			}

			for(int i = 0; i < W; i++) {
				st = new StringTokenizer(br.readLine());
				int S = Integer.parseInt(st.nextToken()) - 1;
				int E = Integer.parseInt(st.nextToken()) - 1;
				int T = Integer.parseInt(st.nextToken()) * (-1);
				if(edge[S][E] > T)
					edge[S][E] = T;
			}

			boolean b = false;
			for(int i = 0; i < N; i++) {
				b = bellmanford(i);
				if(b) {
					System.out.println("YES");
					break;
				}
			}
			if(!b)
				System.out.println("NO");

		}

	}

	static boolean bellmanford(int n) {

		for(int i = 0 ; i < N; i++)
			dist[i] = INF;

		dist[n] = 0;

		boolean b = false;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(edge[i][j] == INF)
					continue;
				if(dist[i] != INF && dist[j] > dist[i] + edge[i][j])
					dist[j] = dist[i] + edge[i][j];
			}
		}


		if(dist[n] < 0)
			return true;
		else
			return false;
	}
}
