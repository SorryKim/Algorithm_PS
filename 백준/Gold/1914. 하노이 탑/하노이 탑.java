import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    static long count = 0;
    static StringBuilder sb = new StringBuilder();

    static void Hanoi(int n, int a, int b, int c){

        if(n == 0) return;
        count++;

        // a -> c
        Hanoi(n - 1, a, c, b);

        if(n <= 20){
            sb.append(a + " " + c + "\n");
        }

        // c -> b
        Hanoi(n - 1, b, a, c);
    }

    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        if(N <= 20){
            Hanoi(N, 1, 2, 3);
            System.out.println(count);
            System.out.print(sb.toString());
        }
        else{
            BigInteger moves = BigInteger.valueOf(2).pow(N).subtract(BigInteger.ONE);
            System.out.println(moves);
        }
        
    }
    
}
