import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Input
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N + 1];
        boolean[] visited = new boolean[N + 1];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) arr[i] = Integer.parseInt(st.nextToken());
        
        StringBuilder sb = new StringBuilder();
        
        int current = 1;
        for (int cnt = 0; cnt < N; cnt++) {
            // 현재 풍선 터뜨리기
            visited[current] = true;
            sb.append(current).append(" ");
            
            // 마지막 풍선을 터뜨렸다면 이동 없이 종료
            if (cnt == N - 1) break;
            
            // 현재 풍선에 적혀있던 수만큼 이동
            int move = arr[current];
            if (move > 0) {
                for (int i = 0; i < move; i++) current = getNextRight(current, visited, N);
            } else {
                for (int i = 0; i < -move; i++) current = getNextLeft(current, visited, N);
            }
        }
        
        // 결과 출력
        System.out.println(sb.toString());
    }
    
    // 이미 터진 풍선은 건너뛰면서 오른쪽으로 한 칸 이동
    private static int getNextRight(int current, boolean[] visited, int N) {
        do {
            current++;
            if (current > N) current = 1;
        } while (visited[current]);
        return current;
    }
    
    // 이미 터진 풍선은 건너뛰면서 왼쪽으로 한 칸 이동
    private static int getNextLeft(int current, boolean[] visited, int N) {
        do {
            current--;
            if (current < 1) current = N; // 원형 구조
        } while (visited[current]);
        return current;
    }
}
