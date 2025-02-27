import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[][] arr = new int[K][2];
        int[] dp = new int[N + 1];
        Arrays.fill(dp, 0);

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        for (int[] temp : arr) {
            int var = temp[0];
            int time = temp[1];

            for (int i = N; i >= time; i--) {
                dp[i] = Math.max(dp[i], dp[i - time] + var);
            }
        }

        System.out.println(dp[N]);
    }

}