#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> belt(N);
    for(int i = 0; i < N; i++)
        cin >> belt[i];

    unordered_map<int, int> table;
    int ans = 0;

    // 초기 윈도우 설정
    for(int i = 0; i < k; i++)
        table[belt[i]]++;

    table[c]++;

    ans = table.size();

    // 슬라이딩 윈도우
    for(int i = 1; i < N; i++){

        // 왼쪽 초밥 제거
        int leftSushi = belt[(i - 1) % N];
        table[leftSushi]--;
        if(table[leftSushi] == 0)
            table.erase(leftSushi);

        // 오른쪽 초밥 추가
        int rightSushi = belt[(i + k - 1) % N];
        table[rightSushi]++;

        ans = max(ans, (int)table.size());
        if(ans == d + 1)
            break;
    }

    cout << ans;
    return 0;
}
