import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int C = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        int a = A*D + B*C; // 분모
        int b = B*D; // 분자

        int gcd = GCD(a, b);

        a /= gcd;
        b /= gcd;

        System.out.println(a + " " + b);

    }

    static int GCD(int a, int b){

        while(b != 0){
            int temp = b;
            b =  a % b;
            a = temp;
        }

        return a;
    }
}
