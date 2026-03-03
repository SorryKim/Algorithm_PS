#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    long long N;
    cin >> N;

    long long val = N / 5;
    
    for(int i = 0; i < 5 && val - i >= 0; i++){
        long long temp = val - i;
        long long remain = N - 5 * temp;

        if(remain % 3 == 0){
            cout << temp + remain / 3;
            return 0;
        }
    }

    cout << -1;
    
    return 0;
}