#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> v;
int parent[1000001];

vector<vector<int>> makeSet() {
    vector<vector<int>> result;
    vector<int> group;
    int before = v[0];
    group.push_back(before);

    for (int i = 1; i < v.size(); i++) {
        int now = v[i];
        if (before + 1 == now)
            group.push_back(now);
        else {
            result.push_back(group);
            group.clear();
            group.push_back(now);
        }
        before = now;
    }

    result.push_back(group);
    return result;
}

void setParent(vector<vector<int>> &set) {
    parent[set[0][0]] = -1; // 루트
    int parent_idx = 0;
    int idx = 1;

    while (idx < set.size()) {
        for (int par : set[parent_idx]) {
            if (idx >= set.size()) break;
            for (int child : set[idx])
                parent[child] = par;
            idx++;
        }
        parent_idx++;
    }
}

int solve() {
    vector<vector<int>> set = makeSet();
    setParent(set);

    int parentIdx = parent[K];
    if (parentIdx == -1) return 0;
    int grandParent = parent[parentIdx];
    if (grandParent == -1) return 0;

    int ans = 0;
    for (int now : v) {
        int par = parent[now];
        if (par == -1) continue;
        int gPar = parent[par];
        if (gPar == -1) continue;
        if (gPar == grandParent && par != parentIdx)
            ans++;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> N >> K;
        if (N == 0 && K == 0) break;

        v.resize(N);
        for (int i = 0; i <= 1000000; i++) parent[i] = -1;
        for (int i = 0; i < N; i++)
            cin >> v[i];

        cout << solve() << '\n';
    }

    return 0;
}