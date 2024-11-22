#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

set<string> my_set;
int n, k;

void DFS(string s, int depth, vector<string> &v, vector<bool> &visited) {
    if (depth == k) {
        my_set.insert(s);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) { 
            visited[i] = true;
            DFS(s + v[i], depth + 1, v, visited);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<bool> visited(n, false);
    DFS("", 0, v, visited);

    cout << my_set.size() << '\n';
    return 0;
}
