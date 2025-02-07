import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    
    static StringTokenizer st;
    
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a,b) -> {
            if(a[0] != b[0]) return Integer.compare(a[0], b[0]);
            else return Integer.compare(a[1], b[1]);
        });

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());

            int idx = Integer.parseInt(st.nextToken());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            
            pq.add(new int[]{start, end});
        }

        PriorityQueue<Integer> rooms = new PriorityQueue<>();
        
        while(!pq.isEmpty()){

            int[] temp = pq.poll();
            int start = temp[0];
            int end = temp[1];

            if(!rooms.isEmpty() && start >= rooms.peek()) rooms.poll();
            rooms.add(end);

        }

        System.out.println(rooms.size());

    }
}
