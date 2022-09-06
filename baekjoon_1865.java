// 웜홀 / baekjoon_1865.java
// https://www.acmicpc.net/problem/1865

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class Main {

	static int N, M, W;
	static int[] dist;
	static final int INF = 987654321;
	static ArrayList<Edge>[] edgeList;

	static class Edge{
		int next, cost;

		public Edge(int next, int cost) {

			this.next = next;
			this.cost = cost;
		}
	}

	public static void main(String[] args) throws IOException {

		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(br.readLine());

		while (TC != 0) {
			TC--;

			// input part
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());

			dist = new int[N + 1];
			edgeList = new ArrayList[N + 1];

			for(int i = 0 ; i <= N; i++) {
				edgeList[i] = new ArrayList<>();
			}


			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int S = Integer.parseInt(st.nextToken());
				int E = Integer.parseInt(st.nextToken());
				int T = Integer.parseInt(st.nextToken());
				// 양방향 그래프
				edgeList[S].add(new Edge(E,T));
				edgeList[E].add(new Edge(S,T));
			}

			for (int i = 0; i < W; i++) {
				st = new StringTokenizer(br.readLine());
				int S = Integer.parseInt(st.nextToken());
				int E = Integer.parseInt(st.nextToken());
				int T = Integer.parseInt(st.nextToken());

				edgeList[S].add(new Edge(E,-T));
			}

			boolean b = bellmanford();

			bw.write(b ? "YES\n" : "NO\n");

		}

		br.close();
		bw.close();
	}

	static boolean bellmanford() {

		for (int i = 1; i <= N; i++)
			dist[i] = INF;
		
		// 아무지점에서나 출발해도 찾을 수 있음
		dist[1] = 0;
		for (int i = 1; i < N; i++) {
            for(int j = 1; j < edgeList.length; j++) {
            	for(Edge e : edgeList[j]) {
            		if(dist[e.next] > dist[j] + e.cost) {
            			dist[e.next] = dist[j] + e.cost;
            		}
            	}
            }
        }

		for(int j = 1; j < edgeList.length; j++) {
        	for(Edge e : edgeList[j]) {
        		if(dist[e.next] > dist[j] + e.cost) {
        			return true;
        		}
        	}
        }

		return false;

	}
}
