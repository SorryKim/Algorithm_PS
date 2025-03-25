import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static Edge[] edges;
    static int[] parent, rank;

    static class Edge implements Comparable<Edge> {
        int u, v;
        boolean isDown;

        @Override
        public int compareTo(Edge other) {
            if (this.isDown == other.isDown)
                return 0;
            return this.isDown ? 1 : -1;
        }

        public Edge(int a, int b, int c) {
            this.u = a;
            this.v = b;
            if (c == 1)
                this.isDown = true;
            else
                this.isDown = false;
        }

    }

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        edges = new Edge[M + 1];
        parent = new int[N + 1];
        rank = new int[N + 1];

        for (int i = 0; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            edges[i] = new Edge(a, b, c);
        }

    }

    static int Find(int node) {
        if (parent[node] == node)
            return node;
        else
            return parent[node] = Find(parent[node]);
    }

    static void Union(int a, int b) {
        int parentA = Find(a);
        int parentB = Find(b);

        if (parentA == parentB)
            return;

        if (rank[parentA] > rank[parentB]) {
            parent[parentA] = parentB;
        } else if (rank[parentA] < rank[parentB]) {
            parent[parentB] = parentA;
        } else {
            rank[parentA]++;
            parent[parentB] = parentA;
        }
    }

    // 최대 피로도 계산
    static int MaxValue() {
        int result = 0;
        int cntUp = 0;
        int cntDown = 0;
        int size = 0;

        for (int i = 0; i <= N; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for (Edge edge : edges)
            pq.add(edge);

        while (size < N) {
            Edge edge = pq.poll();

            int u = edge.u;
            int v = edge.v;
            boolean isDown = edge.isDown;

            if (Find(u) == Find(v))
                continue;
            else
                Union(u, v);

            size++;
            if (isDown)
                cntDown++;
            else
                cntUp++;
        }

        result = cntUp * cntUp;

        return result;
    }

    // 최소 피로도 계산
    static int MinValue() {
        int result = 0;
        int cntUp = 0;
        int cntDown = 0;
        int size = 0;

        for (int i = 0; i <= N; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (Edge edge : edges)
            pq.add(edge);

        while (size < N) {
            Edge edge = pq.poll();

            int u = edge.u;
            int v = edge.v;
            boolean isDown = edge.isDown;

            if (Find(u) == Find(v))
                continue;
            else
                Union(u, v);

            size++;
            if (isDown)
                cntDown++;
            else
                cntUp++;
        }

        result = cntUp * cntUp;

        return result;
    }

    static int Solve() {
        int ans = MaxValue() - MinValue();
        return ans;
    }

    public static void main(String[] args) throws Exception {
        Input();
        System.out.println(Solve());
    }
}
