import java.util.*;

class Solution {
    
    public static int solution(int[] scoville, int K) {
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int cnt = 0;
        boolean flag = false;

        for (int s : scoville) pq.offer(s);
        

        while (pq.size() >= 2) {
            
            if (pq.peek() >= K) {
                flag = true;
                break;
            }

            int a = pq.poll();
            int b = pq.poll();

            pq.offer(a + 2 * b);
            cnt++;
        }

        if (!pq.isEmpty() && pq.peek() >= K) flag = true;
        

        return flag ? cnt : -1;
    }
}