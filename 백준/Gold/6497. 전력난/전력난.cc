#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

int Find(int n, vector<int> &parent) {
    if (n == parent[n])
        return parent[n];
    return parent[n] = Find(parent[n], parent);
}

void Union(int a, int b, vector<int> &parent, vector<int> &rank) {
    int rootA = Find(a, parent);
    int rootB = Find(b, parent);

    if (rootA != rootB) {
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        vector<Edge> edges;
        int all_cost = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            all_cost += z;
            edges.push_back(Edge(x, y, z));
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(m);
        vector<int> rank(m, 0);

        for (int i = 0; i < m; i++)
            parent[i] = i;

        int mst_weight = 0;
        int edge_count = 0;

        for (const auto &edge : edges) {
            if (Find(edge.u, parent) != Find(edge.v, parent)) {
                Union(edge.u, edge.v, parent, rank);
                mst_weight += edge.weight;
                edge_count++;
                if (edge_count == m - 1)
                    break;
            }
        }

        cout << all_cost - mst_weight << '\n';
    }

    return 0;
}
