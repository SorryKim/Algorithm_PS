import java.io.*;
import java.util.*;

public class Main {

    static class Edge {
        int x, y, cnt;

        public Edge(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) throws IOException {

        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] dirX = { 1, -1, 0, 0 };
        int[] dirY = { 0, 0, 1, -1 };
        boolean[][] graph = new boolean[N][N];

        // graph 생성
        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            for (int j = 0; j < N; j++) {
                graph[i][j] = s.charAt(j) == '1';
            }
        }

        // 최소 변경 횟수 기록 배열
        int[][] minChanges = new int[N][N];
        for (int i = 0; i < N; i++)
            Arrays.fill(minChanges[i], Integer.MAX_VALUE);

        // Priority Queue 초기화
        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.cnt - b.cnt);
        pq.add(new Edge(0, 0, 0));
        minChanges[0][0] = 0;

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int nowX = edge.x;
            int nowY = edge.y;
            int cnt = edge.cnt;

            // 도착한 경우
            if (nowX == N - 1 && nowY == N - 1) {
                System.out.println(cnt);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = nowX + dirX[i];
                int ny = nowY + dirY[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    int temp = cnt + (graph[nx][ny] ? 0 : 1);

                    // 더 적은 변경 횟수로 도달한 경우에만 업데이트
                    if (temp < minChanges[nx][ny]) {
                        minChanges[nx][ny] = temp;
                        pq.add(new Edge(nx, ny, temp));
                    }
                }
            }
        }
    }
}
