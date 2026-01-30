import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] gold = new int[N + 1];
        int[] silver = new int[N + 1];
        int[] bronze = new int[N + 1];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int id = Integer.parseInt(st.nextToken());
            gold[id] = Integer.parseInt(st.nextToken());
            silver[id] = Integer.parseInt(st.nextToken());
            bronze[id] = Integer.parseInt(st.nextToken());
        }

        int gk = gold[K];
        int sk = silver[K];
        int bk = bronze[K];

        int better = 0;
        for (int i = 1; i <= N; i++) {
            if (i == K) continue;

            if (gold[i] > gk ||
               (gold[i] == gk && silver[i] > sk) ||
               (gold[i] == gk && silver[i] == sk && bronze[i] > bk)) {
                better++;
            }
        }

        System.out.println(better + 1);
    }
}
