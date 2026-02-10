import java.io.*;

public class Main {

    static int N;
    static int[] arr;

    static int gcd(int a, int b){

        while(b != 0){
            int r = a % b;
            a = b;
            b = r;
        }

        return a;
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];

        for(int i = 0; i < N; i++){
            int num = Integer.parseInt(br.readLine());
            arr[i] = num;
        }
    }
    
    static int solve(){
        int ans = 0;
        int d = arr[1] - arr[0];

        for(int i = 2; i < N; i++) d = gcd(d, arr[i] - arr[i - 1]);
        
        for(int i = 1; i < N; i++){
            int dist = arr[i] - arr[i - 1];
            ans += (dist / d) - 1;
        }
        
        return ans;
    }

    public static void main(String[] args) throws Exception {
        input();    
        System.out.println(solve());
    }
}
