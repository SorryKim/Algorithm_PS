#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M, K;
int candies[30001];
int parent[30001];
int cnt[30001];

int Find(int n) {
    if (n == parent[n]) return n;
    else return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
    int p1 = Find(a);
    int p2 = Find(b);

    if (p1 == p2) return; 

   
    if (cnt[p1] < cnt[p2]) {
        parent[p1] = p2;
        cnt[p2] += cnt[p1];
        candies[p2] += candies[p1];
    } else {
        parent[p2] = p1;
        cnt[p1] += cnt[p2];
        candies[p1] += candies[p2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> candies[i];
        parent[i] = i;
        cnt[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    set<int> parents;
    for (int i = 1; i <= N; i++) 
        parents.insert(Find(i));
    
    vector<int> dp(K, 0);
    vector<int> group_weights;
    vector<int> group_values;
    for (int p : parents) {
        group_weights.push_back(cnt[p]);
        group_values.push_back(candies[p]);
    }

    for (int i = 0; i < group_weights.size(); i++) {
        int w = group_weights[i]; 
        int v = group_values[i];  

        for (int j = K - 1; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    int answer = 0;
    for (int i = 0; i < K; i++) {
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';

    return 0;
}
