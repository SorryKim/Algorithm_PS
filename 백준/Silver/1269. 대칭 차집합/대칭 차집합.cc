#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    set<int> a;

    for(int i = 0; i < A; i++){
        int num;
        cin >> num;
        a.insert(num);
    }

    int cnt = 0;
    for(int i = 0; i < B; i++){
        int num;
        cin >> num;

        if(a.find(num) != a.end()) cnt++;
    }

    cout << A + B - 2 * cnt << "\n";
    
    return 0;
}