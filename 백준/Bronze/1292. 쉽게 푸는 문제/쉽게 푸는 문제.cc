#include <iostream>
#include <vector>

using namespace std;

int A, B;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;
}

long long solve(){
    vector<long long> v;
    v.push_back(0);
    v.push_back(1);

    for(int i = 2; i <= 1000; i++){
        
        for(int j = 0; j < i; j++){
            int num = v.back();
            v.push_back(num + i);
        }
    }

    return v[B] - v[A - 1];
}

int main(){
    input();
    cout << solve() << "\n";

    return 0;
}