import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] arr;

    static void input() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        return;
    }

    static int solve(){
        ArrayList<Integer> list = new ArrayList<>();

        for(int i = 0; i < N; i++){
            int now = arr[i];

            int left = 0, right = list.size();
            
            while(left < right){
                int mid = (left + right) / 2;
                if(list.get(mid) >= now) right = mid;
                else left = mid + 1;
            }

            if(left == list.size()) list.add(now);
            else list.set(left, now);
        }

        return list.size();
    }

    public static void main(String[] args) throws Exception {
       input();
       System.out.println(solve());
    }
}
