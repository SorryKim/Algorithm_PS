import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] team;
    static List<Integer>[] graph;
    static boolean[] visited;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        team = new int[N + 1];
        graph = new ArrayList[N + 1];
        visited = new boolean[N + 1];

        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
            visited[i] = false;
        }

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int cnt = Integer.parseInt(st.nextToken());

            for (int j = 0; j < cnt; j++) {
                int hate = Integer.parseInt(st.nextToken());
                graph[i].add(hate);
                graph[hate].add(i);
            }
        }

    }

    static void dfs(int node, boolean flag) {

        if (flag)
            team[node] = 1;
        else
            team[node] = 2;

        for (int next : graph[node]) {
            if (visited[next])
                continue;
            visited[next] = true;
            dfs(next, !flag);
        }
    }

    static List<Integer>[] solve() {

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i, true);
            }
        }

        List<Integer> blue = new ArrayList<>();
        List<Integer> white = new ArrayList<>();

        for (int i = 1; i <= N; i++) {
            if (team[i] == 1)
                blue.add(i);
            else
                white.add(i);
        }

        return new List[] { blue, white };
    }

    public static void main(String[] args) throws IOException {
        input();
        List<Integer>[] result = solve();

        for (List<Integer> temp : result) {

            System.out.println(temp.size());
            for (Integer n : temp) {
                System.out.print(n + " ");
            }
            System.out.println();
        }
    }

}
