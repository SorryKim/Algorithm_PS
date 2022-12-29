// 네트워크 연결 / baekjoon_1922.java
// https://www.acmicpc.net/problem/1922

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static class Edge implements Comparable<Edge>{

		int start, end, cost;

		public Edge(int start, int end, int cost) {
			this.start = start;
			this.end = end;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge e) {
			return (e.cost >= this.cost) ? -1 : 1;
		}

	}

	static int N,M,result;
	static PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
	static int[] parent;

	static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        result = 0;
        parent = new int[N + 1];

        for(int i = 0; i <= N; i++)
        	parent[i] = i;

        for(int i = 0; i < M; i++) {
        	int a,b,c;
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	a = Integer.parseInt(st.nextToken());
        	b = Integer.parseInt(st.nextToken());
        	c = Integer.parseInt(st.nextToken());
        	pq.add(new Edge(a,b,c));
        }

	}


	// 해당 지점 부모 찾기
	static int Find(int n) {

		if(parent[n] == n)
			return n;

		return parent[n] = Find(parent[n]);
	}

	// UNION 작업
	static void union(int n1, int n2) {

		int p1 = Find(n1);
		int p2 = Find(n2);

		if(p1 <= p2)
			parent[p2] = p1;
		else
			parent[p1] = p2;

	}

	static void Solve() {

		while(!pq.isEmpty()) {

			Edge now = pq.poll();
			if(Find(now.start) != Find(now.end)) {
				union(now.start, now.end);
				result += now.cost;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();
		System.out.println(result);

	}
}
