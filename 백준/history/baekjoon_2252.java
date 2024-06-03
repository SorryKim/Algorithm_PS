// 줄 세우기 / baekjoon_2252.java
// https://www.acmicpc.net/problem/2252

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static boolean visit[];
	static int[] degree;
	static ArrayList<ArrayList<Integer>> graph;
	static Queue<Integer> q;
	static Queue<Integer> result;
	
	public static void main(String[] args) throws Exception {

		Input();
		Solve();

	}

	static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		degree = new int[N + 1];
		graph = new ArrayList<>();

		for(int i = 0; i <= N; i++) {
			graph.add(new ArrayList<Integer>());
		}

		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			(graph.get(a)).add(b);
			degree[b] += 1;
		}
		
		br.close();

	}

	
	// 위상정렬
	static void Solve() throws IOException{
		
		q = new LinkedList<>();
		result = new LinkedList<>();
		
		for(int i = 1; i <= N; i++) {
			if(degree[i] == 0)
				q.add(i);
		}

		while(!q.isEmpty()) {
			
			int temp = q.poll();
			result.add(temp);

			for(int i : graph.get(temp)) {
				degree[i] -= 1;

				if(degree[i] == 0)
					q.add(i);
			}
		}

		// print
		StringBuilder sb = new StringBuilder();
		while(!result.isEmpty())
			sb.append(result.poll() + " ");
		System.out.println(sb.toString());
		
	}

}
