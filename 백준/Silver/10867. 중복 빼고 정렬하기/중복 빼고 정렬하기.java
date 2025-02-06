import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    
    static StringTokenizer st;
    
    public static void main(String[] args) throws Exception {
        
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer N = Integer.parseInt(br.readLine());
        Set<Integer> set = new TreeSet();
        
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            set.add(Integer.parseInt(st.nextToken()));
        }

        for(Integer num : set){
            System.out.print(num + " ");
        }
    }
}
