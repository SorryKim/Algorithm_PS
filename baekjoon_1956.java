// 운동/ baekjoon_1956.java
// https://www.acmicpc.net/problem/1956

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int V, E;
	static int [][] graph;
	static final int INF = 999999999;

	static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		graph = new int[V + 1][V+ 1];

		for(int i = 0; i <= V; i++) {
			for(int j = 0; j <= V; j++)
				graph[i][j] = INF;
		}

		for(int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			graph[a][b] = c;
		}
		
		br.close();

	}


	static void Solve() {

		// 플로이드-워샬
		for(int i = 1; i <= V; i++) {
			for(int j = 1; j <= V; j++) {
				for(int k = 1; k <= V; k++) {

					if(i == j || j == k || k == i)
						continue;

					if(graph[j][k] > graph[j][i] + graph[i][k])
						graph[j][k] = graph[j][i] + graph[i][k];
				}
			}
		}
    
    // 사이클 검사
		for(int i = 1; i <= V; i++) {
			for(int j = 1; j <= V; j++) {
				if(i == j)
					continue;
				if(graph[i][i] > graph[i][j] + graph[j][i])
					graph[i][i] = graph[i][j] + graph[j][i];
			}
		}

		int result = INF;
		for(int i = 1; i <= V; i++) {
			if(graph[i][i] != INF)
				result = Math.min(result, graph[i][i]);
		}

		
		result = (result != INF ? result : -1);
		System.out.println(result);

	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();

	}
}
