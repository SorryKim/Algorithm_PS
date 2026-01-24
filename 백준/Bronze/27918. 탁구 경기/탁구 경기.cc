#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int d = 0, p = 0;

    for(int i = 0; i < N; i++){
        char c;
        cin >> c;

        if(c == 'D') d++;
        else p++;

        if(abs(d - p) >= 2){
            break;
        }
    }

    cout << d << ":" << p << "\n";
    return 0;
}
