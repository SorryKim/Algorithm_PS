import java.io.*;
import java.util.*;

public class Main {

    static class Task implements Comparable<Task> {
        int T, S;

        public Task(int T, int S) {
            this.T = T;
            this.S = S;
        }

        // 먼저 끝내야하는 일, 오래걸리는 일부터 먼저 처리
        public int compareTo(Task other) {

            if (this.S == other.S) {
                int a = this.T;
                int b = other.T;
                if (a >= b)
                    return -1;
                else
                    return 1;
            }

            return Integer.compare(this.S, other.S);
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Task[] arr = new Task[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            int S = Integer.parseInt(st.nextToken());
            arr[i] = new Task(T, S);
        }

        Arrays.sort(arr);

        int start = 0;

        while (true) {

            int time = start;
            boolean flag = true;

            for (Task task : arr) {

                int T = task.T;
                int S = task.S;
                time += T;

                if (time > S) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                start++;
            else {
                if (start == 0)
                    System.out.println(-1);
                else
                    System.out.println(start - 1);
                return;
            }
        }
    }
}
