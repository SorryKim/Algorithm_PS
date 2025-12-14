#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

struct Paint {
    int r, g, b;
};

int N;
vector<Paint> paint;
int Rg, Gg, Bg;
int answer = INT_MAX;

void dfs(int idx, int cnt, int sumR, int sumG, int sumB) {
    // 최대 7개 제한
    if (cnt > 7) return;

    // 2개 이상이면 색 차이 계산
    if (cnt >= 2) {
        int avgR = sumR / cnt;
        int avgG = sumG / cnt;
        int avgB = sumB / cnt;

        int diff = abs(avgR - Rg)
                 + abs(avgG - Gg)
                 + abs(avgB - Bg);

        answer = min(answer, diff);
    }

    // 끝까지 확인했으면 종료
    if (idx == N) return;

    // 남은 물감으로 최소 2개 못 채우면 가지치기
    if (cnt + (N - idx) < 2) return;

    dfs(idx + 1,
        cnt + 1,
        sumR + paint[idx].r,
        sumG + paint[idx].g,
        sumB + paint[idx].b);


    dfs(idx + 1, cnt, sumR, sumG, sumB);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    paint.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> paint[i].r >> paint[i].g >> paint[i].b;
    }

    cin >> Rg >> Gg >> Bg;

    dfs(0, 0, 0, 0, 0);

    cout << answer << "\n";
    return 0;
}
