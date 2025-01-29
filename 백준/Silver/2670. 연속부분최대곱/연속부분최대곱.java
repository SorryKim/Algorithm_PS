import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        double[] arr = new double[N];
        
        for(int i = 0; i < N; i++) arr[i]= Double.parseDouble(br.readLine());

        double ans = 0;

        for(int i = 0; i < N; i++){
            double temp = 1;
            for(int j = i; j < N; j++){
                temp *= arr[j];
                ans = Math.max(ans, temp);
            }
        }

        System.out.printf("%.3f%n", ans);
    }
}
