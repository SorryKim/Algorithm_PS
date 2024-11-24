class Solution {
    public long solution(int n) {
        long answer = 0;  
        long[] DP = new long[2001];
        DP[0] = 1;
        DP[1] = 1;
    
        for(int i = 2; i <= 2000; i++){
            DP[i] = (DP[i - 2] + DP[i - 1]) % 1234567;
        }
    
        answer = DP[n];
        return answer;
    }
}