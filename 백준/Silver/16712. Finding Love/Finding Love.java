import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[] A, V;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        A = new int[N];
        V = new int[N - M + 1];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) A[i] = Integer.parseInt(st.nextToken());
        
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N - M + 1; i++) V[i] = Integer.parseInt(st.nextToken());
    }

    static void solve(){
    
        ArrayList<Integer> list = new ArrayList<>();
        
        for(int i = 0; i < M - 1; i++) list.add(A[i]);
        int next = M - 1;
        
        for(int idx : V){
            
            list.add(A[next]);
            next++;
            Collections.sort(list); // 안정정렬
            list.remove(idx - 1);
        }

        for(int ans : list) System.out.print(ans + " ");
        
    }

    public static void main(String[] args) throws Exception {
        input();
        solve();
    }
}
