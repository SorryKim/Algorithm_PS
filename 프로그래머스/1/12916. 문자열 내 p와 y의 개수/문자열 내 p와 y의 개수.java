import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        int cntP = 0;
        int cntY = 0;
        
        for(int i = 0; i < s.length(); i++){
            char now = s.charAt(i);
            if(now == 'P' || now == 'p')
                cntP++;
            if(now == 'Y' || now == 'y')
                cntY++;
            
        }
        
        answer = cntP == cntY ? true : false;
        
        return answer;
    }
}