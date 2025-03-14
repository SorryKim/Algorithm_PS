import java.io.*;
import java.util.*;

public class Main {

    static class Ball implements Comparable<Ball> {
        int index, color, size;

        Ball(int index, int color, int size) {
            this.index = index;
            this.color = color;
            this.size = size;
        }

        @Override
        public int compareTo(Ball other) {
            return Integer.compare(this.size, other.size);
        }
    }

    static int N;
    static Ball[] balls;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        balls = new Ball[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int color = Integer.parseInt(st.nextToken());
            int size = Integer.parseInt(st.nextToken());
            balls[i] = new Ball(i, color, size);
        }

    }

    static int[] Solve() {

        int[] result = new int[N];
        Arrays.sort(balls);

        int[] colorSum = new int[N + 1];
        Arrays.fill(colorSum, 0);

        int left = 0;
        int sum = 0;

        for (int right = 0; right < N; right++) {

            Ball now = balls[right];

            // 자신보다 작은 공들 누적합기록
            // 색깔별 누적합도 기록
            while (balls[left].size < now.size) {
                sum += balls[left].size;
                colorSum[balls[left].color] += balls[left].size;
                left++;
            }

            result[now.index] = sum - colorSum[now.color];
        }

        return result;
    }

    public static void main(String[] args) throws Exception {

        Input();
        int[] answer = Solve();
        for (int i = 0; i < N; i++) {
            System.out.println(answer[i]);
        }

    }
}
