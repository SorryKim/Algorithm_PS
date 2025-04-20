import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] arr;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

    }

    static String solve() {
        long sum = 0;
        long cnt = 0; // 1이 필요한 갯수
    
        for (int i = 0; i < N; i++) {
            sum += arr[i];
            cnt += arr[i] % 2;
        }
        
        // 전체 길이의 합은 3의배수가 되어야 함.
        if (sum % 3 != 0) return "NO";
        
        long temp = sum / 3;
        if (cnt <= temp) return "YES";
        else return "NO";
    }
    

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }

}
