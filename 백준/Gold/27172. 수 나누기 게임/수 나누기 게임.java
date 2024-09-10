import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(reader.readLine());

        st = new StringTokenizer(reader.readLine());
        int[] arr = new int[N + 1];
        int[] score = new int[1000000 + 1];
        boolean[] check = new boolean[1000000 + 1];

        for (int i = 1; i <= 1000000; i++) {
            score[i] = 0;
            check[i] = false;
        }

        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            check[arr[i]] = true;
        }

        // 에라토스테네스의 체처럼 약수-배수 관계를 처리
        for (int i = 1; i <= 1000000; i++) {
            
            if (check[i]) { // i라는 수가 플레이어들 중에 존재하는 경우
                for (int j = 2 * i; j <= 1000000; j += i) {
                    if (check[j]) { // j가 i의 배수일 때
                        score[i]++; // i는 j의 약수이므로 i의 승리
                        score[j]--; // j는 i의 배수이므로 j의 패배
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            System.out.print(score[arr[i]] + " ");
        }
    }
}
