#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int sum;
vector<int> feeling;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    sum = 0;
    feeling.resize(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> feeling[i];
        sum += (feeling[i] + 1);
    }

}

long long solve(){

    if(sum >= M) return 0;

    long long ans = 0;
    int remain = M - sum;

    int div1 = remain / (N + 1);
    int div2 = remain % (N + 1);

    for(int i = 1; i <= div1; i++){
        ans += pow(i, 2) * (N + 1);
    }

    ans += pow(div1 + 1, 2) * div2;

    return ans;
}

int main(){
    input();
    cout << solve() << "\n";

    return 0;

}