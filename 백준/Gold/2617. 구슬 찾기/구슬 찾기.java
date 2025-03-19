import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] dist;

    static void Input() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dist = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = 0;
            }
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            // a > b임
            dist[a][b] = 1;
        }
    }

    static int Solve() {
        int ans = 0;

        // 플로이드 워샬 사용해서 각 노드끼리 거리를 구함
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= N; k++) {
                    if (dist[j][i] == 1 && dist[i][k] == 1) {
                        dist[j][k] = 1;
                    }
                }
            }
        }

        
        for (int i = 1; i <= N; i++) {

            int light = 0;
            int heavy = 0;

            for (int j = 1; j <= N; j++) {
                if (dist[i][j] == 1)
                    light++;
                if (dist[j][i] == 1)
                    heavy++;
            }

            // 거리가 (N + 1)/2 이상이면 중간값이 될 수 없다.
            int pivot = (N + 1) / 2;

            if (light >= pivot || heavy >= pivot) {
                ans++;
            }
        }

        return ans;
    }

    public static void main(String[] args) throws Exception {

        Input();
        System.out.println(Solve());

    }
}
