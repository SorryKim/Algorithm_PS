import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, K;

    public static void main(String[] args) throws Exception {

        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        boolean[][] graph = new boolean[N + 1][M + 1];
        boolean[][] visited = new boolean[N + 1][M + 1];
        for (int i = 1; i <= N; i++) {
            Arrays.fill(graph[i], false);
            Arrays.fill(visited[i], false);
        }

        // 떨어진 음식 체크
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            graph[x][y] = true;
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (visited[i][j] || !graph[i][j])
                    continue;
                ans = Math.max(ans, BFS(i, j, graph, visited));
            }
        }

        System.out.println(ans);

    }

    // 음식물의 갯수 리턴
    public static int BFS(int x, int y, boolean[][] graph, boolean[][] visited) {
        int val = 0;
        int[] dx = { 1, -1, 0, 0 };
        int[] dy = { 0, 0, -1, 1 };

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { x, y });
        visited[x][y] = true;

        while (!q.isEmpty()) {
            int[] temp = q.poll();
            int nowX = temp[0];
            int nowY = temp[1];
            val++;

            for (int i = 0; i < 4; i++) {
                int nx = nowX + dx[i];
                int ny = nowY + dy[i];

                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                    if (!visited[nx][ny] && graph[nx][ny]) {
                        visited[nx][ny] = true;
                        q.add(new int[] { nx, ny });
                    }
                }
            }
        }

        return val;
    }

}
