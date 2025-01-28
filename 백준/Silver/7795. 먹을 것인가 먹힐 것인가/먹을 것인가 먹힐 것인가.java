import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for(int test = 0; test < T; test++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            int[] A = new int[N];
            int[] B = new int[M];
            
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; i++) A[i] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < M; i++) B[i] = Integer.parseInt(st.nextToken());
            
            // B물고기 이분탐색 사용위해 정렬
            Arrays.sort(B);

            int answer = 0;
            for(int i = 0; i < N; i++){
                int target = A[i];
                
                int idx = lower_bound(B, target);
                answer += idx;
            }
            
            System.out.println(answer);
        }  
    }

    // 이분탐색을 사용해 찾으려는 값 이상의 위치 반환
    public static int lower_bound(int[] arr, int target){
        int start = 0;
        int end = arr.length;

        while(start < end){
            int mid = (start + end) / 2;
            if(arr[mid] < target) start = mid + 1;
            else end = mid;
        }

        return start;
    }

    // 이분탐색을 사용해 찾으려는 값 초과하는 위치 반환
    public static int upper_bound(int[] arr, int target){
        int start = 0;
        int end = arr.length;

        while(start < end){
            int mid = (start + end) / 2;
            if(arr[mid] <= target) start = mid + 1;
            else end = mid;
        }

        return start;
    }
    
}
