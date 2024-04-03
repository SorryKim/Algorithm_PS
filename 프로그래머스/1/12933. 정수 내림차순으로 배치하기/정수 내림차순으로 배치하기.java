import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        String str = String.valueOf(n);
        List<Character> digits = new ArrayList<>();
        
        // 문자열의 각 자릿수를 리스트에 추가
        for(int i = 0; i < str.length(); i++){
            char digit = str.charAt(i);
            digits.add(digit);
        }
        
        // 리스트를 내림차순으로 정렬
        Collections.sort(digits, Collections.reverseOrder());
        
        // 정렬된 문자들을 다시 문자열로 연결
        StringBuilder sortedStr = new StringBuilder();
        for(char digit : digits){
            sortedStr.append(digit);
        }
        
        // 문자열을 long으로 변환
        answer = Long.parseLong(sortedStr.toString());
        
        return answer;
    }
}
