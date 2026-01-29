import java.io.*;
import java.util.*;

public class Main {

    static int N, M, K;
    static int[][] dist;
    static int[] C;
    static final int INF = 987654321;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dist = new int[N + 1][N + 1];
        for(int i = 1; i <= N; i++){
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            dist[a][b] = c;
        }

        K = Integer.parseInt(br.readLine());
        C = new int[K];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < K; i++){
            C[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve() {

        
        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int val = INF;
        ArrayList<Integer> ans = new ArrayList<>();

        for(int x = 1; x <= N; x++){
            int temp = 0;
            boolean ok = true;

            for(int i = 0; i < K; i++){
                int c = C[i];
                if(dist[c][x] == INF || dist[x][c] == INF){
                    ok = false;
                    break;
                }
                temp = Math.max(temp, dist[c][x] + dist[x][c]);
            }

            if(!ok) continue;

            if(temp < val){
                val = temp;
                ans.clear();
                ans.add(x);
            }else if(temp == val){
                ans.add(x);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int x : ans) sb.append(x).append(" ");
        System.out.print(sb.toString());
    }

    public static void main(String[] args) throws Exception {
        input();
        solve();
    }
}
