import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] tower;

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        tower = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            tower[i] = Integer.parseInt(st.nextToken());
        }
    }

    static String Solve() {

        Deque<int[]> stack = new ArrayDeque<>(); // {탑의 인덱스, 높이}
        StringBuilder sb = new StringBuilder("");

        for (int i = 1; i <= N; i++) {
            int now = tower[i];

            while (!stack.isEmpty() && stack.getFirst()[1] < now) {
                stack.removeFirst();
            }

            if (stack.isEmpty())
                sb.append("0 ");
            else
                sb.append(stack.getFirst()[0] + " ");

            stack.addFirst(new int[] { i, now });
        }

        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        Input();
        System.out.println(Solve());
    }
}
