import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    
    static StringTokenizer st;
    
    public static void main(String[] args) throws Exception {
        
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Integer[] arr = new Integer[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr, Collections.reverseOrder());
        System.out.println(arr[K - 1]);
    }
}
