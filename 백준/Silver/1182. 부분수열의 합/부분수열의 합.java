import java.util.*;
import java.io.*;



public class Main {

    static int N, S;
    static int[] arr;
    static boolean[] visited;
    static int ans = 0;

    static void DFS(int n, int sum){
        
        if(n == N){
            if(sum == S) ans++;
            return;
        }
        DFS(n + 1, sum + arr[n]);
        DFS(n + 1, sum);
    }

    static void Input() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        arr = new int[N];
        visited = new boolean[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){ 
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException{
        
        Input();
        DFS(0, 0);
        if(S == 0)  ans--;
        System.out.println(ans);
    }
}
