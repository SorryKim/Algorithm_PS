import java.util.*;

public class Solution {
    public String solution(String[] participant, String[] completion) {
        
        String answer = "";
        Map<String, Integer> myMap = new HashMap<>();

        // 참가자 목록을 맵에 추가
        for (String s : participant) {
            myMap.put(s, myMap.getOrDefault(s, 0) + 1);
        }

        // 완주자 목록을 맵에서 제거
        for (String s : completion) {
            myMap.put(s, myMap.get(s) - 1);
        }

        // 완주하지 못한 참가자 찾기
        for (String s : participant) {
            if (myMap.get(s) > 0) {
                answer = s;
                break;
            }
        }

        return answer;
    }
}