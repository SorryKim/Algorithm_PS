import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static PriorityQueue<Integer> pq;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        pq = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            pq.add(Integer.parseInt(br.readLine()));
        }
    }

    static long Solve() {
        long ans = 0;

        while (pq.size() > 1) {
            int a = pq.poll();
            int b = pq.poll();
            ans += (a + b);
            pq.add(a + b);
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {

        Input();
        System.out.println(Solve());
    }
}
