#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
vector<int> words;
vector<char> candidate; 
int answer = 0;

void DFS(int idx, int cnt, int learned) {

    // 선택한 문자의 수가 K를 초과하면 종료
    if (cnt > K) return;

    // 모든 후보 문자를 탐색했을 때 또는 선택한 문자의 수가 K일 때 결과 계산
    if (idx == candidate.size() || cnt == K) {
        int result = 0;

        // 비트 비교를 통해 단어를 읽을 수 있는지 확인
        for (int word : words) 
            if ((word & learned) == word) 
                result++;
        
        answer = max(answer, result);
        return;
    }

    // 현재 문자 선택
    DFS(idx + 1, cnt + 1, learned | (1 << (candidate[idx] - 'a')));

    // 현재 문자 선택 안함
    DFS(idx + 1, cnt, learned);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    // K가 5보다 작으면 어떤 단어도 읽을 수 없음
    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }

    // K가 26이면 모든 단어를 읽을 수 있음
    if (K == 26) {
        cout << N << '\n';
        return 0;
    }

    int init = 0;
    init |= (1 << ('a' - 'a'));
    init |= (1 << ('n' - 'a'));
    init |= (1 << ('t' - 'a'));
    init |= (1 << ('i' - 'a'));
    init |= (1 << ('c' - 'a'));

    vector<bool> isUsed(26, false);
    isUsed['a' - 'a'] = true;
    isUsed['n' - 'a'] = true;
    isUsed['t' - 'a'] = true;
    isUsed['i' - 'a'] = true;
    isUsed['c' - 'a'] = true;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int mask = 0;
        for (char c : s) {
            int bit = c - 'a';
            mask |= (1 << bit);
        }
        words.push_back(mask);

        for (char c : s) {
            if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c')
                continue;
            
            if (!isUsed[c - 'a']) {
                isUsed[c - 'a'] = true;
                candidate.push_back(c);
            }
        }
    }

    DFS(0, 5, init);

    cout << answer << '\n';

    return 0;
}
