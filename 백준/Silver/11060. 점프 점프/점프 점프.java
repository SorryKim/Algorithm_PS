import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {

        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        
        // buttom - up
        int[] dp = new int[N];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for(int i = 0; i < N; i++){
            // 도달할 수 없는 칸이면 건너뛰기
            if(dp[i] == INF) continue;

            int jumpRange = arr[i];
            for(int step = 1; step <= jumpRange; step++){
                int next = i + step;
                if(next >= N) break;
                dp[next] = Math.min(dp[next], dp[i] + 1);
            }
        }
        
        // Print
        System.out.println(dp[N - 1] == INF ? -1 : dp[N - 1]);
    }
}