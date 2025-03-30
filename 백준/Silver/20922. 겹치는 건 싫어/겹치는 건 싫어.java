import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());

        int[] count = new int[100001];
        
        int left = 0;  
        int maxLength = 0;
        
        // 오른쪽 포인터를 이동시키며 윈도우 확장
        for(int right = 0; right < N; right++) {
            
            // 현재 숫자의 카운트 증가
            count[arr[right]]++;
            
            // 현재 숫자의 개수가 K를 초과하면 윈도우 축소
            while(count[arr[right]] > K) {
                count[arr[left]]--;
                left++;  
            }
            
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        System.out.println(maxLength);
    }
}