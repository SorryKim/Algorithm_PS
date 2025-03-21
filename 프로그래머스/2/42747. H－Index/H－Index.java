import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);

        int start = 0;
        int end = citations[citations.length - 1];
        
        for(int i = start; i <= end; i++){
            
            int cnt = 0;
            for(int now : citations){
                if(now >= i)
                    cnt++;
            }
            
            int hidx = Math.min(cnt, i);
            answer = Math.max(answer, hidx);
        }
        
        return answer;
    }
}