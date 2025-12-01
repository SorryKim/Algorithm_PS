#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    if (!(cin >> N >> E)) return 0;

    vector<long long> people(N + 1, 0);

    int idx = 0; // 선영이가 부른 노래의 인덱스

    for (int i = 0; i < E; i++) {
        int K;
        cin >> K;

        vector<int> v(K);
        bool sy = false;

        // 참석자 입력 및 선영이 참석 여부 확인
        for (int j = 0; j < K; j++) {
            cin >> v[j];
            if (v[j] == 1) {
                sy = true;
            }
        }

        if (sy) {
            // 선영이가 참석함 -> 새로운 노래 추가
            // 현재 노래에 해당하는 비트(1 << idx)를 참석자들에게 추가
            long long new_song = (1LL << idx);
            for (int p : v) {
                people[p] |= new_song;
            }
            idx++;
        } else {
            // 선영이가 불참함 -> 서로 아는 노래 공유
            // 참석자들의 지식을 모두 합침
            long long temp = 0;
            for (int p : v) {
                temp |= people[p];
            }
            // 합쳐진 지식을 참석자들에게 다시 분배
            for (int p : v) {
                people[p] = temp;
            }
        }
    }


    long long all_songs = 0;
    if (idx > 0) all_songs = (1LL << idx) - 1;
    
    for (int i = 1; i <= N; i++) {
        if (people[i] == all_songs) cout << i << "\n";
    }

    return 0;
}