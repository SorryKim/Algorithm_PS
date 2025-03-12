import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());
        long[] arr = new long[N];

        st = new StringTokenizer(br.readLine());
        arr[0] = Long.parseLong(st.nextToken());
        for (int i = 1; i < N; i++) {
            arr[i] = arr[i - 1] + Long.parseLong(st.nextToken());
        }

        Map<Long, Long> map = new HashMap<>();
        map.put(0L, 1L);

        long ans = 0;
        for (long sum : arr) {
            long target = sum - K;
            if (map.containsKey(target)) {
                ans += map.get(target);
            }
            map.put(sum, map.getOrDefault(sum, 0L) + 1);
        }

        System.out.println(ans);
    }
}
