import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] arr;
    static final int INF = 987654321;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][M];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static int solve(){
    
        int[][][] dp = new int[N][M][3];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                for(int k = 0; k < 3; k++){
                    dp[i][j][k] = INF;
                }
            }
        }

        // 첫 줄세팅
        for(int j = 0; j < M; j++){
            dp[0][j][0] = arr[0][j];
            dp[0][j][1] = arr[0][j];
            dp[0][j][2] = arr[0][j];
        }

        for(int i = 1; i < N; i++){
            for(int j = 0; j < M; j++){

                // 0, 왼쪽 방향
                if(j + 1 < M){
                    dp[i][j][0] = Math.min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + arr[i][j];
                }

                // 1, 아래쪽 방향
                dp[i][j][1] = Math.min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];

                // 2, 오른쪽 방향
                if(j - 1 >= 0){
                    dp[i][j][2] = Math.min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + arr[i][j];
                }
            }
        }

        int ans = INF;
        
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 3; k++){
                ans = Math.min(ans, dp[N - 1][j][k]);
            }
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        input();
        System.out.println(solve());
    }
}
