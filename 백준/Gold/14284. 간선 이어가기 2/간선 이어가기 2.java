import java.io.*;
import java.util.*;

public class Main {

    static final int INF = Integer.MAX_VALUE;

    static class Edge implements Comparable<Edge> {
        int vertex, cost;
        public Edge(int vertex, int cost){
            this.vertex = vertex;
            this.cost = cost;
        }
        @Override
        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }

    public static void main(String[] args) throws IOException {
        
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); // 정점 개수
        int m = Integer.parseInt(st.nextToken()); // 간선 개수

        // 그래프 인접 리스트
        List<Edge>[] graph = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }

        // 간선 정보 입력
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            // 무방향
            graph[a].add(new Edge(b, c));
            graph[b].add(new Edge(a, c));
        }

        // s, t 입력
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());

        // 다익스트라 알고리즘
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);
        dist[s] = 0;

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.offer(new Edge(s, 0));

        while(!pq.isEmpty()){
            Edge cur = pq.poll();
            int curV = cur.vertex;
            int curCost = cur.cost;

            // 이미 더 짧은 경로가 있으면 패스
            if(dist[curV] < curCost) continue;

            if(curV == t) break;

            // 인접 정점 업데이트
            for(Edge nxt : graph[curV]){
                int newCost = curCost + nxt.cost;
                if(dist[nxt.vertex] > newCost){
                    dist[nxt.vertex] = newCost;
                    pq.offer(new Edge(nxt.vertex, newCost));
                }
            }
        }

        // 결과 출력: s ~ t 최단 거리
        System.out.println(dist[t]);
    }
}
