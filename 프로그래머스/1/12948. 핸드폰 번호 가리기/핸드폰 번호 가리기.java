class Solution {
    public String solution(String phone_number) {
        String answer = "";
        
        
        int size = phone_number.length();
        for(int i = 0; i < size; i++){
            if(i >= size - 4){
                answer += phone_number.charAt(i);
                continue;
            }
            answer += "*"; 
        }
        
        return answer;
    }
}