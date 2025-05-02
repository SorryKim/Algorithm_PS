import java.util.*;
import java.io.*;



public class Main {

    static int N, M;
    static int[] arr;
    static int ans = 0;

    static void DFS(int n, int cnt, int sum){

        if(sum > M) return;

        if(cnt == 3){
            ans = Math.max(ans, sum);
            return;
        }

        for(int i = n; i < N; i++){
            DFS(i + 1, cnt + 1, sum + arr[i]); // 선택
            
        }
    }


    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){ 
            arr[i] = Integer.parseInt(st.nextToken());
        }

        DFS(0, 0, 0);
        System.out.println(ans);
    }
}
