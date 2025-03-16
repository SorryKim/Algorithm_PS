import java.io.*;
import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Integer> map = new HashMap<>();
        
        // 의상 체크
        for(int i = 0; i < clothes.length; i++){
            String name = clothes[i][0];
            String kind = clothes[i][1];
            
            // 종류 포함여부 확인
            if(map.containsKey(kind)){
                map.put(kind, map.get(kind) + 1);
            }else{
                map.put(kind, 1);
            }
        }
        
        for(String key : map.keySet()){
            answer *= map.get(key) + 1;
        }
        
        return answer - 1; // 전체 선택안하는 경우의수 -1
    }
}