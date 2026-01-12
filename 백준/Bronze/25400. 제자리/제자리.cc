#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int need = 1;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x == need){
            need++;
        }
    }

    int ans = need - 1;
    cout << N - ans << "\n";
    
    return 0;
}
