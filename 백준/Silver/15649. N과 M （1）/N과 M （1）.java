import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int N, M;

    static void DFS(int depth, int[] arr, boolean[] visited) {

        if (depth == M) {
            for (int i = 0; i < M; i++)
                System.out.print(arr[i] + " ");
            System.out.println();
        }

        for (int i = 1; i <= N; i++) {

            if (visited[i])
                continue;

            visited[i] = true;
            arr[depth] = i;
            DFS(depth + 1, arr, visited);
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {

        // Input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[] arr = new int[9];
        boolean[] visited = new boolean[10];
        DFS(0, arr, visited);
    }
}
