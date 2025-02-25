import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int[] people;
    static List<Integer>[] graph, tree;
    static int[][] dp;

    static void Input() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        people = new int[N + 1];
        tree = new List[N + 1];
        graph = new List[N + 1];
        dp = new int[N + 1][2];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            people[i] = Integer.parseInt(st.nextToken());
            graph[i] = new LinkedList<>();
            tree[i] = new LinkedList<>();
            dp[i][0] = 0;
            dp[i][1] = 0;
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }

    }

    static void MakeTree(int node, int parent) {

        for (int child : graph[node]) {
            if (child == parent)
                continue;
            tree[node].add(child);
            MakeTree(child, node);
        }
    }

    static void DFS(int node) {

        dp[node][0] = 0;
        dp[node][1] = people[node];

        for (int child : tree[node]) {

            DFS(child);
            dp[node][0] += Math.max(dp[child][0], dp[child][1]);
            dp[node][1] += dp[child][0];
        }

    }

    public static void main(String[] args) throws Exception {

        Input();
        MakeTree(1, 0);
        DFS(1);
        System.out.println(Math.max(dp[1][0], dp[1][1]));
    }

}