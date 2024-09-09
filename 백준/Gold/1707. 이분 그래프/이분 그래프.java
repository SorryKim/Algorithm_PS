import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int K = Integer.parseInt(reader.readLine());

        for (int test = 0; test < K; test++) {

            StringTokenizer st = new StringTokenizer(reader.readLine());

            int V = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());
            int[] group = new int[V + 1];
            ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

            // 그룹 초기화
            // -1: 아직 그룹안정해짐, 0,1로 두그룹으로 나눈다.

            for (int i = 1; i <= V; i++)
                group[i] = -1;

            for (int i = 0; i <= V; i++)
                graph.add(new ArrayList<>());

            for (int i = 0; i < E; i++) {
                st = new StringTokenizer(reader.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());

                graph.get(u).add(v);
                graph.get(v).add(u);
            }

            // 이분 그래프 여부
            boolean flag = true;

            for (int i = 1; i <= V; i++) {

                if (group[i] != -1)
                    continue;

                Queue<Integer> q = new LinkedList<>();

                group[i] = 0;
                q.add(i);

                while (!q.isEmpty() && flag) {

                    int now = q.poll();
                    int nextGroup = (group[now] == 0) ? 1 : 0;

                    for (int next : graph.get(now)) {

                        if (group[next] == group[now]) {
                            flag = false;
                            break;
                        } else {
                            if (group[next] == -1) {
                                group[next] = nextGroup;
                                q.add(next);
                            }
                        }
                    }
                }
            }

            String answer = flag ? "YES" : "NO";
            System.out.println(answer);
        }
    }
}
