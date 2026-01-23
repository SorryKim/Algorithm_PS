#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);
    long long sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }

    // 1) 전체 합이 홀수면 홀수로 나누기 항상 가능
    if(sum % 2 == 1){
        cout << 1 << "\n";
        return 0;
    }

    // 2) 전체 합이 짝수면 짝수로 나누기 가능한지 체크
    long long pref = 0;
    for(int i = 0; i < N-1; i++){
        pref += A[i];
        if(pref % 2 == 0){
            cout << 1 << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";
    return 0;
}
