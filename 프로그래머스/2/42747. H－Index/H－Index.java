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
            
            answer = Math.max(answer, Math.min(cnt, i));
        }
        
        return answer;
    }
}