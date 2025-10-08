#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    for(int i = 0; i < n - 1; i++){
        int target;
        cin >> target;
        s.erase(target);
    }

    for(int num : s) cout << num << "\n";
}