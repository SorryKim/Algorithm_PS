#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int ans;
int N, L;

void DFS(int index, int totalCalories, int totalScore, const vector<pair<int,int>> &v) {

    if (index == N) {
        // 현재까지의 조합에서의 맛의 점수 계산
        if (totalCalories <= L) {
            ans = max(ans, totalScore);
        }
        return;
    }
    
    int nowScore = v[index].first;
    int nowCalrories = v[index].second;
    // 해당 재료를 선택하지 않는 경우
    DFS(index + 1, totalCalories, totalScore, v);

    // 해당 재료를 선택하는 경우
    DFS(index + 1, totalCalories + nowCalrories, totalScore + nowScore, v);
}
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    else {
        return a.second < b.second; 
    }
}

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase) {
        
        cin >> N >> L;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++) {
            int T, K;
            cin >> T >> K;
            v.push_back({ T, K });
        }
        ans = 0;

        DFS(0, 0, 0, v);
        cout << "#" << testCase << " " << ans << "\n";
    }

    return 0;
}
