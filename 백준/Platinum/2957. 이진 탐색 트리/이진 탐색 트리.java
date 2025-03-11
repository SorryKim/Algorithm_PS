import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        long ans = 0;

        // 값, 깊이
        TreeMap<Integer, Integer> tree = new TreeMap<>();
        
        // 끝값 설정
        tree.put(0, -1);
        tree.put(N+1, -1);
        
        for(int i = 0; i < N; i++){
            int num = Integer.parseInt(br.readLine());
            
            int low = tree.lowerKey(num);
            int high = tree.higherKey(num);
            int depth = Math.max(tree.get(low), tree.get(high)) + 1;
            
            tree.put(num, depth);
            ans += depth;
            
            System.out.println(ans);
        }
    }
}
