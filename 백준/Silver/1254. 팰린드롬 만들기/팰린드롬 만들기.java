import java.io.*;

public class Main {
    
    
    public static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while(left < right) {
            if(s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        int n = S.length();
        int i;
        
        for(i = 0; i < n; i++){
            if(isPalindrome(S.substring(i))){
                break;
            }
        }
        
    
        System.out.println(n + i);
    }
}
