#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    vector<int> v;

    cin >> a >> b;

    for(int i = 0; i < a; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    for(int i = 0 ; i < b; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    for(int n : v) cout << n << " ";
    
    return 0;
}