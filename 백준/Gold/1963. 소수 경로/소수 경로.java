import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Pair {
        int val, cnt;

        Pair(int val, int cnt) {
            this.val = val;
            this.cnt = cnt;
        }
    }

    static boolean CanMove(int n1, int n2) {
        int cnt = 0;

        while (n1 > 0 && n2 > 0) {
            if (n1 % 10 == n2 % 10)
                cnt++;
            n1 /= 10;
            n2 /= 10;
        }

        return cnt == 3; // 4자리 중 3자리만 일치하면 이동 가능
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(reader.readLine());

        // 소수 체크를 위한 배열
        boolean[] isPrime = new boolean[10000];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;

        // 에라토스테네스의 체로 소수 구하기
        for (int i = 2; i * i < 10000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < 10000; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // 테스트 케이스 처리
        for (int TC = 0; TC < T; TC++) {
            st = new StringTokenizer(reader.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());

            boolean[] visited = new boolean[10000];
            Queue<Pair> q = new LinkedList<>();
            q.add(new Pair(n1, 0));
            visited[n1] = true;

            int answer = 0;

            while (!q.isEmpty()) {
                Pair p = q.poll();
                int now = p.val;
                int cnt = p.cnt;

                if (now == n2) {
                    answer = cnt;
                    break;
                }

                // 한 자리씩 변경하여 가능한 소수 찾기
                for (int i = 1000; i < 10000; i++) {
                    if (isPrime[i] && CanMove(now, i) && !visited[i]) {
                        visited[i] = true;
                        q.add(new Pair(i, cnt + 1));
                    }
                }
            }

            System.out.println(answer); // 정답 출력
        }
    }
}
