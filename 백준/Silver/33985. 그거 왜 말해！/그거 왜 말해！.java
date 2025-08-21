import java.io.*;

public class Main {

    static int N;
    static String T;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        T = br.readLine();
    }

    public static String solve() {
        
        int cnt = 0;
        if(T.charAt(0) == 'B') return "No";
        if(T.charAt(T.length() - 1) == 'A') return "No";
        
        

        return "Yes";
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solve());
    }
}