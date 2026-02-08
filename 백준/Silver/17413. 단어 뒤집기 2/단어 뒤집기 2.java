import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        StringBuilder sb = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        boolean inTag = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            // 태그 시작
            if (c == '<') {
                // 기존 단어 뒤집어 출력
                while (!stack.isEmpty()) sb.append(stack.pop());
                inTag = true;
                sb.append(c);
            }

            // 태그 끝
            else if (c == '>') {
                inTag = false;
                sb.append(c);
            }

            // 태그 안
            else if (inTag) sb.append(c);
            
            // 태그 밖
            else {
                if (c == ' ') {
                    // 단어 끝
                    while (!stack.isEmpty()) sb.append(stack.pop());
                    sb.append(c);
                } else stack.push(c);
            }
        }

        while (!stack.isEmpty()) sb.append(stack.pop());
        System.out.println(sb.toString());
    }
}
