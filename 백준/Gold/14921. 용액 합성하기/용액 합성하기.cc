#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int ans = 1e9;

    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    int left = 0;
    int right = N - 1;

    while(left < right){
        int sum = v[left] + v[right];

        if(abs(sum) < abs(ans)) ans = sum;
        
        if(sum > 0) right--;
        else if(sum < 0) left++;
        else break;
    }
    
    cout << ans;
}