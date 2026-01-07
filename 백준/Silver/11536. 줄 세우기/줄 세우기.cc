#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    bool inc = true, dec = true;

    for(int i = 0; i < N - 1; i++){
        if(v[i] >= v[i+1]) inc = false;  
        if(v[i] <= v[i+1]) dec = false;
    }

    if(inc) cout << "INCREASING\n";
    else if(dec) cout << "DECREASING\n";
    else cout << "NEITHER\n";

    return 0;
}
