import java.io.*;
import java.util.*;

public class Main {

    static int N, M, L, K;
    static int[][] stars;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        stars = new int[K][2];

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            stars[i][0] = Integer.parseInt(st.nextToken());
            stars[i][1] = Integer.parseInt(st.nextToken());
        }

    }

    static int solve() {
        int res = 0;

        // 별똥별을 기준으로 트램펄린 설친
        //  두 점기준 모든 방향 탐색이 가능함
        for (int[] s1 : stars) {
            for (int[] s2 : stars) {
                int startX = s1[0];
                int startY = s2[1];
                int cnt = 0;

                // 트램펄린 범위 안에 있는 별똥별 개수 세기
                for (int[] star : stars) {
                    int x = star[0];
                    int y = star[1];
                    if (x >= startX && x <= startX + L && y >= startY && y <= startY + L) {
                        cnt++;
                    }
                }

                res = Math.max(res, cnt);
            }
        }

        return K - res;
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }

}
