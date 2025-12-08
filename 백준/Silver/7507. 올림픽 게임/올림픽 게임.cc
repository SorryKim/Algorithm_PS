#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Game {
    int d, s, e;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {

        int N;
        int ans = 0;
        cin >> N;

        vector<Game> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i].d >> v[i].s >> v[i].e;
        }
        
        sort(v.begin(), v.end(), [](const Game &a, const Game &b) {
            if (a.d != b.d) return a.d < b.d;   // 날짜 오름차순
            if (a.e != b.e) return a.e < b.e;   // 종료시간 오름차순
            return a.s < b.s;                   // 시작시간 오름차순
        });

        
        int now = v[0].d;
        int last = -1;

        for (int i = 0; i < N; i++) {
            
            // 날짜 바뀌면 새로 시작
            if (v[i].d != now) {
                now = v[i].d;
                last = -1;
            }

            // 종료시간 기준 greedy 선택
            if (v[i].s >= last) {
                ans++;
                last = v[i].e;
            }
        }

        cout << "Scenario #" << tc << ":\n";
        cout << ans << "\n\n";
    }

    return 0;
}
