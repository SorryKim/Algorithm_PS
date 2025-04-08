import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static String founder;
    static String[] candidate;
    static Map<String, Double> weight;
    static Map<String, String[]> parents;

    public static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        founder = br.readLine();
        candidate = new String[M];
        parents = new HashMap<>();
        weight = new HashMap<>();

        // 혈연 관계 입력
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String child = st.nextToken();
            String parent1 = st.nextToken();
            String parent2 = st.nextToken();

            parents.put(child, new String[] { parent1, parent2 });
            weight.put(child, 0.0);
            weight.put(parent1, 0.0);
            weight.put(parent2, 0.0);
        }

        weight.put(founder, 1.0);

        // 후보자 입력
        for (int i = 0; i < M; i++) {
            candidate[i] = br.readLine();
        }
    }

    static double DFS(String node) {

        if (parents.containsKey(node)) {
            double d1 = DFS(parents.get(node)[0]);
            double d2 = DFS(parents.get(node)[1]);

            return (d1 + d2) / 2.0;
        }

        if (node.equals(founder))
            return 1.0;
        else
            return 0.0;

    }

    static String Solve() {

        String answer = "";
        double val = 0.0;

        for (String s : candidate) {
            double temp = DFS(s);
            if (temp > val) {
                answer = s;
                val = temp;
            }
        }

        return answer;
    }

    public static void main(String[] args) throws Exception {
        Input();
        System.out.println(Solve());
    }
}
