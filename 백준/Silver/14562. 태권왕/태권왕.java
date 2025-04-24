import java.io.*;
import java.util.*;

public class Main {


    public static int bfs(int startS, int startT) {

        Queue<int[]> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        q.offer(new int[]{startS, startT, 0});
        visited.add(startS + "," + startT);

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int s = cur[0];
            int t = cur[1];
            int cnt = cur[2];

            if (s == t) return cnt;

            // 연산 A: s += s, t += 3
            if (s < t) {
                int newS = s + s;
                int newT = t + 3;
                String key = newS + "," + newT;
                if (!visited.contains(key) && newS <= newT) {
                    visited.add(key);
                    q.offer(new int[]{newS, newT, cnt + 1});
                }
            }

            // 연산 B: s += 1
            if (s < t) {
                int newS = s + 1;
                String key = newS + "," + t;
                if (!visited.contains(key)) {
                    visited.add(key);
                    q.offer(new int[]{newS, t, cnt + 1});
                }
            }
        }

        return -1; 
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int C = Integer.parseInt(br.readLine());

        for (int i = 0; i < C; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken());
            int T = Integer.parseInt(st.nextToken());
            System.out.println(bfs(S, T));
        }
    }
}
