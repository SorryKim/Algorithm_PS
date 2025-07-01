import java.io.*;
import java.util.*;

public class Main {


    static int N;
    static List<Integer> ranking;

    public static void input() throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        ranking = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            ranking.add(Integer.parseInt(st.nextToken()));
        }

    }

    public static long solve(){

        long ans = 0;

        // 랭킹이 가장 낮은 선수부터 차례대로 탈락시킨다.
        // 마지막 한 명은 남아야 하므로 N-1번의 경기가 일어난다.
        for (int i = 0; i < N - 1; i++) {

            // 현재 리스트에서 랭킹이 가장 낮은 선수를 찾는다.
            int maxRank = 0;
            int targetIndex = -1;
            for (int j = 0; j < ranking.size(); j++) {
                if (ranking.get(j) > maxRank) {
                    maxRank = ranking.get(j);
                    targetIndex = j;
                }
            }

            // 양옆 선수와의 랭킹 차이를 계산하여 더 작은 값을 비용으로 선택
            int left = Integer.MAX_VALUE;
            int right = Integer.MAX_VALUE;

            // 왼쪽에 선수가 있는 경우
            if (targetIndex > 0) {
                left = maxRank - ranking.get(targetIndex - 1);
            }
            // 오른쪽에 선수가 있는 경우
            if (targetIndex < ranking.size() - 1) {
                right = maxRank - ranking.get(targetIndex + 1);
            }

            // 두 차이 중 더 작은 값을 비용에 추가
            ans += Math.min(left, right);

            // 해당 선수를 리스트에서 제거
            ranking.remove(targetIndex);
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {

        input();
        System.out.println(solve());
    }
}