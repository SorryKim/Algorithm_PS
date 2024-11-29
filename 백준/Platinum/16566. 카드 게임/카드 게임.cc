#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> cards;
vector<bool> check; // 카드의 사용여부를 체크

void Input(){

    cin >> N >> M >> K;
    cards.resize(M);
    check.resize(M, false);
    for(int i = 0; i < M; i++) cin >> cards[i];
    sort(cards.begin(), cards.end());
}

void Solve(){

    for(int i = 0; i < K; i++){

        int num;
        cin >> num;

        int idx = upper_bound(cards.begin(), cards.end(), num) - cards.begin();
        while(check[idx]) idx++;

        check[idx] = true;
        cout << cards[idx] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();
    Solve();
    
    return 0;
}
