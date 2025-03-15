import java.io.*;
import java.util.*;

public class Main {

    static int N, M, K;
    static Edge[] edges;
    static int[] parent;
    static int[] rank;
    static boolean[] hasPower;

    static class Edge implements Comparable<Edge> {
        public int u, v, w;

        public Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.w, other.w);
        }
    }

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        hasPower = new boolean[N + 1];
        parent = new int[N + 1];
        rank = new int[N + 1];
        edges = new Edge[M];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            int powerNode = Integer.parseInt(st.nextToken());
            hasPower[powerNode] = true;
        }

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            edges[i] = new Edge(u, v, w);
        }
    }

    static int Find(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = Find(parent[n]);
    }

    static void Union(int a, int b) {
        int rootA = Find(a);
        int rootB = Find(b);

        if (rootA == rootB)
            return;

        // 합친 후 컴포넌트에 발전소가 하나라도 있으면 true
        boolean flag = (hasPower[rootA] || hasPower[rootB]);

        
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
            hasPower[rootB] = flag;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
            hasPower[rootA] = flag;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
            hasPower[rootA] = flag;
        }
    }

    // 모든 도시가 발전소를 포함하는 컴포넌트에 속해있는지 확인
    static boolean isFinish() {
        for (int i = 1; i <= N; i++) {
            if (!hasPower[Find(i)])
                return false;
        }
        return true;
    }

    static int Solve() {
        int ans = 0;
        Arrays.sort(edges); // 간선을 비용 오름차순 정렬

        for (Edge edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            int rootU = Find(u);
            int rootV = Find(v);

            // 이미 같은 컴포넌트이면 넘어감
            if (rootU == rootV)
                continue;

            // 두 컴포넌트 모두 이미 발전소를 보유하고 있다면 연결하면 안 됨
            if (hasPower[rootU] && hasPower[rootV])
                continue;

            Union(u, v);
            ans += w;

            if (isFinish())
                return ans;
        }
        
        return ans;
    }

    public static void main(String[] args) throws Exception {
        Input();
        System.out.println(Solve());
    }
}
