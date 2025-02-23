import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] graph;
    static boolean[][] visited;
    static int[] dx = {1, -1, 0, 0, 1, -1, 1, -1};
    static int[] dy = {0, 0, 1, -1, 1, -1, -1, 1}; 

    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new int[N + 1][M + 1];
        visited = new boolean[N + 1][M + 1];
        int peakCount = 0;

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!visited[i][j]) {
                    if (bfs(i, j)) {
                        peakCount++;
                    }
                }
            }
        }
        
        System.out.println(peakCount);
    }   

    static boolean bfs(int startX, int startY) {
        Queue<Pair> q = new LinkedList<>();
        List<Pair> region = new ArrayList<>();
        q.add(new Pair(startX, startY));
        visited[startX][startY] = true;
        int height = graph[startX][startY];
        boolean isPeak = true;  

        while (!q.isEmpty()) {
            Pair temp = q.poll();
            int now_x = temp.x;
            int now_y = temp.y;
            region.add(temp);

            for (int d = 0; d < 8; d++) {
                int nx = now_x + dx[d];
                int ny = now_y + dy[d];

                if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;

                if (graph[nx][ny] > height) isPeak = false;
                

                if (!visited[nx][ny] && graph[nx][ny] == height) {
                    visited[nx][ny] = true;
                    q.add(new Pair(nx, ny));
                }
            }
        }
        return isPeak;
    }

    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
