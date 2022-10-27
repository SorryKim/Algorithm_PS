// 도시 분할 계획/ baekjoon_1647.java
// https://www.acmicpc.net/problem/1647

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{

	int destination, cost;
	Node(){}
	Node(int a, int b){
		destination = a;
		cost = b;
	}

	// 우선순위 큐를 사용하기 위한 비교
	@Override
	public int compareTo(Node node) {

		if(this.cost > node.cost)
			return 1;

		else if(this.cost < node.cost)
			return -1;

		else
			return 0;
	}
}


public class Main {

	static int N, M, sum, max;
	static LinkedList<Node>[] Graph;
	static boolean[] visited;

	public static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		sum = 0;
		max = 0;

		Graph = new LinkedList[N + 1];
		visited = new boolean[N + 1];

		for(int i = 1; i <= N; i++)
			Graph[i] = new LinkedList<>();

		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			Graph[a].add(new Node(b,c));
			Graph[b].add(new Node(a,c));
		}

		br.close();

	}

	static void Prim() {

		Queue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(1,0));

		while(!pq.isEmpty()) {

			Node node = pq.poll();

			if(visited[node.destination])
				continue;

			if(node.cost > max)
				max = node.cost;

			sum += node.cost;
			visited[node.destination] = true;

			for(Node next : Graph[node.destination]) {
				if(!visited[next.destination])
					pq.add(next);
			}
		}
	}

	static void Solve() {
		Prim();
		// 가장 값이 높은 길을 하나 빼줌
		sum -= max;
		System.out.println(sum);
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();
	}

}
