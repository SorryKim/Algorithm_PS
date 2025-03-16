import java.io.*;

public class Main {

    static String Func(int num){

        if(num % 15 == 0) return "FizzBuzz";
        else if(num % 3 == 0) return "Fizz";
        else if(num % 5 == 0) return "Buzz";
        else return Integer.toString(num);
    }

    static boolean isNum(String str){
        if(str.equals("Fizz") || str.equals("Buzz") || str.equals("FizzBuzz")) return false;
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String s1 = br.readLine();
        String s2 = br.readLine();
        String s3 = br.readLine();

        int num = 0;

        if(isNum(s1)) num = Integer.parseInt(s1) + 3;
        else if(isNum(s2)) num = Integer.parseInt(s2) + 2;
        else num = Integer.parseInt(s3) + 1;

        System.out.println(Func(num));
        
    }
}