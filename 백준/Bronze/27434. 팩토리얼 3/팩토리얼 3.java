import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {

    static BigInteger Factorial(int a, int b){

        BigInteger temp = BigInteger.valueOf(a);
        
        if(a < b){
            int c = (a + b) / 2;
            temp = Factorial(a, c).multiply(Factorial(c + 1, b));
        }

        return temp;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        BigInteger answer = Factorial(1, N);
        System.out.println(answer);
    
    }
}