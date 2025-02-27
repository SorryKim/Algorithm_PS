import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[][] arr = new int[M][2];
        int[] dp = new int[N + 1];
        Arrays.fill(dp, 0);

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[i][0] = a;
            arr[i][1] = b;
        }

        for (int i = 0; i < M; i++) {

            int time = arr[i][0];
            int pages = arr[i][1];

            for (int j = N; j >= time; j--) {
                dp[j] = Math.max(dp[j], dp[j - time] + pages);
            }
        }

        System.out.println(dp[N]);
    }

}