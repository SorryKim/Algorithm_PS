import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] graph;
    static int[] dx = { 1, -1, 0, 0 };
    static int[] dy = { 0, 0, 1, -1 };
    static final int INF = Integer.MAX_VALUE;

    public static class Node implements Comparable<Node> {
        int x, y, cost;

        Node(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.cost, other.cost);
        }
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static int solve() {

        int[][] dist = new int[N][M];
        for (int i = 0; i < N; i++) {
            Arrays.fill(dist[i], INF);
        }

        PriorityQueue<Node> pq = new PriorityQueue<>();
        dist[0][0] = graph[0][0];
        if(dist[0][0] == -1) return -1;
        pq.add(new Node(0, 0, graph[0][0]));

       

        while (!pq.isEmpty()) {
            Node node = pq.poll();

            int x = node.x;
            int y = node.y;
            int cost = node.cost;

            if(cost > dist[x][y]) continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                int road = graph[nx][ny];
                if(road == -1) continue;
                int nextCost = cost + road;

                if (dist[nx][ny] > nextCost) {
                    dist[nx][ny] = nextCost;
                    pq.add(new Node(nx, ny, nextCost));
                }
            }
        }

        return dist[N - 1][M - 1] == INF ? -1 : dist[N - 1][M - 1];
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }
}