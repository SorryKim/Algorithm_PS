import java.util.*;


class Solution {
    
    static int GCD(int a, int b){
        
        if(b > a){
            int temp = a;
            a = b;
            b = temp;
        }
        while(a % b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }        
        
        return b;
    }
    
    static int LCM(int a, int b){   
        return a*b / GCD(a,b);
    }
    
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        
        answer[0] = GCD(n,m);
        answer[1] = LCM(n,m);
        
        return answer;
    }
}