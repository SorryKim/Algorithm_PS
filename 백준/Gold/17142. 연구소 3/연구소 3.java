import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[][] graph;
    static List<int[]> virusList;
    static int answer = Integer.MAX_VALUE;
    static int emptyCount;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new int[N][N];
        virusList = new ArrayList<>();
        emptyCount = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
                if (graph[i][j] == 2) {
                    virusList.add(new int[] { i, j });
                } else if (graph[i][j] == 0) {
                    emptyCount++;
                }
            }
        }
    }

    static int BFS(int[][] viruses) {
        int[][] copiedGraph = new int[N][N];
        
        for (int i = 0; i < N; i++) {
            copiedGraph[i] = graph[i].clone();
        }

        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[N][N];
        int filled = 0; // 감염시킨 빈 칸의 수
        int maxTime = 0;
        int[] dx = { -1, 1, 0, 0 };
        int[] dy = { 0, 0, -1, 1 };

    
        for (int[] virus : viruses) {
            q.add(new int[] { virus[0], virus[1], 0 });
            visited[virus[0]][virus[1]] = true;
            copiedGraph[virus[0]][virus[1]] = 0; // 활성 바이러스 위치는 0으로 설정
        }

        // 빈 칸이 없으면 즉시
        if (emptyCount == 0)
            return 0;

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0];
            int y = curr[1];
            int time = curr[2];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if (visited[nx][ny] || copiedGraph[nx][ny] == 1)
                    continue;

                visited[nx][ny] = true;

                // 빈 칸을 감염시키는 경우
                if (copiedGraph[nx][ny] == 0) {
                    filled++;
                    maxTime = Math.max(maxTime, time + 1);
                }

                // 비활성 바이러스도 확산 대상임 감염 처리 후 큐에 추가
                copiedGraph[nx][ny] = time + 1;
                q.add(new int[] { nx, ny, time + 1 });
            }
        }
        
        return (filled == emptyCount) ? maxTime : Integer.MAX_VALUE;
    }

    static void Select(int idx, int depth, int[][] arr) {
        if (depth == M) {
            answer = Math.min(answer, BFS(arr));
            return;
        }
        for (int i = idx; i < virusList.size(); i++) {
            arr[depth] = virusList.get(i);
            Select(i + 1, depth + 1, arr);
        }
    }

    static void Solve() {
        if (emptyCount == 0) {
            answer = 0;
            return;
        }
        Select(0, 0, new int[M][2]);
    }

    public static void main(String[] args) throws Exception {
        Input();
        Solve();
        System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
    }
}
