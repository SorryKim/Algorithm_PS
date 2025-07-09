import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, K;
    public static int[][] graph;
    public static int[] dx = { 1, -1, 0, 0 };
    public static int[] dy = { 0, 0, 1, -1 };

    public static class Node implements Comparable<Node> {
        int x, y, value;

        public Node(int x, int y, int value) {
            this.x = x;
            this.y = y;
            this.value = value;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(other.value, this.value);
        }
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new int[N + 1][M + 1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        K = Integer.parseInt(br.readLine());

    }

    public static List<int[]> solve() {
        List<int[]> pass = new ArrayList<>();
        PriorityQueue<Node> pq = new PriorityQueue<>();
        boolean[][] visited = new boolean[N + 1][M + 1];

        // 초기 테두리 넣기
        for (int i = 1; i <= M; i++) {
            // 위쪽 (1, i)
            if (!visited[1][i]) {
                visited[1][i] = true;
                pq.add(new Node(1, i, graph[1][i]));
            }
            // 아래쪽 (N, i)
            if (!visited[N][i]) {
                visited[N][i] = true;
                pq.add(new Node(N, i, graph[N][i]));
            }
        }

        for (int i = 1; i <= N; i++) {
            // 왼쪽 (i, 1)
            if (!visited[i][1]) {
                visited[i][1] = true;
                pq.add(new Node(i, 1, graph[i][1]));
            }
            // 오른쪽 (i, M)
            if (!visited[i][M]) {
                visited[i][M] = true;
                pq.add(new Node(i, M, graph[i][M]));
            }
        }

        while (pass.size() != K) {

            Node node = pq.poll();
            pass.add(new int[] { node.x, node.y });

            for (int i = 0; i < 4; i++) {
                int nx = node.x + dx[i];
                int ny = node.y + dy[i];

                if (nx < 1 || nx > N || ny < 1 || ny > M)
                    continue;
                if (visited[nx][ny])
                    continue;

                visited[nx][ny] = true;
                pq.add(new Node(nx, ny, graph[nx][ny]));
            }

        }

        return pass;
    }

    public static void main(String[] args) throws IOException {
        input();
        List<int[]> ans = solve();
        StringBuilder sb = new StringBuilder("");
        for (int[] tmp : ans) {
            sb.append(tmp[0] + " " + tmp[1] + "\n");
        }
        System.out.print(sb.toString());
    }

}
