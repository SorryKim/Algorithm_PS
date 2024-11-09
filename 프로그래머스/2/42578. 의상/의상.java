import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        
        for(int i = 0; i < clothes.length; i++){
            String kind = clothes[i][1];
            
            if(map.containsKey(kind)){
                int num = map.get(kind);
                map.put(kind, num + 1);
            }else{
                map.put(kind, 1);
            }
        }
        
        for(String key : map.keySet())
            answer *= (map.get(key) + 1);
        
        return answer - 1;
    }
}