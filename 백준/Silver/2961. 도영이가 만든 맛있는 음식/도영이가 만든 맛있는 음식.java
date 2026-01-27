import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static Ing[] arr;
    static long ans = Long.MAX_VALUE;

    static class Ing{
        public int S, B;

        public Ing(int s, int b){
            S = s;
            B = b;
        }
    };

    static void input() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new Ing[N];

        for(int i = 0; i <  N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            arr[i] = new Ing(s, b);
        }
    }

    static long solve(){
        
        for(int mask = 1; mask < (1 << N); mask++){
            long s = 1;
            long b = 0;

            for(int i = 0; i < N; i++){
                if((mask & (1 << i)) != 0){
                    s *= arr[i].S;
                    b += arr[i].B;
                }
            }

            long val = Math.abs(s - b);
            ans = Math.min(val, ans);
        }

        return ans;
    }

    public static void main(String[] args) throws Exception {
       input();
       System.out.println(solve());
    }
}
