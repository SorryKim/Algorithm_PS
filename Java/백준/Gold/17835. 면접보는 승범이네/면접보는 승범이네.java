import java.util.*;
import java.io.*;

public class Main {

    static int N, M, K;
    static List<int[]>[] graph;
    static int[] interview;

    static void input() throws IOException{ 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        for(int i = 1; i <= N; i++){
            graph[i] = new ArrayList<>();
        }


        // 그래프 방향 역순으로 하여 면접장소를 시작으로 다익스트라
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int U = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            graph[V].add(new int[]{U, C});
        }

        interview = new int[K];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < K; i++){
            interview[i] = Integer.parseInt(st.nextToken());
        }
    }
    
    static long[] solve() {
        long[] distance = new long[N + 1];
        Arrays.fill(distance, Long.MAX_VALUE);
    
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[1], b[1]));
    
        for (int start : interview) {
            pq.add(new long[]{start, 0});
            distance[start] = 0;
        }
    
        while (!pq.isEmpty()) {
            long[] temp = pq.poll();
            int now = (int) temp[0];
            long cost = temp[1];
    
            if (cost > distance[now]) continue;
    
            for (int[] edge : graph[now]) {
                int next = edge[0];
                long nextCost = cost + edge[1];
    
                if (distance[next] > nextCost) {
                    distance[next] = nextCost;
                    pq.add(new long[]{next, nextCost});
                }
            }
        }
    
        long maxDist = -1;
        int city = 0;
        for (int i = 1; i <= N; i++) {
            if (distance[i] == Long.MAX_VALUE) continue;
    
            if (distance[i] > maxDist) {
                maxDist = distance[i];
                city = i;
            }
        }
    
        return new long[]{city, maxDist};
    }
    


    public static void main(String[] args) throws IOException{
        input();
        long[] ans = solve();
        for(long v : ans){
            System.out.println(v);
        }
        
    }
}