#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num = 1;
    while(num != 0){
        cin >> num;
        if(num == 0) return 0;

        int ans = 0;
        for(int i = 1; i <= num; i++) ans += i;

        cout << ans << '\n';
    }

    return 0;
}