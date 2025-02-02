import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int M = Integer.parseInt(br.readLine());

        Stack<Character> leftStack = new Stack<>();
        Stack<Character> rightStack = new Stack<>();

        // 초기 문자열을 leftStack에 넣음
        for (char c : s.toCharArray()) {
            leftStack.push(c);
        }

        for (int i = 0; i < M; i++) {
            String cmd = br.readLine();
            if (cmd.startsWith("P")) {
                // P $ 명령어: $를 커서 왼쪽에 추가
                char ch = cmd.charAt(2);
                leftStack.push(ch);
            } else if (cmd.equals("L")) {
                // L 명령어: 커서를 왼쪽으로 이동
                if (!leftStack.isEmpty()) {
                    rightStack.push(leftStack.pop());
                }
            } else if (cmd.equals("D")) {
                // D 명령어: 커서를 오른쪽으로 이동
                if (!rightStack.isEmpty()) {
                    leftStack.push(rightStack.pop());
                }
            } else if (cmd.equals("B")) {
                // B 명령어: 커서 왼쪽의 문자를 삭제
                if (!leftStack.isEmpty()) {
                    leftStack.pop();
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (char c : leftStack) {
            sb.append(c);
        }
        while (!rightStack.isEmpty()) {
            sb.append(rightStack.pop());
        }

        System.out.println(sb.toString());
    }
}