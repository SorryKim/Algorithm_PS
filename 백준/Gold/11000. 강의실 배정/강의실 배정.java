import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        // Input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());

        int[][] arr = new int[N][2];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        // 첫번째 기준 오름차순 정렬
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // 첫번째 강의 끝나는 시간
        pq.add(arr[0][1]);

        for (int i = 1; i < N; i++) {

            // 강의 추가
            pq.add(arr[i][1]);

            // 새로운 강의실을 안써도 되는 경우
            if (pq.peek() <= arr[i][0])
                pq.poll();
        }

        System.out.println(pq.size());

    }
}
