import java.io.*;
import java.util.*;

public class Main {

    static int N, K;
    static int[] parent, rank, cnt;
    static List<Integer>[] graph;

    public static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        rank = new int[N + 1];
        graph = new LinkedList[N + 1];
        cnt = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            rank[i] = 0;
            graph[i] = new LinkedList<>();
            cnt[i] = 1;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            // i번째 사람이 타려면 graph[i].get(0)번 사람이 타야 한다.
            graph[i].add(Integer.parseInt(st.nextToken()));
        }
    }

    static int Find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = Find(parent[node]);
    }

    static void Union(int a, int b) {
        int parentA = Find(a);
        int parentB = Find(b);

        if (parentA == parentB)
            return;

        if (rank[parentA] > rank[parentB]) {
            parent[parentA] = parentB;
        } else if (rank[parentA] < rank[parentB]) {
            parent[parentB] = parentA;
        } else {
            parent[parentB] = parentA;
            rank[parentA]++;
        }
    }

    // DFS를 통해 각 노드를 연결된 그룹으로 묶습니다.
    static void DFS(int node) {
        for (int next : graph[node]) {
            if (Find(node) == Find(next))
                continue;
            Union(node, next);
            DFS(next);
        }
    }

    static int Solve() {
        int ans = 0;

        // Union과정
        for (int i = 1; i <= N; i++) {
            DFS(i);
        }

        // 각 그룹별 전체 인원 수 계산
        Map<Integer, Integer> groupCount = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            int head = Find(i);
            groupCount.put(head, groupCount.getOrDefault(head, 0) + 1);
        }

        // 각 그룹별 최소 필수 인원을 계산
        int[] groupMin = new int[N + 1]; // 그룹 대표에 대해 해당 그룹의 사이클 길이
        boolean[] visited = new boolean[N + 1];

        // 사이클 구성 인원 구하기
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                Map<Integer, Integer> pos = new HashMap<>();
                int cur = i;
                while (!pos.containsKey(cur)) {
                    pos.put(cur, pos.size());
                    visited[cur] = true;
                    cur = graph[cur].get(0);
                }
                groupMin[Find(cur)] = pos.size() - pos.get(cur);
            }
        }

        // {필수 최소 인원(사이클 길이), 전체 그룹 크기} 쌍
        List<int[]> groups = new ArrayList<>();
        for (int head : groupCount.keySet())
            groups.add(new int[] { groupMin[head], groupCount.get(head) });

        // 지금까지 선택한 그룹들로 i명을 구성할 수 있다면 true.
        boolean[] check = new boolean[K + 1];
        check[0] = true;

        for (int[] group : groups) {
            int min = group[0];
            int max = group[1];
            boolean[] temp = new boolean[K + 1];

            for (int i = 0; i <= K; i++) {
                if (check[i]) {
                    temp[i] = true; // 그룹을 선택하지 않는 경우(즉, 기존 상태 유지)
                    for (int j = min; j <= max; j++) {  // 해당 그룹을 선택하는 경우
                        if (i + j <= K) {
                            temp[i + j] = true;
                        }
                    }
                }
            }

            check = temp;
        }

        // 가능한 인원수 중 K 이하에서 최대값을 구합니다.
        for (int j = 0; j <= K; j++) {
            if (check[j])
                ans = j;
        }

        return ans;
    }

    public static void main(String[] args) throws Exception {
        Input();
        System.out.println(Solve());
    }
}
