// 행성 터널 / baekjoon_2887.java
// https://www.acmicpc.net/problem/2887

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

// 행성 클래스
class Planet {

	int index;
	int x, y, z;

	Planet(int x, int y, int z, int index) {
		this.x = x;
		this.y = y;
		this.z = z;
		this.index = index;
	}

}

// 다음 행성과 거리값을 가지는 간선
class Edge implements Comparable<Edge> {

	int cost, next;

	Edge(int cost, int next) {
		this.cost = cost;
		this.next = next;
	}

	// priority queue를 위한 비교연산자
	@Override
	public int compareTo(Edge edge) {

		if (this.cost > edge.cost)
			return 1;

		else if (this.cost < edge.cost)
			return -1;

		else
			return 0;

	}
}

public class Main {

	static int N;
	static long sum; // 결과 값
	static Planet[] planets; // 입력받은 행성배열
	static ArrayList<Edge>[] edges; // 간선 행렬
	static boolean[] visit;

	// 입력 받기
	static void Input() throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		planets = new Planet[N];
		edges = new ArrayList[N];
		visit = new boolean[N];
		sum = 0;

		for (int i = 0; i < N; i++) {
			edges[i] = new ArrayList<>();
			visit[i] = false;
		}

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a, b, c;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			planets[i] = new Planet(a, b, c, i);
		}

		br.close();

	}

	// 행성간의 거리를 구하는 메소드
	static int Calc(Planet p1, Planet p2) {

		int x = Math.abs(p1.x - p2.x);
		int y = Math.abs(p1.y - p2.y);
		int z = Math.abs(p1.z - p2.z);

		return Math.min(x, Math.min(y, z));
	}

	// 가능한 간선들을 생성
	// 기존 o(n^2) 방식으로 간선을 저장하면 메모리초과발생
	// x, y, z 좌표를 기준으로 작은것부터 N개씩만 사용 -> 총 3N개의 edge생성 가능
	static void MakeEdges() {

		// x기준
		Arrays.sort(planets, new Comparator<Planet>() {
			@Override
			public int compare(Planet p1, Planet p2) {
				return p1.x - p2.x;
			}
		});

		for (int i = 0; i < N - 1; i++) {
			Planet p1 = planets[i];
			Planet p2 = planets[i + 1];
			edges[p1.index].add(new Edge(Calc(p1, p2), p2.index));
			edges[p2.index].add(new Edge(Calc(p1, p2), p1.index));
		}

		// y기준
		Arrays.sort(planets, new Comparator<Planet>() {
			@Override
			public int compare(Planet p1, Planet p2) {
				return p1.y - p2.y;
			}
		});

		for (int i = 0; i < N - 1; i++) {
			Planet p1 = planets[i];
			Planet p2 = planets[i + 1];
			edges[p1.index].add(new Edge(Calc(p1, p2), p2.index));
			edges[p2.index].add(new Edge(Calc(p1, p2), p1.index));
		}
		// z기준
		Arrays.sort(planets, new Comparator<Planet>() {
			@Override
			public int compare(Planet p1, Planet p2) {
				return p1.z - p2.z;
			}
		});

		for (int i = 0; i < N - 1; i++) {
			Planet p1 = planets[i];
			Planet p2 = planets[i + 1];
			edges[p1.index].add(new Edge(Calc(p1, p2), p2.index));
			edges[p2.index].add(new Edge(Calc(p1, p2), p1.index));
		}

	}

	// 프림알고리즘을 사용해 최소 비용 구하기
	static void Prim() {
		Queue<Edge> pq = new PriorityQueue<>();

		pq.add(new Edge(0, 0));

		while (!pq.isEmpty()) {

			Edge edge = pq.poll();

			if (visit[edge.next])
				continue;

			sum += edge.cost;
			visit[edge.next] = true;

			for (Edge next : edges[edge.next]) {
				if (!visit[next.next])
					pq.add(next);
			}

		}
	}

	static void Solve() {

		MakeEdges();
		Prim();
		System.out.println(sum);

	}

	public static void main(String[] args) throws Exception {

		Input();
		Solve();

	}

}
