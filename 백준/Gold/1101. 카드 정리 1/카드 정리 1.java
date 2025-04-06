import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] box;
    static int[] color; // 전체 색상별 카드 수

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        box = new int[N + 1][M + 1];
        color = new int[M + 1];
        
        for (int i = 1; i <= N; i++)
            Arrays.fill(box[i], 0);
        Arrays.fill(color, 0);
        
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                box[i][j] = Integer.parseInt(st.nextToken());
                color[j] += box[i][j];
            }
        }
    }

    // 박스 idx가 비어있지 않은지 확인
    static boolean isNonEmpty(int idx) {
        for (int c = 1; c <= M; c++) {
            if (box[idx][c] > 0) return true;
        }
        return false;
    }

    // 박스 idx가 순수한지 확인하여, 순수하면 그 색상의 번호를 반환,
    // 두 개 이상의 색이 섞여있다면 0을 반환.
    static int pureColor(int idx) {
        int found = 0;
        for (int c = 1; c <= M; c++) {
            if (box[idx][c] > 0) {
                if (found == 0) found = c;
                else return 0; // 두 색 이상 존재 → 순수하지 않음
            }
        }

        return found;
    }
    
    static int solveWithJoker(int joker) {

        int cost = 0;
        // 순수한 박스에서 나타나는 색을 저장
        HashSet<Integer> pureSet = new HashSet<>();
        
        for (int i = 1; i <= N; i++) {
            if (i == joker) continue;
            
            if (isNonEmpty(i)) {
                cost++;
            }

            int col = pureColor(i);
            if (col != 0) {
                pureSet.add(col); // 해당 색상으로 이미 한 박스는 정리되어 있음
            }
        }

        // 각 색상마다 한 박스는 최종 목적지로 남길 수 있으므로 비용에서 절감
        return cost - pureSet.size();
    }
    
    // 조커 박스를 사용하지 않는 경우: 모든 박스가 비조커인 상황에서 계산
    static int solveNoJoker() {

        int cost = 0;
        HashSet<Integer> pureSet = new HashSet<>();
        for (int i = 1; i <= N; i++) {
            if (isNonEmpty(i)) {
                cost++;
            }
            int col = pureColor(i);
            if (col != 0) {
                pureSet.add(col);
            }
        }

        return cost - pureSet.size();
    }
    
    public static void main(String[] args) throws Exception {
        Input();
        int answer = Integer.MAX_VALUE;
        
        // 조커 박스를 사용하지 않는 경우
        answer = Math.min(answer, solveNoJoker());
        
        // 각 박스를 조커 박스로 지정하는 경우
        for (int i = 1; i <= N; i++) {
            answer = Math.min(answer, solveWithJoker(i));
        }
        
        System.out.println(answer);
    }
}
