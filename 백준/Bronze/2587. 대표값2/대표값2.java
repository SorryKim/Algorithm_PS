import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    
    static int N, M, K;
    
    public static void main(String[] args) throws Exception {
        
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[5];
        
        int sum = 0;
        for(int i = 0; i < 5; i++){
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }

        Arrays.sort(arr);
        System.out.println(sum / 5);
        System.out.println(arr[2]);  
    }
}
