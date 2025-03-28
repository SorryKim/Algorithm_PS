import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[][] dist;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dist = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                dist[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static long Solve() {
        long ans = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                boolean flag = true;
                
                for (int k = 1; k <= N; k++) {

                    if (k == i || k == j) continue;

                    // 잘못된 입력인 경우: 직접 가는 경로보다 다른 경로가 더 짧으면 안됨
                    if (dist[i][j] > dist[i][k] + dist[k][j]) 
                        return -1;
                    
                    // 다른 도시를 거쳐서도 같은 최소 시간이 나오면 직접 연결된 도로는 필요없음
                    if (dist[i][j] == dist[i][k] + dist[k][j]) {
                        flag = false;
                        break;
                    }

                }
                if (flag) ans += dist[i][j];
                
            }
        }

        return ans;
    }

    public static void main(String[] args) throws Exception {
        Input();
        System.out.println(Solve());
    }
}
