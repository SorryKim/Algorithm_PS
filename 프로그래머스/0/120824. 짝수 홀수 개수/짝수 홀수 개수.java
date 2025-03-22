class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = {};
        
        int cnt1 = 0;
        int cnt2 = 0;
        
        for(int i = 0; i < num_list.length; i++){
            int now = num_list[i];
            if(now % 2 == 0) cnt1++;
            else cnt2++;
        }
        
        return new int[]{cnt1, cnt2};
    }
}