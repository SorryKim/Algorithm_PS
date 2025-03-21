class Solution {
    public int solution(int slice, int n) {
        int answer = (int)Math.ceil((double)n / (double)slice);
        return answer;
    }
}