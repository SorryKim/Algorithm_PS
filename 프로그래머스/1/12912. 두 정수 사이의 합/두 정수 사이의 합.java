class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        int end = a > b ? a : b;
        int start = end == a ? b : a;
        
            
        for(int i = start; i <= end; i++){
            answer += i;
        }
        
        return answer;
    }
}