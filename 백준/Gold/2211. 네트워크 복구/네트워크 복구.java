import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static List<int[]>[] graph;
    static int[] parent;

    static void Input() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new LinkedList[N + 1];
        parent = new int[N + 1];

        for (int i = 0; i <= N; i++) {
            graph[i] = new LinkedList<>();
            parent[i] = -1;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new int[] { b, c });
            graph[b].add(new int[] { a, c });
        }

    }

    static void Dijkstra() {

        int[] dist = new int[N + 1];
        Arrays.fill(dist, 1000000000);
        Queue<int[]> q = new LinkedList<>();
        dist[1] = 0;
        parent[1] = 1;
        q.add(new int[] { 1, 0 });

        while (!q.isEmpty()) {
            int now = q.peek()[0];
            int val = q.peek()[1];
            q.poll();

            if (val > dist[now])
                continue;

            for (int[] temp : graph[now]) {
                int next = temp[0];
                int next_cost = temp[1] + val;

                // 교체할 때 경로처리를 해줘야할 듯...
                if (dist[next] > next_cost) {
                    dist[next] = next_cost;
                    q.add(new int[] { next, next_cost });
                    parent[next] = now;
                }
            }

        }

    }

    public static void main(String[] args) throws Exception {

        Input();
        System.out.println(N - 1);
        Dijkstra();
        for (int i = 2; i <= N; i++) {
            System.out.println(i + " " + parent[i]);
        }

    }
}
