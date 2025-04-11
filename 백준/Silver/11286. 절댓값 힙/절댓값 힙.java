import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            int cmp = Integer.compare(Math.abs(a), Math.abs(b));
            if (cmp == 0)
                return Integer.compare(a, b);
            return cmp;
        });

        for (int test = 0; test < N; test++) {
            int now = Integer.parseInt(br.readLine());

            if (now != 0)
                pq.add(now);
            else {
                if (pq.isEmpty())
                    sb.append("0\n");
                else
                    sb.append(pq.poll()).append("\n");
            }
        }

        System.out.println(sb.toString());
    }
}
