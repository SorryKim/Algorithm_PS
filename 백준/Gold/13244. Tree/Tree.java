import java.io.*;
import java.util.*;

public class Main {

    static int Find(int n, int[] parent) {
        if (n == parent[n])
            return n;
        return parent[n] = Find(parent[n], parent);
    }

    static void Union(int a, int b, int[] parent, int[] rank) {

        int parentA = Find(a, parent);
        int parentB = Find(b, parent);
        if (parentA == parentB)
            return;

        if (rank[parentA] > rank[parentB]) {
            parent[parentB] = parentA;
        } else if (rank[parentA] < rank[parentB]) {
            parent[parentA] = parentB;
        } else {
            parent[parentB] = parentA;
            rank[parentA]++;
        }

    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int test = 0; test < T; test++) {

            int N = Integer.parseInt(br.readLine());
            int M = Integer.parseInt(br.readLine());
            boolean isGraph = false;

            int[] parent = new int[N + 1];
            int[] rank = new int[N + 1];

            for (int i = 1; i <= N; i++) {
                parent[i] = i;
                rank[i] = 1;
            }

            for (int i = 0; i < M; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                // 싸이클 생성
                if (Find(a, parent) == Find(b, parent)) {
                    isGraph = true;
                } else {
                    Union(a, b, parent, rank);
                }
            }

            if (isGraph || N - 1 != M)
                System.out.println("graph");
            else
                System.out.println("tree");

        }
    }
}
