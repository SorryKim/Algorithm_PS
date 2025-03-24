import java.io.*;
import java.util.*;

public class Main {

    public static class Node implements Comparable<Node> {

        String name;
        Map<String, Node> children;

        public Node(String name) {
            this.name = name;
            children = new TreeMap<>();
        }

        public void AddChild(Node node) {
            children.put(node.name, node);
        }

        @Override
        public int compareTo(Node other) {
            return this.name.compareTo(other.name);
        }
    }

    static int N;
    static Map<String, Node> root;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        root = new TreeMap<>();

        // 트리 입력받기
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());
            String name = st.nextToken();
            Node parent;
            if (root.containsKey(name)) {
                parent = root.get(name);
            } else {
                parent = new Node(name);
                root.put(name, parent);
            }

            // 자식으로 추가
            for (int j = 1; j < K; j++) {
                String temp = st.nextToken();
                Node node;

                // 이미 해당 자식이 존재하는지 확인: 존재하면 재사용, 없으면 새로 생성
                if (parent.children.containsKey(temp)) {
                    node = parent.children.get(temp);
                } else {
                    node = new Node(temp);
                    parent.AddChild(node);
                }
                parent = node;
            }
        }
    }

    static void DFS(Node node, int depth) {

        for (int i = 0; i < depth; i++) {
            System.out.print("--");
        }

        System.out.println(node.name);

        for (String name : node.children.keySet()) {
            Node next = node.children.get(name);
            DFS(next, depth + 1);
        }
    }

    static void Solve() {

        for (String key : root.keySet()) {
            Node parent = root.get(key);
            System.out.println(parent.name);
            for (String temp : parent.children.keySet()) {
                Node next = parent.children.get(temp);
                DFS(next, 1);
            }
        }

    }

    public static void main(String[] args) throws Exception {
        input();
        Solve();
    }
}
