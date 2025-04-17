import java.io.*;
import java.util.*;

public class Main {
    static char[][] graph = new char[12][6];
    static final int[] dx = { -1, 1, 0, 0 }, dy = { 0, 0, -1, 1 };

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 12; i++) {
            String s = br.readLine();
            for (int j = 0; j < 6; j++) {
                graph[i][j] = s.charAt(j);
            }
        }
    }

    static int solve() {
        int cnt = 0;

        while (true) {
            boolean flag = popOnce();
            if (!flag)
                break;
            move();
            cnt++;
        }

        return cnt;
    }

    static boolean popOnce() {
        boolean[][] visited = new boolean[12][6];
        boolean flag = false;
        List<int[]> list = new ArrayList<>();

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {

                if (!visited[i][j] && graph[i][j] != '.') {
                    List<int[]> group = BFS(i, j, visited);
                    if (group.size() >= 4) {
                        flag = true;
                        list.addAll(group);
                    }
                }
            }
        }

        // 실제 제거
        for (int[] p : list) {
            graph[p[0]][p[1]] = '.';
        }

        return flag;
    }

    static List<int[]> BFS(int x, int y, boolean[][] visited) {
        char color = graph[x][y];
        Queue<int[]> q = new ArrayDeque<>();
        List<int[]> group = new ArrayList<>();

        visited[x][y] = true;
        q.offer(new int[] { x, y });
        group.add(new int[] { x, y });

        while (!q.isEmpty()) {
            int[] now = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];

                if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
                    continue;

                if (!visited[nx][ny] && graph[nx][ny] == color) {
                    visited[nx][ny] = true;
                    q.offer(new int[] { nx, ny });
                    group.add(new int[] { nx, ny });
                }
            }
        }

        return group;
    }

    // 중력 적용, 각 열마다 아래부터 빈칸을 채움
    static void move() {
        for (int i = 0; i < 6; i++) {
            int row = 11; // 뿌요를 쓸 위치(바닥부터)

            for (int j = 11; j >= 0; j--) {
                if (graph[j][i] != '.') {
                    graph[row][i] = graph[j][i];
                    if (row != j)
                        graph[j][i] = '.';
                    row--;
                }
            }

            // 위쪽 남은 칸은 모두 '.'
            for (int j = row; j >= 0; j--) {
                graph[j][i] = '.';
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }
}
