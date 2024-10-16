import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        int idx = 0;
        
        for(int[] command : commands){
            int i = command[0];
            int j = command[1];
            int k = command[2];
            
            List<Integer> temp = new ArrayList<>();
            for(int t = i - 1; t < j; t++)
                temp.add(array[t]);
            
            Collections.sort(temp);
            answer[idx] = temp.get(k - 1);
            idx++; 
        }
        
        return answer;
    }
}
